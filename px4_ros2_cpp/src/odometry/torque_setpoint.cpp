/****************************************************************************
 * Copyright (c) 2023 PX4 Development Team.
 * SPDX-License-Identifier: BSD-3-Clause
 ****************************************************************************/

#include <px4_ros2/odometry/torque_setpoint.hpp>

namespace px4_ros2
{

OdometryTorqueSetpoint::OdometryTorqueSetpoint(Context & context)
: Subscription<px4_msgs::msg::VehicleTorqueSetpoint>(context, "fmu/out/vehicle_torque_setpoint")
{
  RequirementFlags requirements{};
  requirements.attitude = true;
  context.setRequirement(requirements);
}

} // namespace px4_ros2
