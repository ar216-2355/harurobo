#include "robomas_plugins/msg/robomas_frame.hpp"
#include "robomas_plugins/msg/robomas_target.hpp"

robomas_plugins::msg::RobomasFrame mode_setting(uint8 motor_number, uint8 motor_mode){
    robomas_plugins::msg::RobomasFrame meesage;
    message.motor = motor_number//mo-ta- bango 0 1 2 
    message.c620 = false; //610 ka 620 ka
    message.mode = motor_mode; //0 dis , 1 vel(sokudo)
    message.temp = 50; //ondo50doijo de tomaru
    message.velkp = 0.15; //p
    message.velki = 9; //i
    message.poskp = 0.5; //itiseigyo 
    message.tyoku_vel_target = 0; //0
    message.tyoku_pos_target = 0;
    message.stable_pos_limit_vel = 0;
    
    return message;
}


robomas_plugins::msg::RobomasTarget moter(){
// -943 ~ 943 943 ha dekasugiru


}