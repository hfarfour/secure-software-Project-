#pragma once
#include "IIntegerSensor.h"
#include "SecureInts.h"
#include "Role.h"
#include "World.h"

class WaterLevelSensor : public IIntegerSensor
{
public:
   WaterLevelSensor(const World& world)
      :
      m_world(world)
   {
   }

   int32_s GetValue() const override
   {
      return m_world.GetWaterLevel();
   }

   Users::Role GetRequiredRole() const override
   {
      return m_requiredRole;
   }

private:
   const World& m_world;
   Users::Role m_requiredRole = Users::Role::Visitor;
};