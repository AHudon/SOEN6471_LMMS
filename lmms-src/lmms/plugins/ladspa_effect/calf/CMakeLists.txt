FILE(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
ADD_LIBRARY(calf MODULE ${SOURCES})
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src)
INSTALL(TARGETS calf LIBRARY DESTINATION ${PLUGIN_DIR}/ladspa)
SET_TARGET_PROPERTIES(calf PROPERTIES PREFIX "")
SET(INLINE_FLAGS "")
IF(NOT LMMS_BUILD_APPLE)
SET(INLINE_FLAGS "-finline-functions-called-once")
ENDIF(NOT LMMS_BUILD_APPLE)
SET_TARGET_PROPERTIES(calf PROPERTIES COMPILE_FLAGS "-O2 -finline-limit=80 -finline-functions ${INLINE_FLAGS}")

IF(LMMS_BUILD_WIN32)
	ADD_CUSTOM_COMMAND(TARGET calf POST_BUILD COMMAND ${STRIP} ${CMAKE_CURRENT_BINARY_DIR}/calf.dll)
ENDIF(LMMS_BUILD_WIN32)
IF(NOT LMMS_BUILD_APPLE)
	SET_TARGET_PROPERTIES(calf PROPERTIES LINK_FLAGS "${LINK_FLAGS} -shared -Wl,-no-undefined")
ENDIF(NOT LMMS_BUILD_APPLE)

