//***********************************************************
//
//  File:        Subject.h  
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
#include <string>

class Subject {
	std::string id;
	std::string firstName;
	std::string lastName;

public:
	Subject(std::string firstN, std::string lastN);
	Subject(void) {};
	std::string getId(void);
	void enterId(void);
	void enterFirstName(void);
	std::string getFirstName(void);
	std::string getLastName(void);
	void enterLastName(void);

};





