
## Archived: 2026-11-02
* The project requires Bazel 4.0.0 for building.
* The repository's Bazel setup (specifically `rules_python`) is incompatible with Python 3.12, causing build failures.
* When Bazel fails due to environment issues, manual `g++` compilation can be used to verify C++ logic.
