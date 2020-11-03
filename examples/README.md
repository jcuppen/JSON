# Examples
## How to Run?
```bash
sac2c FILENAME.sac
./a.out
```
## Files
### `printing_json_empty.sac`
Creates an empty json object and outputs it to stdout.
expected result:
```json
{
}
```

### `printing_json_booleans.sac`
Creates a json object and sets some booleans in various ways.
Then outputs the json object to stdout.
expected result:
```json
{
	"isTrue":		true,
	"isFalse":		false,
	"isAlsoTrue":	true,
	"isAlsoFalse":	false
}
```

### `printing_json_numbers.sac`
Creates a json object and sets numbers in various ways (int, float, double).
Then outputs the json object to stdout.
expected result:
```json
{
	"integer":	42,
	"float":	1.2000000476837158,
	"double":	3.4
}
```

### `printing_json_string.sac`
Creates a json object and sets a string.
Then outputs the json object to stdout.
expected result:
```json
{
	"aString":	"Hello World!"
}
```

### `printing_json_array.sac`
Creates a json object.
Then a json array that is filled with booleans.
Then a json array that is filled with various types of numbers.
Then a json array that is filled with strings.
All arrays are then added and the json object is printed.
Then the focus is shifted to the array containing numbers, and said array is printed.
Another number is added after insertion to show this is possible.
Finally we shift focus back to the root object and print that., then an array and sets a string.

expected result:
```json
{
	"myNumberArr":	[4, 3.7999999523162842, 42.22],
	"myBoolArr":	[true, false, true, false],
	"myStringArr":	["Hello", "World"]
}
[4, 3.7999999523162842, 42.22, 42]
{
	"myNumberArr":	[4, 3.7999999523162842, 42.22, 42],
	"myBoolArr":	[true, false, true, false],
	"myStringArr":	["Hello", "World"]
}
```
