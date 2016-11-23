; Auto-generated. Do not edit!


(cl:in-package serial_node-srv)


;//! \htmlinclude ResetAngle-request.msg.html

(cl:defclass <ResetAngle-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass ResetAngle-request (<ResetAngle-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ResetAngle-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ResetAngle-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name serial_node-srv:<ResetAngle-request> is deprecated: use serial_node-srv:ResetAngle-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ResetAngle-request>) ostream)
  "Serializes a message object of type '<ResetAngle-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ResetAngle-request>) istream)
  "Deserializes a message object of type '<ResetAngle-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ResetAngle-request>)))
  "Returns string type for a service object of type '<ResetAngle-request>"
  "serial_node/ResetAngleRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ResetAngle-request)))
  "Returns string type for a service object of type 'ResetAngle-request"
  "serial_node/ResetAngleRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ResetAngle-request>)))
  "Returns md5sum for a message object of type '<ResetAngle-request>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ResetAngle-request)))
  "Returns md5sum for a message object of type 'ResetAngle-request"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ResetAngle-request>)))
  "Returns full string definition for message of type '<ResetAngle-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ResetAngle-request)))
  "Returns full string definition for message of type 'ResetAngle-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ResetAngle-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ResetAngle-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ResetAngle-request
))
;//! \htmlinclude ResetAngle-response.msg.html

(cl:defclass <ResetAngle-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass ResetAngle-response (<ResetAngle-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ResetAngle-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ResetAngle-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name serial_node-srv:<ResetAngle-response> is deprecated: use serial_node-srv:ResetAngle-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ResetAngle-response>) ostream)
  "Serializes a message object of type '<ResetAngle-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ResetAngle-response>) istream)
  "Deserializes a message object of type '<ResetAngle-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ResetAngle-response>)))
  "Returns string type for a service object of type '<ResetAngle-response>"
  "serial_node/ResetAngleResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ResetAngle-response)))
  "Returns string type for a service object of type 'ResetAngle-response"
  "serial_node/ResetAngleResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ResetAngle-response>)))
  "Returns md5sum for a message object of type '<ResetAngle-response>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ResetAngle-response)))
  "Returns md5sum for a message object of type 'ResetAngle-response"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ResetAngle-response>)))
  "Returns full string definition for message of type '<ResetAngle-response>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ResetAngle-response)))
  "Returns full string definition for message of type 'ResetAngle-response"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ResetAngle-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ResetAngle-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ResetAngle-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ResetAngle)))
  'ResetAngle-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ResetAngle)))
  'ResetAngle-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ResetAngle)))
  "Returns string type for a service object of type '<ResetAngle>"
  "serial_node/ResetAngle")