; Auto-generated. Do not edit!


(cl:in-package tcc_msgs-msg)


;//! \htmlinclude interrupt_counter.msg.html

(cl:defclass <interrupt_counter> (roslisp-msg-protocol:ros-message)
  ((int1
    :reader int1
    :initarg :int1
    :type cl:integer
    :initform 0)
   (int2
    :reader int2
    :initarg :int2
    :type cl:integer
    :initform 0)
   (int3
    :reader int3
    :initarg :int3
    :type cl:integer
    :initform 0))
)

(cl:defclass interrupt_counter (<interrupt_counter>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <interrupt_counter>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'interrupt_counter)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name tcc_msgs-msg:<interrupt_counter> is deprecated: use tcc_msgs-msg:interrupt_counter instead.")))

(cl:ensure-generic-function 'int1-val :lambda-list '(m))
(cl:defmethod int1-val ((m <interrupt_counter>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader tcc_msgs-msg:int1-val is deprecated.  Use tcc_msgs-msg:int1 instead.")
  (int1 m))

(cl:ensure-generic-function 'int2-val :lambda-list '(m))
(cl:defmethod int2-val ((m <interrupt_counter>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader tcc_msgs-msg:int2-val is deprecated.  Use tcc_msgs-msg:int2 instead.")
  (int2 m))

(cl:ensure-generic-function 'int3-val :lambda-list '(m))
(cl:defmethod int3-val ((m <interrupt_counter>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader tcc_msgs-msg:int3-val is deprecated.  Use tcc_msgs-msg:int3 instead.")
  (int3 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <interrupt_counter>) ostream)
  "Serializes a message object of type '<interrupt_counter>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'int1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'int1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'int1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'int1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'int2)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'int2)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'int2)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'int2)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'int3)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'int3)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'int3)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'int3)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <interrupt_counter>) istream)
  "Deserializes a message object of type '<interrupt_counter>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'int1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'int1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'int1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'int1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'int2)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'int2)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'int2)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'int2)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'int3)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'int3)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'int3)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'int3)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<interrupt_counter>)))
  "Returns string type for a message object of type '<interrupt_counter>"
  "tcc_msgs/interrupt_counter")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'interrupt_counter)))
  "Returns string type for a message object of type 'interrupt_counter"
  "tcc_msgs/interrupt_counter")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<interrupt_counter>)))
  "Returns md5sum for a message object of type '<interrupt_counter>"
  "5c1c28d031d374be466e93c93fdd9023")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'interrupt_counter)))
  "Returns md5sum for a message object of type 'interrupt_counter"
  "5c1c28d031d374be466e93c93fdd9023")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<interrupt_counter>)))
  "Returns full string definition for message of type '<interrupt_counter>"
  (cl:format cl:nil "uint32 int1~%uint32 int2~%uint32 int3~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'interrupt_counter)))
  "Returns full string definition for message of type 'interrupt_counter"
  (cl:format cl:nil "uint32 int1~%uint32 int2~%uint32 int3~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <interrupt_counter>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <interrupt_counter>))
  "Converts a ROS message object to a list"
  (cl:list 'interrupt_counter
    (cl:cons ':int1 (int1 msg))
    (cl:cons ':int2 (int2 msg))
    (cl:cons ':int3 (int3 msg))
))
