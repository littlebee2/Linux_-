cmake_minimum_required(VERSION 3.5)
project(Linux_Gateway-master)
#支持GBD
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

add_subdirectory(libcan)
add_subdirectory(libled)
add_subdirectory(analyis)
add_subdirectory(src)
add_subdirectory(libcrc)