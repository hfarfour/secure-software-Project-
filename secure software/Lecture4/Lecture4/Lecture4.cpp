#include<iomanip>
#include <iostream>
using namespace std;

void main()
{
    float a;
    cout << "enter a floating point number " << endl;
    cin >> a;

    cout << " you entered : " << fixed << setprecision(3) << a << endl;
    printf("\n\n");
    system("pause");
}

