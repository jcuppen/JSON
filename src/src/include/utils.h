#include <string.h>
#include "sac.h"

char * copyString(char * source)
{
	char * destination;
	destination = SAC_MALLOC( strlen( source) + 1);
	destination = strcpy( destination, source);
	return destination;
}
