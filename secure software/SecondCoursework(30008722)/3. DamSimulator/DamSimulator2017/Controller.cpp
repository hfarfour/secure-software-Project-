#include "Controller.h"

Controller::Controller(Model& model, IView& view)
   :
   m_model(model),
   m_view(view)
{
   m_model.SetObserver(this);
   m_view.SetObserver(this);

   //Start model on new thread.
   m_modelThread = std::thread(&Model::Start, &m_model);
   m_view.Start();
}

Controller::~Controller()
{
   m_modelThread.detach();
}

void Controller::Update(ISubject& subject)
{
   //View has changed, so update the Model.
   if(auto view = dynamic_cast<ConsoleView*>(&subject))
   {
      switch (m_view.GetUserInteraction())
      {
         case UserInteraction::Login:
         {
            m_model.AuthenticateUser(m_view.GetUsernameInput(), m_view.GetPasswordInput());
            break;
         }
         case UserInteraction::SetValveRelease:
         {
            auto valveRelease = m_view.GetValveReleaseInput();
            m_model.SetValveRelease(valveRelease);
            break;
         }
         case UserInteraction::SetLogger:
         {
            m_model.SetLogger(m_view.GetLoggerOutputInput(), m_view.GetLoggerFormatInput());
            break;
         }
         case UserInteraction::UpdateRole:
         {
            m_model.UpdateRole(m_view.GetUpdateRoleUsernameInput(), m_view.GetUpdateRoleInput());
            break;
         }
         default:
         {
            break;
         }
      }
   }
   //Model has changed, so update the View.
   else if(auto model = dynamic_cast<Model*>(&subject))
   {
      auto time = m_model.GetTime();
      m_view.SetTime(time);
      m_view.SetIsAuthenicated(m_model.GetIsAuthenticated());
      m_view.SetUsername(m_model.GetUsername());
      m_view.SetRole(m_model.GetRole());

      m_view.SetPrecipitation(m_model.GetPrecipitation());
      m_view.SetPrecipitationAccess(m_model.GetPrecipitationAccess());

      m_view.SetEnergyDemand(m_model.GetEnergyDemand());
      m_view.SetEnergyDemandAccess(m_model.GetEnergyDemandAccess());

      m_view.SetEnergyOutput(m_model.GetEnergyOutput());
      m_view.SetEnergyOutputAccess(m_model.GetEnergyOutputAccess());

      m_view.SetSpillway(m_model.GetSpillway());
      m_view.SetSpillwayAccess(m_model.GetSpillwayAccess());

      m_view.SetWaterLevel(m_model.GetWaterLevel());
      m_view.SetWaterLevelAccess(m_model.GetWaterLevelAccess());

      m_view.SetMaxWaterLevel(m_model.GetMaxWaterLevel());
      m_view.SetMaxWaterLevelAccess(m_model.GetMaxWaterLevelAccess());

      m_view.SetValveRelease(m_model.GetValveRelease());
      m_view.SetValveReleaseAccess(m_model.GetValveReleaseAccess());

      m_view.ForceRefresh();
   }
}
