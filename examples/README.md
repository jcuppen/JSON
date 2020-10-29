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