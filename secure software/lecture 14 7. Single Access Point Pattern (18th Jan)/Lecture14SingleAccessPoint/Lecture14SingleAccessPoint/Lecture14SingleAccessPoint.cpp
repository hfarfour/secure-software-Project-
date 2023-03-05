// Lecture14SingleAccessPoint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<Map>
#include <iostream>
#include <vector>
using namespace std;



enum comandType { off, on };
enum receiverType { r_empty, r_light, r_fan };
enum TrustLevel {bogus , little , complete };


class Trust
{
	map<string, TrustLevel>trustMap;

public:
	Trust()
	{
		trustMap["14.8.9.28"] = TrustLevel::complete;
		trustMap["14.8.9.29"] = TrustLevel::little;
		trustMap["14.8.9.30"] = TrustLevel::bogus;
	}
	TrustLevel getTrustLevel(string ip)
	{
		map<string, TrustLevel>::iterator it;
		it = trustMap.find(ip);
		if (it != trustMap.end())
			return it->second;
		else
			return TrustLevel::bogus;
	}
};

class Subject
{
	string ipAddr{ "0.0.0.0" };
	TrustLevel trustlevel { TrustLevel::bogus };  // initialise the defualt level of trust  
public:
	Subject(string newIpAddr)
	{
		Trust t;
		trustlevel = t.getTrustLevel(ipAddr);
	}
	~Subject()
	{ 
		ipAddr = "0.0.0.0";
		trustlevel = TrustLevel::bogus;   // when the subject destroyed reinitialise to default level 
	}
	TrustLevel getTrustLevel() const  // geting the level of trust 
	{
		return trustlevel;
	}
	string getIpAddr() const // getting the IP address 
	{
		return ipAddr;
	}
};

class Command
{
public:
	string name;  // 
	virtual void execute() = 0;
};

class Receiver
{
public:
	virtual void on() = 0;
	virtual void off() = 0;
	//virtual void increase() = 0;
	//virtual void execute() = 0;
	
};

class Light : public Receiver
{
	int intensity { 0 };
public:
	void on() override
	{
		intensity = 50;
		cout << "The light is on, intensity =" << intensity << "\n";
	}
	void off() override
	{
		cout << "The light is off\n";
	}
	/*void increase()
	{
		intensity = intensity + 30;
		cout << "speed increase . speed = " << intensity << "\n";
	}*/
};

class Fan : public Receiver
{
	int speed{ 0 };
public:
	void on() override
	{
		speed = 80;
		cout << " the fan is on ,the speed is  = " << speed << "\n";
	}
	void off() override
	{
		cout << " the fan is off \n";
	}
	/*void increase()
	{
		speed = speed + 30;
		cout << "speed increase . speed = " << speed << "\n";
	}*/
};
//class Increase :public Command
//{
//	Receiver* mReceiver;
//public:
//	Increase(Receiver* receiver) :mReceiver(receiver)
//	{
//	}
//	void execute() override
//	{
//		mReceiver->increase();
//	}
//};

class OnCommand : public Command
{
	Receiver* mReceiver;
public:
	OnCommand(Receiver* receiver) : mReceiver(receiver) 
	{
		name = "OnCommand ";
	}
	void execute() override
	{
		mReceiver->on();
	}
};

class OffCommand : public Command
{
	Receiver* mReceiver;
public:
	OffCommand(Receiver* receiver) : mReceiver(receiver)
	{
		name = "OffCommand ";   // name of the command we would like to use
	}
	void execute() override
	{
		mReceiver->off();
	}
};

class CommandChecker
{
	map<string, TrustLevel> commands;
	bool checkCredentials(TrustLevel l, string calledMethodName)
	{
		map<string, TrustLevel>::iterator it = commands.find(calledMethodName);
		if (it != commands.end())
		{
			TrustLevel t = it->second;
			if (1 >= t) return true;
			else
				return false;
		}
	}
	public:
		CommandChecker()
		{
			commands["OnCommand"] = { TrustLevel::complete };
			commands["OffCommand"] = { TrustLevel::little };
		}
		bool accessAllowed(const Subject client, string calledMethodName)
		{
			if (!(checkCredentials(client.getTrustLevel(), calledMethodName)))
			{
				cout << "the client trust level is not sufficient to execute method " + calledMethodName << endl;
				return false;
			}
			else
			return true;
		}
};
class RemoteControl
{
private:
	vector<Command*> mCmd;
	CommandChecker cmdChecker;
public:
	RemoteControl()
	{
		mCmd.resize(4, nullptr);
	}
	void setCommand(int slot, Command* cmd)
	{
		if (slot >= 0 && slot < mCmd.size())
		{
			mCmd[slot] = cmd;
		}
		else
		{
			cout << "Error, receiver can notbe set , slot = " << slot << "does not exist !\n\n";
		}
	}
	void buttonPressed(int slot,const Subject client)
	{
		if (slot >= 0 && slot < mCmd.size())
		{
			if (cmdChecker.accessAllowed(client , mCmd[slot]-> name))
			{
				cout << "command " << slot << " executed ";
				mCmd[slot]->execute();
			}
		}
		else
		{
			cout << "Error, command can not be excuted slot = " << slot << " does not exist!\n\n";
		}
	}
};


int main()
{
	Subject currSubject = Subject("14.8.9.28");
//	("14.8.9.28") compelete
//	("14.8.9.29") little
//	("14.8.9.30") bogus

	RemoteControl control;
	vector<Receiver*> receivers = { new Light,new Fan };
	vector<Command*> commands = {
		new  OnCommand(receivers[1]),
		//new  Increase(receivers[1]),
		new  OffCommand(receivers[1]),


		new  OnCommand(receivers[0]) ,
		//new  Increase(receivers[0]),
		new  OffCommand(receivers[0]) };


	for (int slot = 0; slot < commands.size(); slot++)
		control.setCommand(slot, commands[slot]);

	for (int slot = 0; slot < commands.size(); slot++)
		control.buttonPressed(slot,currSubject);

	for (int slot = 0; slot < receivers.size(); slot++)
		delete receivers[slot];

	for (int slot = 0; slot < commands.size(); slot++)
		delete commands[slot];

	cout << '\n';
	system("pause");
	return 0;
}