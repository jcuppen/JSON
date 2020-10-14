CMAKE_MINIMUM_REQUIRED (VERSION 3.3)

PROJECT (sac-jsonmodule)

# Where the compiled sac modules result
SET (DLL_BUILD_DIR "${PROJECT_BINARY_DIR}/lib")

# For what targets we build modules
SET (TARGETS      seq mt_pth  CACHE STRING "Build stdlib-cuda for these targets")
SET (SAC2C_EXEC               CACHE STRING "A path to sac2c compiler")
SET (LINKSETSIZE  "0"         CACHE STRING "Set a value for -linksetsize parameter of sac2c")

# Check whether sac2c is operational
INCLUDE ("cmake-common/check-sac2c.cmake")
INCLUDE ("cmake-common/misc-macros.cmake")

# add our custom Find*.cmake
LIST (APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Ensure cJSON is available
FIND_PACKAGE (cJSON REQUIRED)

MESSAGE (${CJSON_LIBRARIES})

# For every target run CMakeLists.txt in src
FOREACH (TARGET IN ITEMS ${TARGETS})
  ADD_SUBDIRECTORY (src src-${TARGET})
ENDFOREACH ()

# This build target is responsible for generating the package sac2crc file
CREATE_SAC2CRC_TARGET ("jsonmodule" "${DLL_BUILD_DIR}" "${DLL_BUILD_DIR}" "-ljson")