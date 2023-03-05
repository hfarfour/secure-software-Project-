#include "AuthenticationInfo.h"
#include <iostream> 
using namespace std;

AuthenticationInfo::AuthenticationInfo()
{
	userID = "0123";
	password = "1*2*3";
}

//determines whether a user-specified PIN matches PIN in Account
bool AuthenticationInfo::validateUser(string ID, string pass)
{
	bool validUser = false;
	if (!(ID.compare(userID)))
	{
		if (!(password.compare(pass)))
		{
			validUser = true;
		}
	}
	return validUser;
}

