set(_AMENT_PACKAGE_NAME "rosidl_typesupport_c")
set(rosidl_typesupport_c_VERSION "3.2.2")
set(rosidl_typesupport_c_MAINTAINER "Dharini Dutia <dharini@openrobotics.org>, Shane Loretz <sloretz@openrobotics.org>")
set(rosidl_typesupport_c_BUILD_DEPENDS "rosidl_runtime_c" "rosidl_typesupport_introspection_c" "rcpputils" "rcutils")
set(rosidl_typesupport_c_BUILDTOOL_DEPENDS "ament_cmake_ros")
set(rosidl_typesupport_c_BUILD_EXPORT_DEPENDS "rosidl_runtime_c" "rcpputils" "rcutils")
set(rosidl_typesupport_c_BUILDTOOL_EXPORT_DEPENDS "python3" "ament_cmake_core")
set(rosidl_typesupport_c_EXEC_DEPENDS "ament_index_python" "rosidl_cli" "rosidl_generator_c" "rosidl_pycommon" "rosidl_typesupport_interface" "rcpputils" "rcutils")
set(rosidl_typesupport_c_TEST_DEPENDS "ament_lint_auto" "ament_lint_common" "mimick_vendor" "performance_test_fixture")
set(rosidl_typesupport_c_GROUP_DEPENDS "rosidl_typesupport_c_packages")
set(rosidl_typesupport_c_MEMBER_OF_GROUPS "rosidl_runtime_packages")
set(rosidl_typesupport_c_DEPRECATED "")
set(rosidl_typesupport_c_EXPORT_TAGS)
list(APPEND rosidl_typesupport_c_EXPORT_TAGS "<build_type>ament_cmake</build_type>")
