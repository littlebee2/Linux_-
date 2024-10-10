include_directories(${PROJECT_SOURCE_DIR}/libcan)
include_directories(${PROJECT_SOURCE_DIR}/libled)
include_directories(${PROJECT_SOURCE_DIR}/analyis)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 11)  #C++ 11以上支持线程
add_executable(Linux_Gateway_master main.c)
target_link_libraries(Linux_Gateway_master libcan libled pthread libcan_anayse)