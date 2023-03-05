#include <string>
#include <iostream>
#include <iomanip>
#include "View.h"
#include "Choice.h" 

using namespace std;

void View::printModelDetails(const Model& m) const {
	cout << "**************************************" << endl;
	cout << "Device Name: " << m.getName() << endl;
	cout << "Temperature: " << m.getTemperature() << endl;
	cout << "**************************************" << endl;
}

void View::displayHeader(void) {
	cout << " Time" << setw(6) <<"Temp" << endl;
	cout << "[Hour]"<< setw(6) <<" [C]" << endl;
}

void View::displayData(int hour, int temp) {
	ios init(NULL);
	init.copyfmt(cout);
	cout << setfill('0') << setw(2) << hour;
	cout.copyfmt(init);
	cout << setw(10) << temp << endl;
}

void View::message(std::string s) {
	cout << s << endl;
}

Choice View::mainMenu(void) {
	int input = 0;
	cout << "\nWelcome to the device simulation\n";
	cout << "Select from the following options\n";
	cout << "---------------------------------\n";
	cout << (int)(Choice::Information) << ": Information about the device\n";
	cout << (int)(Choice::Login) << ": Log in\n";
	cout << (int)(Choice::Read) << ": Read data\n";
	cout << (int)(Choice::Configure) << ": Configure\n";
	cout << (int)(Choice::Quit) << ": Quit\n";
	cout << "Your choice :";
	cin >> input;
	return (Choice)input;
}
