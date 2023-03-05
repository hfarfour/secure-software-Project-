#include "ConsoleView.h"

#include "ISubject.h"
#include "Console.h"
#include "DamLabels.h"

ConsoleView::ConsoleView()
{
   Console::Initialize(64, 13);
}

void ConsoleView::Start()
{
   while(true)
   {
      PollKeyEvents();

      if (m_forceRefresh)
      {
         Refresh();
      }
   }
}

void ConsoleView::ForceRefresh()
{
   m_forceRefresh = true;
}

void ConsoleView::PollKeyEvents()
{
   //If key is pressed.
   if (GetAsyncKeyState(VK_ESCAPE) & 0x01)
   {
      //Exit Console logging screen
      if (m_loggerTypeInput == Logger::Type::Console)
      {
         m_loggerTypeInput = Logger::Type::None;
         Notify(*this);

         Refresh();
      }
      //Enter options menu..
      else if(m_isOptionsMenu == false)
      {
         m_isOptionsMenu = true;
         Console::Clear();

         DisplayOptionsMenu();

         m_isOptionsMenu = false;
         Console::Clear();

         Refresh();
      }
   }   
}

void ConsoleView::DisplayOptionsMenu()
{
   m_lblOptions.Show();//#V4_1
   if(!m_numOptions.Show())//#V4_1
   {
      return;
   }

   Console::Clear();

   switch (m_numOptions.GetValue().GetValue())
   {
   case 1: //Login
   {
      if (!m_txtUsername.Show())//#V4_1
      {
         return;
      }

      if (!m_txtPassword.Show())//#V4_1
      {
         return;
      }

      m_usernameInput = m_txtUsername.GetText();
      m_passwordInput = m_txtPassword.GetText();
      m_userInteraction = UserInteraction::Login;

      Notify(*this);

      break;
   }
   case 2: //Set valve release
   {
      if (m_valveReleaseAccess)
      {
         if (!m_numValveRelease.Show())//#V4_1
         {
            return;
         }

         m_valveReleaseInput = m_numValveRelease.GetValue();
         m_userInteraction = UserInteraction::SetValveRelease;
         Notify(*this);
      }

      break;
   }
   case 3://Logger options
   {
      m_lblLoggerType.Show();//#V4_1
      if (!m_numLoggerType.Show())//#V4_1
      {
         return;
      }

      Console::Clear();

      m_lblLoggerFormat.Show();//#V4_1
      if (!m_numLoggerFormat.Show())//#V4_1
      {
         return;
      }

      m_loggerTypeInput = static_cast<Logger::Type>(m_numLoggerType.GetValue().GetValue());
      m_loggerFormatInput = static_cast<Logger::Format>(m_numLoggerFormat.GetValue().GetValue());
      m_userInteraction = UserInteraction::SetLogger;

      Notify(*this);

      break;
   }
   case 4://Update role
   {
      if (!m_txtUpdateRoleUsername.Show())//#V4_1
      {
         return;
      }

      m_lblRoles.Show();//#V4_1
      if (!m_numUpdateRole.Show())//#V4_1
      {
         return;
      }
      m_updateRoleInput = static_cast<Users::Role>(m_numUpdateRole.GetValue().GetValue());
      m_updateRoleUsernameInput = m_txtUpdateRoleUsername.GetText();
      m_userInteraction = UserInteraction::UpdateRole;

      Notify(*this);

      break;
   }
   default:
      break;
   }
}

//Clears and redraws the entire console.
void ConsoleView::Refresh()
{
   if (m_isOptionsMenu == false && m_loggerTypeInput != Logger::Type::Console)
   {
      Console::Clear();

      //Draw status.
      std::string status = m_time.ToString() + " | ";
      if (m_precipitationAccess)
      {
         status += std::string(m_precipitation ? "Raining" : "Clear") + " | ";
      }
      status += std::string(m_isAuthenticated ? m_username : "Unknown") + " | ";
      status += std::to_string(static_cast<int>(m_role)); //TODO: Print role as string.
      m_lblStatus.SetLabel(status);
      m_lblStatus.Show();//#V4_1
      m_lblHint.Show();//#V4_1

      //Draw dam stats.
      auto spillwayText = std::string(m_spillway ? "Active" : "Inactive");
      m_lblDamStatistics.SetLabel(
      {
         "DAM STATS",
         " Water(l):    " + (m_waterLevelAccess ? std::to_string(m_waterLevel.GetValue()) : NO_ACCESS),
         " Valve(%):    " + (m_valveReleaseAccess ? std::to_string(m_valveRelease.GetValue()) : NO_ACCESS),
         " Spillway:    " + (m_spillwayAccess ? spillwayText : NO_ACCESS)
      });
      m_lblDamStatistics.Show();//#V4_1

      //Draw energy stats.
      int32_s energySurplus = m_energyOutput - m_energyDemand; //#V2_2

      m_lblEnergyStatistics.SetLabel(
      {
         "ENERGY STATS",
         " Demand(MW):  " + (m_energyDemandAccess ? std::to_string(m_energyDemand.GetValue()) : NO_ACCESS),
         " Output(MW):  " + (m_energyOutputAccess ? std::to_string(m_energyOutput.GetValue()) : NO_ACCESS),
         " Surplus(MW): " + (m_energyDemandAccess & m_energyOutputAccess ? std::to_string(energySurplus.GetValue()) : NO_ACCESS)
      });
      m_lblEnergyStatistics.Show();//#V4_1

      //Draw Textures.
      if (m_isAuthenticated)
      {
         if (m_precipitation)
         {
            m_alternateRainLabel = !m_alternateRainLabel;
            if (m_alternateRainLabel)
            {
               DamLabels::Rain1.Show();//#V4_1
            }
            else
            {
               DamLabels::Rain2.Show();//#V4_1
            }
         }

         DamLabels::Wall.Show();//#V4_1
         DamLabels::Ground.Show();//#V4_1

         if (m_maxWaterLevel > 0) //Preventing divide by zero errors.
         {
            double waterPercentage = static_cast<double>(m_waterLevel.GetValue()) / static_cast<double>(m_maxWaterLevel.GetValue());

            if (waterPercentage > 0.75)
            {
               DamLabels::WaterInput4.Show();//#V4_1
            }
            else if (waterPercentage > 0.5)
            {
               DamLabels::WaterInput3.Show();//#V4_1
            }
            else if (waterPercentage > 0.25)
            {
               DamLabels::WaterInput2.Show();//#V4_1
            }
            else if (waterPercentage > 0)
            {
               DamLabels::WaterInput1.Show();//#V4_1
            }

            if (m_valveRelease > 0 && m_waterLevel > 0)
            {
               DamLabels::WaterOutput.Show();//#V4_1
            }
         }
      }
   }

   m_forceRefresh = false;
}

std::string ConsoleView::GetPasswordInput()
{
   //Clear password member variable in view.
   std::string tempPassword = m_passwordInput;
   m_passwordInput = "";
   return tempPassword;
}