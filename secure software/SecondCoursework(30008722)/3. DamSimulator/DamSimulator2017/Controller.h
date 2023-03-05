#pragma once
#include "IObserver.h"

#include "IView.h"
#include "ConsoleView.h"
#include "Model.h"
#include <thread>

class Controller : public IObserver
{
public:
   Controller(Model& model, IView& view);
   ~Controller();
   void Update(ISubject& subject) override;

private:
   Model& m_model;
   IView& m_view;
   std::thread m_modelThread;
};