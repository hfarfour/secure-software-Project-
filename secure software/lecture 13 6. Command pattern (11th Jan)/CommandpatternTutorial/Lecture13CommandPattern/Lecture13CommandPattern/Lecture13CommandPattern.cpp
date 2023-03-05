// Lecture13CommandPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
using namespace std;



enum comandType { off, on };
enum receiverType { r_empty, r_light, r_fan };

class Command
{
public:
	virtual void execute() = 0;
};

class Receiver
{
public:
	virtual void on() = 0;
	virtual void off() = 0;
   virtual void increase() = 0;
};

class OnCommand : public Command
{
	Receiver* mReceiver;
public:
	OnCommand(Receiver* receiver) : mReceiver(receiver)
	{
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
	}
	void execute() override
	{
		mReceiver->off();
	}
};


class Light : public Receiver
{
	int intensity{ 0 };
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
	void increase()
	{
		intensity = intensity + 30;
		cout << "speed increase . speed = " << intensity << "\n";
	}
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
	void increase()
	{
		speed = speed + 30;
		cout << "speed increase . speed = " << speed << "\n";
	}
};
class Increase :public Command
{
	Receiver* mReceiver;
public:
	Increase(Receiver* receiver) :mReceiver(receiver)
	{
	}
	void execute() override
	{
		mReceiver->increase();
	}
};

class RemoteControl
{
	vector<Command*> mCmd;
public:
	RemoteControl()
	{
		mCmd.resize(4, nullptr);
	}
	void setCommand(int slot, Command* cmd)
	{
		if (slot >= 0 && slot < mCmd.size())
		{
			mCmd[slot]  = cmd ;                           /////////////////////////////////////////////////
		}
		else
		{
			cout << "Error, receiver can notbe set , slot = "<<slot<<"does not exist !\n\n";
		}
	}
	void buttonPressed(int slot)
	{
		if (slot >= 0 && slot < mCmd.size()) 
		{
			cout << "command " << slot << " executed ";
			mCmd[slot]-> execute();
		}
		else 
		{
			cout << "Error, command can not be excuted slot = " << slot << " does not exist!\n\n";
		}
	}
};


int main()
{
	/*RemoteControl control;
	control.setReceiver(0, light);
	control.setReceiver(1, light);
	control.setReceiver(2, fan);
	control.setReceiver(3, fan);


	control.buttonPressed(0, comandType::on);
	control.buttonPressed(1, comandType::off);
	control.buttonPressed(2, comandType::on);
	control.buttonPressed(3, comandType::off);

	delete light;
	delete fan;*/
	
	//	("14.8.9.28") compelete
	//	("14.8.9.29") little
	//	("14.8.9.30") bogus


	RemoteControl control;
	vector<Receiver*> receivers = { new Light,new Fan };
	vector<Command*> commands = {
		new  OnCommand(receivers[1]),
		new  Increase(receivers[1]),
		new  OffCommand(receivers[1]),

		new  OnCommand(receivers[0]) ,
		new  Increase(receivers[0]),
		new  OffCommand(receivers[0]) };


	for (int slot = 0; slot < commands.size(); slot++)
		control.setCommand(slot, commands[slot]);

	for (int slot = 0; slot < commands.size(); slot++)
		control.buttonPressed(slot);

	for (int slot = 0; slot < receivers.size(); slot++)
		delete receivers[slot];

	for (int slot = 0; slot < commands.size(); slot++)
		delete commands[slot];

	cout << '\n';
	system("pause");
	return 0;
}