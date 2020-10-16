# SAC JSON Module
## About
This is a Sac module that wraps around some of the [cJSON](https://github.com/DaveGamble/cJSON) library. Currently this is a work in progress.
## Build Instructions
You'll need to have installed sac2c and have a copy of the Stdlib installed as well.
```bash
cd JSON
git submodule init
git submodule update
cd build
cmake ..
make -j4
```
