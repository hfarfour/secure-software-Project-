#include "Authenticator.h" 
#include <time.h>  
#include <string>
#include <iostream> 
using namespace std;

bool Authenticator::authenticateUser(Subject &subject)
{
	AuthenticationInfo ainfo;
	bool authenticated = false;
	string Id = subject.getId();
	string pass;
	string token;
	cout << "\nEnter password :";
    cin >> pass;
	if (ainfo.validateUser(Id, pass))	{
			cout << "\nWelcome!";
			cout << "\nAuthenticated!\n";
			authenticated = true;
	}
	else
		cout << "Invalid user ID or password. Please try again.";
	return authenticated;

}; 

