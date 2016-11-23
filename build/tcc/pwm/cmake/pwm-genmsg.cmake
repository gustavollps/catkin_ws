# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "pwm: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ipwm:/home/tony/catkin_ws/src/tcc/pwm/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(pwm_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/pwm/msg/cmd_vel_msg.msg" NAME_WE)
add_custom_target(_pwm_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pwm" "/home/tony/catkin_ws/src/tcc/pwm/msg/cmd_vel_msg.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(pwm
  "/home/tony/catkin_ws/src/tcc/pwm/msg/cmd_vel_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pwm
)

### Generating Services

### Generating Module File
_generate_module_cpp(pwm
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pwm
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(pwm_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(pwm_generate_messages pwm_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/pwm/msg/cmd_vel_msg.msg" NAME_WE)
add_dependencies(pwm_generate_messages_cpp _pwm_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pwm_gencpp)
add_dependencies(pwm_gencpp pwm_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pwm_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(pwm
  "/home/tony/catkin_ws/src/tcc/pwm/msg/cmd_vel_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pwm
)

### Generating Services

### Generating Module File
_generate_module_lisp(pwm
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pwm
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(pwm_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(pwm_generate_messages pwm_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/pwm/msg/cmd_vel_msg.msg" NAME_WE)
add_dependencies(pwm_generate_messages_lisp _pwm_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pwm_genlisp)
add_dependencies(pwm_genlisp pwm_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pwm_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(pwm
  "/home/tony/catkin_ws/src/tcc/pwm/msg/cmd_vel_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pwm
)

### Generating Services

### Generating Module File
_generate_module_py(pwm
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pwm
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(pwm_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(pwm_generate_messages pwm_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tony/catkin_ws/src/tcc/pwm/msg/cmd_vel_msg.msg" NAME_WE)
add_dependencies(pwm_generate_messages_py _pwm_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pwm_genpy)
add_dependencies(pwm_genpy pwm_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pwm_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pwm)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pwm
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(pwm_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pwm)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pwm
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(pwm_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pwm)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pwm\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pwm
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(pwm_generate_messages_py std_msgs_generate_messages_py)
