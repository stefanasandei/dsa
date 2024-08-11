# Data Structures & Algorithms

This is my implementation of common data structures and algorithms in modern C++. The project is structured within two
main projects: a library and a test suite:

- `external`: 3rd party libraries (only gtest for now)
- `lib`: the library containing the data structures and algorithms
- `test`: test suite using Google Test

## Setup

Clone the repository:

```
git clone https://github.com/stefanasandei/dsa.git --recursive
```

Create a build directory (this will contain the solution files):

```
mkdir build
cd build
```

Generate the project:

```
cmake ..
```

Now open the build directory in a file explorer, and open the solution in your preferred IDE. On startup, set
the `dsa_tests` as the startup project.

## License

[MIT](LICENSE) © [Asandei Stefan-Alexandru](https://asandei.com). All rights reserved.
