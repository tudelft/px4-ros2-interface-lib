/****************************************************************************
 * Copyright (c) 2023 PX4 Development Team.
 * SPDX-License-Identifier: BSD-3-Clause
 ****************************************************************************/

#pragma once

#include <px4_msgs/msg/vehicle_torque_setpoint.hpp>
#include <Eigen/Core>

#include <px4_ros2/common/setpoint_base.hpp>

namespace px4_ros2
{
/** \ingroup setpoint_types_experimental
 *  @{
 */

/**
 * @brief Setpoint type for direct torque control
*/
class TorqueSetpointType : public SetpointBase
{
public:
  explicit TorqueSetpointType(Context & context);

  ~TorqueSetpointType() override = default;

  Configuration getConfiguration() override;
  float desiredUpdateRateHz() override {return 500.f;}

  void update(
    const Eigen::Vector3f & torque_setpoints_ned_rad);

private:
  rclcpp::Node & _node;
  rclcpp::Publisher<px4_msgs::msg::VehicleTorqueSetpoint>::SharedPtr _vehicle_torque_setpoint_pub;
};

/** @}*/
} /* namespace px4_ros2 */
