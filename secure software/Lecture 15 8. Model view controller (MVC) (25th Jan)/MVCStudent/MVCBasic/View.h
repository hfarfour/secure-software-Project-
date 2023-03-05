#pragma once
#include <string>
#include "Model.h"
#include "Choice.h" 

class View {
public:
	void printModelDetails(const Model &m) const;
	Choice mainMenu(void);
	void displayData(int hour, int temp);
	void displayHeader(void);
	void message(std::string s);
};