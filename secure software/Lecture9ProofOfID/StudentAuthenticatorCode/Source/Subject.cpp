#include "Subject.h" 
#include <iostream> 
using namespace std;


Subject::Subject(string firstN,string lastN)
	: firstName(firstN), lastName(lastN) {
}


void Subject::enterId(void) {
	cout << "\nEnter UserID :";
   cin >> id;
}

void Subject::enterFirstName(void) {
	cout << "\nEnter First name :";
	cin >> lastName;
}

void Subject::enterLastName(void) {
	cout << "\nEnter Last name :";
	cin >> firstName;
}

string Subject::getFirstName(void) {
	return firstName;
};
string Subject::getLastName(void) {
	return lastName;
};


string Subject::getId(void) { 
	return id; 
};





