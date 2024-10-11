# WRover_Playground_ROS2

 Let’s first get the simulation running. Here are the steps:
 
- Open a new terminal and navigate to WRPlayTemp

- run `colcon build`
  
- Open a new terminal and source your workspace with “source install/local_setup.bash”. NOTE: I've been running `source install/setup.bash` instead.

  
- Now you can run `ros2 run robot_sim_gui gui` to run the gui.py file that should start the simulation. If the robot and beacon show up without moving then it is correct.

## TASK 1:

Create a new package for controlling the robot. In that new package, make a new file that contains a node that will publish to the topic that makes the robot move. For now, you can publish any value. Your goal is to make the robot move.
**Documentation**
First I looked to see what topics and messages were available to publish to while the gui was running:
```bash
# See what topics are running
$ ros2 topic list
/parameter_events
/robot/drive_power
/robot/ir_sensor
/rosout

# Check messages for drive_power
$ ros2 topic info /robot/drive_power
Type: custom_msgs_srvs/msg/DrivePower
Publisher count: 0
Subscription count: 1

# Check message format for DrivePower:
$ ros2 interface show custom_msgs_srvs/msg/DrivePower
float64 left_power
float64 right_power
```


I tested publishing in the command line first:
```bash
ros2 topic pub /robot/drive_power custom_msgs_srvs/msg/DrivePower "{left_power: 10, right_power: 10}"
```
Then to create my package, I followed the  [this doc](https://docs.ros.org/en/jazzy/Tutorials/Beginner-Client-Libraries/Writing-A-Simple-Py-Publisher-And-Subscriber.html) to create a project and script.

After this I modified the publisher_member_function.py to actually publish movement.


Then to run the code, I did the following:
```bash
# Make sure to be in WRPlay
rosdep install -i --from-path src --rosdistro jazzy -y
colcon build
source install/setup.bash

ros2 run move_bot_sub talker  # Yaya this started
```
## TASK 2: 
	There is a topic that gives you sensor data for the rover called “/robot/ir_sensor.” This works like an Infrared Sensor that provides a list with 180 data points going from 9 o’ clock to 3 o’clock going clockwise. Subscribe to this data to drive towards the beacon. Your goal is to reach the target.

I modified code and kept on using `ros2 run move_bot_sub talker`.

## TASK 3:
	In the real world, we need the robot to notify us that it has reached the target. You are going to use services to accomplish this task. There are two services already set up in gui.py. LightStatus and ContinuationStatus. You need to first make a client to the LightStatus service to say that you are DONE when you are within 100 units of the beacon. Then, you will continuously poll the ContinuationsStatus service until the canComplete message is True. Once then, you can continue to the next beacon. It is highly recommended to check gui.py to see how the services work so you can implement the clients correctly. Your goal is for the robot to keep going and arriving at targets until you close the program. 

	First I looked to see what topics and messages were available to publish to while the gui was running:
```bash
# See what topics are running
$ ros2 service list
/robot/continuation
/robot/status_light
/robot_sim_gui/describe_parameters
/robot_sim_gui/get_parameter_types
/robot_sim_gui/get_parameters
/robot_sim_gui/get_type_description
/robot_sim_gui/list_parameters
/robot_sim_gui/set_parameters
/robot_sim_gui/set_parameters_atomically

# Check messages for continuation and  status_light
$ ros2 service info  /robot/continuation
Type: custom_msgs_srvs/srv/ContinuationStatus
Clients count: 0
Services count: 1

$ ros2 service info  /robot/status_light
Type: custom_msgs_srvs/srv/LightStatus
Clients count: 0



# Check message format :

$ ros2 interface show custom_msgs_srvs/srv/ContinuationStatus
bool nada
---
bool can_continue


$ ros2 interface show custom_msgs_srvs/srv/LightStatus
int8 DONE = 0
int8 NOT_DONE = 1
int8 light_status

```
I modified code and kept on using `ros2 run move_bot_sub talker`.

## TASK 4: (Extra)
	Use PID controls to arrive at the target more effectively. You can also try to implement turning PID but that might be a little overkill.

I modified code to use P and kept on using `ros2 run move_bot_sub talker`.


FOR HELP:
	Always refer to these tutorials ( https://docs.ros.org/en/jazzy/Tutorials/Beginner-Client-Libraries.html) as well as the internet, software members, and leads. (Other code in the project can also be helpful).


# Docs
https://docs.ros.org/en/jazzy/Tutorials/Beginner-Client-Libraries/Custom-ROS2-Interfaces.html

