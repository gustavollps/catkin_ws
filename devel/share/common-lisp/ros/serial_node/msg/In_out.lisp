; Auto-generated. Do not edit!


(cl:in-package serial_node-msg)


;//! \htmlinclude In_out.msg.html

(cl:defclass <In_out> (roslisp-msg-protocol:ros-message)
  ((input
    :reader input
    :initarg :input
    :type cl:float
    :initform 0.0)
   (output
    :reader output
    :initarg :output
    :type cl:float
    :initform 0.0))
)

(cl:defclass In_out (<In_out>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <In_out>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'In_out)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name serial_node-msg:<In_out> is deprecated: use serial_node-msg:In_out instead.")))

(cl:ensure-generic-function 'input-val :lambda-list '(m))
(cl:defmethod input-val ((m <In_out>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader serial_node-msg:input-val is deprecated.  Use serial_node-msg:input instead.")
  (input m))

(cl:ensure-generic-function 'output-val :lambda-list '(m))
(cl:defmethod output-val ((m <In_out>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader serial_node-msg:output-val is deprecated.  Use serial_node-msg:output instead.")
  (output m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <In_out>) ostream)
  "Serializes a message object of type '<In_out>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'input))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'output))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <In_out>) istream)
  "Deserializes a message object of type '<In_out>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'input) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'output) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<In_out>)))
  "Returns string type for a message object of type '<In_out>"
  "serial_node/In_out")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'In_out)))
  "Returns string type for a message object of type 'In_out"
  "serial_node/In_out")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<In_out>)))
  "Returns md5sum for a message object of type '<In_out>"
  "46f3fd29c4f8033525b878269a5aed96")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'In_out)))
  "Returns md5sum for a message object of type 'In_out"
  "46f3fd29c4f8033525b878269a5aed96")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<In_out>)))
  "Returns full string definition for message of type '<In_out>"
  (cl:format cl:nil "float32 input~%float32 output~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'In_out)))
  "Returns full string definition for message of type 'In_out"
  (cl:format cl:nil "float32 input~%float32 output~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <In_out>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <In_out>))
  "Converts a ROS message object to a list"
  (cl:list 'In_out
    (cl:cons ':input (input msg))
    (cl:cons ':output (output msg))
))
