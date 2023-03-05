#pragma once
#include "IView.h"
#include <string>
#include "Time.h"
#include "User.h"
#include "Label.h"
#include "NumberInput.h"
#include "TextInput.h"
#include "LoggerTypes.h"
#include "UserInteraction.h"
#include "SecureInts.h"

class ConsoleView : public IView
{
public:
   ConsoleView();
   void Start() override;
   void ForceRefresh() override;

   //Set displayable values.
   void SetTime(Time& time) override { m_time = time; };
   void SetUsername(const std::string& username) override { m_username = username; }
   void SetIsAuthenicated(const bool isAuthenticated) override { m_isAuthenticated = isAuthenticated; }
   void SetRole(const Users::Role& role) override { m_role = role; }

   void SetPrecipitation(const bool precipitation) override { m_precipitation = precipitation; };
   void SetEnergyDemand(const int32_s& energyDemand) override { m_energyDemand = energyDemand; }
   void SetEnergyOutput(const int32_s& energyOutput) override { m_energyOutput = energyOutput; }
   void SetSpillway(const bool spillway) override { m_spillway = spillway; }
   void SetWaterLevel(const int32_s& waterLevel) override { m_waterLevel = waterLevel; }
   void SetMaxWaterLevel(const int32_s& maxWaterLevel) override { m_maxWaterLevel = maxWaterLevel; }
   void SetValveRelease(const int32_s& valveRelease) override { m_valveRelease = valveRelease; }

   void SetPrecipitationAccess(const bool precipitationAccess) override { m_precipitationAccess = precipitationAccess; };
   void SetEnergyDemandAccess(const bool energyDemandAccess) override { m_energyDemandAccess = energyDemandAccess; }
   void SetEnergyOutputAccess(const bool energyOutputAccess) override { m_energyOutputAccess = energyOutputAccess; }
   void SetSpillwayAccess(const bool spillwayAccess) override { m_spillwayAccess = spillwayAccess; }
   void SetWaterLevelAccess(const bool waterLevelAccess) override { m_waterLevelAccess = waterLevelAccess; }
   void SetMaxWaterLevelAccess(const bool maxWaterLevelAccess) override { m_maxWaterLevelAccess = maxWaterLevelAccess; }
   void SetValveReleaseAccess(const bool valveReleaseAccess) override { m_valveReleaseAccess = valveReleaseAccess; }

   //Get inputs.
   UserInteraction GetUserInteraction() override { return m_userInteraction; };
   int32_s GetValveReleaseInput() const override { return m_valveReleaseInput; };
   std::string GetUsernameInput() const override { return m_usernameInput; }
   std::string GetPasswordInput() override;
   Logger::Type GetLoggerOutputInput() const override { return m_loggerTypeInput; }
   Logger::Format GetLoggerFormatInput() const override { return m_loggerFormatInput; }
   std::string GetUpdateRoleUsernameInput() const override { return m_updateRoleUsernameInput; };
   Users::Role GetUpdateRoleInput() const override { return m_updateRoleInput; };

private:
   void PollKeyEvents();
   void DisplayOptionsMenu();
   void Refresh();

   bool m_forceRefresh = true;

   //Displayable values
   Time m_time = Time(0, 0);

   bool m_isAuthenticated = false;
   std::string m_username;
   UserInteraction m_userInteraction = UserInteraction::None;
   Users::Role m_role = Users::Role::NoRole;

   bool m_precipitation = false;
   int32_s m_energyDemand = 0;
   int32_s m_energyOutput = 0;
   bool m_spillway = false;
   int32_s m_waterLevel = 100000;
   int32_s m_maxWaterLevel = 0;
   int32_s m_valveRelease = 0;

   bool m_precipitationAccess = false;
   bool m_energyDemandAccess = false;
   bool m_energyOutputAccess = false;
   bool m_spillwayAccess = false;
   bool m_waterLevelAccess = false;
   bool m_maxWaterLevelAccess = false;
   bool m_valveReleaseAccess = false;

   bool m_isOptionsMenu = false;
   const std::string NO_ACCESS = "******";
   bool m_alternateRainLabel = false;

   //Temporary input values.
   std::string m_usernameInput;
   std::string m_passwordInput;
   int32_s m_valveReleaseInput = 0;
   Logger::Type m_loggerTypeInput = Logger::Type::None;
   Logger::Format m_loggerFormatInput = Logger::Format::None;
   Users::Role m_updateRoleInput = Users::Role::NoRole;
   std::string m_updateRoleUsernameInput;

   //Input controls.
   NumberInput m_numOptions = NumberInput(2, 6, "Select: ", 1, 4);
   TextInput m_txtUsername = TextInput(2, 1, "Username [3-10 chars]: ", 3, 10);
   TextInput m_txtPassword = TextInput(2, 2, "Password [3-10 chars]: ", 3, 10);
   NumberInput m_numValveRelease = NumberInput(2, 1, "Release valve [0-100%]: ", 0, 100);
   NumberInput m_numLoggerType = NumberInput(2, 5, "Select: ", 0, 2);
   NumberInput m_numLoggerFormat = NumberInput(2, 5, "Select: ", 0, 2);
   TextInput m_txtUpdateRoleUsername = TextInput(2, 1, "Username [3-10 chars]: ", 3, 10);
   NumberInput m_numUpdateRole = NumberInput(2, 7, "Select: ", 0, 3);

   //Output controls.
   Label m_lblStatus = Label(2, 1);
   Label m_lblHint = Label(41, 1, "Press 'Esc' for options");
   Label m_lblOptions = Label(2, 1,
   {
      "Options",
      "1 - Login [All]",
      "2 - Configure release valve [Employee]",
      "3 - Configure logger [Employee]",
      "4 - Configure permissions [Admin]"
   });
   Label m_lblLoggerType = Label(2, 1,
   {
      "Output type",
      "0 - None",
      "1 - Console",
      "2 - File"
   });
   Label m_lblLoggerFormat = Label(2, 1,
   {
      "Format type",
      "0 - None",
      "1 - CSV",
      "2 - XML"
   });
   Label m_lblRoles = Label(2, 2,
   {
      "Role",
      "0 - None",
      "1 - Visitor",
      "2 - Employee",
      "3 - Admin"
   });
   Label m_lblDamStatistics = Label(2, 3);
   Label m_lblEnergyStatistics = Label(2, 8);
};
