#pragma once
#include "IBooleanSensor.h"
#include "SecureInts.h"
#include "Role.h"
#include "World.h"

class PrecipitationSensor : public IBooleanSensor
{
public:
   PrecipitationSensor(const World& world)
      :
      m_world(world)
   {
   }

   bool GetValue() const override
   {
      return m_world.GetIsRaining();
   }

   Users::Role GetRequiredRole() const override
   {
      return m_requiredRole;
   }

private:
   const World& m_world;
   Users::Role m_requiredRole = Users::Role::Visitor;
};