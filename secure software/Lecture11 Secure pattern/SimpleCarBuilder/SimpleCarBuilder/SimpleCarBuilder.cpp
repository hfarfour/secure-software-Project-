// SimpleCarBuilder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// using raw pointer
#include <iostream>
#include <string>
using namespace std;



const int NO_Wheels = 4;
/* Car parts */
class Wheel
{
public:
	int size;
};

class Engine
{
public:
	double horsepower;
};

class Body
{
public:
	string shape;
};


class Car
{
public:
	string make;
	Wheel* wheels[NO_Wheels];
	Engine* engine;
	Body* body;
	Car(string amake,int wheelSize,double horsepower,string shape)
	{
		for (int i = 0; i < NO_Wheels; i++)
		{
			wheels[i] = new Wheel;
			wheels[i]->size = wheelSize;
		}
		make = amake;
		engine = new Engine;
		engine->horsepower = horsepower;
		body = new Body;
		body->shape = shape;
	}
	void specifications() 
	{
		cout << "make :" << make << endl;
		cout << "body :" << body->shape << endl;
		cout << "engine horsepower :" << engine->horsepower << endl;
		cout << "tire size :" << wheels[0]->size << " " << endl;
	}
	~Car(void)
	{
		for (int i = 0; i < NO_Wheels; i++)
		delete wheels[i];
		delete engine;
		delete body;
	}
};

int main()
{
	Car* Nissan = new Car("Nissan", 16, 85, "hatchback");
	Nissan->specifications();
	delete Nissan;
	cout << endl;

	///* Build a Jeep */
	Car* Jeep = new Car("Jeep", 20, 200, "DCV");
	Jeep->specifications();
	delete Jeep;
	cout << endl;

	system("pause");
	return 0;
}

