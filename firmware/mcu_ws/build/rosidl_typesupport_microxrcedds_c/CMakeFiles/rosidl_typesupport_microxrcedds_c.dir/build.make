# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/uros/rosidl_typesupport_microxrcedds/rosidl_typesupport_microxrcedds_c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/rosidl_typesupport_microxrcedds_c

# Include any dependencies generated for this target.
include CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/flags.make

CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/src/identifier.c.obj: CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/flags.make
CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/src/identifier.c.obj: /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/uros/rosidl_typesupport_microxrcedds/rosidl_typesupport_microxrcedds_c/src/identifier.c
CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/src/identifier.c.obj: CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/rosidl_typesupport_microxrcedds_c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/src/identifier.c.obj"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/src/identifier.c.obj -MF CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/src/identifier.c.obj.d -o CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/src/identifier.c.obj -c /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/uros/rosidl_typesupport_microxrcedds/rosidl_typesupport_microxrcedds_c/src/identifier.c

CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/src/identifier.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/src/identifier.c.i"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/uros/rosidl_typesupport_microxrcedds/rosidl_typesupport_microxrcedds_c/src/identifier.c > CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/src/identifier.c.i

CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/src/identifier.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/src/identifier.c.s"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/uros/rosidl_typesupport_microxrcedds/rosidl_typesupport_microxrcedds_c/src/identifier.c -o CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/src/identifier.c.s

# Object files for target rosidl_typesupport_microxrcedds_c
rosidl_typesupport_microxrcedds_c_OBJECTS = \
"CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/src/identifier.c.obj"

# External object files for target rosidl_typesupport_microxrcedds_c
rosidl_typesupport_microxrcedds_c_EXTERNAL_OBJECTS =

librosidl_typesupport_microxrcedds_c.a: CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/src/identifier.c.obj
librosidl_typesupport_microxrcedds_c.a: CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/build.make
librosidl_typesupport_microxrcedds_c.a: CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/rosidl_typesupport_microxrcedds_c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library librosidl_typesupport_microxrcedds_c.a"
	$(CMAKE_COMMAND) -P CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/build: librosidl_typesupport_microxrcedds_c.a
.PHONY : CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/build

CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/clean

CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/depend:
	cd /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/rosidl_typesupport_microxrcedds_c && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/uros/rosidl_typesupport_microxrcedds/rosidl_typesupport_microxrcedds_c /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/uros/rosidl_typesupport_microxrcedds/rosidl_typesupport_microxrcedds_c /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/rosidl_typesupport_microxrcedds_c /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/rosidl_typesupport_microxrcedds_c /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/rosidl_typesupport_microxrcedds_c/CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/rosidl_typesupport_microxrcedds_c.dir/depend

