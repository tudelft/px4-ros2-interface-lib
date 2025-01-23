/****************************************************************************
 * Copyright (c) 2023 PX4 Development Team.
 * SPDX-License-Identifier: BSD-3-Clause
 ****************************************************************************/

#include <px4_ros2/control/setpoint_types/experimental/thrust.hpp>


namespace px4_ros2
{

ThrustSetpointType::ThrustSetpointType(Context & context)
: SetpointBase(context), _node(context.node())
{
  _vehicle_thrust_setpoint_pub =
    context.node().create_publisher<px4_msgs::msg::VehicleThrustSetpoint>(
    context.topicNamespacePrefix() + "fmu/in/vehicle_thrust_setpoint", 1);
}

void ThrustSetpointType::update(
  const Eigen::Vector3f & thrust_setpoint_frd)
{
  onUpdate();

  px4_msgs::msg::VehicleThrustSetpoint sp{};
  sp.xyz[2] = thrust_setpoint_frd(2);
  sp.timestamp = _node.get_clock()->now().nanoseconds() / 1000;
  _vehicle_thrust_setpoint_pub->publish(sp);
}

SetpointBase::Configuration ThrustSetpointType::getConfiguration()
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
