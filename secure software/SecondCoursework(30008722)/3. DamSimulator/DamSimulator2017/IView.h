#pragma once
#include "ISubject.h"
#include <string>
#include "SecureInts.h"

enum class UserInteraction;
struct Time;
namespace Users
{
   enum class Role;
   class User;
}
namespace Logger
{
   enum class Type;
   enum class Format;
}

class IView : public ISubject
{
public:
   virtual ~IView() {}
   virtual void Start() = 0;
   virtual void ForceRefresh() = 0;

   virtual void SetTime(Time& time) = 0;
   virtual void SetUsername(const std::string& username) = 0;
   virtual void SetIsAuthenicated(const bool isAuthenticated) = 0;
   virtual void SetRole(const Users::Role& role) = 0;

   virtual void SetPrecipitation(const bool precipitation) = 0;
   virtual void SetEnergyDemand(const int32_s& energyDemand) = 0;
   virtual void SetEnergyOutput(const int32_s& energyOutput) = 0;
   virtual void SetSpillway(const bool spillway) = 0;
   virtual void SetWaterLevel(const int32_s& waterLevel) = 0;
   virtual void SetMaxWaterLevel(const int32_s& maxWaterLevel) = 0;
   virtual void SetValveRelease(const int32_s& valveRelease) = 0;

   virtual void SetPrecipitationAccess(const bool precipitationAccess) = 0;
   virtual void SetEnergyDemandAccess(const bool energyDemandAccess) = 0;
   virtual void SetEnergyOutputAccess(const bool energyOutputAccess) = 0;
   virtual void SetSpillwayAccess(const bool spillwayAccess) = 0;
   virtual void SetWaterLevelAccess(const bool waterLevelAccess) = 0;
   virtual void SetMaxWaterLevelAccess(const bool maxWaterLevelAccess) = 0;
   virtual void SetValveReleaseAccess(const bool valveReleaseAccess) = 0;

   virtual UserInteraction GetUserInteraction() = 0;

   virtual int32_s GetValveReleaseInput() const = 0;
   virtual Logger::Type GetLoggerOutputInput() const = 0;
   virtual Logger::Format GetLoggerFormatInput() const = 0;
   virtual std::string GetUsernameInput() const = 0;
   virtual std::string GetPasswordInput() = 0;
   virtual std::string GetUpdateRoleUsernameInput() const = 0;
   virtual Users::Role GetUpdateRoleInput() const = 0;
};