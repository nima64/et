# CMakeList.txt : CMake project for cmakeprojterst, include source and define
# project specific logic here.
#
include_directories("./header_files")

cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
link_directories("./winlibs")
add_executable (cmakeprojterst "cmakeprojterst.cpp" "header_files/cmakeprojterst.h"     "header_files/Game.h"  "header_files/util.h"  "header_files/test_util.h" "util.cpp"  )
target_link_libraries(cmakeprojterst SDL2 SDL2main)




# TODO: Add tests and install targets if needed.
