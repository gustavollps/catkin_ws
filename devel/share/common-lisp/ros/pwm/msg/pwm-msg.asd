
(cl:in-package :asdf)

(defsystem "pwm-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "cmd_vel_msg" :depends-on ("_package_cmd_vel_msg"))
    (:file "_package_cmd_vel_msg" :depends-on ("_package"))
  ))