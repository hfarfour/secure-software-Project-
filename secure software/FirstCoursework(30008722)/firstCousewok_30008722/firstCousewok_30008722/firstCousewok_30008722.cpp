// firstCousewok_30008722.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// CS2S562_CW1M.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Created By 30008722   HOSSAM FARFOUR

#pragma once
#include <iomanip>
#include <utility>
#include <sstream>
#include <map>
#include<string>
#include  <fstream> 
#include <iostream> 
#include <thread>
#include <vector>
using namespace std;


enum LoggerType { LggerTextFile = 1, LoggerBinFile, LoggerConsole };
enum FormateType { NoFORMAT = 1, HTMLFormate, ENCFormate };
class Logger
{
	unsigned formatType;
	string encryptDecrypt(string toEncrypt) {}
public:
	Logger(unsigned aformatType = NoFORMAT) :formatType(aformatType) {};
	virtual void log(string message) = 0;
	virtual ~Logger() {};
	virtual string formatMessage(string message) {};
};

class LoggerDecorator :public Logger
{
	unsigned formatType;
	unique_ptr<Logger>contents;
	void log(string message)
	{
		message = formatMessage(message);
		contents->log(message);
	}
	string encryptDecrypt(string toEncrypt)
	{
		char key = 'A';
		string output = toEncrypt;
		for (uint16_t i = 0; i < toEncrypt.size(); i++)
			output[i] = toEncrypt[i] ^ key;
		return output;
	}

public:
	LoggerDecorator(unique_ptr<Logger>contents, uint16_t formatType)
	{
	}
	virtual string formatMessage(string message)
	{
		cout << "FORMATTING" << endl;
	}
};

class TxtFileLogger : public Logger
{
public:
	void log(string message)
	{
		cout << " Writing " << message << " to a text file\n";
	}
};
class ConsoleLogger : public Logger
{
public:
	void log(string message)
	{
		cout << " Writing " << message << "to console\n";
	}
};
class BinFileLogger : public Logger
{
public:
	void log(string message)
	{
		cout << " Writing " << message << " to a BIN file\n";
	}
};
class SimpleFileLogger
{
	string filePath;
	ofstream outputStream;
public:
	SimpleFileLogger(const string& filePath) : filePath (filePath)
	{
		outputStream.open(filePath, std::ios::out);
	}
	~SimpleFileLogger()
	{
		outputStream.close();
	}
	void log(const string& message)
	{
		outputStream << message << endl << flush;
	}
};


class Subject
{
	string id;
	string firstName;
	string lastName;

public:
	Subject(string firstN, string lastN) : firstName(firstN), lastName(lastN)
	{
	}

	Subject()
	{
	}

	void enterId()
	{
		cout << "\nEnter UserID : ";
		cin >> id;
	}
	string getId()
	{
		return id;
	}

	void enterFirstName()
	{
		cout << "\nEnter user First name :";
		cin >> firstName;
	}

	string getFirstName()
	{
		return firstName;
	}

	void enterLastName()
	{
		cout << "\nEnter user Last name :";
		cin >> lastName;
	}
	string getLastName()
	{
		return lastName;
	}

	
};

class AuthenticationInfo
{
	map<string, string >Users;
public:
	AuthenticationInfo(void)
	{
		Users.insert(pair<string , string >("1234" , "1111"));
		Users.insert(pair<string, string >("2345", "2111"));
		Users.insert(pair<string, string >("3456", "3111"));
	}
	bool validateUser(string Id, string password)
	{
		bool validUser = false;
		map<string, string >::iterator it;
		it = Users.find(Id);
		if (it !=Users.end())
		{
			if (!(it->second.compare(password))) 
			{
				validUser = true;
			}
		}
		return validUser;
	}
};



enum class MachineState { Off, On };
//
//class ReportTemperature
//{
//public:
//	MachineState currentState = MachineState::On;
//	void On()
//	{
//		currentState = MachineState::On;
//		cout << " the machine is on \n";
//	}
//	void Off()
//	{
//		currentState = MachineState::Off;
//		cout << " the machine is off \n";
//	}
//
//	MachineState getState() const
//	{
//		return currentState;
//	}
//};


class Temperature
{
	int temp{ 25 };
	int maxTemp{ 100 };
public:
	int read() const
	{
		return temp;
	}
	void write(int t)
	{
		temp = t;
	}
	void configure()
	{
		maxTemp = 100;
	}

};
class Humidity
{
	int hum{ 80 };
	int maxTemp{ 100 };
public:
	int read() const
	{
		return hum;
	}
	void write(int h)
	{
		hum = h;
	}
	void configure()
	{
		maxTemp = 100;
	}

};
class WindSpeed
{
	int speed{ 20 };
	int maxSpeed{ 100 };
public:
	int read() const
	{
		return speed;
	}
	void write(int S)
	{
		speed = S;
	}
	void configure()
	{
		maxSpeed = 100;
	}

};
class Model
{

	Temperature temp;
	Humidity hum;
	WindSpeed speed;
	string name;
	//ReportTemperature Report;
	string MachineStat = "ON";
	int samplingPeriod{ 100 };
	unique_ptr<SimpleFileLogger>logger;
public:
	Model(void)
	{
		logger = make_unique<SimpleFileLogger>("DeviceInfo.log");
		retriveDataFromDatabase();
	}

	const string getName() const
	{
		return this->name;
	}

	void setName(const string name)
	{
		this->name = name;
	}

	int getTemperature() const
	{
		return temp.read();
	}

	void setTemperature(const int t)
	{
		temp.write(t);
	}
	int getHumidity(void) const
	{
		return hum.read();
	}
	void setHumidity(const int t)
	{
		hum.write(t);
	}
	int getWindSpeed() const
	{
		return speed.read();
	}

	void setWindSpeed(const int S)
	{
		speed.write(S);
	}

	void setSampling(const int sampling)
	{
		samplingPeriod = sampling;
	}

	int getSampling(void)
	{
		return samplingPeriod;
	}

	void retriveDataFromDatabase(void)
	{
		setName("Report Air Temperature and Humidity");
		setTemperature(25);
	}

	const string getMachineState() const
	{
		return MachineStat;
	}

	void setMachineState(const string machineState)
	{
		MachineStat = machineState;
	}

	void saveDataToFile(int hour, int temp, int hum, int Report)
	{
		string output;
		output += to_string(hour);
		output += "  ";
		output += to_string(temp);
		output += "  ";
		output += to_string(hum);
		output += "  ";
		output += to_string((int)Report);
		output += "  ";
		logger->log(output);

	}
};



enum class Choice
{
	Quit,
	Information,
	login,
	Read,
	Configure,
	ReadDataFromFile,
};

class View
{
public:
	void ModelDetails(const Model& D) const
	{
		cout << "Device Name is: " << D.getName() << endl;
		cout << "Temperature is : " << D.getTemperature() << endl;
		cout << "Humidity is : " << D.getHumidity() << endl;
		cout << "Air Speed is : " << D.getWindSpeed() << endl;
	}
	Choice mainMenu()
	{
		int input = 1;
		cout << "\nIntroduction to the Air temperatur and Humidity and wind speed reporter device\n";
		cout << "\nSamrt device simulation\n";
		cout << "Select from the following options\n";
		cout << endl;
		cout << (int)(Choice::Information) << ": Information about the device\n";
		cout << (int)(Choice::login) << ": Loging in\n";
		cout << (int)(Choice::Read) << ": Read data\n";
		cout << (int)(Choice::Configure) << ": Configure\n";
		cout << (int)(Choice::ReadDataFromFile) << ": Reading data from a file \n";
		cout << (int)(Choice::Quit) << ": Quit\n";
		cout << "Your choice : ";
		cin >> input;
		return (Choice)input;

	}
	void displayData(int hour, int temp, int hum, int speed, string state)
	{
		ios init(NULL);
		init.copyfmt(cout);
		cout << setfill('0') << setw(2) << hour;
		cout.copyfmt(init);
		cout << setw(8) << temp << setw(8) << hum << setw(8) << speed << endl;
		cout << " the machine state  is always   " << state << endl << endl;
	}
	void displayHeader()
	{
		cout << " Time" << setw(7) << "Temp " << setw(7) << "Hum " << setw(7) << "    AirSpeed " << setw(7) <<  " state " << setw(7) << endl;
		cout << "[Hour]" << setw(5) << " [C]" << setw(7) << "  [%] " << setw(5) << "   [Speed] " << setw(5) << "  [ON]" << setw(7) << endl;
	}
	void message(string s)
	{
		cout << s << endl;
	}
};

enum AccessType : uint16_t
{
	NA = 0x00, //00000000 
	W = 0x04, //00000100
	R = 0x08, //00001000
	FA = 0x10  //00010000
};
ostream& operator<<(ostream& os, AccessType c)
{
	switch (c)
	{
	case NA: os << "No access";			   break;
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
	{	                                   //    0    1     2      
		userResourceAccessMap["1234"] = { FA , FA,   FA,   FA,   FA,  FA };
		userResourceAccessMap["2345"] = { W ,   W,    W,	W,   W,   W };
		userResourceAccessMap["3456"] = { R,    R,    R,    R,    R,   R };
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


class Controller
{
	string userID;
	string password;
	Model model;
	View view;
	Subject subject;
	bool logged{ false };
	
public:
	void configureSensor()
	{
		int samplingPeriod = model.getSampling();
		view.message("\nCurrent sampling Period [ms]:");
		view.message(std::to_string(samplingPeriod));
		view.message("\nEnter new sampling Period [ms]:");
		cin >> samplingPeriod;
		model.setSampling(samplingPeriod);
	}
	void readData()
	{
		int temp = model.getTemperature();
		int hum = model.getHumidity();
		int speed = model.getWindSpeed();
		string state = model.getMachineState();
		view.displayHeader();
		for (int i = 1; i <= 10; i++)
		{
			model.setTemperature(temp + rand() % 10 - 5);
			model.setHumidity(hum + rand() % 20 - 10);
			model.setWindSpeed(speed + rand() % 20 - 5);
			temp = model.getTemperature();
			hum = model.getHumidity();
			speed = model.getWindSpeed();
			string state = model.getMachineState();
			view.displayData(i, temp, hum,speed, state);
			model.saveDataToFile(i, temp, hum, speed);
			this_thread::sleep_for(chrono::milliseconds(model.getSampling()));
			this_thread::sleep_for(chrono::milliseconds(model.getSampling()));
		}
	}
	bool User(string Id, string PassWord)
	{
		bool validUser = false;
		if (!(Id.compare(userID)))
		{
			if (!(password.compare(PassWord)))
			{
				validUser = true;
			}
		}
		return validUser;
	}
	
	bool Login()
	{
		AuthenticationInfo ainfo;
		cout << "*******User Id and Password ******* " << endl;
		cout<<"1234  "<<  "1111 "<<endl;
		cout << "2345  " << "2111 " << endl;
		cout << "3456  " << "3111 " << endl;
		cout << "********************************** " << endl;
		
		subject.enterId();
		bool authenticated = false;
	    uint16_t again = 1;

		string Id = subject.getId();
		string password;
		cout << "\nEnter password :";
		cin >> password;
		while (again)
		{
			subject.enterFirstName();
			subject.enterLastName();
			cout << "\nTry again? Yes = 1 , No  = 0 :  " << endl;
			cin >> again;
		}

		if (ainfo.validateUser(Id,password)) 
		{
			cout << "\n Welcome!   " << subject.getFirstName() << "  " << subject.getLastName() << endl;
			cout << "\n Authenticated ! Logged in successfully  \n";
			authenticated = true;
		}
		else
		
			cout << "Invalid user ID or password. Please try again." << endl;
		    return authenticated;

    }
	void ReadDataFromFile()
	{
		char buffer[20];
		try
		{
			ifstream myfile("DeviceInfo.log"); // open a text file for reading
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
				//cout << "There was an error: " << e.what() << endl;
			}
		}
	}
	
	void run(void)
	{
		Choice choice = Choice::login;
		Permission permission;
		while (choice != Choice::Quit)
		{
			choice = view.mainMenu();
			switch (choice)
			{
			case Choice::Information:
				view.ModelDetails(model);
				break;
			case Choice::login:
				if (logged) view.message("You are already logged in ! ");
				else logged = Login();
				break;
			case Choice::Read:
				readData();
				break;
			case Choice::Configure:
				// check the permission for the sensors;
				if (permission.checkPermission(subject.getId(), 0) == FA)configureSensor();     
				else view.message("You do not have sufficient privileges to modify sensors");
				break;
			case Choice::ReadDataFromFile:
				cout << "======================" << endl;
				cout << "readind data from a file " << endl;
				cout << "======================" << endl;
				ReadDataFromFile();
				break;
			default:
				cout << "Good Bay ! " << endl;
				break;
			}
		}
	}
};


int main()

{
	Controller AirTemperature;
	AirTemperature.run();
	/*uint16_t loggerType;
	uint16_t userExited = 0;
	uint16_t formatType;

	while (!userExited)
	{
		cout << "\n Select logger [ 1 : txt file ,  2 : Bin File , 3 : Console ]" << endl;
		cin >> loggerType;
		cout << "\n Select Format [ 1 : NOFORMAT ,  2 : HTMAL , 3 : ENCRYPT ]" << endl;
		cin >> formatType;
		unique_ptr < Logger >logger;
		switch (loggerType)
		{
		case LggerTextFile:
			logger = make_unique<TxtFileLogger>();
			break;

		case LoggerBinFile:
			logger = make_unique<BinFileLogger>();
			break;

		case LoggerConsole:
			logger = make_unique<ConsoleLogger>();
			break;
		default:
			cout << " NO LOGGER " << endl;
		}

		switch (formatType)
		{
		case NoFORMAT:
			logger = make_unique<LoggerDecorator>(move(logger), formatType);
			break;

		case HTMLFormate:

			logger = make_unique<LoggerDecorator>(move(logger), formatType);
			break;

		case ENCFormate:

			logger = make_unique<LoggerDecorator>(move(logger), formatType);
			break;
		default:
			cout << "unknown format" << endl;
			break;
		}

		string message = " A message to log ";
		cout << " logging : " << endl;
		logger->log(message);
		cout << "\n Exit yes = 1 , No = 0 ";
		cin >> userExited;

	}
	*/
	system("pause");
	return 0;
}
