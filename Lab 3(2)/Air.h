#pragma once
#include <string>
#include "IControllable.h";
#include "Device.h";
using namespace std;
class Air:public IControllable, public Device
{
public:
	Air();
	Air(int year, int weight, int temperature, const string model, const string firm, int power,const string mode);
	virtual ~Air() {}
	void control(int temperature) override;
	void printInfo() override;
};

