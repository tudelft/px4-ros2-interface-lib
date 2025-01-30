/****************************************************************************
 * Copyright (c) 2023 PX4 Development Team.
 * SPDX-License-Identifier: BSD-3-Clause
 ****************************************************************************/

#pragma once

#include <px4_msgs/msg/vehicle_thrust_setpoint.hpp>
#include <Eigen/Core>

#include <px4_ros2/common/setpoint_base.hpp>

namespace px4_ros2
{
/** \ingroup setpoint_types_experimental
 *  @{
 */

/**
 * @brief Setpoint type for direct thrust control
*/
class ThrustSetpointType : public SetpointBase
{
public:
  explicit ThrustSetpointType(Context & context);

  ~ThrustSetpointType() override = default;

  Configuration getConfiguration() override;
  float desiredUpdateRateHz() override {return 500.f;}

  void update(
    const Eigen::Vector3f & thrust_setpoint_frd);

private:
  rclcpp::Node & _node;
  rclcpp::Publisher<px4_msgs::msg::VehicleThrustSetpoint>::SharedPtr _vehicle_thrust_setpoint_pub;
};

/** @}*/
} /* namespace px4_ros2 */
