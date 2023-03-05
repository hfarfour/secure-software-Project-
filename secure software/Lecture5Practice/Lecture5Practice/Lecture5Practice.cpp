#include<string>
#include  <fstream> // for ifstream
#include <iostream> // for cout
using namespace std; // for exception, ifstream and cout
//
//int main()
//{
//	char buffer[20];
//	try
//	{
//		ifstream myfile("test.txt"); // open a text file for reading
//		// ifstream does not have exceptions by default. Let’s register 3 of them to the stream:
//		myfile.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
//		while (myfile)
//		{
//			myfile.getline(buffer, 20);
//			cout << buffer << endl;
//		}
//		myfile.close();
//	}
//	/*catch (exception e)
//	{
//		cout << "There was an error: " << e.what() << endl;
//	}
//	system("pause");*/
//	catch (exception e)
//	{
//		// strstr: finds out if 2nd string is contained within 1st string.
//		// Returns a pointer to occurrence of 2nd string in 1st string
//		if (strstr(e.what(), "eofbit") != NULL)
//		{
//			cout << buffer << endl;
//			cout << "END OF FILE REACHED" << endl;
//		}
//		else
//		{
//			cout << "There was an error: " << e.what() << endl;
//		}
//	}
//	return 0;
//}
int main()
{
	char buffer[20];
	try
	{
		ifstream myfile("test.txt"); // open a text file for reading
		// ifstream does not have exceptions by default. Let’s register 3 of them to the stream:
		myfile.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
		while (myfile)
		{
			myfile.getline(buffer, 20);
			cout << buffer << endl;
		}
		myfile.close();
	}
	catch (exception e)
	{
		// strstr: finds out if 2nd string is contained within 1st string.
		// Returns a pointer to occurrence of 2nd string in 1st string
		if (strstr(e.what(), "eofbit") != NULL)
		{
			cout << buffer << endl;
			cout << "END OF FILE REACHED" << endl;
		}
		else
		{
			cout << "There was an error: " << e.what() << endl;
		}
	}
	system("pause");
	return 0;
}
