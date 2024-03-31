
#include <iostream>
#include <functional>
#include <memory>
#include <sstream>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include "msg_interfaces/msg/counter.hpp"

#include "cpp_header_lib/counter_manipulator_header.hpp"
#include "cpp_lib/random_matrix.hpp"

using std::placeholders::_1;

class CounterSubsriber : public rclcpp::Node
{
public:
    CounterSubsriber() : Node("counter_subscriber") {
        sub_ = this->create_subscription<msg_interfaces::msg::Counter>(
            "counter", 10, std::bind(&CounterSubsriber::counter_callback, this, _1));
    }

private:
    void counter_callback(const msg_interfaces::msg::Counter::SharedPtr msg) const {
        RCLCPP_INFO(this->get_logger(), "I heard: [%d]", msg->count);

        const int increased = counter_manipulator_.get_increased_value(*msg);

        RCLCPP_INFO(this->get_logger(), "Increased value: [%d]", increased);

        const Eigen::MatrixXd random_matrix = 
            random_matrix_generator_.generate_random_matrix(3, 3);

        std::stringstream ss;
        ss << random_matrix;

        RCLCPP_INFO(this->get_logger(), 
            "Random matrix: \n%s", 
            ss.str().c_str() );
    }

    rclcpp::Subscription<msg_interfaces::msg::Counter>::SharedPtr sub_;
    counter::CounterManipulatorHeader<msg_interfaces::msg::Counter> counter_manipulator_;
    ros_selfcheck::RandomMatrixGenerator random_matrix_generator_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CounterSubsriber>());
    rclcpp::shutdown();
    return 0;
}