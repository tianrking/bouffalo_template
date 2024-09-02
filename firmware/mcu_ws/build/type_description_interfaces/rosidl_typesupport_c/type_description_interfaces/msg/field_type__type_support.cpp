// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from type_description_interfaces:msg/FieldType.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "type_description_interfaces/msg/detail/field_type__struct.h"
#include "type_description_interfaces/msg/detail/field_type__type_support.h"
#include "type_description_interfaces/msg/detail/field_type__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace type_description_interfaces
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _FieldType_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FieldType_type_support_ids_t;

static const _FieldType_type_support_ids_t _FieldType_message_typesupport_ids = {
  {
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
    "rosidl_typesupport_microxrcedds_c",  // ::rosidl_typesupport_microxrcedds_c::typesupport_identifier,
  }
};

typedef struct _FieldType_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FieldType_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FieldType_type_support_symbol_names_t _FieldType_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, type_description_interfaces, msg, FieldType)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, type_description_interfaces, msg, FieldType)),
  }
};

typedef struct _FieldType_type_support_data_t
{
  void * data[2];
} _FieldType_type_support_data_t;

#ifdef ROSIDL_TYPESUPPORT_STATIC_TYPESUPPORT
#ifdef __cplusplus
extern "C"
{
#endif
rosidl_message_type_support_t * ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, type_description_interfaces, msg, FieldType)();
rosidl_message_type_support_t * ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, type_description_interfaces, msg, FieldType)();
#ifdef __cplusplus
}
#endif

static _FieldType_type_support_data_t _FieldType_message_typesupport_data = {
  {
    (void*) ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, type_description_interfaces, msg, FieldType),
    (void*) ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, type_description_interfaces, msg, FieldType),
  }
};
#else
static _FieldType_type_support_data_t _FieldType_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};
#endif // ROSIDL_TYPESUPPORT_STATIC_TYPESUPPORT

static const type_support_map_t _FieldType_message_typesupport_map = {
  2,
  "type_description_interfaces",
  &_FieldType_message_typesupport_ids.typesupport_identifier[0],
  &_FieldType_message_typesupport_symbol_names.symbol_name[0],
  &_FieldType_message_typesupport_data.data[0],
};

static rosidl_message_type_support_t FieldType_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FieldType_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &type_description_interfaces__msg__FieldType__get_type_hash,
  &type_description_interfaces__msg__FieldType__get_type_description,
  &type_description_interfaces__msg__FieldType__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace type_description_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, type_description_interfaces, msg, FieldType)() {
  if (!::type_description_interfaces::msg::rosidl_typesupport_c::FieldType_message_type_support_handle.typesupport_identifier) {
    ::type_description_interfaces::msg::rosidl_typesupport_c::FieldType_message_type_support_handle.typesupport_identifier =
    rosidl_typesupport_c__typesupport_identifier;
  }

  return &::type_description_interfaces::msg::rosidl_typesupport_c::FieldType_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
