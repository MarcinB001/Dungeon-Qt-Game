# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\dungeon_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\dungeon_autogen.dir\\ParseCache.txt"
  "dungeon_autogen"
  )
endif()
