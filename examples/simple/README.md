# Examples
## How to Run?
```bash
sac2c FILENAME.sac
./a.out
```
## Files
### `booleans.sac`
Creates a JSON object and sets some booleans in various ways.
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

### `element_removal.sac`
Creates a JSON object and sets two boolean under the key "isTrue" and "isFalse".
This object is printed to stdout.
Then the element with the key "isTrue" is removed and the object is printed to stdout.

expected result:
```json
{
	"isTrue":		true,
	"isFalse":		false
}
{

	"isFalse":		false
}
```

### `element_replacement.sac`
Create a JSON object with every kind of element.
This object is printed to stdout.
Then all elements are replaced with another and is printed to stdout once more.

expected result:
```json
{
	"becomesFalse":	true,
	"becomesFalseAsWell":	true,
	"becomesTrue":	false,
	"becomes42":	2,
	"becomes3.14":	1.1,
	"becomes2.1f":	1.2000000476837158,
	"becomesBYE":	"HELLO",
	"becomes[]":	[true],
	"becomes{}":	{
		"int":	5
	}
}
{
	"becomesFalse":	false,
	"becomesFalseAsWell":	false,
	"becomesTrue":	true,
	"becomes42":	42,
	"becomes3.14":	3.14,
	"becomes2.1f":	2.0999999046325684,
	"becomesBYE":	"BYE",
	"becomes[]":	[],
	"becomes{}":	{}
}
```


### `empty_json_object.sac`
Creates an empty JSON object and outputs it to stdout.

expected result:
```json
{
}
```

### `numbers.sac`
Creates a JSON object and sets numbers in various ways (int, float, double).
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
Creates a JSON object and sets a string.
Then outputs the object to stdout.

expected result:
```json
{
	"aString":	"Hello World!"
}
```
