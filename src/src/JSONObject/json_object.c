#include <cjson/cJSON.h>

void delete_json_object( cJSON * object)
{
	cJSON_Delete( object);
}

void delete_json_inner_object( cJSON * object)
{
	// do nothing, cJSON will take care of this when deleting its parent object
}
