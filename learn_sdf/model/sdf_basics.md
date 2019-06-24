Basic setup:
1) write the xml version and sdf version
2) write the model name
3) set the self collide property 
4) set the static property at the end

We have now written the bare essentials for the model.
Now, lets add links and joints.

-----------------------------------LINKS-------------------------------------
A link has following elements:
1)link pose
//this sets the pose of the link frame wrt to the global frame. Where the origin of the link frame is located depends on the link geometry. It is usually the geometric center for symmetric objects. For irregular objects, you can set this origin at the time of export from your software.//

2)inertial properties:
	a)COM pose wrt to link frame.
	b)mass of the link
	c)inertia matrix

3)visual properties:
	a)Pose of the visual stl file wrt link frame.
	b)geometry of the visual stl file. It can be one of the standard geometries or any irregular mesh file.

4)collision properties:
	a)Pose of the collision stl file wrt link frame.
	b)geometry of the collision stl file. 
-----------------------------------LINKS-------------------------------------





-----------------------------------JOINTS-------------------------------------
A joint has following elements besides joint name and joint type.
1)name of child link

2)name of parent link

3)axis
	a)xyz orientation of the link
	b)pose of the axis
	c)upper and lower limits of the joint positions
	d)dynamic properties
-----------------------------------JOINTS-------------------------------------



-Apart from links and joints, a model can also have a plugin. 
-A plugin is basically a shared library whose source code is written in c language. 
-A plugin is used to control various properties of a model. 
-The variables of a plugin can be set through the sdf file using custom tags.
-the plugin has a name and a filename. 
