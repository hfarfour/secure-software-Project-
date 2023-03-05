#pragma once
#include <utility>
#include <sstream>
#include <string>
#include <map>
using namespace std;
 
class AuthenticationInfo
{
string userID;
	string password;
public:
	AuthenticationInfo(void); // constructor sets attributes 
	bool validateUser(string id, string pass);
};



