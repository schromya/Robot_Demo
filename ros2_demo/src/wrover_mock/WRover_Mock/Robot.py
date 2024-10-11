
import rclpy, std_msgs, geometry_msgs
from rclpy.node import Node
from WRover_Mock.AbstractRobot import Robot
from geometry_msgs.msg import Pose2D
from std_msgs.msg import Float64


class Rover(Node):

    def __init__(self):
        super().__init__('rover')

        #setting up subscribers
        self.left_subscriber = self.create_subscription(
            Float64,
            'rover/cmd/left',
            self.set_left,
            10)
        self.right_subscriber = self.create_subscription(
            Float64,
            'rover/cmd/right',
            self.set_right,
            10)

        #Setting up Publishers
        self.left_enc_publisher = self.create_publisher( Float64,'rover/enc/left', 10)
        self.right_enc_publisher = self.create_publisher( Float64,'rover/enc/left', 10)
        self.gyro_publisher = self.create_publisher( Float64, 'rover/gyro', 10)
        self.pose_publisher = self.create_publisher(Pose2D,'rover/pose',  10) # top secret - do not subscribe!

        #setting up timer to publish.timer_call
        timer_period = 1/hz  # seconds (executes every .05 seconds if hz is 20)
        self.timer = self.create_timer(timer_period, self.timer_callback)
    
    def timer_callback(self):
        rover.update()
        self.left_enc_publisher.publish((rover.getLeftDistance()))
        self.right_enc_publisher.publish((rover.getRightDistance()))
        self.gyro_publisher.publish((rover.getHeading()))

        pose = Pose2D()
        pose.x = rover.x
        pose.y = rover.y
        pose.theta = rover.theta
        self.pose_publisher.publish(pose)

    def set_left(self, msg): rover.setLeft(msg.data)

    def set_right(self, msg): rover.setRight(msg.data)

def main(args = None):
    rclpy.init(args=args)

    rover = Rover()

    rclpy.spin(rover)

    #Kill program after ending
    rover.destroy_node()
    rclpy.shutdown()

hz = 20
rover = Robot(
    wheelBase = 50,
    maxVelocity = 1000/hz,
    acceleration = 10000,
)


if __name__ == '__main__':
    main()