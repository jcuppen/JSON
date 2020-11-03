#include <cjson/cJSON.h>
#include <stdbool.h>
#include <stdio.h>
#include "../include/utils.h"
#include "sac.h"
#include "../include/sac_cjson.h"

// Creation
static SAC_cJSON * make_sac_cjson_object( cJSON * object)
{
	SAC_cJSON * result;
	result = SAC_MALLOC( sizeof( SAC_cJSON));
	result->head = object;
	result->root = object;
	return result;
}
SAC_cJSON * create_object()
{
	return make_sac_cjson_object( cJSON_CreateObject());
}
SAC_cJSON * create_array()
{
	return make_sac_cjson_object( cJSON_CreateArray());
}

// Booleans
void set_bool( cJSON * object, char * key, bool boolean)
{
	cJSON * value;
	value = boolean ? cJSON_CreateTrue() : cJSON_CreateFalse();
	cJSON_AddItemToObject( object, key, value);
}
void set_true( cJSON * object, char * key)
{
	set_bool( object, key, true);
}
void set_false( cJSON * object, char * key)
{
	set_bool( object, key, false);
}

// Numbers
void set_int( cJSON * object, char * key, int value)
{
	cJSON_AddNumberToObject( object, key, value);
}
void set_float( cJSON * object, char * key, float value)
{
	cJSON_AddNumberToObject( object, key, (double)value);
}
void set_double( cJSON * object, char * key, double value)
{
	cJSON_AddNumberToObject( object, key, value);
}

// String
void set_string( cJSON * object, char * key, char * value)
{
	cJSON_AddStringToObject( object, key, value);
}

// Arrays
void insert_array( SAC_cJSON ** object, SAC_array_descriptor_t * object_descriptor,
					char * key, SAC_cJSON * array, SAC_array_descriptor_t array_descriptor)
{
	char * local;
	local = copyString( key);
	if( array->head != array->root)
	{
		SAC_RuntimeError( "Trying to insert non-root JSON object!");
	}
	cJSON_AddItemToObject( (*object)->head, local, array->head);
	SAC_FREE( array_descriptor);
}

// Array manipulation
void add_to_array( cJSON * array, cJSON * item)
{
	cJSON_AddItemToArray( array, item);
}
void add_int_to_array( SAC_cJSON * array, int number)
{
	cJSON * value;
	value = cJSON_CreateNumber( number);
	add_to_array( array->head, value);
}

// JSON traversal
void change_focus( SAC_cJSON ** out, SAC_array_descriptor_t * out_descriptor,
					SAC_cJSON * in, SAC_array_descriptor_t in_descriptor, char * key)
{
	cJSON * result;
	char * local;

	local = copyString( key);
	result = cJSON_GetObjectItemCaseSensitive( in->head, local);
	if ( result == NULL)
	{
		SAC_RuntimeError( "keyword \"%s\" not found", local);
	}
	*out = in;
	(*out)->head = result;
	*out_descriptor = in_descriptor;
}

// Input Output
void serialize_object( SAC_cJSON * object)
{
	char * str;
	str = cJSON_Print( object->head);
	printf( "%s\n", str);
}
