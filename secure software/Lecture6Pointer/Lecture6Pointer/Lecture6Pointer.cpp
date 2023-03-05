using namespace std;
#include <iostream>

/*int main()
{
    //uint16_t x = 65534;
    //uint16_t* p;		// Declare a pointer p of type uint16_t* 

    //p = &x;				// Make the pointer point to the address of x
    //cout << "The storage address of content " << *p << " is " << p << endl;
    //++* p;				// increment the content
    //cout << "The storage address of content " << *p << " is " << p << endl;
    //++p;				// increment the pointer - may be anything there
    //cout << "The storage address of content " << *p << " is " << p << endl;
    cout << "=========================================================" << endl;




    //   cout << "=========================================================" << endl;

    //   uint32_t nums[] = { 10,20,30,40,50 };	// an array of 5 int
    //   uint32_t*p = nums;							// p points to nums[0]

    //   for (int i = 0; i < 7; i++)	 // deliberate buffer over-run mistake here with y<7
    //   {
    //cout << "nums["<< i << "]content:" << nums[i] <<"and address is:"<< &nums[i] <<"same as:" << p << endl;
    //   }
    //   

       //FILE* fp;
       //int error = fopen_s(&fp, fileName, "r");
       ////error is 0 if no file
       //if (error)
       //{
       //    cout << "Could not open file" << endl;
       //    system("pause");
       //}
}*/

/*void printArray(int *arr)
{
    for (int i = 0; i < 6; ++i)
    {
        cout << "Element " << i << " is: " << arr[i] << endl;
    }
}

int main()
{
    int x[6] = { 100, 200, 300, 400, 500, 600 };

    printArray(x);

    system("Pause"); // creates 'Any key to continue'
    return 0;
}*/


int main()
{
    int x[6] = { 100, 200, 300, 400, 500, 600 };
    int* y = x;

    cout << "*y is: " << *y << endl;
    ++y;
    cout << "*y is: " << *y << endl;
   y++;
    cout << "*y is: " << *y << endl;
    /*y+=1;
    cout << "*y is: " << *y << endl;*/
    y ++;
    cout << "*y is: " << *y << endl;
    y += 1;
    cout << "*y is: " << *y << endl;
    y += 1;
    cout << "*y is: " << *y << endl;
  /*  y = y + 10;
    cout << "*y is: " << *y << endl;*/

    cout << "=========================================================" << endl;

  
    



    system("Pause"); // creates 'Any key to continue'


    return 0;
}







