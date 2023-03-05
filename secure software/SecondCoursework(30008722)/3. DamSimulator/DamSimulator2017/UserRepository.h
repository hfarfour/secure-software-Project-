
#pragma once
#include <map>
#include "Role.h"

namespace Users
{
   class UserRepository
   {
   public:
      UserRepository();
      bool AuthenticateUser(const std::string& username, const std::string& password);

   private:
      //This map is a placeholder. The final solution would retrieve the data from a secure database.
      std::map<const std::string, const std::string> m_users;
   };
}
