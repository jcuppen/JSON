# SAC JSON Module
## About
This is a Sac module that wraps around some of the [cJSON](https://github.com/DaveGamble/cJSON) library.
Currently this is a work in progress.

## Supported Functionality
- Creation of empty JSON object.
- Adding booleans to JSON objects.
- Adding integers to JSON objects.
- Adding floats to JSON objects.
- Adding doubles to JSON objects.
- Adding strings to JSON objects.
- Serializing JSON objects to stdout.

## Build Instructions
You will need to have installed sac2c and have a copy of the Stdlib installed as well.
```bash
cd JSON
git submodule init
git submodule update
cd build
cmake ..
make -j4
```
