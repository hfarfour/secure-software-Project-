#pragma once
using namespace std;
#include <string>
#include <iostream>
#include <memory>


class Logger
{
public:
	virtual void log(string msg) = 0;
	virtual ~Logger() {};
};

class ConsoleLogger : public Logger
{
public:
	void log(string msg)
	{
		cout << " Writing " << msg << "to console\n";
	}
};

class TxtFileLogger : public Logger
{
public:
	void log(string msg)
	{
		cout << " Writing " << msg << " to a text file\n";
	}
};


enum LoggerType { L_TEXT_FILE = 1, L_BIN_FILE, L_CONSOLE };
enum FormatType { NO_FORMAT = 1, HTML_FORMAT, ENC_FORMAT };


using namespace std;

int main(void)
{
	uint16_t loggerType;       // variable to store the input
	uint16_t userExited = 0;   // user has not chosen to exit

	// loop while user has not chosen option to exit system
	while (!userExited)
	{
		cout << "\n SELECT LOGGER [1: TXT FILE, 2: CONSOLE] : ";
		cin >> loggerType;

		unique_ptr< Logger> logger;
		switch (loggerType) {
		case L_TEXT_FILE:
			logger = make_unique<TxtFileLogger>();

			break;
		case L_CONSOLE:
			logger = make_unique<ConsoleLogger>();
			break;
		default:
			cout << "NO LOGGER" << endl;
			break;
		} //switch

		cout << " Logging: ";
		logger->log("A message to log");   // virtual dispatch
		cout << "\n EXIT Yes = 1 , No  = 0 : ";
		cin >> userExited;
	}//while
	return 0;
}

