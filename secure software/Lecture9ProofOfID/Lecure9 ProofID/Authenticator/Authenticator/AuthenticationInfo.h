#pragma once
#include <utility>
#include <sstream>
#include <string>
#include <map>
using namespace std;

class AuthenticationInfo
{private:
	string userID;
	string password;
public:
    AuthenticationInfo();   // constructor 
	bool validateUser(string id, string pass);
};



