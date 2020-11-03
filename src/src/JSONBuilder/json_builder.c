#include <cjson/cJSON.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "sac.h"
#include "../include/sac-cjson.h"

static 
SAC_cJSON * makePair( cJSON * obj)
{
   SAC_cJSON *res;
   res = SAC_MALLOC( sizeof(SAC_cJSON));
   res->head = obj;
   res->root = obj;

   return res;
}

SAC_cJSON * create_object()
{
	return makePair( cJSON_CreateObject());
}

SAC_cJSON * create_array()
{
	return makePair( cJSON_CreateArray());
}

#if 0
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

#endif

// Arrays
void insert_array( SAC_cJSON ** object, SAC_array_descriptor_t *object_desc,
                   char * key, SAC_cJSON * array, SAC_array_descriptor_t array_desc)
{
        char *local;
        local = SAC_MALLOC( strlen(key)+1);
        local = strcpy( local, key);
        if( array->head != array->root) 
          SAC_RuntimeError( "Trying to insert non-root JSON object!");
	cJSON_AddItemToObject((*object)->head, local, array->head);
        SAC_FREE( array_desc);
}

#if 0
void set_array_ref( cJSON * object, char * key, cJSON * array)
{
	cJSON_AddItemReferenceToObject(object, key, array);
}
cJSON * create_empty_array_in_object( cJSON * object, char * key)
{
	return cJSON_AddArrayToObject(object, key);
}
#endif

// Array manipulation
void add_to_array( cJSON * array, cJSON * item)
{
	cJSON_AddItemToArray(array, item);
}

void add_int_to_array( SAC_cJSON * array, int item)
{
	cJSON * val;
	val = cJSON_CreateNumber(item);
	add_to_array(array->head, val);
}

#if 0
cJSON * add_int_to_array_ref( cJSON * array, int item)
{
	cJSON * val;
	val = cJSON_CreateNumber(item);
	add_to_array_ref(array, val);
        return val;
}
#endif

// Serialization
void serialize_object( SAC_cJSON* object)
{
	char * str;
	str = cJSON_Print(object->head);
	printf("%s\n", str);
}
