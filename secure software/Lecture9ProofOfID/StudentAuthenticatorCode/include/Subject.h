#pragma once
#include <string>
using namespace std;

class Subject {
	string id;
	string firstName;
	string lastName;

public:
	Subject(std::string firstN, std::string lastN);
	Subject(void) {};
string getId(void);
	void enterId(void);
	void enterFirstName(void);
	string getFirstName(void);
	string getLastName(void);
	void enterLastName(void);

};





