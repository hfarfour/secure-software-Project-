#pragma once
#include "IDevice.h"
#include "SecureInts.h"

class IIntegerSensor : public IDevice
{
public:
   virtual int32_s GetValue() const = 0;
};
