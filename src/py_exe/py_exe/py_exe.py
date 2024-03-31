
import rclpy

from py_exe.counter_publisher import CounterPublisher

def main(args=None):
    rclpy.init(args=args)

    counter_publisher = CounterPublisher()

    rclpy.spin(counter_publisher)

    counter_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
    