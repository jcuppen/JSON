#include <yaml.h>

#include "sac.h"

cJSON * create_object( /*FILE* stream*/)
{
	return cJSON_CreateObject()
}

char * serialize_object( cJSON* object)
{
	return cJSON_Print(monitor);
}
