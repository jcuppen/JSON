#include <cjson/cJSON.h>
#include <stdbool.h>
#include <stdio.h>

cJSON * create_object()
{
	return cJSON_CreateObject();
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
	cJSON * val;
	val = cJSON_CreateNumber(value);
	cJSON_AddItemToObject(object, key, val);
}
void set_float( cJSON * object, char * key, float value)
{
	cJSON * val;
	val = cJSON_CreateNumber((double)value);
	cJSON_AddItemToObject(object, key, val);
}
void set_double( cJSON * object, char * key, double value)
{
	cJSON * val;
	val = cJSON_CreateNumber(value);
	cJSON_AddItemToObject(object, key, val);
}

void serialize_object( cJSON* object)
{
	char * str;
	str = cJSON_Print(object);
	printf("%s\n", str);
}
