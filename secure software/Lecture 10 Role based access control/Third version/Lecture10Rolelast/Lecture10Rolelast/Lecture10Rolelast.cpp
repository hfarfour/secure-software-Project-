// Lecture10Rolelast.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


enum AccessType : uint16_t
{
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
	map< string, resources> userResourceAccessMap;
public:
	Permission()
	{
		                              //    0        1             2         3     4     5        	   //resourceID		
		userResourceAccessMap["0123"] = { FA ,      FA,          FA,	    FA,   FA,   FA };			//Janusz
		userResourceAccessMap["0124"] = { E | W , E | W | R,  E | W | R,    E,    E,    E };			//Louise
		userResourceAccessMap["0125"] = { E | W , E | W | R,  E | W | R,	E,    E,    E };			//John
		userResourceAccessMap["0126"] = { NA ,      R,          W | R ,	    R,    NA,   R };			//Peter
		userResourceAccessMap["0127"] = { NA ,      R,          W | R ,	    R,    NA,   R };	 	    //Fred
		userResourceAccessMap["0128"] = { NA ,      R,          W | R ,	    R,    NA,   R };		    //Barbara

	}
	uint16_t checkPermission(string subjectId, uint32_t resourceId)
	{
		map<string, resources>::iterator it;
		it = userResourceAccessMap.find(subjectId);
		if (it != userResourceAccessMap.end())
			if (resourceId <= it->second.size())
				return it->second[resourceId];
			else cout << "Resource id = " << resourceId << " not found\n";
		else cout << "Subject id = " << subjectId << " not found\n";
		return NA;
	}
};

class Role
{
	map< string, string> userResourceAccessMap;
public:
	Role()
	{
		                           	
		userResourceAccessMap["0123"] = {"Administrator" };			
		userResourceAccessMap["0124"] = {"Lecturer"};			
		userResourceAccessMap["0125"] = { "Lecturer" };
		userResourceAccessMap["0126"] = { "Student" };			
		userResourceAccessMap["0127"] = { "Student" };	 	    
		userResourceAccessMap["0128"] = { "Student" };

	}
	string getRoleName(string _id)
	{
		map<string, string >::iterator it;
		it = userResourceAccessMap.find(_id);
		if (it != userResourceAccessMap.end())
			return it->second;

		else return "Guest";
	}
};

class Subject {
	string id;
	string role;
	//name, surname etc
	//attributes omitted for brevity
public:
	Subject(string _id) :id(_id)
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

	//methods omitted for brevity
};


class Resource {
	string secret;
	AccessType accessType;
	uint32_t id;
public:
	Resource(const Subject& subject, Permission& permission, uint32_t _id = 0, AccessType _aT = NA) :
		id(_id), accessType(NA)
	{
		if (permission.checkPermission(subject.getId(), _id) & (_aT | FA))
		{
			accessType = _aT;
			cout << accessType << " to the resource id=" << _id << " granted\n";
			secret = "**********secret stuff*****************";
		}
		else cout << _aT << " to resource id=" << _id << " denied";
	}
	uint32_t getId(void)
	{
		return id;
	}
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
		if (accessType & (E | FA))
			cout << "\nrunning some query...";
		else cout << "\nNot authorised to runSomeQuery";
	}
	~Resource()
	{
		cout << "\nresource destroyed!";
	}
};




int main()
{
	Subject subject("0123");
	Permission permission;
	{
		Resource r(subject, permission, 1, FA); //subject, permission, id, accesstype
		cout << r.getSecret();
		r.runSomeQuery();
	}

	cout << endl;
	system("pause");
	return 0;
}
