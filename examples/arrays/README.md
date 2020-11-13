# Examples
## How to Run?
```bash
sac2c FILENAME.sac
./a.out
```
## Files
### `changing_focus.sac`
A JSON object is created.
Then a JSON array is created.
This array is filled with the boolean true and is added to the object under the key "myBoolArr".
The object is printed to stdout.
focus is shifted to the array with key "myBoolArr"
A false is added after the original array was inserted.
This array is then printed to stdout.
And finally focus is shifted back to the root object and printed to stdout.

expected result:
```json
{
	"myBoolArr":	[true]
}
[true, false]
{
	"myBoolArr":	[true, false]
}
```

### `element_removal.sac`
This creates a JSON array `json_array`
the integers 1,2 and 3 are added to this array.
Then the array is printed to stdout.
After that the element at index 1 is removed and the array is printed to stdout again.

expected result:
```json
[1, 2, 3]
[1, 3]
```

### `element_replacement.sac`
This creates a JSON array with lots of `true`s.
Which are then replaced by various other elements.

expected result:
```json
[true, true, true, true, true, true, true, true, true]
[
	true,
	true,
	false,
	4,
	2.3,
	4.3000001907348633,
	"HELLO",
	{},
	[]
]
```

### `json_array_in_object.sac`
A JSON object is created.
Then a JSON array is created.
This array is then filled with various types of numbers and added to the object.
And finally the object containing the array is printed to stdout.

expected result:
```json
{
	"myNumberArr":	[4, 3.7999999523162842, 42.22]
}
```

### `json_array_simple.sac`
A JSON array is created.
Then it is filled with various types of numbers.
And finally it is printed to stdout.

expected result:
```json
[4, 3.7999999523162842, 42.22]
```
