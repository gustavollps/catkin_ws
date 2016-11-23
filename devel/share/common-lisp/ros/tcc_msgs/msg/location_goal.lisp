; Auto-generated. Do not edit!


(cl:in-package tcc_msgs-msg)


;//! \htmlinclude location_goal.msg.html

(cl:defclass <location_goal> (roslisp-msg-protocol:ros-message)
  ((start
    :reader start
    :initarg :start
    :type tcc_msgs-msg:point
    :initform (cl:make-instance 'tcc_msgs-msg:point))
   (goal
    :reader goal
    :initarg :goal
    :type tcc_msgs-msg:point
    :initform (cl:make-instance 'tcc_msgs-msg:point)))
)

(cl:defclass location_goal (<location_goal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <location_goal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'location_goal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name tcc_msgs-msg:<location_goal> is deprecated: use tcc_msgs-msg:location_goal instead.")))

(cl:ensure-generic-function 'start-val :lambda-list '(m))
(cl:defmethod start-val ((m <location_goal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader tcc_msgs-msg:start-val is deprecated.  Use tcc_msgs-msg:start instead.")
  (start m))

(cl:ensure-generic-function 'goal-val :lambda-list '(m))
(cl:defmethod goal-val ((m <location_goal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader tcc_msgs-msg:goal-val is deprecated.  Use tcc_msgs-msg:goal instead.")
  (goal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <location_goal>) ostream)
  "Serializes a message object of type '<location_goal>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'start) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <location_goal>) istream)
  "Deserializes a message object of type '<location_goal>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'start) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<location_goal>)))
  "Returns string type for a message object of type '<location_goal>"
  "tcc_msgs/location_goal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'location_goal)))
  "Returns string type for a message object of type 'location_goal"
  "tcc_msgs/location_goal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<location_goal>)))
  "Returns md5sum for a message object of type '<location_goal>"
  "0bd1bb248c5558be85460e2f5009eda1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'location_goal)))
  "Returns md5sum for a message object of type 'location_goal"
  "0bd1bb248c5558be85460e2f5009eda1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<location_goal>)))
  "Returns full string definition for message of type '<location_goal>"
  (cl:format cl:nil "point start~%point goal~%~%================================================================================~%MSG: tcc_msgs/point~%int32 x~%int32 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'location_goal)))
  "Returns full string definition for message of type 'location_goal"
  (cl:format cl:nil "point start~%point goal~%~%================================================================================~%MSG: tcc_msgs/point~%int32 x~%int32 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <location_goal>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'start))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <location_goal>))
  "Converts a ROS message object to a list"
  (cl:list 'location_goal
    (cl:cons ':start (start msg))
    (cl:cons ':goal (goal msg))
))
