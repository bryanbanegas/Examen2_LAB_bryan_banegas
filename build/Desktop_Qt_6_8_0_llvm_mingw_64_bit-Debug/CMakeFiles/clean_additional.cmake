# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Examen2_LAB_bryan_banegas_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Examen2_LAB_bryan_banegas_autogen.dir\\ParseCache.txt"
  "Examen2_LAB_bryan_banegas_autogen"
  )
endif()
