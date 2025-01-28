/****************************************************************************
 * Copyright (c) 2023 PX4 Development Team.
 * SPDX-License-Identifier: BSD-3-Clause
 ****************************************************************************/

#include <px4_ros2/odometry/rate_setpoint.hpp>

namespace px4_ros2
{

OdometryRateSetpoint::OdometryRateSetpoint(Context & context)
: Subscription<px4_msgs::msg::VehicleRatesSetpoint>(context, "fmu/out/vehicle_rates_setpoint")
{
  RequirementFlags requirements{};
  requirements.attitude = true;
  context.setRequirement(requirements);
}

} // namespace px4_ros2
