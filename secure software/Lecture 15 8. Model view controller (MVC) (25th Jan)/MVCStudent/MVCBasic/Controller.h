#pragma once
#include "Model.h"
#include "View.h"

class Controller {
	Model model;
	View view;
	bool logged{ false };
public:
	void configureSensor(void);
	void readData(void);
	void run(void);
};

