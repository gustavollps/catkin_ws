
(cl:in-package :asdf)

(defsystem "serial_node-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ResetAngle" :depends-on ("_package_ResetAngle"))
    (:file "_package_ResetAngle" :depends-on ("_package"))
  ))