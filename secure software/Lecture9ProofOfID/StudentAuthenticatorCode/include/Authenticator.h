#pragma once
#include "AuthenticationInfo.h" 
#include "Subject.h" 
using namespace std;


class Authenticator
{
public:
	bool authenticateUser(Subject &s);
}; 

