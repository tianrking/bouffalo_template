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
CMAKE_SOURCE_DIR = /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/microcdr

# Include any dependencies generated for this target.
include CMakeFiles/microcdr.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/microcdr.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/microcdr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/microcdr.dir/flags.make

CMakeFiles/microcdr.dir/src/c/common.c.obj: CMakeFiles/microcdr.dir/flags.make
CMakeFiles/microcdr.dir/src/c/common.c.obj: /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/common.c
CMakeFiles/microcdr.dir/src/c/common.c.obj: CMakeFiles/microcdr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/microcdr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/microcdr.dir/src/c/common.c.obj"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/microcdr.dir/src/c/common.c.obj -MF CMakeFiles/microcdr.dir/src/c/common.c.obj.d -o CMakeFiles/microcdr.dir/src/c/common.c.obj -c /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/common.c

CMakeFiles/microcdr.dir/src/c/common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/microcdr.dir/src/c/common.c.i"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/common.c > CMakeFiles/microcdr.dir/src/c/common.c.i

CMakeFiles/microcdr.dir/src/c/common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/microcdr.dir/src/c/common.c.s"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/common.c -o CMakeFiles/microcdr.dir/src/c/common.c.s

CMakeFiles/microcdr.dir/src/c/types/basic.c.obj: CMakeFiles/microcdr.dir/flags.make
CMakeFiles/microcdr.dir/src/c/types/basic.c.obj: /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/types/basic.c
CMakeFiles/microcdr.dir/src/c/types/basic.c.obj: CMakeFiles/microcdr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/microcdr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/microcdr.dir/src/c/types/basic.c.obj"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/microcdr.dir/src/c/types/basic.c.obj -MF CMakeFiles/microcdr.dir/src/c/types/basic.c.obj.d -o CMakeFiles/microcdr.dir/src/c/types/basic.c.obj -c /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/types/basic.c

CMakeFiles/microcdr.dir/src/c/types/basic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/microcdr.dir/src/c/types/basic.c.i"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/types/basic.c > CMakeFiles/microcdr.dir/src/c/types/basic.c.i

CMakeFiles/microcdr.dir/src/c/types/basic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/microcdr.dir/src/c/types/basic.c.s"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/types/basic.c -o CMakeFiles/microcdr.dir/src/c/types/basic.c.s

CMakeFiles/microcdr.dir/src/c/types/string.c.obj: CMakeFiles/microcdr.dir/flags.make
CMakeFiles/microcdr.dir/src/c/types/string.c.obj: /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/types/string.c
CMakeFiles/microcdr.dir/src/c/types/string.c.obj: CMakeFiles/microcdr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/microcdr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/microcdr.dir/src/c/types/string.c.obj"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/microcdr.dir/src/c/types/string.c.obj -MF CMakeFiles/microcdr.dir/src/c/types/string.c.obj.d -o CMakeFiles/microcdr.dir/src/c/types/string.c.obj -c /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/types/string.c

CMakeFiles/microcdr.dir/src/c/types/string.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/microcdr.dir/src/c/types/string.c.i"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/types/string.c > CMakeFiles/microcdr.dir/src/c/types/string.c.i

CMakeFiles/microcdr.dir/src/c/types/string.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/microcdr.dir/src/c/types/string.c.s"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/types/string.c -o CMakeFiles/microcdr.dir/src/c/types/string.c.s

CMakeFiles/microcdr.dir/src/c/types/array.c.obj: CMakeFiles/microcdr.dir/flags.make
CMakeFiles/microcdr.dir/src/c/types/array.c.obj: /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/types/array.c
CMakeFiles/microcdr.dir/src/c/types/array.c.obj: CMakeFiles/microcdr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/microcdr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/microcdr.dir/src/c/types/array.c.obj"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/microcdr.dir/src/c/types/array.c.obj -MF CMakeFiles/microcdr.dir/src/c/types/array.c.obj.d -o CMakeFiles/microcdr.dir/src/c/types/array.c.obj -c /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/types/array.c

CMakeFiles/microcdr.dir/src/c/types/array.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/microcdr.dir/src/c/types/array.c.i"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/types/array.c > CMakeFiles/microcdr.dir/src/c/types/array.c.i

CMakeFiles/microcdr.dir/src/c/types/array.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/microcdr.dir/src/c/types/array.c.s"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/types/array.c -o CMakeFiles/microcdr.dir/src/c/types/array.c.s

CMakeFiles/microcdr.dir/src/c/types/sequence.c.obj: CMakeFiles/microcdr.dir/flags.make
CMakeFiles/microcdr.dir/src/c/types/sequence.c.obj: /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/types/sequence.c
CMakeFiles/microcdr.dir/src/c/types/sequence.c.obj: CMakeFiles/microcdr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/microcdr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/microcdr.dir/src/c/types/sequence.c.obj"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/microcdr.dir/src/c/types/sequence.c.obj -MF CMakeFiles/microcdr.dir/src/c/types/sequence.c.obj.d -o CMakeFiles/microcdr.dir/src/c/types/sequence.c.obj -c /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/types/sequence.c

CMakeFiles/microcdr.dir/src/c/types/sequence.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/microcdr.dir/src/c/types/sequence.c.i"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/types/sequence.c > CMakeFiles/microcdr.dir/src/c/types/sequence.c.i

CMakeFiles/microcdr.dir/src/c/types/sequence.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/microcdr.dir/src/c/types/sequence.c.s"
	/home/w0x7ce/toolchain_gcc_t-head_linux/bin/riscv64-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR/src/c/types/sequence.c -o CMakeFiles/microcdr.dir/src/c/types/sequence.c.s

# Object files for target microcdr
microcdr_OBJECTS = \
"CMakeFiles/microcdr.dir/src/c/common.c.obj" \
"CMakeFiles/microcdr.dir/src/c/types/basic.c.obj" \
"CMakeFiles/microcdr.dir/src/c/types/string.c.obj" \
"CMakeFiles/microcdr.dir/src/c/types/array.c.obj" \
"CMakeFiles/microcdr.dir/src/c/types/sequence.c.obj"

# External object files for target microcdr
microcdr_EXTERNAL_OBJECTS =

libmicrocdr.a: CMakeFiles/microcdr.dir/src/c/common.c.obj
libmicrocdr.a: CMakeFiles/microcdr.dir/src/c/types/basic.c.obj
libmicrocdr.a: CMakeFiles/microcdr.dir/src/c/types/string.c.obj
libmicrocdr.a: CMakeFiles/microcdr.dir/src/c/types/array.c.obj
libmicrocdr.a: CMakeFiles/microcdr.dir/src/c/types/sequence.c.obj
libmicrocdr.a: CMakeFiles/microcdr.dir/build.make
libmicrocdr.a: CMakeFiles/microcdr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/microcdr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C static library libmicrocdr.a"
	$(CMAKE_COMMAND) -P CMakeFiles/microcdr.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/microcdr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/microcdr.dir/build: libmicrocdr.a
.PHONY : CMakeFiles/microcdr.dir/build

CMakeFiles/microcdr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/microcdr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/microcdr.dir/clean

CMakeFiles/microcdr.dir/depend:
	cd /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/microcdr && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/eProsima/Micro-CDR /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/microcdr /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/microcdr /home/w0x7ce/Desktop/microros_ws/firmware/mcu_ws/build/microcdr/CMakeFiles/microcdr.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/microcdr.dir/depend

