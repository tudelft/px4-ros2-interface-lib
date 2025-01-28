/****************************************************************************
 * Copyright (c) 2024 PX4 Development Team.
 * SPDX-License-Identifier: BSD-3-Clause
 ****************************************************************************/

#pragma once

#include <Eigen/Eigen>
#include <px4_msgs/msg/vehicle_rates_setpoint.hpp>
#include <px4_ros2/common/context.hpp>
#include <px4_ros2/odometry/subscription.hpp>
#include <px4_ros2/utils/geometry.hpp>

namespace px4_ros2
{
/** \ingroup odometry
 *  @{
 */

/**
 * @brief Provides access to the vehicle's rate setpoint
 */
class OdometryRateSetpoint : public Subscription<px4_msgs::msg::VehicleRatesSetpoint>
{
public:
  explicit OdometryRateSetpoint(Context & context);

  /**
   * @brief Get the vehicle's rate setpoint.
   *
   * @return the xyz rate setpoints
   */
  Eigen::Vector3f rate_setpoint() const
  {
    const px4_msgs::msg::VehicleRatesSetpoint & rate_sp = last();
    return Eigen::Vector3f{rate_sp.roll, rate_sp.pitch, rate_sp.yaw};
  }
};

/** @}*/
} /* namespace px4_ros2 */
