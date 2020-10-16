#include <cjson/cJSON.h>
#include <stdio.h>

cJSON * create_object( /*FILE* stream*/)
{
	return cJSON_CreateObject();
}

void serialize_object( cJSON* object)
{
	char * str;
	str = cJSON_Print(object);
	printf("%s\n", str);
}
