# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Transformations_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Transformations_autogen.dir\\ParseCache.txt"
  "Transformations_autogen"
  )
endif()
