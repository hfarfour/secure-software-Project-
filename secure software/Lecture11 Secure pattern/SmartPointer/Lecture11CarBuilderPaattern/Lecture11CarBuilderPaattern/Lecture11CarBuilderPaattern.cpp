// Lecture11CarBuilderPaattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//using smart pointer 

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
{                                                                 // to use  smart pointer by making it unique   
public:
	unique_ptr<Wheel>wheels[NO_Wheels];   //Wheel* wheels[NO_Wheels]; // raw pointer
	unique_ptr<Engine>engine;            //Engine* engine;
	unique_ptr<Body>body;                //Body* body;                          
	void specifications()
	{
		cout << "body:" << body->shape << endl;
		cout << "engine horsepower:" << engine->horsepower << endl;
		cout << "tire size:" << wheels[0]->size << " " << endl;
	}

	virtual ~Car()
	{
		cout << " car has been destroyed" << endl;
	}

	/*~Car()        // for  old pointer
	{
	 for (int i = 0; i < NO_Wheels; i++) delete wheels[i];
	 delete engine;
	 delete body;
	}*/
};

/* Builder is responsible for constructing the smaller parts */
class Builder
{
public:
	virtual unique_ptr<Wheel> getWheel() const = 0;      //virtual Wheel* getWheel(void) const = 0;
	virtual unique_ptr<Engine> getEngine() const = 0;    // virtual Engine* getEngine(void) const = 0;
	virtual unique_ptr<Body> getBody() const = 0;       //virtual Body* getBody(void) const = 0;
	virtual ~Builder() = default;
};

/* Director is responsible for the whole process */
class Director
{
	shared_ptr<Builder> builder;                // Builder* builder;
public:
	void setBuilder(shared_ptr<Builder> newBuilder)     //void setBuilder(Builder* newBuilder) 
	{                              
		builder = newBuilder;
	}

	 unique_ptr<Car>getCar()                              //Car* getCar(void)
	{
		 unique_ptr<Car>car = make_unique <Car>();                             //Car* car = new Car;
		car->body = builder->getBody();
		car->engine = builder->getEngine();
		for (int i = 0; i < NO_Wheels; i++)
		car->wheels[i] = builder->getWheel();
                                                  //car->engine = builder->getEngine();
		return car;
	}
	 ~Director()
	 {
		 cout << "director has been destroyed" << endl;
	 }
};

/* Concrete Builder for Jeep SUV cars */
class JeepBuilder : public Builder
{
public:
	unique_ptr<Body>getBody(void) const override
	{
		unique_ptr<Body>body = make_unique<Body>();
		body->shape = "SUV body";
		return body;
	}

	unique_ptr<Engine> getEngine(void) const override
	{
		unique_ptr<Engine>engine = make_unique<Engine>();
		engine->horsepower = 400;
		return engine;
		//cout << body->shape << endl;
	}

	unique_ptr<Wheel> getWheel(void) const override
	{
		unique_ptr<Wheel>wheel = make_unique<Wheel>();
		wheel->size = 22;
		return wheel;
		//cout << body->shape << endl;
	}
	~JeepBuilder()
	{
		cout << "jeepBuilder has been destroyed" << endl;
	}
};
/* Concrete Builder for Nissan cars */
class NissanBuilder : public Builder
{
public:
	/*Wheel* getWheel() const
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
	}*/
	unique_ptr<Body> getBody(void) const override
	{
		unique_ptr<Body>body = make_unique<Body>();
		body->shape = "Hashback body";
		return body;
	}

	unique_ptr<Engine> getEngine(void) const override
	{
		unique_ptr<Engine>engine = make_unique<Engine>();
		engine->horsepower = 200;
		return engine;
	}

	unique_ptr<Wheel> getWheel(void) const override
	{
		unique_ptr<Wheel>wheel = make_unique<Wheel>();
		wheel->size = 20;
		return wheel;
	}
	~NissanBuilder()
	{
		cout << "NissBuilder has been destroyed" << endl;
	}
};


//int main()
//{
//	Car* car; 
//	Director director;
//	JeepBuilder jeepBuilder;
//
//	/* Build a Jeep */
//	cout << "Jeep" << endl;
//	director.setBuilder(&jeepBuilder); // using JeepBuilder instance
//	car = director.getCar();
//	car->specifications();
//	delete car;
//	cout << endl;
//
//	/* Build a Nissan */
//	NissanBuilder nissanBuilder;
//	cout << "Nissan" << endl;
//	director.setBuilder(&nissanBuilder);
//	car = director.getCar();
//	car->specifications();
//	delete car;
//	cout << endl;
//	system("pause");
//	return 0;
//}
//
int main()
{
	 Director director;
	/* Build a Jeep */
	shared_ptr<Builder>builder = make_shared<JeepBuilder>();
	director.setBuilder(builder);
	cout << "Jeep" << endl;
	unique_ptr<Car>Jeep1 = director.getCar();
	Jeep1->specifications();
	cout << "==================================" << endl;
	/* Build a Nissan */
	shared_ptr<Builder>builder = make_shared<NissanBuilder>();
	director.setBuilder(builder);
	cout << "Nissan" << endl;
	unique_ptr<Car>Nisssan1 = director.getCar();
	Nisssan1->specifications();
	
	cout << endl;
	system("pause");
	return 0;
}

