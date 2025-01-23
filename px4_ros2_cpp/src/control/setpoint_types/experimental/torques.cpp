/****************************************************************************
 * Copyright (c) 2023 PX4 Development Team.
 * SPDX-License-Identifier: BSD-3-Clause
 ****************************************************************************/

#include <px4_ros2/control/setpoint_types/experimental/torques.hpp>


namespace px4_ros2
{

TorqueSetpointType::TorqueSetpointType(Context & context)
: SetpointBase(context), _node(context.node())
{
  _vehicle_torque_setpoint_pub =
    context.node().create_publisher<px4_msgs::msg::VehicleTorqueSetpoint>(
    context.topicNamespacePrefix() + "fmu/in/vehicle_torque_setpoint", 1);
}

void TorqueSetpointType::update(
  const Eigen::Vector3f & torque_setpoints_ned_rad)
{
  onUpdate();

  px4_msgs::msg::VehicleTorqueSetpoint sp{};
  sp.xyz[0] = torque_setpoints_ned_rad(0);
  sp.xyz[1] = torque_setpoints_ned_rad(1);
  sp.xyz[2] = torque_setpoints_ned_rad(2);
  sp.timestamp = _node.get_clock()->now().nanoseconds() / 1000;
  _vehicle_torque_setpoint_pub->publish(sp);
}

SetpointBase::Configuration TorqueSetpointType::getConfiguration()
{
  Configuration config{};
  config.manual_enabled = true;
  config.rates_enabled = true;
  config.attitude_enabled = true;
  config.altitude_enabled = true;
  config.climb_rate_enabled = true;
  config.acceleration_enabled = false;
  config.velocity_enabled = true;
  config.position_enabled = true;
  config.multicopter_position_control_enabled = true;
  return config;
}
} // namespace px4_ros2
