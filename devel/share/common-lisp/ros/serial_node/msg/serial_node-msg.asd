
(cl:in-package :asdf)

(defsystem "serial_node-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Angle" :depends-on ("_package_Angle"))
    (:file "_package_Angle" :depends-on ("_package"))
    (:file "PIDparams" :depends-on ("_package_PIDparams"))
    (:file "_package_PIDparams" :depends-on ("_package"))
    (:file "In_out" :depends-on ("_package_In_out"))
    (:file "_package_In_out" :depends-on ("_package"))
  ))