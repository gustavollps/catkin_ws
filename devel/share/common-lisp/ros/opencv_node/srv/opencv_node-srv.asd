
(cl:in-package :asdf)

(defsystem "opencv_node-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "SetParams" :depends-on ("_package_SetParams"))
    (:file "_package_SetParams" :depends-on ("_package"))
  ))