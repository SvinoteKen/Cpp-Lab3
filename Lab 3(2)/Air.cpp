#include "Air.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Air::Air()
{
    model_ = "unknown";
    firm_ = "unknown";
    mode_ = "auto";
    year_ = 2017;
    w = 10;
    t = 0;
    p = 0;
}

Air::Air(int year, int weight, int temperature, const string model, const string firm,int power,string mode)
{
    year_ = year;
    w = weight;
    t = temperature;
    firm_ = firm;
    p = power;
    mode_ = mode;
    model_ = model;
}
void Air::control(int temperature) {
    if (temperature < 10) 
    { 
        std::cout << "Temperature below 10, turning off the air conditioner\n" << std::endl; 
        mode_ = "OFF";
        t = 0;
    }
    if (temperature >= 10 && temperature < 15) 
    {
        mode_ = "1";
        t = temperature;
    }
    if (temperature >= 15 && temperature < 20)
    {
        mode_ = "2";
        t = temperature;
    }
    if (temperature >= 20)
    {
        mode_ = "Heat";
        t = temperature;
    }
}
void Air::printInfo() {
    std::cout << firm_ << " " << model_ << " " << year_ <<"\n–ежим:" << mode_ <<", температура:" << t << ", вес:" << w<< " кг, мощность:" << p <<" к¬т"<< std::endl;
}
