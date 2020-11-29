#pragma once
#include <string>
#include "IControllable.h";
#include "Device.h";
using namespace std;
class Heater: public IControllable, public Device
{
public:
	Heater();
	Heater(int year, int weight, int temperature, const string model, const string firm, int power,const string mode);
	virtual ~Heater() {}
	void control(int temperature) override;
	void printInfo() override;
};

