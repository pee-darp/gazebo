#ifndef _VELODYNE_PLUGIN_HH_
#define _VELODYNE_PLUGIN_HH_

#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>

namespace gazebo
{
  /// \brief A plugin to control a Velodyne sensor.
  class VelodynePlugin: public ModelPlugin
  {
    /// \brief Constructor
   public: VelodynePlugin() {}

    /// \brief The load function is called by Gazebo when the plugin is
    /// inserted into simulation
    /// \param[in] _model A pointer to the model that this plugin is
    /// attached to.
    /// \param[in] _sdf A pointer to the plugin's SDF element.
   public: virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
    {
     //Safety check
     if (_model->GetJointCount()==0)
    {
     std::cerr << "Invalid Joint count, Velodyne plugin is not loaded\n";
    }
     //Store the model pointer for convenience.
     this->model = _model;
     this->joint = _model->GetJoints()[0];
     this->pid = common::PID(0.1,0,0);
     this->model->GetJointController()->SetVelocityPID(this->joint->GetScopedName(),this->pid);		//Applying P controller to the joint.
     double velocity = 0;
     if(_sdf->HasElement("velocity"))
      velocity = _sdf->Get<double>("velocity");
     this->model->GetJointController()->SetVelocityTarget(this->joint->GetScopedName(),velocity);		//Setting joint's target velocity.

     this->node = transport::NodePtr(new transport::Node());
     #if GAZEBO_MAJOR_VERSION < 8
     this->node->Init(this->model->GetWorld()->GetName());
     #else
     this->node->Init(this->model->GetWorld()->Name());
     #endif
     std::string topicName = "~/" + this->model->GetName() + "/vel_cmd";
     this->sub = this->node->Subscribe(topicName,&VelodynePlugin::OnMsg,this);
     
    }

   /// \brief Set the velocity of the Velodyne
   /// \param[in] _vel New target velocity
   public: void SetVelocity(const double &_vel)
   {
    this->model->GetJointController()->SetVelocityTarget(this->joint->GetScopedName(),_vel);
   }

   private: void OnMsg(ConstVector3dPtr &_msg)
   {this->SetVelocity(_msg->x());}
 
    private: physics::ModelPtr model;
    private: physics::JointPtr joint;
    private: common::PID pid;
    private: transport::NodePtr node;
    private: transport::SubscriberPtr sub;  
  };    

  //Tell Gazebo about this plugin so that Gazebo can call Load on this plugin.
  GZ_REGISTER_MODEL_PLUGIN(VelodynePlugin)

}
#endif
