/******************************************************************************
 * BSD 3-Clause License
 *
 * Copyright (C) 2018, Rohith Jayarajan
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Stanford University or Willow Garage, Inc. nor the
 * names of its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/
/**
 *  @file    roomba_walker.hpp
 *  @author  rohithjayarajan
 *  @date 11/18/2018
 *  @version 1.0
 *
 *  @brief header file for RoombaWalker class
 *
 *  @section DESCRIPTION
 *
 *  header file for roomba_walker which contains the declaration of RoombaWalker
 * class
 *
 */

#ifndef INCLUDE_TURTLEBOT_ROOMBA_WALKER_ROOMBA_WALKER_HPP_
#define INCLUDE_TURTLEBOT_ROOMBA_WALKER_ROOMBA_WALKER_HPP_
// C++ header
// #include <cmath>
// #include <sstream>
// #include <string>
#include "geometry_msgs/Twist.h"
// ROS header
#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"

/**
 * @brief the declaration of RoombaWalker class
 *
 * Declaration of the variable and methods of RoombaWalker class
 */
class RoombaWalker
{
private:
  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the
   * last NodeHandle destructed will close down the node.
   */
  ros::NodeHandle nh;
  // declare variable to hold message to be published
  geometry_msgs::Twist twistMsg_;
  // create subscriber for laserscan topic messages
  ros::Subscriber laserScan_;
  // create publisher to advertise messages to command motion of turtlebot
  ros::Publisher vel_;
  // declare variable to hold fixed value of linear velocity
  double linearVel_;
  // declare variable to hold fixed value of angular velocity
  double angularVel_;
  // declare variable to hold distance threshold for a collision threat
  double minDist_;
  // declare variable to check if collision threat exists
  bool isCollision_;
  // declare variable which tells closest distance to potential collision
  double collisionDist_;
  // declare variable to set publishing rate
  double frequency_;

public:
  /**
   *   @brief Default constructor for RoombaWalker
   *
   *   @param nothing
   *   @return nothing
   */
  RoombaWalker();
  /**
   *   @brief Default destructor for RoombaWalker
   *
   *   @param nothing
   *   @return nothing
   */
  ~RoombaWalker();
  /**
   *   @brief callback function for to monitor collision threat based on laser
   * scan messages
   *
   *   @param boost shared pointer to sensor_msgs::LaserScan
   *   @return nothing
   */
  void laserCallback(const sensor_msgs::LaserScan::ConstPtr &msg);
  /**
   *   @brief function to perform random walk exploration of the robot
   *
   *   @param nothing
   *   @return nothing
   */
  void startExploration();
};

#endif // INCLUDE_TURTLEBOT_ROOMBA_WALKER_ROOMBA_WALKER_HPP_
