/****************************************************************************
 * Copyright (c) 2024 PX4 Development Team.
 * SPDX-License-Identifier: BSD-3-Clause
 ****************************************************************************/

#pragma once

#include <Eigen/Eigen>
#include <px4_msgs/msg/vehicle_torque_setpoint.hpp>
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
class OdometryTorqueSetpoint : public Subscription<px4_msgs::msg::VehicleTorqueSetpoint>
{
public:
  explicit OdometryTorqueSetpoint(Context & context);

  /**
   * @brief Get the vehicle's torque setpoint.
   *
   * @return the xyz torque setpoint
   */
  Eigen::Vector3f torque_setpoint() const
  {
    const px4_msgs::msg::VehicleTorqueSetpoint & torque_sp = last();
    return Eigen::Vector3f{torque_sp.xyz[0], torque_sp.xyz[1], torque_sp.xyz[2]};
  }
};

/** @}*/
} /* namespace px4_ros2 */
