
#include <string>
#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include "Controller.h"
#include "Choice.h"

using namespace std;

void Controller::run(void) {

	Choice choice = Choice::Login;
	while (choice != Choice::Quit) {
		choice = view.mainMenu();
		switch (choice) {
		case Choice::Information: //Model deatils
			view.printModelDetails(model);
			break;
		case Choice::Login: 
			//add login
			break;
		case Choice::Read: 
			readData();
			break;
		case Choice::Configure:
			if (logged) configureSensor();
			else view.message("You have to be logged to configure sensor");
			break;
		//
		//continue with menu options...
		//.............................
		default:
			break;
		}
	}
}


void Controller::readData(void) {
	int temp = model.getTemperature();
	view.displayHeader();
	for (int i = 1; i <= 24; i++) {
		model.setTemperature(temp + rand() % 10 - 5);
		temp = model.getTemperature();
		view.displayData(i, temp);
		std::this_thread::sleep_for(std::chrono::milliseconds(model.getSampling()));
	}
}

void Controller::configureSensor(void){
	int samplingPeriod = model.getSampling();
	view.message("\Current sampling Period [ms]:");
	view.message(std::to_string(samplingPeriod));
	view.message("\nEnter new sampling Period [ms]:");
	cin >> samplingPeriod;
	model.setSampling(samplingPeriod);
}