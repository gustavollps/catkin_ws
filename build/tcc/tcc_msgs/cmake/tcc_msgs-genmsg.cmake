# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "tcc_msgs: 4 messages, 0 services")

set(MSG_I_FLAGS "-Itcc_msgs:/home/tony/catkin_ws/src/tcc/tcc_msgs/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(tcc_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/cmd_vel_msg.msg" NAME_WE)
add_custom_target(_tcc_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "tcc_msgs" "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/cmd_vel_msg.msg" ""
)

get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/interrupt_counter.msg" NAME_WE)
add_custom_target(_tcc_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "tcc_msgs" "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/interrupt_counter.msg" ""
)

get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/location_goal.msg" NAME_WE)
add_custom_target(_tcc_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "tcc_msgs" "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/location_goal.msg" "tcc_msgs/point"
)

get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/point.msg" NAME_WE)
add_custom_target(_tcc_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "tcc_msgs" "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/point.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(tcc_msgs
  "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/cmd_vel_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/tcc_msgs
)
_generate_msg_cpp(tcc_msgs
  "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/interrupt_counter.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/tcc_msgs
)
_generate_msg_cpp(tcc_msgs
  "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/location_goal.msg"
  "${MSG_I_FLAGS}"
  "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/tcc_msgs
)
_generate_msg_cpp(tcc_msgs
  "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/point.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/tcc_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(tcc_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/tcc_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(tcc_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(tcc_msgs_generate_messages tcc_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/cmd_vel_msg.msg" NAME_WE)
add_dependencies(tcc_msgs_generate_messages_cpp _tcc_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/interrupt_counter.msg" NAME_WE)
add_dependencies(tcc_msgs_generate_messages_cpp _tcc_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/location_goal.msg" NAME_WE)
add_dependencies(tcc_msgs_generate_messages_cpp _tcc_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/point.msg" NAME_WE)
add_dependencies(tcc_msgs_generate_messages_cpp _tcc_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(tcc_msgs_gencpp)
add_dependencies(tcc_msgs_gencpp tcc_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS tcc_msgs_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(tcc_msgs
  "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/cmd_vel_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/tcc_msgs
)
_generate_msg_lisp(tcc_msgs
  "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/interrupt_counter.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/tcc_msgs
)
_generate_msg_lisp(tcc_msgs
  "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/location_goal.msg"
  "${MSG_I_FLAGS}"
  "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/tcc_msgs
)
_generate_msg_lisp(tcc_msgs
  "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/point.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/tcc_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(tcc_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/tcc_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(tcc_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(tcc_msgs_generate_messages tcc_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/cmd_vel_msg.msg" NAME_WE)
add_dependencies(tcc_msgs_generate_messages_lisp _tcc_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/interrupt_counter.msg" NAME_WE)
add_dependencies(tcc_msgs_generate_messages_lisp _tcc_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/location_goal.msg" NAME_WE)
add_dependencies(tcc_msgs_generate_messages_lisp _tcc_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/point.msg" NAME_WE)
add_dependencies(tcc_msgs_generate_messages_lisp _tcc_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(tcc_msgs_genlisp)
add_dependencies(tcc_msgs_genlisp tcc_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS tcc_msgs_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(tcc_msgs
  "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/cmd_vel_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/tcc_msgs
)
_generate_msg_py(tcc_msgs
  "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/interrupt_counter.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/tcc_msgs
)
_generate_msg_py(tcc_msgs
  "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/location_goal.msg"
  "${MSG_I_FLAGS}"
  "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/tcc_msgs
)
_generate_msg_py(tcc_msgs
  "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/point.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/tcc_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(tcc_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/tcc_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(tcc_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(tcc_msgs_generate_messages tcc_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/cmd_vel_msg.msg" NAME_WE)
add_dependencies(tcc_msgs_generate_messages_py _tcc_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/interrupt_counter.msg" NAME_WE)
add_dependencies(tcc_msgs_generate_messages_py _tcc_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/location_goal.msg" NAME_WE)
add_dependencies(tcc_msgs_generate_messages_py _tcc_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/tcc_msgs/msg/point.msg" NAME_WE)
add_dependencies(tcc_msgs_generate_messages_py _tcc_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(tcc_msgs_genpy)
add_dependencies(tcc_msgs_genpy tcc_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS tcc_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/tcc_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/tcc_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(tcc_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/tcc_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/tcc_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(tcc_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/tcc_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/tcc_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/tcc_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(tcc_msgs_generate_messages_py std_msgs_generate_messages_py)
