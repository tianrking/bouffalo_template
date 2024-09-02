set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CROSSCOMPILING 1)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# 设置编译器路径
set(CMAKE_C_COMPILER riscv64-unknown-elf-gcc)
set(CMAKE_CXX_COMPILER riscv64-unknown-elf-g++)

set(CMAKE_C_COMPILER_WORKS 1 CACHE INTERNAL "")
set(CMAKE_CXX_COMPILER_WORKS 1 CACHE INTERNAL "")

# 设置 BL616 特定的编译标志
set(FLAGS "-march=rv32imac -mabi=ilp32 -mcmodel=medlow -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -fno-zero-initialized-in-bss -Os -ggdb -Wall -mno-save-restore -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common" CACHE STRING "" FORCE)

# 设置 C 标志
set(CMAKE_C_FLAGS_INIT "-std=gnu99 ${FLAGS}" CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_INIT}" CACHE STRING "" FORCE)

# 设置 C++ 标志
set(CMAKE_CXX_FLAGS_INIT "-std=gnu++11 ${FLAGS} -fno-rtti -fno-exceptions" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_INIT}" CACHE STRING "" FORCE)

# 设置链接标志
set(CMAKE_EXE_LINKER_FLAGS_INIT "-nostartfiles -Wl,--gc-sections -Wl,--check-sections -Wl,--unresolved-symbols=report-all -Wl,--warn-common" CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS_INIT}" CACHE STRING "" FORCE)

# 设置目标处理器
set(CMAKE_SYSTEM_PROCESSOR riscv)

# 设置小端序
set(__BIG_ENDIAN__ 0)

# 设置查找路径
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# 添加额外的定义
add_definitions(-DARCH_RISCV -DBFLB_CRYPT_HARDWARE -DBFLB_PKA_HARDWARE)
add_definitions(-D_POSIX_TIMERS)
add_definitions(-DUCLIENT_PLATFORM_RISCV)
add_definitions(-DCLOCK_MONOTONIC=0)
add_definitions(-DRCUTILS_NO_64_ATOMIC)
add_definitions(-DRCUTILS_CUSTOM_TIME_IMPL)
add_definitions(-DUCLIENT_PROFILE_UDP=OFF)
add_definitions(-DUCLIENT_PROFILE_TCP=OFF)
#add_definitions(-DUCLIENT_PROFILE_SERIAL=ON)
