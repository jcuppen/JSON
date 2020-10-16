#include <cjson/cJSON.h>

void delete_json_object( cJSON * object)
{
	cJSON_Delete( object);
}
