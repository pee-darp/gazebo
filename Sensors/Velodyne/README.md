This project creates a Velodyne HDL32 sensor model for use in Gazebo.

Ref: http://gazebosim.org/tutorials?cat=guided_i&tut=guided_i1 

Problems Faced:
  1) gazebo.hh not found error: Silly typing mistake in velodyne_plugin.cc, line 4 "#include gazeb/gazebo.hh".
  2) libvelodyne_plugin.so not found: path format followed in the tutorial should be updated while attaching plugin. filename="./libvelodyne_plugin.so"
  
	
	
Overview:
1)Model Creation
	a)Basic SDF
	b)Adding Inertia
	c)Adding the joints
	d)Adding Sensor (Ray: Scan and Range)
	e)Mesh Acquisition
	
2)Adding sensor noise

3)Writing a control plugin
