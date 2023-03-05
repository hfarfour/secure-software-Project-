
#include <memory> 
#include <iostream> 
using namespace std; 


class Rectangle 
{
private :
	int width, height;
public :

	Rectangle(int w, int h) // Constructor
	{
		width = w;
		height = h;
		cout << "Rectangle created" << endl;
	}

	void area() // some Method
	{
		cout << "The area is:  " << (width * height) << endl;
	}
	~Rectangle() // Destructor
	{
		cout << "Rectangle was = deleted" << endl;
	}

};

class UseRectangle
{
	Rectangle* r1 = new Rectangle(5, 2);
	void aMethod()
	{
		Rectangle* r2 = new Rectangle(3, 3); // construct
		// lots of code here
      //delete r2; // delete
	}
	void anotherMethod()
	{
		r1->area();
	}
};



//int main()
//{
//
//	/*Rectangle box(5, 2);
//	cout<< box.area() << endl;*/
//
//	Rectangle* r1 = new Rectangle (5, 2); // create "raw" pointer r1
//
//	r1->area();
//
//	delete r1;
//
//	system("Pause"); // creates 'Any key to continue'
//	return 0;
//}


int main()
{
	Rectangle* r1 = new Rectangle(5, 2);
	                                                                    //Rectangle* r2 = new Rectangle(5, 2);
	Rectangle* r1Copy = r1; // Step 1: create a copy of the pointer r1
	r1->area();
	r1Copy->area(); // Step 2: see if the copied pointer works
	delete r1; // Rectangle gone but r1Copy still points to it
	 // r1Copy still is now 'dangling'!
	r1Copy->area();  // Step 3: and presto - ooops!
                                                                               //r2->area();
	system("Pause"); // creates 'Any key to continue'
	return 0;
}


//
//int main()
//{
//	unique_ptr<Rectangle> r1 (new Rectangle(5, 2));
//
//	//unique_ptr<Rectangle> r1Copy = r1;
//	//Rectangle* r1Copy = r1;
//
//	r1->area();
//	r1.reset();
//
//}




