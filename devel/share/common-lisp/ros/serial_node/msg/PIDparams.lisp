; Auto-generated. Do not edit!


(cl:in-package serial_node-msg)


;//! \htmlinclude PIDparams.msg.html

(cl:defclass <PIDparams> (roslisp-msg-protocol:ros-message)
  ((kp
    :reader kp
    :initarg :kp
    :type cl:float
    :initform 0.0)
   (ki
    :reader ki
    :initarg :ki
    :type cl:float
    :initform 0.0)
   (kd
    :reader kd
    :initarg :kd
    :type cl:float
    :initform 0.0)
   (setpoint
    :reader setpoint
    :initarg :setpoint
    :type cl:float
    :initform 0.0)
   (min
    :reader min
    :initarg :min
    :type cl:float
    :initform 0.0)
   (max
    :reader max
    :initarg :max
    :type cl:float
    :initform 0.0))
)

(cl:defclass PIDparams (<PIDparams>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PIDparams>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PIDparams)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name serial_node-msg:<PIDparams> is deprecated: use serial_node-msg:PIDparams instead.")))

(cl:ensure-generic-function 'kp-val :lambda-list '(m))
(cl:defmethod kp-val ((m <PIDparams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader serial_node-msg:kp-val is deprecated.  Use serial_node-msg:kp instead.")
  (kp m))

(cl:ensure-generic-function 'ki-val :lambda-list '(m))
(cl:defmethod ki-val ((m <PIDparams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader serial_node-msg:ki-val is deprecated.  Use serial_node-msg:ki instead.")
  (ki m))

(cl:ensure-generic-function 'kd-val :lambda-list '(m))
(cl:defmethod kd-val ((m <PIDparams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader serial_node-msg:kd-val is deprecated.  Use serial_node-msg:kd instead.")
  (kd m))

(cl:ensure-generic-function 'setpoint-val :lambda-list '(m))
(cl:defmethod setpoint-val ((m <PIDparams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader serial_node-msg:setpoint-val is deprecated.  Use serial_node-msg:setpoint instead.")
  (setpoint m))

(cl:ensure-generic-function 'min-val :lambda-list '(m))
(cl:defmethod min-val ((m <PIDparams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader serial_node-msg:min-val is deprecated.  Use serial_node-msg:min instead.")
  (min m))

(cl:ensure-generic-function 'max-val :lambda-list '(m))
(cl:defmethod max-val ((m <PIDparams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader serial_node-msg:max-val is deprecated.  Use serial_node-msg:max instead.")
  (max m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PIDparams>) ostream)
  "Serializes a message object of type '<PIDparams>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'kp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'ki))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'kd))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'setpoint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'min))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'max))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PIDparams>) istream)
  "Deserializes a message object of type '<PIDparams>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'kp) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ki) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'kd) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'setpoint) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'min) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'max) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PIDparams>)))
  "Returns string type for a message object of type '<PIDparams>"
  "serial_node/PIDparams")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PIDparams)))
  "Returns string type for a message object of type 'PIDparams"
  "serial_node/PIDparams")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PIDparams>)))
  "Returns md5sum for a message object of type '<PIDparams>"
  "2d703500b36bd081738aa374697bbd39")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PIDparams)))
  "Returns md5sum for a message object of type 'PIDparams"
  "2d703500b36bd081738aa374697bbd39")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PIDparams>)))
  "Returns full string definition for message of type '<PIDparams>"
  (cl:format cl:nil "float32 kp~%float32 ki~%float32 kd~%float32 setpoint~%float32 min~%float32 max~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PIDparams)))
  "Returns full string definition for message of type 'PIDparams"
  (cl:format cl:nil "float32 kp~%float32 ki~%float32 kd~%float32 setpoint~%float32 min~%float32 max~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PIDparams>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PIDparams>))
  "Converts a ROS message object to a list"
  (cl:list 'PIDparams
    (cl:cons ':kp (kp msg))
    (cl:cons ':ki (ki msg))
    (cl:cons ':kd (kd msg))
    (cl:cons ':setpoint (setpoint msg))
    (cl:cons ':min (min msg))
    (cl:cons ':max (max msg))
))
