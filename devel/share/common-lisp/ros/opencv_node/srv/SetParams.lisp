; Auto-generated. Do not edit!


(cl:in-package opencv_node-srv)


;//! \htmlinclude SetParams-request.msg.html

(cl:defclass <SetParams-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass SetParams-request (<SetParams-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetParams-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetParams-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name opencv_node-srv:<SetParams-request> is deprecated: use opencv_node-srv:SetParams-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetParams-request>) ostream)
  "Serializes a message object of type '<SetParams-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetParams-request>) istream)
  "Deserializes a message object of type '<SetParams-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetParams-request>)))
  "Returns string type for a service object of type '<SetParams-request>"
  "opencv_node/SetParamsRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetParams-request)))
  "Returns string type for a service object of type 'SetParams-request"
  "opencv_node/SetParamsRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetParams-request>)))
  "Returns md5sum for a message object of type '<SetParams-request>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetParams-request)))
  "Returns md5sum for a message object of type 'SetParams-request"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetParams-request>)))
  "Returns full string definition for message of type '<SetParams-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetParams-request)))
  "Returns full string definition for message of type 'SetParams-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetParams-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetParams-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetParams-request
))
;//! \htmlinclude SetParams-response.msg.html

(cl:defclass <SetParams-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass SetParams-response (<SetParams-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetParams-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetParams-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name opencv_node-srv:<SetParams-response> is deprecated: use opencv_node-srv:SetParams-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetParams-response>) ostream)
  "Serializes a message object of type '<SetParams-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetParams-response>) istream)
  "Deserializes a message object of type '<SetParams-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetParams-response>)))
  "Returns string type for a service object of type '<SetParams-response>"
  "opencv_node/SetParamsResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetParams-response)))
  "Returns string type for a service object of type 'SetParams-response"
  "opencv_node/SetParamsResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetParams-response>)))
  "Returns md5sum for a message object of type '<SetParams-response>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetParams-response)))
  "Returns md5sum for a message object of type 'SetParams-response"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetParams-response>)))
  "Returns full string definition for message of type '<SetParams-response>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetParams-response)))
  "Returns full string definition for message of type 'SetParams-response"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetParams-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetParams-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetParams-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetParams)))
  'SetParams-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetParams)))
  'SetParams-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetParams)))
  "Returns string type for a service object of type '<SetParams>"
  "opencv_node/SetParams")