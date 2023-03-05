#pragma once
#include "IDevice.h"
#include "SecureInts.h"

class IBooleanSensor : public IDevice
{
public:
   virtual bool GetValue() const = 0;
};
