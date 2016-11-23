; Auto-generated. Do not edit!


(cl:in-package serial_node-msg)


;//! \htmlinclude Angle.msg.html

(cl:defclass <Angle> (roslisp-msg-protocol:ros-message)
  ((angle
    :reader angle
    :initarg :angle
    :type cl:float
    :initform 0.0))
)

(cl:defclass Angle (<Angle>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Angle>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Angle)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name serial_node-msg:<Angle> is deprecated: use serial_node-msg:Angle instead.")))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <Angle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader serial_node-msg:angle-val is deprecated.  Use serial_node-msg:angle instead.")
  (angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Angle>) ostream)
  "Serializes a message object of type '<Angle>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Angle>) istream)
  "Deserializes a message object of type '<Angle>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angle) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Angle>)))
  "Returns string type for a message object of type '<Angle>"
  "serial_node/Angle")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Angle)))
  "Returns string type for a message object of type 'Angle"
  "serial_node/Angle")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Angle>)))
  "Returns md5sum for a message object of type '<Angle>"
  "2d11dcdbe5a6f73dd324353dc52315ab")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Angle)))
  "Returns md5sum for a message object of type 'Angle"
  "2d11dcdbe5a6f73dd324353dc52315ab")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Angle>)))
  "Returns full string definition for message of type '<Angle>"
  (cl:format cl:nil "float32 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Angle)))
  "Returns full string definition for message of type 'Angle"
  (cl:format cl:nil "float32 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Angle>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Angle>))
  "Converts a ROS message object to a list"
  (cl:list 'Angle
    (cl:cons ':angle (angle msg))
))
