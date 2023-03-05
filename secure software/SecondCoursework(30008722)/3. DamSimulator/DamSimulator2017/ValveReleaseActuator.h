#pragma once
#include "IIntegerActuator.h"
#include "SecureInts.h"
#include "Role.h"
#include "World.h"

class ValveReleaseActuator : public IIntegerActuator
{
public:
   ValveReleaseActuator(World& world)
      :
      m_world(world)
   {
   }

   int32_s GetValue() const override
   {
      return m_world.GetValveRelease();
   }

   void SetValue(const int32_s& value) override
   {
      m_world.SetValveRelease(value);
   }

   Users::Role GetRequiredRole() const override
   {
      return m_requiredRole;
   }

private:
   World& m_world;
   Users::Role m_requiredRole = Users::Role::Employee;
};