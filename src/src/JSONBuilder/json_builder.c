#include <cjson/cJSON.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
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
SAC_cJSON * create_object(void)
{
	return make_sac_cjson_object( cJSON_CreateObject());
}
SAC_cJSON * create_array(void)
{
	return make_sac_cjson_object( cJSON_CreateArray());
}


// Element removal
void remove_item_from_object( SAC_cJSON * object, char * key)
{
	cJSON_DeleteItemFromObjectCaseSensitive(object->head, key);
}
void remove_item_from_array( SAC_cJSON * array, int index)
{
	cJSON_DeleteItemFromArray(array->head, index);
}

static char * copy_string(char * source)
{
	char * result;
	result = SAC_MALLOC( strlen( source) + 1);
	result = strcpy( result, source);
	return result;
}


void set_item( SAC_cJSON * object, char * key, cJSON * value)
{
	remove_item_from_object( object, key);
	cJSON_AddItemToObject( object->head, copy_string(key), value);
}

// Booleans
void set_bool( SAC_cJSON * object, char * key, bool boolean)
{
	set_item( object, key, cJSON_CreateBool( boolean));
}
void set_true( SAC_cJSON * object, char * key)
{
	set_bool( object, key, true);
}
void set_false( SAC_cJSON * object, char * key)
{
	set_bool( object, key, false);
}


// Numbers
void set_int( SAC_cJSON * object, char * key, int value)
{
	set_item( object, key, cJSON_CreateNumber(value));
}
void set_float( SAC_cJSON * object, char * key, float value)
{
	set_item( object, key, cJSON_CreateNumber(value));
}
void set_double( SAC_cJSON * object, char * key, double value)
{
	set_item( object, key, cJSON_CreateNumber(value));
}

// String
void set_string( SAC_cJSON * object, char * key, char * value)
{
	set_item( object, key, cJSON_CreateString(value));
}

// Array & Objects
void set_object( SAC_cJSON ** object, SAC_array_descriptor_t * object_descriptor, char * key,
					SAC_cJSON * inner_object, SAC_array_descriptor_t inner_object_descriptor)
{
	if( inner_object->head != inner_object->root)
	{
		SAC_RuntimeError( "Trying to insert non-root JSON object!");
	}
	set_item( (*object), key, inner_object->head);
	// cJSON_AddItemToObject( (*object)->head, copy_string( key), inner_object->head);
	SAC_FREE( inner_object_descriptor);
}

// Array manipulation
void add_to_array( SAC_cJSON * array, cJSON * item)
{
	cJSON_AddItemToArray( array->head, item);
}
//// Booleans
void add_bool_to_array( SAC_cJSON * array, bool boolean)
{
	// cJSON * value;
	// value = ;
	add_to_array( array, cJSON_CreateBool( boolean));
}
void add_true_to_array( SAC_cJSON * array)
{
	add_bool_to_array(array, true);
}
void add_false_to_array( SAC_cJSON * array)
{
	add_bool_to_array(array, false);
}
//// Numbers
void add_int_to_array( SAC_cJSON * array, int number)
{
	cJSON * value;
	value = cJSON_CreateNumber( number);
	add_to_array( array, value);
}
void add_double_to_array( SAC_cJSON * array, double number)
{
	cJSON * value;
	value = cJSON_CreateNumber( number);
	add_to_array( array, value);
}
void add_float_to_array( SAC_cJSON * array, float number)
{
	cJSON * value;
	value = cJSON_CreateNumber( (double)number);
	add_to_array( array, value);
}
//// String
void add_string_to_array( SAC_cJSON * array, char * string)
{
	cJSON * value;
	value = cJSON_CreateString( string);
	add_to_array( array, value);
}
//// Array & Objects
void add_object_to_array( SAC_cJSON ** array, SAC_array_descriptor_t * array_descriptor,
							SAC_cJSON * object, SAC_array_descriptor_t object_descriptor)
{
	if( object->head != object->root)
	{
		SAC_RuntimeError( "Trying to insert non-root JSON object!");
	}
	add_to_array( (*array), object->head);
	SAC_FREE( object_descriptor);
}

// JSON traversal
void change_focus( SAC_cJSON ** out, SAC_array_descriptor_t * out_descriptor,
					SAC_cJSON * in, SAC_array_descriptor_t in_descriptor, char * key)
{
	cJSON * result;
	char * local;

	local = copy_string( key);
	result = cJSON_GetObjectItemCaseSensitive( in->head, local);
	if ( result == NULL)
	{
		SAC_RuntimeError( "keyword \"%s\" not found", local);
	}
	*out = in;
	(*out)->head = result;
	*out_descriptor = in_descriptor;
}

void focus_root( SAC_cJSON ** out, SAC_array_descriptor_t * out_descriptor,
					SAC_cJSON * in, SAC_array_descriptor_t in_descriptor)
{
	*out = in;
	(*out)->head = (*out)->root;
	*out_descriptor = in_descriptor;
}

// Input Output
void serialize_object( SAC_cJSON * object)
{
	char * str;
	str = cJSON_Print( object->head);
	printf( "%s\n", str);
}
