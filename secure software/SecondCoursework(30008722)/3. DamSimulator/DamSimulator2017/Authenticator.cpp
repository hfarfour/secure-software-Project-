#include "Authenticator.h"
#include "UserRepository.h"

#include <iostream>

using namespace Users;

User Authenticator::CreateUser(const std::string& username, const std::string& password)
{
   UserRepository repository;
   bool isAuthenticated = repository.AuthenticateUser(username, password);
   m_sessionId = GenerateSessionId();

   return User(username, m_sessionId, isAuthenticated);
}

bool Authenticator::Authenticate(const User& user) const
{
   return user.GetIsAuthenticated() && user.GetSessionId() == m_sessionId;
}

std::string Authenticator::GenerateSessionId()
{
   //TODO: Generate random session id.
   return "temp_session_id";
}
