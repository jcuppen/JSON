#include <cjson/cJSON.h>
#include <stdbool.h>
#include <stdio.h>

cJSON * create_object()
{
	return cJSON_CreateObject();
}

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

void serialize_object( cJSON* object)
{
	char * str;
	str = cJSON_Print(object);
	printf("%s\n", str);
}
