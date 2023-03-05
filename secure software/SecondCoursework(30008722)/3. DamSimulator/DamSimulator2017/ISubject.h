#pragma once
#include "IObserver.h"

class ISubject
{
public:
   virtual ~ISubject(){};
   void SetObserver(IObserver* observer) { m_observer = observer; }
   void Notify(ISubject& subject) { m_observer->Update(subject); }

private:
   IObserver* m_observer = nullptr; //#V6_1
};