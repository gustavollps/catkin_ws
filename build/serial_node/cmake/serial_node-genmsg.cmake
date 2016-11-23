# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "serial_node: 3 messages, 1 services")

set(MSG_I_FLAGS "-Iserial_node:/home/tony/catkin_ws/src/serial_node/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(serial_node_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/tony/catkin_ws/src/serial_node/srv/ResetAngle.srv" NAME_WE)
add_custom_target(_serial_node_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "serial_node" "/home/tony/catkin_ws/src/serial_node/srv/ResetAngle.srv" ""
)

get_filename_component(_filename "/home/tony/catkin_ws/src/serial_node/msg/Angle.msg" NAME_WE)
add_custom_target(_serial_node_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "serial_node" "/home/tony/catkin_ws/src/serial_node/msg/Angle.msg" ""
)

get_filename_component(_filename "/home/tony/catkin_ws/src/serial_node/msg/In_out.msg" NAME_WE)
add_custom_target(_serial_node_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "serial_node" "/home/tony/catkin_ws/src/serial_node/msg/In_out.msg" ""
)

get_filename_component(_filename "/home/tony/catkin_ws/src/serial_node/msg/PIDparams.msg" NAME_WE)
add_custom_target(_serial_node_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "serial_node" "/home/tony/catkin_ws/src/serial_node/msg/PIDparams.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(serial_node
  "/home/tony/catkin_ws/src/serial_node/msg/Angle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/serial_node
)
_generate_msg_cpp(serial_node
  "/home/tony/catkin_ws/src/serial_node/msg/In_out.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/serial_node
)
_generate_msg_cpp(serial_node
  "/home/tony/catkin_ws/src/serial_node/msg/PIDparams.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/serial_node
)

### Generating Services
_generate_srv_cpp(serial_node
  "/home/tony/catkin_ws/src/serial_node/srv/ResetAngle.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/serial_node
)

### Generating Module File
_generate_module_cpp(serial_node
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/serial_node
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(serial_node_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(serial_node_generate_messages serial_node_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tony/catkin_ws/src/serial_node/srv/ResetAngle.srv" NAME_WE)
add_dependencies(serial_node_generate_messages_cpp _serial_node_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/serial_node/msg/Angle.msg" NAME_WE)
add_dependencies(serial_node_generate_messages_cpp _serial_node_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/serial_node/msg/In_out.msg" NAME_WE)
add_dependencies(serial_node_generate_messages_cpp _serial_node_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/serial_node/msg/PIDparams.msg" NAME_WE)
add_dependencies(serial_node_generate_messages_cpp _serial_node_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(serial_node_gencpp)
add_dependencies(serial_node_gencpp serial_node_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS serial_node_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(serial_node
  "/home/tony/catkin_ws/src/serial_node/msg/Angle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/serial_node
)
_generate_msg_lisp(serial_node
  "/home/tony/catkin_ws/src/serial_node/msg/In_out.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/serial_node
)
_generate_msg_lisp(serial_node
  "/home/tony/catkin_ws/src/serial_node/msg/PIDparams.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/serial_node
)

### Generating Services
_generate_srv_lisp(serial_node
  "/home/tony/catkin_ws/src/serial_node/srv/ResetAngle.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/serial_node
)

### Generating Module File
_generate_module_lisp(serial_node
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/serial_node
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(serial_node_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(serial_node_generate_messages serial_node_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tony/catkin_ws/src/serial_node/srv/ResetAngle.srv" NAME_WE)
add_dependencies(serial_node_generate_messages_lisp _serial_node_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/serial_node/msg/Angle.msg" NAME_WE)
add_dependencies(serial_node_generate_messages_lisp _serial_node_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/serial_node/msg/In_out.msg" NAME_WE)
add_dependencies(serial_node_generate_messages_lisp _serial_node_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/serial_node/msg/PIDparams.msg" NAME_WE)
add_dependencies(serial_node_generate_messages_lisp _serial_node_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(serial_node_genlisp)
add_dependencies(serial_node_genlisp serial_node_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS serial_node_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(serial_node
  "/home/tony/catkin_ws/src/serial_node/msg/Angle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/serial_node
)
_generate_msg_py(serial_node
  "/home/tony/catkin_ws/src/serial_node/msg/In_out.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/serial_node
)
_generate_msg_py(serial_node
  "/home/tony/catkin_ws/src/serial_node/msg/PIDparams.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/serial_node
)

### Generating Services
_generate_srv_py(serial_node
  "/home/tony/catkin_ws/src/serial_node/srv/ResetAngle.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/serial_node
)

### Generating Module File
_generate_module_py(serial_node
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/serial_node
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(serial_node_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(serial_node_generate_messages serial_node_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tony/catkin_ws/src/serial_node/srv/ResetAngle.srv" NAME_WE)
add_dependencies(serial_node_generate_messages_py _serial_node_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/serial_node/msg/Angle.msg" NAME_WE)
add_dependencies(serial_node_generate_messages_py _serial_node_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/serial_node/msg/In_out.msg" NAME_WE)
add_dependencies(serial_node_generate_messages_py _serial_node_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tony/catkin_ws/src/serial_node/msg/PIDparams.msg" NAME_WE)
add_dependencies(serial_node_generate_messages_py _serial_node_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(serial_node_genpy)
add_dependencies(serial_node_genpy serial_node_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS serial_node_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/serial_node)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/serial_node
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(serial_node_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/serial_node)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/serial_node
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(serial_node_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/serial_node)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/serial_node\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/serial_node
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(serial_node_generate_messages_py std_msgs_generate_messages_py)
