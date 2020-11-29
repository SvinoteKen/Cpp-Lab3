#include "Heater.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
Heater::Heater()
{
    model_ = "unknown";
    firm_ = "unknown";
    mode_ = "auto";
    year_ = 2017;
    w = 10;
    t = 0;
    p = 0;
}

Heater::Heater(int year, int weight, int temperature, const string model, const string firm, int power,string mode)
{
    year_ = year;
    w = weight;
    t = temperature;
    firm_ = firm;
    p = power;
    mode_ = mode;
    model_ = model;
}
void Heater::control(int temperature) 
{
    if (temperature < 10)
    {
        std::cout << "Temperature above 45, turning off the heater\n" << std::endl;
        mode_ = "OFF";
        t = 0;
    }
    if (temperature <= 45 && temperature > 35)
    {
        mode_ = "1";
        t = temperature;
    }
    if (temperature <= 35 && temperature > 25)
    {
        mode_ = "2";
        t = temperature;
    }
    if (temperature <=25)
    {
        mode_ = "Air";
        t = temperature;
    }
}
void Heater::printInfo() {
    std::cout << firm_ << " " << model_ << " " << year_ << "\n–ежим:" << mode_ << ", температура:" << t << ", вес:" << w << " кг, мощность:" << p << " к¬т" << std::endl;
}
