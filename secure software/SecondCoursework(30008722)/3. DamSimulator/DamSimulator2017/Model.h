#pragma once
#include "ISubject.h"
#include "Time.h"
#include "World.h"
#include "User.h"
#include <memory>
#include "XMLFormat.h"
#include "LoggerTypes.h"
#include "Authenticator.h"
#include "SecureInts.h"
#include "Permission.h"
#include "Role.h"

#include "WaterLevelSensor.h"
#include "MaxWaterLevelSensor.h"
#include "PrecipitationSensor.h"
#include "EnergyOutputSensor.h"
#include "EnergyDemandSensor.h"
#include "SpillwaySensor.h"
#include "ValveReleaseActuator.h"

class Model : public ISubject
{
public:
   Model();
   ~Model();
   void Start();

   Time GetTime() const { return m_world.GetTime(); }

   bool GetIsAuthenticated() const { return m_user.GetIsAuthenticated(); }
   std::string GetUsername() const { return m_user.GetUsername(); }
   Users::Role GetRole() const { return m_permission.GetRole(m_user); }

   void SetLogger(const Logger::Type& type, const Logger::Format& format);
   void AuthenticateUser(const std::string& username, const std::string& password);
   void UpdateRole(const std::string& username, const Users::Role& role);

   //Precipitation sensor.
   bool GetPrecipitation() const;
   bool GetPrecipitationAccess() const;

   //Energy demand sensor.
   int32_s GetEnergyDemand() const;
   bool GetEnergyDemandAccess() const;

   //Energy output sensor.
   int32_s GetEnergyOutput() const;
   bool GetEnergyOutputAccess() const;

   //Spillway sensor
   bool GetSpillway() const;
   bool GetSpillwayAccess() const;

   //Water level sensor
   int32_s GetWaterLevel() const;
   bool GetWaterLevelAccess() const;

   //Max water level sensor.
   int32_s GetMaxWaterLevel() const;
   bool GetMaxWaterLevelAccess() const;

   //Valve release actuator
   void SetValveRelease(const int32_s& valveRelease);
   int32_s GetValveRelease() const;
   bool GetValveReleaseAccess() const;

private:
   World m_world;

   const int32_s DEFAULT_INT = -1;
   const bool DEFAULT_BOOL = false;

   //Devices
   PrecipitationSensor m_precipitation;
   EnergyDemandSensor m_energyDemand;
   EnergyOutputSensor m_energyOutput;
   SpillwaySensor m_spillway;
   WaterLevelSensor m_waterLevel;
   MaxWaterLevelSensor m_maxWaterLevel;
   ValveReleaseActuator m_valveRelease;

   //Users
   Users::User m_user;
   Users::Authenticator m_authenticator;
   Users::Permission m_permission;

   //Logger
   const std::string NO_ACCESS = "*****";
   Logger::Type m_loggerOutputType = Logger::Type::None;
   Logger::Format m_loggerFormatType = Logger::Format::None;
   Logger::ILogger* m_logger = nullptr; //#V6_1
};
