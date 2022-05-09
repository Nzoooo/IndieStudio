====

# Building

## Command Line (via CMake)

Required tools:
- CMake 3.17 (minimum)

on Linux:
```sh
# Create the build directory
take build

# Configure the project
cmake .. -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Release

# Build the executable and libraries
cmake --build .

# Return to previous directory
cd -
```