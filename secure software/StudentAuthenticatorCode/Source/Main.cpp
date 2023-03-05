//***********************************************************
//
//  File:        main.cpp
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
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	uint16_t again = 1;  
	Subject subject;
	Authenticator authenticator;
	bool authenticated = false;
	
	while (again)
	{
		subject.enterFirstName();
		subject.enterLastName();
		cout << "Hello " << subject.getFirstName() << " " << subject.getLastName() << endl;
		subject.enterId();
		authenticated = authenticator.authenticateUser(subject);
		cout << "\nTry again? Yes = 1 , No  = 0 : ";
		cin >> again;
	}
		
	if (authenticated) {
		cout << "\nAs an athenticated user you can access this content" << endl;
		cout << "\n********************Secret Stuff******************\n" << endl;
	}
	else 
		cout << "\nSorry you need to be authenticated to access this content" << endl;

	system("pause");
} // end main