; Auto-generated. Do not edit!


(cl:in-package tcc_msgs-msg)


;//! \htmlinclude cmd_vel_msg.msg.html

(cl:defclass <cmd_vel_msg> (roslisp-msg-protocol:ros-message)
  ((pwm1
    :reader pwm1
    :initarg :pwm1
    :type cl:float
    :initform 0.0)
   (pwm2
    :reader pwm2
    :initarg :pwm2
    :type cl:float
    :initform 0.0)
   (pwm3
    :reader pwm3
    :initarg :pwm3
    :type cl:float
    :initform 0.0))
)

(cl:defclass cmd_vel_msg (<cmd_vel_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <cmd_vel_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'cmd_vel_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name tcc_msgs-msg:<cmd_vel_msg> is deprecated: use tcc_msgs-msg:cmd_vel_msg instead.")))

(cl:ensure-generic-function 'pwm1-val :lambda-list '(m))
(cl:defmethod pwm1-val ((m <cmd_vel_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader tcc_msgs-msg:pwm1-val is deprecated.  Use tcc_msgs-msg:pwm1 instead.")
  (pwm1 m))

(cl:ensure-generic-function 'pwm2-val :lambda-list '(m))
(cl:defmethod pwm2-val ((m <cmd_vel_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader tcc_msgs-msg:pwm2-val is deprecated.  Use tcc_msgs-msg:pwm2 instead.")
  (pwm2 m))

(cl:ensure-generic-function 'pwm3-val :lambda-list '(m))
(cl:defmethod pwm3-val ((m <cmd_vel_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader tcc_msgs-msg:pwm3-val is deprecated.  Use tcc_msgs-msg:pwm3 instead.")
  (pwm3 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <cmd_vel_msg>) ostream)
  "Serializes a message object of type '<cmd_vel_msg>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pwm1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pwm2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pwm3))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <cmd_vel_msg>) istream)
  "Deserializes a message object of type '<cmd_vel_msg>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pwm1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pwm2) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pwm3) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<cmd_vel_msg>)))
  "Returns string type for a message object of type '<cmd_vel_msg>"
  "tcc_msgs/cmd_vel_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'cmd_vel_msg)))
  "Returns string type for a message object of type 'cmd_vel_msg"
  "tcc_msgs/cmd_vel_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<cmd_vel_msg>)))
  "Returns md5sum for a message object of type '<cmd_vel_msg>"
  "e03293df3d14e0aa43909bef4c94fc72")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'cmd_vel_msg)))
  "Returns md5sum for a message object of type 'cmd_vel_msg"
  "e03293df3d14e0aa43909bef4c94fc72")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<cmd_vel_msg>)))
  "Returns full string definition for message of type '<cmd_vel_msg>"
  (cl:format cl:nil "float32 pwm1~%float32 pwm2~%float32 pwm3~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'cmd_vel_msg)))
  "Returns full string definition for message of type 'cmd_vel_msg"
  (cl:format cl:nil "float32 pwm1~%float32 pwm2~%float32 pwm3~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <cmd_vel_msg>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <cmd_vel_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'cmd_vel_msg
    (cl:cons ':pwm1 (pwm1 msg))
    (cl:cons ':pwm2 (pwm2 msg))
    (cl:cons ':pwm3 (pwm3 msg))
))
