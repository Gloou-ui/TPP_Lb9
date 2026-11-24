# Laboratory 9

The project uses C++17 and contains two parts:

1. A refactored library-management example.
2. A refactoring of the fraction-approximation kata.

## Build

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build
./build/lab9_demo
```

On Windows with Ninja:

```sh
cmake -S . -B build -G "Ninja"
cmake --build build
ctest --test-dir build
.\build\lab9_demo.exe
```
