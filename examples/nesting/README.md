# Examples
## How to Run?
```bash
sac2c FILENAME.sac
./a.out
```
## Files

### `2_in_1_then_1_in_0.sac`
Creates 3 JSON objects: `lvl_0_object`, `lvl_1_object` and `lvl_2_object`.
A string is added to `lvl_2_object`.
`lvl_2_object` is inserted into `lvl_1_object`
`lvl_1_object` is inserted into `lvl_0_object`
And finally `lvl_0_object` is printed to stdout.

expected result:
```json
{
	"lvl_1":	{
		"lvl_2":	{
			"msg":	"first: 2 in 1, then 1 in 0"
		}
	}
}
```

### `1_in_0_then_2_in_1.sac`
Creates two JSON objects `lvl_0_object` and `lvl_1_object`.
Inserts `lvl_1_object` into `lvl_0_object` under the key "lvl_1".
We change focus to the element with key "lvl_1" and assign it to `lv1`.
Then we create another JSON object `lvl_2_object` and add a string to it.
This `lvl_2_object` is inserted into `lv1`.
Focus is shifted back to the root and the root is printed to stdout.

expected result:
```json
{
	"lvl_1":	{
		"lvl_2":	{
			"msg":	"first: 1 in 0, then 2 in 1"
		}
	}
}
```
