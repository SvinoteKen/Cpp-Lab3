#pragma once
#include <string>
using namespace std;
class Device
{
public:
    virtual void printInfo() = 0;
    virtual ~Device() {}
protected:
	string model_;
	string firm_;
	string mode_;
	int w;
	int t;
	int year_;
	int p;
};

