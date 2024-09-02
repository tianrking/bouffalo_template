# Install script for directory: /home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/ament/ament_lint/ament_cmake_clang_tidy

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/install/ament_cmake_clang_tidy")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_clang_tidy/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/ament_cmake_clang_tidy")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_clang_tidy/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/ament_cmake_clang_tidy")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_clang_tidy/environment" TYPE FILE FILES "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_clang_tidy/environment" TYPE FILE FILES "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_clang_tidy/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_clang_tidy/environment" TYPE FILE FILES "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_clang_tidy/environment" TYPE FILE FILES "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_clang_tidy/ament_cmake_environment_hooks/path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_clang_tidy" TYPE FILE FILES "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_clang_tidy/ament_cmake_environment_hooks/local_setup.bash")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_clang_tidy" TYPE FILE FILES "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_clang_tidy/ament_cmake_environment_hooks/local_setup.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_clang_tidy" TYPE FILE FILES "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_clang_tidy/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_clang_tidy" TYPE FILE FILES "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_clang_tidy/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_clang_tidy" TYPE FILE FILES "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_clang_tidy/ament_cmake_environment_hooks/package.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_clang_tidy/ament_cmake_index/share/ament_index/resource_index/packages/ament_cmake_clang_tidy")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_clang_tidy/cmake" TYPE FILE FILES "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/ament/ament_lint/ament_cmake_clang_tidy/ament_cmake_clang_tidy-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_clang_tidy/cmake" TYPE FILE FILES
    "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_clang_tidy/ament_cmake_core/ament_cmake_clang_tidyConfig.cmake"
    "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_clang_tidy/ament_cmake_core/ament_cmake_clang_tidyConfig-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_clang_tidy" TYPE FILE FILES "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/ament/ament_lint/ament_cmake_clang_tidy/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_clang_tidy" TYPE DIRECTORY FILES "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/ament/ament_lint/ament_cmake_clang_tidy/cmake")
endif()

if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
  file(WRITE "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_clang_tidy/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
