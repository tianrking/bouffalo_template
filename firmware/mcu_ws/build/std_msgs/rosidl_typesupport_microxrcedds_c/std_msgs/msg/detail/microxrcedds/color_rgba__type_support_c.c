// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from std_msgs:msg/ColorRGBA.idl
// generated code does not contain a copyright notice
#include "std_msgs/msg/detail/color_rgba__rosidl_typesupport_microxrcedds_c.h"
#include "std_msgs/msg/detail/color_rgba__functions.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "std_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "std_msgs/msg/detail/color_rgba__struct.h"
#include "std_msgs/msg/detail/color_rgba__functions.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


typedef std_msgs__msg__ColorRGBA _ColorRGBA__ros_msg_type;

static bool _ColorRGBA__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _ColorRGBA__ros_msg_type * ros_message = (_ColorRGBA__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: r
  rv = ucdr_serialize_float(cdr, ros_message->r);
  // Member: g
  rv = ucdr_serialize_float(cdr, ros_message->g);
  // Member: b
  rv = ucdr_serialize_float(cdr, ros_message->b);
  // Member: a
  rv = ucdr_serialize_float(cdr, ros_message->a);

  return rv;
}

static bool _ColorRGBA__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _ColorRGBA__ros_msg_type * ros_message = (_ColorRGBA__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: r
  rv = ucdr_deserialize_float(cdr, &ros_message->r);
  // Field name: g
  rv = ucdr_deserialize_float(cdr, &ros_message->g);
  // Field name: b
  rv = ucdr_deserialize_float(cdr, &ros_message->b);
  // Field name: a
  rv = ucdr_deserialize_float(cdr, &ros_message->a);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_std_msgs
size_t get_serialized_size_std_msgs__msg__ColorRGBA(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _ColorRGBA__ros_msg_type * ros_message = (const _ColorRGBA__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: r
  {
    const size_t item_size = sizeof(ros_message->r);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: g
  {
    const size_t item_size = sizeof(ros_message->g);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: b
  {
    const size_t item_size = sizeof(ros_message->b);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: a
  {
    const size_t item_size = sizeof(ros_message->a);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ColorRGBA__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_std_msgs__msg__ColorRGBA(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_std_msgs
size_t max_serialized_size_std_msgs__msg__ColorRGBA(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: r
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);
  // Member: g
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);
  // Member: b
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);
  // Member: a
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);

  return current_alignment - initial_alignment;
}

static size_t _ColorRGBA__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_std_msgs__msg__ColorRGBA(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_ColorRGBA = {
  "std_msgs::msg",
  "ColorRGBA",
  _ColorRGBA__cdr_serialize,
  _ColorRGBA__cdr_deserialize,
  _ColorRGBA__get_serialized_size,
  get_serialized_size_std_msgs__msg__ColorRGBA,
  _ColorRGBA__max_serialized_size
};

static rosidl_message_type_support_t _ColorRGBA__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_ColorRGBA,
  get_message_typesupport_handle_function,

  &std_msgs__msg__ColorRGBA__get_type_hash,
  &std_msgs__msg__ColorRGBA__get_type_description,
  &std_msgs__msg__ColorRGBA__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, ColorRGBA)() {
  return &_ColorRGBA__type_support;
}

#if defined(__cplusplus)
}
#endif
