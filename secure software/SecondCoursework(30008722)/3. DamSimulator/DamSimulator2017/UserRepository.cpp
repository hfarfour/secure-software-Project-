#include "UserRepository.h"

using namespace Users;

UserRepository::UserRepository()
{
   //TODO: This would ideally be stored in a secure database, with salted and hashed passwords.
   m_users = {
      { "Peter", "abc" },
      { "Janusz", "1234" },
      { "Bobby", "droptable" }
   };
}

bool UserRepository::AuthenticateUser(const std::string& username, const std::string& password)
{
   auto user = m_users.find(username);
   if (user != m_users.end())
   {
      return user->second == password;
   }
   return false;
}
