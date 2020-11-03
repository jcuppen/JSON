# SAC JSON Module
## About
This is a Sac module that wraps around some of the [cJSON](https://github.com/DaveGamble/cJSON) library.
Currently this is a work in progress.

## Supported Functionality
- Creation of:
	- JSON objects
	- JSON arrays
- Booleans
	- Insertion into JSON object
	- Insertion into JSON array
- Numbers (int, float, double)
	- Insertion into JSON object
	- Insertion into JSON array
- Strings
	- Insertion into JSON object
	- Insertion into JSON array
- Arrays
	- Insertion into JSON object
	- Insertion of additional elements after insertion by means of changing focus.
- Serialization to stdout of:
	- JSON objects
	- JSON arrays
- Shifting focus:
	- to child nodes
	- to the root JSON object

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
