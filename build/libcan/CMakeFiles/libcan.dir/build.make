# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/danneil/items/app/linux网关

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/danneil/items/app/linux网关/build

# Include any dependencies generated for this target.
include libcan/CMakeFiles/libcan.dir/depend.make

# Include the progress variables for this target.
include libcan/CMakeFiles/libcan.dir/progress.make

# Include the compile flags for this target's objects.
include libcan/CMakeFiles/libcan.dir/flags.make

libcan/CMakeFiles/libcan.dir/can.c.o: libcan/CMakeFiles/libcan.dir/flags.make
libcan/CMakeFiles/libcan.dir/can.c.o: ../libcan/can.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danneil/items/app/linux网关/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libcan/CMakeFiles/libcan.dir/can.c.o"
	cd /home/danneil/items/app/linux网关/build/libcan && /usr/local/arm/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/libcan.dir/can.c.o   -c /home/danneil/items/app/linux网关/libcan/can.c

libcan/CMakeFiles/libcan.dir/can.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libcan.dir/can.c.i"
	cd /home/danneil/items/app/linux网关/build/libcan && /usr/local/arm/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/danneil/items/app/linux网关/libcan/can.c > CMakeFiles/libcan.dir/can.c.i

libcan/CMakeFiles/libcan.dir/can.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libcan.dir/can.c.s"
	cd /home/danneil/items/app/linux网关/build/libcan && /usr/local/arm/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/danneil/items/app/linux网关/libcan/can.c -o CMakeFiles/libcan.dir/can.c.s

libcan/CMakeFiles/libcan.dir/can.c.o.requires:

.PHONY : libcan/CMakeFiles/libcan.dir/can.c.o.requires

libcan/CMakeFiles/libcan.dir/can.c.o.provides: libcan/CMakeFiles/libcan.dir/can.c.o.requires
	$(MAKE) -f libcan/CMakeFiles/libcan.dir/build.make libcan/CMakeFiles/libcan.dir/can.c.o.provides.build
.PHONY : libcan/CMakeFiles/libcan.dir/can.c.o.provides

libcan/CMakeFiles/libcan.dir/can.c.o.provides.build: libcan/CMakeFiles/libcan.dir/can.c.o


# Object files for target libcan
libcan_OBJECTS = \
"CMakeFiles/libcan.dir/can.c.o"

# External object files for target libcan
libcan_EXTERNAL_OBJECTS =

libcan/libcan.a: libcan/CMakeFiles/libcan.dir/can.c.o
libcan/libcan.a: libcan/CMakeFiles/libcan.dir/build.make
libcan/libcan.a: libcan/CMakeFiles/libcan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danneil/items/app/linux网关/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libcan.a"
	cd /home/danneil/items/app/linux网关/build/libcan && $(CMAKE_COMMAND) -P CMakeFiles/libcan.dir/cmake_clean_target.cmake
	cd /home/danneil/items/app/linux网关/build/libcan && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libcan.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libcan/CMakeFiles/libcan.dir/build: libcan/libcan.a

.PHONY : libcan/CMakeFiles/libcan.dir/build

libcan/CMakeFiles/libcan.dir/requires: libcan/CMakeFiles/libcan.dir/can.c.o.requires

.PHONY : libcan/CMakeFiles/libcan.dir/requires

libcan/CMakeFiles/libcan.dir/clean:
	cd /home/danneil/items/app/linux网关/build/libcan && $(CMAKE_COMMAND) -P CMakeFiles/libcan.dir/cmake_clean.cmake
.PHONY : libcan/CMakeFiles/libcan.dir/clean

libcan/CMakeFiles/libcan.dir/depend:
	cd /home/danneil/items/app/linux网关/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danneil/items/app/linux网关 /home/danneil/items/app/linux网关/libcan /home/danneil/items/app/linux网关/build /home/danneil/items/app/linux网关/build/libcan /home/danneil/items/app/linux网关/build/libcan/CMakeFiles/libcan.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libcan/CMakeFiles/libcan.dir/depend

