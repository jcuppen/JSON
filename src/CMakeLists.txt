CMAKE_MINIMUM_REQUIRED (VERSION 3.3)
INCLUDE ("${CMAKE_SOURCE_DIR}/cmake-common/sac2c-variables.cmake")
INCLUDE ("${CMAKE_SOURCE_DIR}/cmake-common/resolve-sac2c-dependencies.cmake")

# C files relatively to this CMakeLists.txt.
SET (C_DEPS_SRC
	src/JSONBuilder/json_builder.c
	src/JSONObject/delete_json_object.c
)

# SaC files relatively to this CMakeLists.txt.
SET (
	JSONBuilder.sac
	JSONObject.sac
	JSON.sac
)

# For every C source, compile an object file maintaining the right location
# in the binary dir so that sac files can pick it up.

foreach(name ${C_DEPS_SRC})
	SET (src "${CMAKE_CURRENT_SOURCE_DIR}/${name}")
	GET_FILENAME_COMPONENT (dir ${name} DIRECTORY)
	GET_FILENAME_COMPONENT (dst ${name} NAME_WE)
	SET (dst "${CMAKE_CURRENT_BINARY_DIR}/${dir}/${dst}${OBJEXT}")

  	# Make sure that we put the object file in the same location where
  	# the source file was.
  	FILE (MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${dir}")

  	ADD_CUSTOM_COMMAND (
    	OUTPUT "${dst}"
    	MAIN_DEPENDENCY "${src}"
    	IMPLICIT_DEPENDS C "${src}"
    	COMMAND ${SAC2C} -v0 -noprelude -cc ccmod -o "${dst}" "${src}"
    	COMMENT "Generating ${dst}"
  	)

# Make a directory for sac2c output
FILE (MAKE_DIRECTORY "${DLL_BUILD_DIR}/${TARGET_ENV}/${SBI}")

# For every sac file, compile Tree and Mod files.
foreach (name ${SAC_SRC})
    SET (src "${CMAKE_CURRENT_SOURCE_DIR}/${name}")
    # sac2c requires computed objectfiles relatively to the working directory
    # of the call to sac2c.
    GET_FILENAME_COMPONENT (dir "${CMAKE_CURRENT_BINARY_DIR}/${name}" DIRECTORY)
    GET_FILENAME_COMPONENT (dst ${name} NAME_WE)
    SET (mod "${DLL_BUILD_DIR}/${TARGET_ENV}/${SBI}/lib${dst}Mod${MODEXT}")
    SET (tree "${DLL_BUILD_DIR}/tree/${TARGET_ENV}/lib${dst}Tree${TREE_DLLEXT}")

    RESOLVE-SAC2C-DEPENDENCIES ("${name}" "${SAC_SRC}" moddep_list)

    MESSAGE ("dependencies of ${name} => `${moddep_list}'")
endforeach(name)
