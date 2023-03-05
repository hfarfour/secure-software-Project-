//***********************************************************
//
//  File:        Authenticator.h  
//  Description: header file 
//  Rev:         1
//  Created:     10 Nov 2020
//  Author:      Janusz Kulon, University of South Wales
//  email:       j.kulon@southwales.ac.uk 
//  web:         http://staff.southwales.ac.uk/users/1032-jkulon
//  Tel:         +44 (0) 1443 654136
//
//
//***********************************************************
#pragma once

#include "AuthenticationInfo.h" 
#include "Subject.h" 


class Authenticator
{
public:
	bool authenticateUser(Subject &s);
}; 

