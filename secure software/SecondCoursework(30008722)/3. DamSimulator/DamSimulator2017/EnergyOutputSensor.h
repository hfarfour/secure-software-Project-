#pragma once
#include "IIntegerSensor.h"
#include "SecureInts.h"
#include "Role.h"
#include "World.h"

class EnergyOutputSensor : public IIntegerSensor
{
public:
   EnergyOutputSensor(const World& world)
      :
      m_world(world)
   {
   }

   int32_s GetValue() const override
   {
      return m_world.GetEnergyOutput();
   }

   Users::Role GetRequiredRole() const override
   {
      return m_requiredRole;
   }

private:
   const World& m_world;
   Users::Role m_requiredRole = Users::Role::Employee;
};