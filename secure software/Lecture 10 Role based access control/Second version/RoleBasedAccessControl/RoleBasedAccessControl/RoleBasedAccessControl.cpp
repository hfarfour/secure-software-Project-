// RoleBasedAccessControl.cpp : This file contains the 'main' function. Program execution begins and ends there.
// checking the roles and not just ResourseID
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


enum AccessType : uint16_t {
	NA = 0x00, //00000000 
	CO = 0x01, //00000001
	E = 0x02, //00000010
	W = 0x04, //00000100
	R = 0x08, //00001000
	FA = 0x10  //00010000
};

ostream& operator<<(ostream& os, AccessType c)
{
	switch (c)
	{
	case NA: os << "No access";			   break;
	case CO: os << "Copy access";		   break;
	case E:  os << "Execute access";       break;
	case W:  os << "Write access";         break;
	case R:  os << "Read access";          break;
	case FA: os << "Full Access";		   break;
	default: os.setstate(ios_base::failbit);
	}
	return os;
}

class Permission
{
	typedef vector<uint16_t> resources;
	map< string, resources> roleResourceAccessMap;
public:
	Permission()
	{
		                                      //    0        1             2         3     4     5         //resourceID		
		roleResourceAccessMap["Administrator"] = { FA ,      FA,          FA,	    FA,   FA,   FA };
		roleResourceAccessMap["Lecturer"] =      { E | W , E | W | R,  E | W | R,    E,    E,    E };			
		roleResourceAccessMap["Student"] =       { NA ,      R,          W | R ,	 R,    NA,   R };			
	
	}
	uint16_t checkPermission(string role, uint32_t resourceId)
	{
		map<string, resources>::iterator it;
		it = roleResourceAccessMap.find(role);
		if (it != roleResourceAccessMap.end())
			if (resourceId <= it->second.size())
				return it->second[resourceId];
			else cout << "Resource id = " << resourceId << " not found\n";    
		else cout << "Role = " << role << " not found\n";
		return NA;
	}
};

class Subject {
	string id;
	string role;
	//name, surname etc
	//attributes omitted for brevity
public:
	Subject(string _id,string _role) : id(_id),role(_role)
	{
	}
	string getId() const
	{
		return id;
	}
	string getRole() const
	{
		return role;
	}	
};


class Resource
{
	string secret;
	AccessType accessType;
	uint32_t id;
public:
	Resource(const Subject& subject, Permission& permission, uint32_t _id = 0, AccessType _aT = NA) :id(_id), accessType(NA) 
	{
		if (permission.checkPermission(subject.getRole(), _id) & (_aT | FA))
		{
			accessType = _aT;
			cout << subject.getRole() << " to the resource id=" << _id << " granted\n";
			secret = "**********secret stuff*****************";
		}
		else cout << _aT << " to resource id=" << _id << " denied";
	}
	uint32_t getId() 
	{
		return id;
	};
	string getSecret() const 
	{
		if (accessType & (R | FA))
			return secret;
		else return "\nNo access to getSecret()";
	}
	void setSecret(string s) 
	{
		if (accessType & (W | FA)) secret = s;
		else cout << "\nNo access to setSecret()";
	}
	void runSomeQuery(void)
	{
		if (accessType & (E | FA)) cout << "\nrunning some query...";
		else cout << "\nNot authorised to runSomeQuery";
	}
	~Resource() 
	{
		cout << "\nresource destroyed!";
	}
};




int main()
{
	Subject subject("0123","Student");
	Permission permission;
	{
		Resource r(subject, permission, 1, R); //subject, permission, id, accesstype
		cout << r.getSecret();
		r.runSomeQuery();
	}

	cout << endl;
	system("pause");
	return 0;
}
