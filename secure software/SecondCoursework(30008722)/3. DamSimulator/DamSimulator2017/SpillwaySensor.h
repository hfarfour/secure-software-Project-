#pragma once
#include "IBooleanSensor.h"
#include "SecureInts.h"
#include "Role.h"
#include "World.h"

class SpillwaySensor : public IBooleanSensor
{
public:
   SpillwaySensor(const World& world)
      :
      m_world(world)
   {
   }

   bool GetValue() const override
   {
      return m_world.GetIsSpillwayActive();
   }

   Users::Role GetRequiredRole() const override
   {
      return m_requiredRole;
   }

private:
   const World& m_world;
   Users::Role m_requiredRole = Users::Role::Visitor;
};