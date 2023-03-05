#pragma once
#include "User.h"
#include <list>

namespace Users
{
   class Authenticator
   {
   public:
      User CreateUser(const std::string& username, const std::string& password);
      bool Authenticate(const User& user) const;

   private:
      static std::string GenerateSessionId();
      std::string m_sessionId;
   };
}