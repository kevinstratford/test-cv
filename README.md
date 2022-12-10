# test-cv

There are a couple of things going on here. One is `codecov`, and
the other is `codeql`.

## Codecov

Should work without too much difficulty.

## CodeQL query

First, try to run the query locally. This requires the installation of
the CodeQL CLI (binaries) and the codeql repository in the same
location. This is discussed, e.g., here:

https://github.blog/2022-04-19-sharing-security-expertise-through-codeql-packs-part-i/

Get the location into the local `PATH`.

In the local copy of this repository, run the database creation step
```
$ codeql database create ql-database --language=cpp --command=make --overwrite
```
Here, `make` will compile the code (no run actually necessary). Use
`--overwrite` to force creation of a new database, if required.

One can run a standard query, e.g.,
```
$ codeql database analyze ql-database \
         codeql/cpp-queries:Critical/LargeParameter.ql \
	 --format=sarifv2.1.0 --sarif-add-query-help --output=cpp-results.sarif
```
for a `cpp/large-parameter` test.

To run a standard suite, one can use `cpp-code-scanning.qls`,
`cpp-security-extended.qls` or `cpp-security-and-quality.qls`.

To add a new query, I'm just going to take a copy of the `cpp/large-parameter`
code, and relax the constraint to a size of 128 bytes. Update the new query
metadata in the file header.

We will place the new query in
```
./codeql/relaxed-large-parameter.ql
```

Add an appropriate `qlpack.yml` file (must have that name) with a new
description of dependencies.

Run once:
```
$ codeql pack install codeql
```
which will create a `codeql-pack.lock.yml` in the `codeql` subdirectory
(this doesn't need to be checked-in).

It should then be possible to run an analysis, e.g.,:
```
$ codeql database analyze ql-database ./codeql/relaxed-large-parameter.ql \
        --format=sarifv2.1.0 --sarif-add-query-help \
	--output=cpp-results.sarif --sarif-add-snippets --rerun
```
(note use `--rerun` to force the query to be rerun if necessary).


For CI, I've set up the `.github/workflows/codeql.yml` to run with
a config file `./github/workflows/codeql-config.yml`. The latter has
```
queries:
  - uses: security-and-quality
  - uses: ./codeql/relaxed-large-parameter.ql

query-filters:
- exclude:
    id:
    - cpp/large-parameter
```
to substitute the standard `cpp/large-parameter` test with the relaxed
version. One should probably also add a query help file and an example
to appear in the console.

