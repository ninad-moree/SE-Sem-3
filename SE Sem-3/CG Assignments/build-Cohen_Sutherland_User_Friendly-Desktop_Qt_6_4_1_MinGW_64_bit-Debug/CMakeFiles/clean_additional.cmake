# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Cohen_Sutherland_User_Friendly_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Cohen_Sutherland_User_Friendly_autogen.dir\\ParseCache.txt"
  "Cohen_Sutherland_User_Friendly_autogen"
  )
endif()
