#pragma once
#include "IIntegerSensor.h"
#include "SecureInts.h"

class IIntegerActuator : public IIntegerSensor
{
public:
   virtual void SetValue(const int32_s& value) = 0;
};
