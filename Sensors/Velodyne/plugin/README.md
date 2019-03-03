inside this folder, run the following:


mkdir build
cd build
cmake ..
make

Inside the build folder,after the shared object file has been created run:
gazebo --verbose ../velodynePluginTest.world 
