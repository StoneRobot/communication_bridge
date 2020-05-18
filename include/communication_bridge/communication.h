#pragma once
#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/UInt8MultiArray.h>
#include <std_msgs/UInt16MultiArray.h>

#include "rb_srvs/rb_ArrayAndBool.h"
#include "rb_srvs/rb_DoubleBool.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
using namespace std;
 

class Communication
{
private:
    ros::Subscriber rbConnCommand;
    ros::Subscriber rbRunCommand;
    ros::Subscriber ruStopCommand;
public:
    bool checkNet(std::string);
    bool checkAllNect();
    bool stopCommand();
    Communication(/* args */);
    ~Communication();
};

Communication::Communication(/* args */)
{
}

Communication::~Communication()
{
}
