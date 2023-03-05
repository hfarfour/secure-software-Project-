
#include<memory>
#include <iostream>
#include <string>
using namespace std;



enum LoggerType { L_Text_File = 1, L_Bin_File, L_Console };
enum FormateType { No_FORMAT = 1, HTML_Formate, ENC_Formate };

class Logger
{
	unsigned formatType;
	string encryptDecrypt(string toEncrypt)
	{}
public:
	Logger(unsigned aformatType = No_FORMAT) :formatType(aformatType) {};
	virtual void log(string msg) = 0;
	virtual ~Logger() {};
	virtual string formatMessage(string msg) {};
};
class LoggerDecorator:public Logger
{
	uint16_t formatType;
	unique_ptr<Logger>contents;
	void log(string msg)
	{
		msg = formatMessage(msg);
		contents->log(msg);
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
	LoggerDecorator(unique_ptr<Logger>logger, uint16_t formatType) //:contents
	//{ move(Logger) }, FormateType(aformatType)
	{}
	
	virtual string formatMessage(string msg)
	{
		cout << "FORMATTING" << endl;
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

class ConsoleLogger : public Logger
	{
	public:
		void log(string msg)
		{
			cout << " Writing " << msg << "to console\n";
		}
	};
		
class BinFileLogger : public Logger 
{
		public:
			void log(string msg)
			{
				cout << " Writing " << msg << " to a BIN file\n";
			}
};


int main()

{
	uint16_t loggerType;
	uint16_t userExited=0;
	uint16_t formatType;

	while (!userExited)
	{
		cout << "\n Select logger [ 1 : txt file ,  2 : Bin File , 3 : Console ]" << endl;
		cin >> loggerType;
		cout << "\n Select Format [ 1 : NO_FORMAT ,  2 : HTMAL , 3 : ENCRYPT ]" << endl;
		cin >> formatType;
		unique_ptr < Logger >logger;
		switch (loggerType)
		{
		case L_Text_File:
			logger = make_unique<TxtFileLogger>();
			break;

		case L_Bin_File:
			logger = make_unique<BinFileLogger>();
			break;

		case L_Console:
			logger = make_unique<ConsoleLogger>();
			break;
		default:
			cout << " NO LOGGER " << endl;
		}

		switch (formatType)
		{
		case No_FORMAT:
			logger = make_unique<LoggerDecorator>(move(logger), formatType);
			break;

		case HTML_Formate:

			logger = make_unique<LoggerDecorator>(move(logger), formatType);
			break;

			break;
		case ENC_Formate:

			logger = make_unique<LoggerDecorator>(move(logger), formatType);
			break;

			break;

		default:
			cout << "unknown format" << endl;
			break;
		}
	
		string mag = " A message to log ";
		cout << " logging : " << endl;
		logger->log(mag);
		cout << "\n Exit yes = 1 , No = 0 ";
		cin >> userExited;

	}
	return 0;
}

