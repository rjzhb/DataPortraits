file(GLOB_RECURSE DataPortraits_headers ${PROJECT_SOURCE_DIR}/src/*/*.h)
file(GLOB_RECURSE DataPortraits_sources ${PROJECT_SOURCE_DIR}/src/*/*.cpp)
add_library(DataPortraits_lib STATIC ${DataPortraits_headers} ${DataPortraits_sources})

