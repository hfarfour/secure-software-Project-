#pragma once
#include <map>
#include "User.h"
#include "IDevice.h"
#include "Action.h"

namespace Users
{
   class Permission
   {
   public:
      Permission();
      bool CheckPermission(const User& user, const IDevice& device) const;
      bool UpdateUserRole(const User& user, const std::string& targetUsername, const Role& targetRole);
      Role GetRole(const User& role) const;

   private:
      //This map is a placeholder. The final solution would retrieve the data from a secure database.
      std::map<const std::string, Role> m_userRoles;
   };
}
