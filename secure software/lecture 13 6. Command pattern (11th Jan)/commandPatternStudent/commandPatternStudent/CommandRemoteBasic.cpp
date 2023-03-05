#include <iostream>
#include <vector>
using namespace std;


class Command 
{
public:
	virtual void execute(void) = 0;
};


class Receiver 
{
public:
	virtual void on(void) = 0;
	virtual void off(void) = 0;
};


class Light : public Receiver 
{
	int intensity{0};
public:
	void on(void) override {
		intensity = 50;
		cout << "The light is on, intensity =" 
			<< intensity << "\n";
	}
	void off(void) override {
		cout << "The light is off\n";
	}
};


class OnCommand : public Command 
{
	Receiver* mReceiver;
public:
	OnCommand(Receiver *receiver): mReceiver(receiver) 
	{
	}
	void execute(void) override {
		mReceiver->on();
	}
};

class OffCommand : public Command 
{
	Receiver* mReceiver;
public:
	OffCommand(Receiver *receiver) :
		mReceiver(receiver) {}
	void execute(void) override {
		mReceiver->off();
	}
};

class RemoteControl
{
	vector<Command*> mCmd;
public:
	RemoteControl(void) { mCmd.resize(4, nullptr); }
	void setCommand(int slot, Command *cmd) {
		if (slot >= 0 && slot < mCmd.size()) 
			mCmd[slot] = cmd;
		else {
			cout << "Error, command does not exist\n";
		}
	}
	void buttonPressed(int slot) {
		if (slot >= 0 && slot < mCmd.size()) {
			cout << "command " << slot << " executed ";
			mCmd[slot]->execute();
		}
		else {
			cout << "Error, command can't be executed, slot = " 
				<< slot << " does not exist!\n\n";
		}
	}
};


int main(void)
{
	RemoteControl control;
	vector<Receiver*> receivers = { new Light };
	vector<Command*> commands = {
		new  OnCommand(receivers[0]),
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