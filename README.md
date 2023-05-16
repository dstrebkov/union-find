Union-Find
================

![cpp-cmake-project-template](https://github.com/dstrebkov/union-find/actions/workflows/cmake.yml/badge.svg?event=push)
[![codecov](https://codecov.io/gh/dstrebkov/union-find/branch/main/graph/badge.svg?token=SFV0P2XPIW)](https://codecov.io/gh/dstrebkov/union-find)
![language](https://img.shields.io/github/languages/top/dstrebkov/union-find)
![repo size](https://img.shields.io/github/repo-size/dstrebkov/union-find)
![language count](https://img.shields.io/github/languages/count/dstrebkov/union-find)

Data structure for solving [Dynamic Connectivity](https://en.wikipedia.org/wiki/Dynamic_connectivity) problem.

Could be used to give quick answers to queries of the form "_Is there a path between X and Y?_" (i.e. "_Do vertices X and Y belong to the same connected component?_").

Implementation include the following [Quick-Find and Quick-Union algorithms](https://algs4.cs.princeton.edu/15uf/):

| Algorithm            | `Union()` time complexity  (worst case) | `Find()`  time complexity  (worst case) | Memory complexity |
|----------------------|-----------------------------------------|-----------------------------------------|-------------------|
| Quick-Find           | `N`                                     | `1`                                     | `N`               |
| Quick-Union          | `N`                                     | `N`                                     | `N`               |
| Weighted Quick-Union | `log2(N)`                               | `log2(N)`                               | `2*N`             |

## Requrements

C++17 and CMake ≥ `3.18`.

GoogleTest is obtained via `FetchContent_MakeAvailable()` and not required to be pre-installed.

CTest-based pipeline starting script `cmake/Pipeline.cmake` uses *GCC*, *gcov*, *Python 3* for *gcovr* installation in venv and (optionally) system Valgrind installation.


## Benchmark

| Problem of 1M sites and ...        | ... 20K `Union()` / `Find()` pairs | ... 700K `Union()` / `Find()` pairs | ... 2M `Union()` / `Find()` pairs |
|------------------------------------|------------------------------------|-------------------------------------|-----------------------------------|
| Quick-Find           | `21.1539` sec.                     | -                                   | -                                 |
| Quick-Union          | `0.012467` sec.                    | `35.1199` sec.                      | -                                 |
| Weighted Quick-Union | `0.016003` sec.                    | `0.468004` sec.                     | `1.20773` sec.                    |

## References

[Algorithms, 4th Edition by Robert Sedgewick and Kevin Wayne](https://algs4.cs.princeton.edu/home/)
