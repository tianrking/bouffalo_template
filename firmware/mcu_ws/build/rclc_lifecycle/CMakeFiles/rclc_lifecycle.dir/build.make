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
CMAKE_SOURCE_DIR = /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/uros/rclc/rclc_lifecycle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/rclc_lifecycle

# Include any dependencies generated for this target.
include CMakeFiles/rclc_lifecycle.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rclc_lifecycle.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rclc_lifecycle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rclc_lifecycle.dir/flags.make

CMakeFiles/rclc_lifecycle.dir/src/rclc_lifecycle/rclc_lifecycle.c.obj: CMakeFiles/rclc_lifecycle.dir/flags.make
CMakeFiles/rclc_lifecycle.dir/src/rclc_lifecycle/rclc_lifecycle.c.obj: /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/uros/rclc/rclc_lifecycle/src/rclc_lifecycle/rclc_lifecycle.c
CMakeFiles/rclc_lifecycle.dir/src/rclc_lifecycle/rclc_lifecycle.c.obj: CMakeFiles/rclc_lifecycle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/rclc_lifecycle/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rclc_lifecycle.dir/src/rclc_lifecycle/rclc_lifecycle.c.obj"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/rclc_lifecycle.dir/src/rclc_lifecycle/rclc_lifecycle.c.obj -MF CMakeFiles/rclc_lifecycle.dir/src/rclc_lifecycle/rclc_lifecycle.c.obj.d -o CMakeFiles/rclc_lifecycle.dir/src/rclc_lifecycle/rclc_lifecycle.c.obj -c /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/uros/rclc/rclc_lifecycle/src/rclc_lifecycle/rclc_lifecycle.c

CMakeFiles/rclc_lifecycle.dir/src/rclc_lifecycle/rclc_lifecycle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/rclc_lifecycle.dir/src/rclc_lifecycle/rclc_lifecycle.c.i"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/uros/rclc/rclc_lifecycle/src/rclc_lifecycle/rclc_lifecycle.c > CMakeFiles/rclc_lifecycle.dir/src/rclc_lifecycle/rclc_lifecycle.c.i

CMakeFiles/rclc_lifecycle.dir/src/rclc_lifecycle/rclc_lifecycle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/rclc_lifecycle.dir/src/rclc_lifecycle/rclc_lifecycle.c.s"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/uros/rclc/rclc_lifecycle/src/rclc_lifecycle/rclc_lifecycle.c -o CMakeFiles/rclc_lifecycle.dir/src/rclc_lifecycle/rclc_lifecycle.c.s

# Object files for target rclc_lifecycle
rclc_lifecycle_OBJECTS = \
"CMakeFiles/rclc_lifecycle.dir/src/rclc_lifecycle/rclc_lifecycle.c.obj"

# External object files for target rclc_lifecycle
rclc_lifecycle_EXTERNAL_OBJECTS =

librclc_lifecycle.a: CMakeFiles/rclc_lifecycle.dir/src/rclc_lifecycle/rclc_lifecycle.c.obj
librclc_lifecycle.a: CMakeFiles/rclc_lifecycle.dir/build.make
librclc_lifecycle.a: CMakeFiles/rclc_lifecycle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/rclc_lifecycle/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library librclc_lifecycle.a"
	$(CMAKE_COMMAND) -P CMakeFiles/rclc_lifecycle.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rclc_lifecycle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rclc_lifecycle.dir/build: librclc_lifecycle.a
.PHONY : CMakeFiles/rclc_lifecycle.dir/build

CMakeFiles/rclc_lifecycle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rclc_lifecycle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rclc_lifecycle.dir/clean

CMakeFiles/rclc_lifecycle.dir/depend:
	cd /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/rclc_lifecycle && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/uros/rclc/rclc_lifecycle /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/uros/rclc/rclc_lifecycle /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/rclc_lifecycle /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/rclc_lifecycle /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/rclc_lifecycle/CMakeFiles/rclc_lifecycle.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/rclc_lifecycle.dir/depend

