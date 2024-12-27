#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
using std::placeholders::_1;

class harurobo : public rclcpp::Node
{
  public:
    harurobo()
    : Node("harurobo")
    {
      subscription_ = this->create_subscription<std_msgs::msg::Joy>(
      "joy", 10, std::bind(&harurobo::topic_callback, this, _1));
    }

  private:
    void topic_callback(const std_msgs::msg::Joy & msg) const
    {
      
    }
    rclcpp::Subscription<std_msgs::msg::Joy>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<harurobo>());
  rclcpp::shutdown();
  return 0;
}