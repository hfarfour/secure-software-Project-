
// using raw pointer

#include <iostream>
#include <string>
using namespace std;



const int NO_Wheels = 4;
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

class Make
{
public:
	string maker;
};


class Car
{
public:
	Make* make;
	Wheel* wheels[NO_Wheels];
	Engine* engine;
	Body* body;

	void specifications()	
	{
		cout << "make :" << make->maker<< endl;
		cout << "body:" << body->shape << endl;
		cout << "engine horsepower:" << engine->horsepower << endl;
		cout << "tire size:" << wheels[0]->size << "'" << endl;
	}
	~Car() 
	{
		for (int i = 0; i < NO_Wheels; i++)
		delete wheels[i];
		delete engine;
		delete body;
		delete make;
	}
};

/* Builder is responsible for constructing the smaller parts */
class Builder
{
public:
	virtual Make* getMake() const = 0;
	virtual Wheel* getWheel() const = 0;
	virtual Engine* getEngine() const = 0;
	virtual Body* getBody() const = 0;
};

/* Director is responsible for the whole process */
class Director
{
	Builder* builder;
public:
	void setBuilder(Builder* newBuilder)
	{
		builder = newBuilder;
	}
	Car* getCar()
	{
		Car* car = new Car;
		car->make = builder->getMake();
		car->body = builder->getBody();
		car->engine = builder->getEngine();
		for (int i = 0; i < NO_Wheels; i++)
			car->wheels[i] = builder->getWheel();
		return car;
	}
};

/* Concrete Builder for Jeep SUV cars */
class JeepBuilder : public Builder
{
public:
	Make* getMake() const
	{
		Make* make = new Make;
		make->maker = "Jeep";
		return make;
	}

	Wheel* getWheel() const
	{
		Wheel* wheel = new Wheel;
		wheel->size = 22;
		return wheel;
	}

	Engine* getEngine()	const 
	{
		Engine* engine = new Engine;
		engine->horsepower = 400;
		return engine;
	}

	Body* getBody() const
	{
		Body* body = new Body;
		body->shape = "SUV";
		return body;
	}
};

/* Concrete Builder for Nissan cars */
class NissanBuilder : public Builder
{
public:
	Make* getMake() const
	{
		Make* make = new Make;
		make->maker = "Nissan";
		return make;
	}


	Wheel* getWheel() const
	{
		Wheel* wheel = new Wheel;
		wheel->size = 23;
		return wheel;
	}

	Engine* getEngine()	const
	{
		Engine* engine = new Engine;
		engine->horsepower = 600;
		return engine;
	}

	Body* getBody() const
	{
		Body* body = new Body;
		body->shape = "hatchback";
		return body;
	}
};


int main()
{

	Car* car;
	/* A director who controls the process */
	Director director;
	/* Concrete builders */
	JeepBuilder jeepBuilder;

	/* Build a Jeep */
	director.setBuilder(&jeepBuilder); // using JeepBuilder instance
	car = director.getCar();
	car->specifications();
	delete car;
	cout << endl;

	/* Build a Nissan */
	NissanBuilder nissanBuilder;
	//cout << "Nissan" << endl;
	director.setBuilder(&nissanBuilder); 
	car = director.getCar();
	car->specifications();
	delete car;
	cout << endl;
	system("pause");
	return 0;
}

