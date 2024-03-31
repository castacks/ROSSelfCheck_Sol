
#include <memory>

#include <rclcpp/rclcpp.hpp>

#include "cpp_exe/cpp_exe_class.hpp"

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CounterSubsriber>());
    rclcpp::shutdown();
    return 0;
}
