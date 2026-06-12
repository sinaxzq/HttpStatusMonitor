# HttpStatusMonitor

A small C++ command-line tool that checks HTTP status codes and response times for one or more URLs.

## Features

* Check one or multiple URLs from the command line
* Print HTTP status code and elapsed response time
* Report request errors such as timeouts
* Use a timeout to avoid hanging requests
* Return a non-zero exit code when any URL is unhealthy
* Unit tests for result formatting and health classification

## Tech stack

* C++17
* CMake
* CTest
* cpr
* libcurl
* assert-based tests

## Architecture

The project separates CLI handling, HTTP checking, result formatting, and health classification.

* `HttpCheckResult` stores the result of checking one URL.
* `HttpChecker` performs the HTTP request and measures elapsed time.
* `ResultFormatter` converts a check result into printable text.
* `StatusClassifier` decides whether a result is healthy.
* `main.cpp` handles command-line arguments and program exit codes.

## Usage

Check one URL:

```powershell
.\build\Debug\HttpStatusMonitor.exe https://example.com
```

Check multiple URLs:

```powershell
.\build\Debug\HttpStatusMonitor.exe https://example.com https://github.com
```

Example output:

```text
https://example.com | 200 | 237 ms
https://github.com | 200 | 412 ms
```

## Exit codes

* `0` — all URLs are healthy
* `1` — invalid usage
* `2` — at least one URL is unhealthy

A result is considered healthy when the request succeeds and the HTTP status code is from `200` to `399`.

## Build

```powershell
cmake -S . -B build
cmake --build build --config Debug
```

## Run tests

```powershell
ctest --test-dir build -C Debug --output-on-failure
```

## Notes

The project uses `cpr`, which is built on top of `libcurl`.

On Windows, runtime DLLs are copied next to the executable after build so the program can run from the build output directory.
