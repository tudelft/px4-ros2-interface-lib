/****************************************************************************
 * Copyright (c) 2024 PX4 Development Team.
 * SPDX-License-Identifier: BSD-3-Clause
 ****************************************************************************/

#pragma once

#include <Eigen/Eigen>
#include <px4_msgs/msg/vehicle_attitude_setpoint.hpp>
#include <px4_ros2/common/context.hpp>
#include <px4_ros2/odometry/subscription.hpp>
#include <px4_ros2/utils/geometry.hpp>

namespace px4_ros2
{
/** \ingroup odometry
 *  @{
 */

/**
 * @brief Provides access to the vehicle's attitude setpoint
 */
class OdometryAttitudeSetpoint : public Subscription<px4_msgs::msg::VehicleAttitudeSetpoint>
{
public:
  explicit OdometryAttitudeSetpoint(Context & context);

  /**
   * @brief Get the vehicle's attitude setpoint.
   *
   * @return the attitude euler angles
   */
  Eigen::Vector3f attitude_setpoint() const
  {
    const px4_msgs::msg::VehicleAttitudeSetpoint & att_sp = last();
    return Eigen::Vector3f{att_sp.roll_body, att_sp.pitch_body, att_sp.yaw_body};
  }

  /**
   * @brief Get the vehicle's yawrate setpoint.
   *
   * @return the yawrate setpoint in rad/s
   */
  float yawrate_setpoint() const
  {
    const px4_msgs::msg::VehicleAttitudeSetpoint & att_sp = last();
    return att_sp.yaw_sp_move_rate;
  }

  /**
   * @brief Get the vehicle's thrust setpoint.
   *
   * @return the thrust vector
   */
  Eigen::Vector3f thrust_body() const
  {
    const px4_msgs::msg::VehicleAttitudeSetpoint & att_sp = last();
    return Eigen::Vector3f{att_sp.thrust_body[0], att_sp.thrust_body[1], att_sp.thrust_body[2]};
  }

  /**
   * @brief Get the vehicle's roll in extrinsic RPY order.
   *
   * @return the attitude roll in radians within [-pi, pi]
   */
  float roll_sp() const
  {
    return attitude_setpoint()[0];
  }

  /**
   * @brief Get the vehicle's pitch in extrinsic RPY order.
   *
   * @return the attitude pitch in radians within [-pi, pi]
   */
  float pitch_sp() const
  {
    return attitude_setpoint()[1];
  }

  /**
   * @brief Get the vehicle's yaw in extrinsic RPY order.
   *
   * @return the attitude yaw in radians within [-pi, pi]
   */
  float yaw_sp() const
  {
    return attitude_setpoint()[2];
  }
};

/** @}*/
} /* namespace px4_ros2 */
