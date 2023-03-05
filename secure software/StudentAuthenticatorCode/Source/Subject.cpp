//***********************************************************
//
//  File:        Subject.cpp
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


#include "Subject.h" 

#include <iostream> 


Subject::Subject(std::string firstN, std::string lastN)
	: firstName(firstN), lastName(lastN) {
}


void Subject::enterId(void) {
	std::cout << "\nEnter UserID :";
    std::cin >> id;
}

void Subject::enterFirstName(void) {
	std::cout << "\nEnter First name :";
	std::cin >> lastName;
}

void Subject::enterLastName(void) {
	std::cout << "\nEnter Last name :";
	std::cin >> firstName;
}

std::string Subject::getFirstName(void) {
	return firstName;
};
std::string Subject::getLastName(void) {
	return lastName;
};


std::string Subject::getId(void) { 
	return id; 
};





