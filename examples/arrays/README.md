# Examples
## How to Run?
```bash
sac2c FILENAME.sac
./a.out
```
## Files
### `json_array_simple.sac`
A JSON array is created.
Then it is filled with various types of numbers.
And finally it is printed to stdout.

expected result:
```json
[4, 3.7999999523162842, 42.22]
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
