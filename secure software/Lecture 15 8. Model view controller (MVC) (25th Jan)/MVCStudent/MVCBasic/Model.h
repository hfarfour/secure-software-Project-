#pragma once
using namespace std;
#include <string>

	class Model {
		int temp {25};
		string name;
		int samplingPeriod {500};
	public:
		Model(void);

		const string getName(void) const;

		void setName(const std::string name);

		int getTemperature(void) const;

		void setTemperature(const int temp);
				
		void setSampling(const int sampling);

		int getSampling(void);

		void retriveDataFromDatabase(void);
	};



