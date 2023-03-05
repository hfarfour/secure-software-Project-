#pragma once
#include <string>
#include "Role.h"

namespace Users
{
   class User
   {
   public:
      User()
      {
      }
      User(const std::string& username, const std::string& sessionId, const bool isAuthenticated)
         :
         m_username(username),
         m_sessionId(sessionId),
         m_isAuthenticated(isAuthenticated)
      {}

      std::string GetUsername() const { return m_username; }
      std::string GetSessionId() const { return m_sessionId; }
      bool GetIsAuthenticated() const { return m_isAuthenticated; }

   private:
      std::string m_username;
      std::string m_sessionId;
      bool m_isAuthenticated = false;
   };
}