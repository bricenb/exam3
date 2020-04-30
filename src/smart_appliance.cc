/* Copyright 2020 Bricen Bennett csce240 */

#include <inc/smart_appliance.h>
#include <iostream>
using std::cout;
using std::endl;

namespace exam3 {

SmartAppliance::~SmartAppliance() {}

SmartLight::~SmartLight() {}

const std::string SmartLight::Activate() {
  if (!state) {
     state = true;
    return "Light activated";
  } else {
    return "Light active";
  }
  return "";
}

const std::string SmartLight::Deactivate() {
  if (!state) {
    return "";
  } else {
    state = false;
    return "Light deactivated";
  }
}

const std::string SmartLight::Set(unsigned int setting) {
  if (state) {
    if (setting > 0 && !on) {
      on = true;
      return "Light set from off to on";
    }
    if (setting > 0 && on) {
      return "Light set on";
    }
    if (setting == 0 && !on) {
      return "Light set off";
    }
    if (setting == 0 && on) {
      on  = false;
      return "Light set from on to off";
    }
    } else {
      return "";
    }
  return "";
  }

SmartThermostat::~SmartThermostat() {}

const std::string SmartThermostat::Activate() {
  if (!temp) {
    temp = true;
    return "Thermostat activated";
  } else if (temp) {
    return "Thermostat active";
  } else {
    return "";
  }
}

const std::string SmartThermostat::Deactivate() {
  if (temp == false) {
    return "";
  } else if (temp == true) {
    temp = false;
    return "Thermostat deactivated";
  }
  return "";
}

const std::string SmartThermostat::Set(unsigned int setting) {
  // setting / 100 * 60 + 40
  if (!temp) {
    return "";
  } else {
  setting_temp = ((setting / 100) * 60) + 40;
  if (setting_temp != active_temp) {
    old_temp = active_temp;
    active_temp = setting_temp;
    return "Thermostat set from " + std::to_string(old_temp) + " to " +
                                    std::to_string(active_temp);
  } else if (setting_temp  == active_temp) {
    return "Thermostat set to " + std::to_string(setting_temp);
  } else {
    return "";
    }
  }
  return "";
}
}  // namespace exam3
