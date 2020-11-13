# Examples
## How to Run?
```bash
sac2c FILENAME.sac
./a.out
```
## Files
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

### `nesting_arrays.sac`
Creates a JSON object `root`
Creates 4 JSON arrays: `outer_array`, `inner_array1`, `inner_array2` & `inner_array3`.
The first inner array is filled with the values 1, 2 & 3.
The second inner array is filled with the values 4, 5 & 6.
The third inner array is filled with the values 7, 8 & 9.
These inner arrays are inserted into the outer array.
This outer array is added to the root object under the key "matrix".
This root is then printed to stdout.

expected result:
```json
{
	"matrix":	[
					[1, 2, 3],
					[4, 5, 6],
					[7, 8, 9]
				]
}
```

### `objects_in_array.sac`
Creates a JSON array `root`.
Creates 3 JSON objects: `obj1`, `obj2` & `obj3`.
Each object gets an int (1,2,3) under respective keys ("one", "two", "three").
All objects are added to the root array.
This root is then printed to stdout.

expected result:
```json
[
	{
		"one":	1
	},
	{
		"two":	2
	},
	{
		"three":	3
	}
]
```
