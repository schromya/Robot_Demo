#!/usr/bin/env python3
import tkinter as tk

import rclpy
from rclpy.node import Node

import threading

from robot_sim_gui.RobotSimCanvas import RobotSimCanvas
from custom_msgs_srvs.msg import DrivePower, IRSensorData
from custom_msgs_srvs.srv import LightStatus, ContinuationStatus

import math
import random
import os
from copy import deepcopy

class RobotSimGui(Node):
    def __init__(self):

        super().__init__('robot_sim_gui')

               
        #Setting up Publishers
        self.ir_publisher = self.create_publisher(IRSensorData, '/robot/ir_sensor', 1)

        #setting up subscribers
        self.powerSubscriber = self.create_subscription(DrivePower, '/robot/drive_power', self.setRobotPower, 1)
        
        #Setting up service
        self.light_service = self.create_service(LightStatus, '/robot/status_light', self.processLight)  
        self.continuation_service = self.create_service(ContinuationStatus, '/robot/continuation',  self.processContinuation)
        self.resp = ContinuationStatus.Response()

        self.start_tkinter()

        self.can_continue = False
        self.counter = 0
        timer_period = 0.1 # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        
    def wait_before_next_target(self, duration):
        self.timer.cancel()  # Stop the main timer during the wait
        self.get_logger().info(f"Waiting for {duration} seconds before placing being able to continue.")
        self.wait_timer = self.create_timer(duration, self.wait_callback)

    def wait_callback(self):
        #self.get_logger().info("Wait period finished. Placing new target.")
        self.wait_timer.cancel()  # Cancel the wait timer
        
 
        self.resetContinue()
        
        self.timer.reset()  # Restart the main timer
    
    #Main Timer`
    def timer_callback(self):
        currTargetPos = deepcopy(self.robotSimCanvas.getTargetPos()) # copy-on-read to avoid race condition
        currRobotPos = self.robotSimCanvas.getRobotPos()

        if currTargetPos == [None, None]:
            return
        

        distToTarget = math.sqrt((currTargetPos[0] - currRobotPos[0]) ** 2 + (currTargetPos[1] - currRobotPos[1]) ** 2)
        if distToTarget < 100 and self.robotSimCanvas.getReachedTarget():
           
            self.can_continue = False
#           Move target but wait 3 seconds           
            self.robotSimCanvas.removeTarget()
            self.placeTargetRandom()
            self.wait_before_next_target(3.0)  # 3 seconds wait            


        self.publishIRMessage()

    #Second Timer
    def resetContinue(self):
        self.can_continue = True
        self.counter += 1
        print('CONTINUING...')
        print(f'COMPLETE WITH {self.counter} TARGETS')
        self.get_logger().info('CONTINUING...')
        self.get_logger().info(f'COMPLETE WITH {self.counter} TARGETS')

    # Set drive power
    def setRobotPower(self, msg: DrivePower):
        if not self.robotSimCanvas.getReachedTarget():
            self.robotSimCanvas.updateRobotSpeeds([msg.left_power, msg.right_power])
        else:
            self.robotSimCanvas.updateRobotSpeeds([0,0])


    # Process placing/hitting targets
    def placeTargetRandom(self):
        self.robotSimCanvas.addTarget(random.randint(150,self.robotSimCanvas.canvas.winfo_width()-150), random.randint(150,self.robotSimCanvas.canvas.winfo_height()-150))

    def processLight(self, request, response):
        #print(f'HEAD MSG {request.light_status}')
        if request.light_status == 0: 
            self.robotSimCanvas.status_light.setReachedTarget()
        else:
            self.can_continue = False
            self.robotSimCanvas.status_light.setNavigatingToTarget()
        return response
    

    def processContinuation(self, request, response):
        response.can_continue = self.can_continue
        return response

    # Publish sensing messages
    def publishIRMessage(self):
        startingMessage = [math.inf] * 180
        currTargetPos = deepcopy(self.robotSimCanvas.getTargetPos()) # copy-on-read to avoid race condition
        currRobotPos = self.robotSimCanvas.getRobotPos()

        # If there's no target, publish empty message
        if None in currTargetPos:
            self.ir_publisher.publish(IRSensorData(distances=startingMessage))
            return

        dY = currRobotPos[0] - currTargetPos[0]
        dX = currRobotPos[1] - currTargetPos[1]
        absAngle = math.degrees(math.atan2(dY, dX))
        relAngle = (((absAngle - (self.robotSimCanvas.getRobotOrientation()))+ 540) % 360) - 180

        # Get distance
        if abs(relAngle) < 90:
            ind = 90 - int(relAngle)
            startingMessage[ind] = math.sqrt((currTargetPos[0] - currRobotPos[0]) ** 2 + (currTargetPos[1] - currRobotPos[1]) ** 2)
        # Publish final message
        self.ir_publisher.publish(IRSensorData(distances=startingMessage))

    def start_tkinter(self):
         # Set up canvas
        self.window = tk.Tk()
        
        self.window.geometry(f'{self.window.winfo_screenwidth()}x{self.window.winfo_screenheight()}')
        
        resource_path = f'{os.getcwd()}/src/robot_sim_gui/resource/'
        
        self.robotSimCanvas = RobotSimCanvas(self.window, self.window.winfo_screenwidth(), self.window.winfo_screenheight(), resource_path, robot_init_x=300, robot_init_y=500)
        self.placeTargetRandom()
    
    # Stop Tk on ROS shutsdown
    def stopTk(self):
        print("Endings")
        self.window.quit()

def main(args = None):
    rclpy.init(args=args)

    rover_gui = RobotSimGui()
        # Start ROS2 spinning in the main thread
    t1 = threading.Thread(target=lambda: rclpy.spin(rover_gui))
    t1.start()

    rover_gui.window.mainloop()

    rover_gui.destroy_node()
    rover_gui.stopTk()
    rclpy.shutdown()
    
    
    

if __name__ == '__main__':
    main()
