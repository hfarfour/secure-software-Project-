#include <iostream> 
#include <memory> 
using namespace std; 



class Animal
{
protected:     // 'protected'=derived subclasses are allowed access to noOfLegs
	int noOfLegs;
public:

	Animal()     // Constructor
	{
		noOfLegs = 0;
		cout << "Animal created" << endl;
	}

	~Animal() // Destructor
	{
		cout << "Animal was deleted" << endl;
	}


	virtual void SetLegs()
	{
	}


}; // End of class Animal

class Dog : public Animal
{
public:

	void SetLegs()
	{
		noOfLegs = 4;
		cout << "It's a Dog with 4 legs" << endl;
	}
}; // End of subclass Dog


class Centipede : public Animal
{
public:
	void SetLegs()
	{
		noOfLegs = 100;
		cout << "It's a Centipede with 100 legs" << endl;
	}
}; // End of subclass Centipede 

//
//int main()
//{
//	Animal* a1 = 0;
//	a1 = new Animal();
//
//	delete a1;
//	system("Pause"); // Creates 'Any key to continue'
//	return 0;
//}
int main()
{
	int x = 1;
	//Animal* a1 = 0;
	//a1 = new Animal();
	unique_ptr<Animal> a1(new Animal());


	if (x > 0)
	{
		//a1 = new Dog();
		a1.reset(new Dog());

		a1->SetLegs();
		// Do more things with the Dog here
	}

	if (x > 1)
	{
		if (a1 != 0)
		{
			//delete a1;
		}
		a1.reset(new Centipede());
		a1->SetLegs();
	}



	//if (x > 1)
	//{
	//	a1 = new Centipede();
 //    	a1->SetLegs();	
	//}
	////delete a1;
	//system("Pause"); // Creates 'Any key to continue'
	//return 0;
}
