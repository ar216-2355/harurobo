// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <sensor_msgs/msg/joy.hpp>

#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "robomas_plugins/msg/robomas_frame.hpp"
#include "robomas_plugins/msg/robomas_target.hpp"
//#include "std_msgs/msg/string.hpp"

#include "harurobo.hpp"

using std::placeholders::_1;

class My_Node1 : public rclcpp::Node
{
public:
  My_Node1()
  : Node("joy_subscriber")
  {
    subscription_ = this->create_subscription<std_msgs::msg::Joy>(
      "joy", 10, std::bind(&My_Node1::topic_callback, this, _1));
    setting_pub = this->create_publisher<robomas_plugins::msg::RobomasFrame>("robomas_frame", 10);
    robomas1_pub = this->create_publisher<robomas_plugins::msg::RobomasTarget>("robomas_target0", 10);
    robomas2_pub = this->create_publisher<robomas_plugins::msg::RobomasTarget>("robomas_target1", 10);
    robomas3_pub = this->create_publisher<robomas_plugins::msg::RobomasTarget>("robomas_target2", 10);
  }

private:
  void topic_callback(const std_msgs::msg::Joy & msg) const
  {



    if(msg.buttons[0]){ //A
      setting_pub->publish(mode_setting(0, 1));
    }
    if(msg.buttons[1]){ //B
      setting_pub->publish(mode_setting(1, 1));
    }
    if(msg.buttons[2]){ //x
      setting_pub->publish(mode_setting(2, 1));
    }
    if(msg.buttons[3]){ //y
    
    }
    if(msg.buttons[4]){ //LB
    
    }
    if(msg.buttons[5]){ //RB
    
    }
    if(msg.buttons[6]){ //back
    
    }
    if(msg.buttons[7]){ //start
      auto message = make_mode_vel();
      setting_pub->publish(message);
    }
    if(msg.buttons[8]){ //power
    
    }
    if(msg.buttons[9]){ //Button stick left
    
    }
    if(msg.buttons[10]){ //Button stick right
    
    }
    //msg.axes[0] Left/Right Axis stick left
    //msg.axes[1] Up/Down Axis stick left
    //msg.axes[2] Left/Right Axis stick right
    //msg.axes[3] Up/Down Axis stick right
    //msg.axes[4] RT
    //msg.axes[5] LT
    //msg.axes[6] cross key left/right
    //msg.axes[7] cross key up/down

    setting_pub->publish(message);
    robomas1_pub->publish(message);
    robomas2_pub->publish(message);
    robomas3_pub->publish(message);
  }
  rclcpp::Subscription<std_msgs::msg::Joy>::SharedPtr subscription_;
  rclcpp::Publisher<robomas_plugins::msg::RobomasFrame>::SharedPtr setting_pub;
  rclcpp::Publisher<robomas_plugins::msg::RobomasTarget>::SharedPtr robomas1_pub;
  rclcpp::Publisher<robomas_plugins::msg::RobomasTarget>::SharedPtr robomas2_pub;
  rclcpp::Publisher<robomas_plugins::msg::RobomasTarget>::SharedPtr robomas3_pub;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<My_Node1>());
  rclcpp::shutdown();
  return 0;
}
