#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <stdio.h>

namespace gazebo
{
	class joint_control : public ModelPlugin
	{
		private: physics::ModelPtr model;
		private: physics::JointPtr joint;
		private: common::PID pid;

		public: joint_control(){}

		public: virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
		{
			if(_model->GetJointCount()==0)
			{
				std::cerr<<"Invalid joint count, joint control plugin not loaded\n";
				return;
			}

			this->model = _model;
			this->joint = _model->GetJoints()[0];
			double p=_sdf->Get<double>("p");
			double i=_sdf->Get<double>("i");
			double d=_sdf->Get<double>("d");
			this->pid = common::PID(p,i,d);

			double pos=0,vel=0;
			pos = _sdf->Get<double>("position");
			vel = _sdf->Get<double>("velocity");

			this->model->GetJointController()->SetVelocityPID(this->joint->GetScopedName(),this->pid);
			this->model->GetJointController()->SetPositionPID(this->joint->GetScopedName(),this->pid);

			this->model->GetJointController()->SetPositionTarget(this->joint->GetScopedName(),pos);
			this->model->GetJointController()->SetVelocityTarget(this->joint->GetScopedName(),vel);

		}
	};

	GZ_REGISTER_MODEL_PLUGIN(joint_control)
}