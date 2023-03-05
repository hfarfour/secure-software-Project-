#pragma once
#include <string>
using namespace std;

class Subject
{
	string id;
	string firstName;
	string lastName;

public:
	Subject(string firstN, string lastN);
	Subject();
	
	void enterId();
	string getId();

	void enterLastName();
	string getLastName();

	void enterFirstName();
	string getFirstName();
	
	

};






