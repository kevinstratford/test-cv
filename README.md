# test-cv

Test coverage

## CodeQL query

First, try to run the query locally. This require installation of
the CodeQL CLI.

Copy a sample query .ql file and make adjustments as required.

Define a query pack .yml description. See, e.g.,

https://github.blog/2022-04-19-sharing-security-expertise-through-codeql-packs-part-i/

Run the database creation step
```
$ codeql database create ql-database --language=cpp --command=make --overwrite
```


Run a standard query, e.g.,
```
$ codeql database analyze ql-database codeql/cpp-queries:Critical/LargeParameter.ql --format=sarifv2.1.0 --sarif-add-query-help --output=cpp-results.sarif
```
for a `LargeParameter` test.

Add an appropriate `qlpack.yml` file (must have that name) with a new
description and relevant individual queries. Run an analysis, e.g.,:
```
$ codeql database analyze ql-database my-query1.ql --format=sarifv2.1.0 --sarif-add-query-help --output=cpp-results.sarif --sarif-add-snippets --rerun

```
