
(cl:in-package :asdf)

(defsystem "tcc_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "cmd_vel_msg" :depends-on ("_package_cmd_vel_msg"))
    (:file "_package_cmd_vel_msg" :depends-on ("_package"))
    (:file "interrupt_counter" :depends-on ("_package_interrupt_counter"))
    (:file "_package_interrupt_counter" :depends-on ("_package"))
    (:file "point" :depends-on ("_package_point"))
    (:file "_package_point" :depends-on ("_package"))
    (:file "location_goal" :depends-on ("_package_location_goal"))
    (:file "_package_location_goal" :depends-on ("_package"))
  ))