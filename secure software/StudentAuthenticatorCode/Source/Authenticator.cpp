//***********************************************************
//
//  File:        Authenticator.cpp
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


#include "Authenticator.h" 
#include <time.h>  
#include <string>
#include <iostream> 

bool Authenticator::authenticateUser(Subject &subject)
{
	AuthenticationInfo ainfo;
	bool authenticated = false;
	std::string Id = subject.getId();
	std::string pass;
	std::string token;
	std::cout << "\nEnter password :";
    std::cin >> pass;
	if (ainfo.validateUser(Id, pass))	{
			std::cout << "\nWelcome!";
			std::cout << "\nAuthenticated!\n";
			authenticated = true;
	}
	else
		std::cout << "Invalid user ID or password. Please try again.";
	return authenticated;

}; 

