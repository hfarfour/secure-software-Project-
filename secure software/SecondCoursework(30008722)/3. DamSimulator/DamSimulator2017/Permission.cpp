#pragma once
#include "Permission.h"
#include <map>
#include "User.h"
#include "IDevice.h"
#include "Action.h"

using namespace Users;

Permission::Permission()
{
   //TODO: Ideally permissions should not be hard coded like this. Should be stored on disk somewhere.
   m_userRoles = {
      { "Peter", Role::Admin },
      { "Janusz", Role::Employee },
      { "Bobby", Role::Visitor }
   };
}

Role Permission::GetRole(const User& user) const
{
   Role role = Role::NoRole;

   if (user.GetIsAuthenticated())
   {
      //Get users role
      auto userItr = m_userRoles.find(user.GetUsername());
      if (userItr != m_userRoles.end())
      {
         role = userItr->second;
      }
   }

   return role;
}

bool Permission::CheckPermission(const User& user, const IDevice& device) const
{
   Role userRole = GetRole(user);

   //Check user can access device.
   return userRole >= device.GetRequiredRole();
}

bool Permission::UpdateUserRole(const User& user, const std::string& targetUsername, const Role& targetRole)
{
   Role userRole = GetRole(user);
   if (userRole == Role::Admin)
   {
      auto targetUser = m_userRoles.find(targetUsername);
      if (targetUser != m_userRoles.end())
      {
         targetUser->second = targetRole;
         return true;
      }
   }
   return false;
}
