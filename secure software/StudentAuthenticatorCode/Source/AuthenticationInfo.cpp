//***********************************************************
//
//  File:        AuthenticationInfo.cpp
//  Description: source code file 
//  Rev:         1
//  Created:     10 Nov 2020
//  Author:      Janusz Kulon, University of South Wales
//  email:       j.kulon@southwales.ac.uk 
//  web:         http://staff.southwales.ac.uk/users/1032-jkulon
//  Tel:         +44 (0) 1443 654136
//
//
//***********************************************************


#include "AuthenticationInfo.h" 
#include <iostream> 
using namespace std;

AuthenticationInfo::AuthenticationInfo(void){
	userID = "0123";
	password = "1*2*3";
};

 //determines whether a user-specified PIN matches PIN in Account
bool AuthenticationInfo::validateUser(string ID, string pass)
{
	bool validUser = false;
	if (!(ID.compare(userID))) {
		if (!(password.compare(pass)) ) {
			validUser = true;
		}
	}
	return validUser;
} 

