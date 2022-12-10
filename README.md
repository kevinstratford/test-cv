# test-cv

Test coverage

## CodeQL query

First, try to run the query locally. This requires the installation of
the CodeQL CLI (binaries) and the codeql repository in the same
location. This is discussed, e.g., here:

https://github.blog/2022-04-19-sharing-security-expertise-through-codeql-packs-part-i/

In the local copy of this repository, run the database creation step
```
$ codeql database create ql-database --language=cpp --command=make --overwrite
```


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
metadata.

Add an appropriate `qlpack.yml` file (must have that name) with a new
description of dependencies. This must be present.

Run once:
```
$ codeql pack install
```

It should then be possible to run an analysis, e.g.,:
```
$ codeql database analyze ql-database my-query1.ql \
        --format=sarifv2.1.0 --sarif-add-query-help \
	--output=cpp-results.sarif --sarif-add-snippets --rerun
```
(note use `--rerun` to force the query to be rerun if necessary).
