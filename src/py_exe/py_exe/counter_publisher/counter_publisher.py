
import rclpy
from rclpy.node import Node

from msg_interfaces.msg import Counter

from py_pkg.counter_msg_creator import CounterMsgCreator

class CounterPublisher(Node):
    def __init__(self):
        super().__init__('counter_publisher')

        self.publisher_ = self.create_publisher(Counter, 'counter', 10)
        self.counter_msg_creator_ = CounterMsgCreator('counter_publisher')

        self.timer_ = self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        msg = self.counter_msg_creator_.create()
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "{0}"'.format(msg))
