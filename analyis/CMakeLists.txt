include_directories(${PROJECT_SOURCE_DIR}/libcan)
include_directories(${PROJECT_SOURCE_DIR}/libcrc)
add_library(libcan_anayse can_anayse.c)
set_target_properties(libcan_anayse PROPERTIES OUTPUT_NAME "libcan_anayse")