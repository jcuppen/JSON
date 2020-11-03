#include <cjson/cJSON.h>
#include "sac.h"
#include "../include/sac-cjson.h"


void delete_json_object( SAC_cJSON * object)
{
	cJSON_Delete( object->root);
        SAC_FREE( object);
}

