A plugin is a c++ file which is used to control various elements of gazebo.

Plugins can be of various types:
1)Model Plugins
2)World Plugins
3)Graphics Plugins
etc...

How to write a plugin:

1)Include the necessary libraries.
2)Include the whole code in the appropriate namespace.
3)Write your whole code as a class and inherit this class from ModelPlugin (i.e the appropriate base Plugin type.)
4)Create private members which hold the pointers to the model, joints and also pid values.
5)Create a Load function which accepts as arguments the pointers to the model and the sdf.
6)Lastly, register your plugin.

Important functions:

1)_model->GetJointCount()
2)_model->GetJoints()[]
3)_model->GetJointController()->SetVelocityPID(joint_name,pid)
4)_model->GetJointController()->SetPositionPID(joint_name,pid)
5)_model->GetJointController()->SetPositionTarget(joint_name,position)
6)_model->GetJointController()->SetVelocityTarget(joint_name,velocity) 
