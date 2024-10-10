#设置目标系统
set(CMAKE_SYSTEM_NAME   Linux)
#设置目标平台
set(CMAKE_SYSTEM_PROCESSOR  arm)
#指定交叉编译工具链的根路径
set(CROSS_CHAIN_PATH  /usr/local/arm/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf)
#指定C编译器
set(CMAKE_C_COMPILER    ${CROSS_CHAIN_PATH}/bin/arm-linux-gnueabihf-gcc)
#指定C++编译器
set(CMAKE_CXX_COMPILER  ${CROSS_CHAIN_PATH}/bin/arm-linux-gnueabihf-g++) 
