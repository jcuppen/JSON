# SAC JSON Module
## About
This is a Sac module that wraps around some of the [cJSON](https://github.com/DaveGamble/cJSON) library.

## Supported Functionality
- Creation of:
	- JSON objects
	- JSON arrays
- Booleans
	- Insertion into JSON object
	- Insertion into JSON array
	- Replacing elements in JSON arrays with Booleans
- Numbers (int, float, double)
	- Insertion into JSON object
	- Insertion into JSON array
	- Replacing elements in JSON arrays with Numbers
- Strings
	- Insertion into JSON object
	- Insertion into JSON array
	- Replacing elements in JSON arrays with Strings
- Arrays
	- Insertion into JSON object
	- Insertion of additional elements after insertion by means of changing focus
	- Replacing elements in JSON arrays with JSON arrays
- Objects
	- Insertion into JSON object
	- Insertion of additional elements after insertion by means of changing focus
	- Replacing elements in JSON arrays with JSON objects
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

### Troubleshooting
#### macOS 11 (Big Sur)
Whenever the error:
`ld: library not found for -lcjson`
is encountered it can be remedied by running the following export.
`export LIBRARY_PATH=$LIBRARY_PATH:{/absolute/path/to/cjson/lib/}`
