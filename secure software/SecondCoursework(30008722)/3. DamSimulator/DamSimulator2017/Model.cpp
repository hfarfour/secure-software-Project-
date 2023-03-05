#include "Model.h"

#include "FileLogger.h"
#include "LoggerFactory.h"
#include "User.h"
#include "SecureConverter.h"

using namespace Users;

Model::Model()
   :
   m_precipitation(m_world),
   m_energyDemand(m_world),
   m_energyOutput(m_world),
   m_spillway(m_world),
   m_waterLevel(m_world),
   m_maxWaterLevel(m_world),
   m_valveRelease(m_world)
{
}

Model::~Model()
{
   if (m_logger != nullptr) //#V6_1
   {
      delete m_logger; //#V3_1
   }
}

void Model::Start()
{
   while (true)
   {
      //Wait for Update cycle.
      if (m_world.Update())
      {
         //Logging
         if (m_loggerOutputType != Logger::Type::None && m_logger != nullptr) //#V6_1
         {
            std::string output;
            output += m_world.GetTime().ToString();
            output += " ";
            output += GetEnergyOutputAccess() ? std::to_string(GetEnergyOutput().GetValue()) : NO_ACCESS;
            output += " ";
            output += GetEnergyDemandAccess() ? std::to_string(GetEnergyDemand().GetValue()) : NO_ACCESS;

            m_logger->Log(output);
         }

         Notify(*this);
      }
   }
}

void Model::AuthenticateUser(const std::string& username, const std::string& password)
{
   m_user = m_authenticator.CreateUser(username, password);

   Notify(*this);
}

void Model::SetLogger(const Logger::Type& outputType, const Logger::Format& formatType)
{
   if(m_loggerOutputType != outputType || m_loggerFormatType != formatType)
   {
      m_loggerOutputType = outputType;
      m_loggerFormatType = formatType;

      if(m_logger != nullptr) //#V6_1
      {
         delete m_logger; //#V3_1
      }

      m_logger = Logger::LoggerFactory::CreateLogger(m_loggerOutputType, m_loggerFormatType);
   }
}

void Model::UpdateRole(const std::string& username, const Users::Role& role)
{
   m_permission.UpdateUserRole(m_user, username, role);

   Notify(*this);
}

void Model::SetValveRelease(const int32_s& valveRelease)
{
   if (GetValveReleaseAccess())
   {
      m_valveRelease.SetValue(valveRelease);
   }
}
int32_s Model::GetValveRelease() const
{
   if (GetValveReleaseAccess())
   {
      return m_valveRelease.GetValue();
   }
   return DEFAULT_INT;
}
bool Model::GetValveReleaseAccess() const
{
   if (m_authenticator.Authenticate(m_user))
   {
      return m_permission.CheckPermission(m_user, m_valveRelease);
   }
   return false;
}

bool Model::GetPrecipitation() const
{
   if (GetPrecipitationAccess())
   {
      return m_precipitation.GetValue();
   }
   return DEFAULT_BOOL;
}
bool Model::GetPrecipitationAccess() const
{
   if (m_authenticator.Authenticate(m_user))
   {
      return m_permission.CheckPermission(m_user, m_precipitation);
   }
   return false;
}

int32_s Model::GetEnergyDemand() const
{
   if (GetEnergyDemandAccess())
   {
      return m_energyDemand.GetValue();
   }
   return DEFAULT_INT;
}
bool Model::GetEnergyDemandAccess() const
{
   if (m_authenticator.Authenticate(m_user))
   {
      return m_permission.CheckPermission(m_user, m_energyDemand);
   }
   return false;
}

int32_s Model::GetEnergyOutput() const
{
   if (GetEnergyOutputAccess())
   {
      return m_energyOutput.GetValue();
   }
   return DEFAULT_INT;
}
bool Model::GetEnergyOutputAccess() const
{
   if (m_authenticator.Authenticate(m_user))
   {
      return m_permission.CheckPermission(m_user, m_energyOutput);
   }
   return false;
}

bool Model::GetSpillway() const
{
   if (GetEnergyOutputAccess())
   {
      return m_spillway.GetValue();
   }
   return DEFAULT_BOOL;
}
bool Model::GetSpillwayAccess() const
{
   if (m_authenticator.Authenticate(m_user))
   {
      return m_permission.CheckPermission(m_user, m_spillway);
   }
   return false;
}

int32_s Model::GetWaterLevel() const
{
   if (GetWaterLevelAccess())
   {
      return m_waterLevel.GetValue();
   }
   return DEFAULT_INT;
}
bool Model::GetWaterLevelAccess() const
{
   if (m_authenticator.Authenticate(m_user))
   {
      return m_permission.CheckPermission(m_user, m_waterLevel);
   }
   return false;
}

int32_s Model::GetMaxWaterLevel() const
{
   if (GetMaxWaterLevelAccess())
   {
      return m_maxWaterLevel.GetValue();
   }
   return DEFAULT_INT;
}
bool Model::GetMaxWaterLevelAccess() const
{
   if (m_authenticator.Authenticate(m_user))
   {
      return m_permission.CheckPermission(m_user, m_maxWaterLevel);
   }
   return false;
}