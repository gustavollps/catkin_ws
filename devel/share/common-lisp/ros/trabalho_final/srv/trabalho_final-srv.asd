
(cl:in-package :asdf)

(defsystem "trabalho_final-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ChangeGoal" :depends-on ("_package_ChangeGoal"))
    (:file "_package_ChangeGoal" :depends-on ("_package"))
  ))