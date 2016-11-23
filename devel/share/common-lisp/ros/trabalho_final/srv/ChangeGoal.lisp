; Auto-generated. Do not edit!


(cl:in-package trabalho_final-srv)


;//! \htmlinclude ChangeGoal-request.msg.html

(cl:defclass <ChangeGoal-request> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0))
)

(cl:defclass ChangeGoal-request (<ChangeGoal-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ChangeGoal-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ChangeGoal-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name trabalho_final-srv:<ChangeGoal-request> is deprecated: use trabalho_final-srv:ChangeGoal-request instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <ChangeGoal-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader trabalho_final-srv:x-val is deprecated.  Use trabalho_final-srv:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <ChangeGoal-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader trabalho_final-srv:y-val is deprecated.  Use trabalho_final-srv:y instead.")
  (y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ChangeGoal-request>) ostream)
  "Serializes a message object of type '<ChangeGoal-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ChangeGoal-request>) istream)
  "Deserializes a message object of type '<ChangeGoal-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ChangeGoal-request>)))
  "Returns string type for a service object of type '<ChangeGoal-request>"
  "trabalho_final/ChangeGoalRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ChangeGoal-request)))
  "Returns string type for a service object of type 'ChangeGoal-request"
  "trabalho_final/ChangeGoalRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ChangeGoal-request>)))
  "Returns md5sum for a message object of type '<ChangeGoal-request>"
  "ff8d7d66dd3e4b731ef14a45d38888b6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ChangeGoal-request)))
  "Returns md5sum for a message object of type 'ChangeGoal-request"
  "ff8d7d66dd3e4b731ef14a45d38888b6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ChangeGoal-request>)))
  "Returns full string definition for message of type '<ChangeGoal-request>"
  (cl:format cl:nil "float32 x~%float32 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ChangeGoal-request)))
  "Returns full string definition for message of type 'ChangeGoal-request"
  (cl:format cl:nil "float32 x~%float32 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ChangeGoal-request>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ChangeGoal-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ChangeGoal-request
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
))
;//! \htmlinclude ChangeGoal-response.msg.html

(cl:defclass <ChangeGoal-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass ChangeGoal-response (<ChangeGoal-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ChangeGoal-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ChangeGoal-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name trabalho_final-srv:<ChangeGoal-response> is deprecated: use trabalho_final-srv:ChangeGoal-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ChangeGoal-response>) ostream)
  "Serializes a message object of type '<ChangeGoal-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ChangeGoal-response>) istream)
  "Deserializes a message object of type '<ChangeGoal-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ChangeGoal-response>)))
  "Returns string type for a service object of type '<ChangeGoal-response>"
  "trabalho_final/ChangeGoalResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ChangeGoal-response)))
  "Returns string type for a service object of type 'ChangeGoal-response"
  "trabalho_final/ChangeGoalResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ChangeGoal-response>)))
  "Returns md5sum for a message object of type '<ChangeGoal-response>"
  "ff8d7d66dd3e4b731ef14a45d38888b6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ChangeGoal-response)))
  "Returns md5sum for a message object of type 'ChangeGoal-response"
  "ff8d7d66dd3e4b731ef14a45d38888b6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ChangeGoal-response>)))
  "Returns full string definition for message of type '<ChangeGoal-response>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ChangeGoal-response)))
  "Returns full string definition for message of type 'ChangeGoal-response"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ChangeGoal-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ChangeGoal-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ChangeGoal-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ChangeGoal)))
  'ChangeGoal-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ChangeGoal)))
  'ChangeGoal-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ChangeGoal)))
  "Returns string type for a service object of type '<ChangeGoal>"
  "trabalho_final/ChangeGoal")