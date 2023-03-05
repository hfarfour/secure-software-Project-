#include "Model.h"

	Model::Model(void) { retriveDataFromDatabase(); }

	const std::string Model::getName(void) const {
		return this->name;
	}
	void Model::setName(const std::string name) {
		this->name = name;
	}
	int Model::getTemperature(void) const {
		return temp;
	}
	void Model::setTemperature(const int t) {
		temp = t;
	}
	void Model::setSampling(const int sampling) {
		samplingPeriod = sampling;
	}
	int Model::getSampling(void) {
		return samplingPeriod;
	}
	void Model::retriveDataFromDatabase(void) {
		setName("Greenhouse");
		setTemperature(25);
	}


