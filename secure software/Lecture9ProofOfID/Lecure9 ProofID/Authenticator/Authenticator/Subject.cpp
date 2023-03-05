#include "Subject.h"
#include "Subject.h" 
#include <iostream> 
using namespace std;


Subject::Subject(string firstN, string lastN): firstName(firstN), lastName(lastN) 
{
}

Subject::Subject()
{
}


void Subject::enterId()
{
	cout << "\nEnter UserID :";
	cin >> id;
}

string Subject::getId() {
	return id;
};



void Subject::enterFirstName()
{
	cout << "\nEnter First name :";
	cin >> firstName;
}

string Subject::getFirstName() {
	return firstName;
};

void Subject::enterLastName() {
	cout << "\nEnter Last name :";
	cin >> lastName;
}
string Subject::getLastName() {
	return lastName;
};







