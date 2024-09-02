# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/ament/ament_cmake/ament_cmake_vendor_package/test/exlib_bad")
  file(MAKE_DIRECTORY "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/ament/ament_cmake/ament_cmake_vendor_package/test/exlib_bad")
endif()
file(MAKE_DIRECTORY
  "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_vendor_package/test/exlib_bad-prefix/src/exlib_bad-build"
  "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_vendor_package/test/exlib_bad-prefix/install"
  "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_vendor_package/test/exlib_bad-prefix/tmp"
  "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_vendor_package/test/exlib_bad-prefix/src/exlib_bad-stamp"
  "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_vendor_package/test/exlib_bad-prefix/src"
  "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_vendor_package/test/exlib_bad-prefix/src/exlib_bad-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_vendor_package/test/exlib_bad-prefix/src/exlib_bad-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/build/ament_cmake_vendor_package/test/exlib_bad-prefix/src/exlib_bad-stamp${cfgdir}") # cfgdir has leading slash
endif()
