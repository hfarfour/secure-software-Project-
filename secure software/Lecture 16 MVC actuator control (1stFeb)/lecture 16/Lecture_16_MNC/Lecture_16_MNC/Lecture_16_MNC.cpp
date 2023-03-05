// Lecture_16_MNC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include <string>
#include <iostream>
#include <thread>    
#include <iomanip>
using namespace std;



class Temp
{
	int temp{ 25 };
	int maxTemp{ 100 };
public:
	int read() const
	{
		return temp;
	}
	void write(int t)
	{
		temp = t;
	}
	void configure()
	{
		maxTemp = 100;
	}

};
class Humidity
{
	int hum{ 60 };
	int maxTemp{ 100 };
public:
	int read() const
	{
		return hum;
	}
	void write(int h)
	{
		hum = h;
	}
	void configure()
	{
		maxTemp = 100;
	}

};
class Model
{
	Temp temp;
	Humidity hum;
	string name;
	Fan fan;
	int samplingPeriod{ 500 };
	//unique_ptr<SimpleFileLogger> logger;/////////////
public:
	Model(void)
	{
		retriveDataFromDatabase();
	}

	const string getName() const
	{
		return this->name;
	}

	void setName(const string name)
	{
		this->name = name;
	}

	int getTemperature() const
	{
		return temp.read();
	}

	void setTemperature(const int t)
	{
		temp.write(t);
	}
	int getHumidity() const
	{
		return hum.read();
	}
	void setHumidity(const int t)
	{
		hum.write(t);
	}

	void setSampling(const int sampling)
	{
		samplingPeriod = sampling;
	}

	int getSampling()
	{
		return samplingPeriod;
	}

	void retriveDataFromDatabase()
	{
		setName("Greenhouse");
		setTemperature(25);
	}
};
//========================
enum class state { Off, On };

class Fan
{
	int speed{ 0 };
public:
	state currentFanState = state::Off;

	void On()
	{
		currentFanState = state::On;
		speed = 80;
		cout << " the fan is on ,the speed is  = " << speed << "\n";
	}
	void Off()
	{
		currentFanState = state::Off;
		cout << " the fan is off \n";
	}

	void increaseSpeed()
	{
		speed = speed + 30;
		cout << "speed increase . speed = " << speed << "\n";
	}
	state getState() const
	{
		return currentFanState;
	}
};

enum class Choice
{
	Quit,
	Information,
	Login,
	Read,
	Configure
};

class View
{
public:
	void printModelDetails(const Model& m) const
	{
		cout << "**************************************" << endl;
		cout << "Device Name: " << m.getName() << endl;
		cout << "Temperature: " << m.getTemperature() << endl;
		cout << "Humidity: " << m.getHumidity() << endl;
		cout << "**************************************" << endl;
	}
	Choice mainMenu(void)
	{
		int input = 0;
		cout << "\n device simulation\n";
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
	void displayData(int hour, int temp, int hum , int fan)
	{
		ios init(NULL);
		init.copyfmt(cout);
		cout << setfill('0') << setw(2) << hour;
		cout.copyfmt(init);
		cout << setw(8) << temp << setw(8) << hum <<setw(8) << fan <<setw(8)<<endl;
	}
	void displayHeader(void)
	{
		cout << " Time" <<setw(5)<< "Temp "<< setw(5)<< "Hum "<<setw(5)<<"state "<<setw(5)<<endl;
		cout << "[Hour]" << setw(5) << " [C]" << setw(5) << "[%] " << setw(5) << "[ON\OFF]" << setw(5) << endl;
	}
	void message(string s)
	{
		cout << s << endl;
	}
};
	
class Controller
{
	Model model;
	View view;
	bool logged{ false };
public:

	void configureSensor(void)
	{
		int samplingPeriod = model.getSampling();
		view.message("\nCurrent sampling Period [ms]:");
		view.message(std::to_string(samplingPeriod));
		view.message("\nEnter new sampling Period [ms]:");
		cin >> samplingPeriod;
		model.setSampling(samplingPeriod);
	}

	void readData()
	{
		int temp = model.getTemperature();
		int hum = model.getHumidity();
		state fanState = model.getFanState();
		view.displayHeader();
		for (int i = 1; i <= 24; i++)
		{
			model.setTemperature(temp + rand() % 10 - 5);
			model.setHumidity(hum + rand() % 20 - 10);
			temp = model.getTemperature();
			hum = model.getHumidity();
			fanState = model.getFanState();
			this_thread::sleep_for(chrono::milliseconds(model.getSampling()));
			if (temp > 20 || hum>60)
			{
				model.switchFanOn();
				model.setTemperature(temp - 2);
				model.setHumidity(hum - 2);
			}
			else if (temp < 18 || hum<50)
			{
				model.switchFanOff();
				model.setTemperature(temp + 2);
				model.setHumidity(temp + 2);
			}
			fanState = model.getFanState();
			view.displayData(i, temp, hum,fanState);
		}
	}
	void run(void)
	{
		Choice choice = Choice::Login;
		while (choice != Choice::Quit)
		{
			choice = view.mainMenu();
			switch (choice) {
			case Choice::Information: //Model deatils
				view.printModelDetails(model);
				break;
			case Choice::Login:
				login();

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
	bool login(void)
	{
		string id;
		string password;
		view.message("\nEnter UserID");
		cin >> id;
		view.message("\nEnter password please");
		cin >> password;
		if (id == "0123" && password == "pass")
		{
			view.message("\nlogged in ");
			return true;
		}
	}
};


int main()
{
	Controller greenhouse;
	greenhouse.run();
	return 0;
}
