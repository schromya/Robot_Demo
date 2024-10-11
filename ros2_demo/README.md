# URC

## Setup

First set up display forwarding:
```bash
cd ros2_demo
xhost +local:
```

Now  build the container image and start the container. Make sure you are in this directories root directory (NIST_Benchmark). These commands use the current directory as the containers file system so any changes you make to the files on your host machine will be mirrored in the container. TJese commands also allow the containers display to be forwarded to your host machine so that you can see it.
```bash
sudo docker build -t urc-container .
sudo docker run -it --env DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -v $(pwd):/workspace --net=host urc-container
```

```bash
source /opt/ros/jazzy/setup.bash
cd workspace
colcon build
source install/setup.bash
```

## Running
```bash
ros2 run robot_sim_gui gui

# In another terminal do the following
ros2 topic pub -1 /robot/drive_power custom_msgs_srvs/msg/DrivePower "{left_power: 1, right_power: 1}"
```


Other useful commands:
```bash
ros2 topic list
ros2 topic info /robot/drive_power
ros2 interface show custom_msgs_srvs/msg/DrivePower
```

## Notes
* To open another docker terminal for a running container, run the following on your home-machine:
```bash
# Show your running CONTAINER_ID
docker ps 

# Open another terminal using that CONTAINER_ID
docker exec -it  <YOUR_CONTAINER_ID> bash

# Source ROS properly
source /opt/ros/jazzy/setup.sh
cd workspace
source install/setup.bash
```