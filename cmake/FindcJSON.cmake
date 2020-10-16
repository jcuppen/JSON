# CMake module to search for the cJSON library
# (library for printing JSON files)
#
# If it's found it sets CJSON_FOUND to TRUE
# and following variables are set:
#    CJSON_INCLUDE_DIR
#    CJSON_LIBRARIES

FIND_PATH(CJSON_INCLUDE_DIR NAMES cjson/cJSON.h)
FIND_LIBRARY(CJSON_LIBRARIES NAMES cjson)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(
	cJSON 
	DEFAULT_MSG CJSON_LIBRARIES 
	CJSON_INCLUDE_DIR
)
MARK_AS_ADVANCED(CJSON_INCLUDE_DIR CJSON_LIBRARIES)
