# Examples
## How to Run?
```bash
sac2c FILENAME.sac
./a.out
```
## Files
### `empty_json_object.sac`
Creates an empty json object and outputs it to stdout.
expected result:
```json
{
}
```

### `booleans.sac`
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

### `numbers.sac`
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

### `string.sac`
Creates a json object and sets a string.
Then outputs the json object to stdout.
expected result:
```json
{
	"aString":	"Hello World!"
}
```
