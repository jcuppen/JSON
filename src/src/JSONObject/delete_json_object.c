#include <cjson/cJSON.h>

// #include "sac.h"

void delete_json_object( cJSON * object)
{
  cJSON_Delete( object);
}