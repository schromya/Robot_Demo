# Simulating the Bot
In order to simulate the bot using Gazebo and RVIZ, follow the instructions below


## Setup

First set up display forwarding:
```bash
cd ros1_demo
xhost +local:
```

Now  build the container image and start the container. Make sure you are in this directories root directory (NIST_Benchmark). These commands use the current directory as the containers file system so any changes you make to the files on your host machine will be mirrored in the container. TJese commands also allow the containers display to be forwarded to your host machine so that you can see it.
```bash
sudo docker build -t panda-container .
sudo docker run -it --env DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -v $(pwd):/workspace --net=host panda-container
```

Now your container should be running and you should be in it's command line. So in the container's terminal, setup the visualization:
```bash
apt-get update
apt install -y python3-catkin-tools 

cd src/relaxed_ik_ros1/relaxed_ik_core
cargo build
cd /workspace
source /opt/ros/noetic/setup.sh
catkin build
source devel/setup.sh
```

## Running
```bash
roslaunch franka_gazebo panda.launch controller:=joint_variable_impedance_controller rviz:=true

# Run the following in another terminal
rostopic pub -1 /equilibrium_configuration  sensor_msgs/JointState -- '{position: [0, -0.785, 0, -2.356, 0, 1.57, 3.14]}' # Move to default position
rostopic pub -1 /equilibrium_configuration  sensor_msgs/JointState -- '{position: [1, -0.785, 0, -2.356, 0, 1.57, 3.14]}' # Move to another position


####################################################################################
# Joint stiffness
rosrun dynamic_reconfigure dynparam get /dynamic_reconfigure_compliance_param_node # Get joint stiffness
# MAX stiffness:
# {'joint_1': 600.0, 'joint_2': 600.0, 'joint_3': 600.0, 'joint_4': 600.0, 'joint_5': 250.0, 'joint_6': 150.0, 'joint_7': 50.0, 'damping_ratio': 1.0, 'groups': {'id': 0, 'parent': 0, 'name': 'Default', 'type': '', 'state': True, 'groups': {}, 'parameters': {}, 'joint_1': 600.0, 'joint_2': 600.0, 'joint_3': 600.0, 'joint_4': 600.0, 'joint_5': 250.0, 'joint_6': 150.0, 'joint_7': 50.0, 'damping_ratio': 1.0}}


rosrun dynamic_reconfigure dynparam set /dynamic_reconfigure_compliance_param_node "{joint_1: 100, joint_2: 100, joint_3: 100, joint_4: 100, joint_5: 100, joint_6: 100, joint_7: 20}" # Set joint stiffness
```






