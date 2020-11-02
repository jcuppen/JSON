#include <cjson/cJSON.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

cJSON * create_object()
{
	return cJSON_CreateObject();
}
cJSON * create_array()
{
	return cJSON_CreateArray();
}

// Booleans
void set_bool( cJSON * object, char * key, bool boolean)
{
	cJSON * val;
	val = boolean ? cJSON_CreateTrue() : cJSON_CreateFalse();
	cJSON_AddItemToObject(object, key, val);
}
void set_true( cJSON * object, char * key) 
{
	set_bool(object, key, true);
}
void set_false( cJSON * object, char * key) 
{
	set_bool(object, key, false);
}

// Numbers
void set_int( cJSON * object, char * key, int value)
{
	cJSON_AddNumberToObject(object, key, value);
}
void set_float( cJSON * object, char * key, float value)
{
	cJSON_AddNumberToObject(object, key, (double)value);
}
void set_double( cJSON * object, char * key, double value)
{
	cJSON_AddNumberToObject(object, key, value);
}

// String
void set_string( cJSON * object, char * key, char * value)
{
	cJSON_AddStringToObject(object, key, value);
}

// Arrays
cJSON * set_array( cJSON * object, char * key, cJSON * array)
{
        char *local;
        local = malloc( strlen( key) +1);
        local = strcpy( local, key);
	cJSON_AddItemToObject(object, local, array);
        return array;
}
void set_array_ref( cJSON * object, char * key, cJSON * array)
{
	cJSON_AddItemReferenceToObject(object, key, array);
}
cJSON * create_empty_array_in_object( cJSON * object, char * key)
{
	return cJSON_AddArrayToObject(object, key);
}

// Array manipulation
void add_to_array( cJSON * array, cJSON * item)
{
	cJSON_AddItemToArray(array, item);
}
void add_to_array_ref( cJSON * array, cJSON * item)
{
	cJSON_AddItemReferenceToArray(array, item);
}
void add_int_to_array( cJSON * array, int item)
{
	cJSON * val;
	val = cJSON_CreateNumber(item);
	add_to_array(array, val);
}
cJSON * add_int_to_array_ref( cJSON * array, int item)
{
	cJSON * val;
	val = cJSON_CreateNumber(item);
	add_to_array_ref(array, val);
        return val;
}

// Serialization
void serialize_object( cJSON* object)
{
	char * str;
	str = cJSON_Print(object);
	printf("%s\n", str);
}
