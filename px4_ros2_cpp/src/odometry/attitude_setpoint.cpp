/****************************************************************************
 * Copyright (c) 2023 PX4 Development Team.
 * SPDX-License-Identifier: BSD-3-Clause
 ****************************************************************************/

#include <px4_ros2/odometry/attitude_setpoint.hpp>

namespace px4_ros2
{

OdometryAttitudeSetpoint::OdometryAttitudeSetpoint(Context & context)
: Subscription<px4_msgs::msg::VehicleAttitudeSetpoint>(context, "fmu/out/vehicle_attitude_setpoint")
{
  RequirementFlags requirements{};
  requirements.attitude = true;
  context.setRequirement(requirements);
}

} // namespace px4_ros2
