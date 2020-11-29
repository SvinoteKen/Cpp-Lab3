#include <iostream>
#include <fstream>
#include "Device.h"
#include "Air.h"
#include "Heater.h"
/*Дополнить код задания 3 лабораторной работы № 2, написав еще два класса по
предметной области, в соответствии с вариантом.Продумать и корректно реализовать
схему наследования классов.В главной функции продемонстрировать применение
интерфейса, полиморфизм и RTTI на примере 3 - 4 объектов классов, по аналогии с
заданием 1.*/
int main()
{
   /* Класс КОНДИЦИОНЕР + классы БЫТОВОЕ УСТРОЙСТВО, ОБОГРЕВАТЕЛЬ.
      Реализовать схему наследования классов и корректно распределить по классам данные :
      фирма, модель, вес, температура, режим, год выпуска, мощность.
      Интерфейс возможности управления / регулировки устройства IControllable с
      методом void control(int temperature) – отрегулировать устройство в зависимости
      от установленной в параметре температуры.Реализация метода в классе кондиционера :
      если температура задана меньше 10 градусов, то выдать сообщение и выключиться,
      иначе присвоить текущему режиму разный номер в зависимости от температуры(т.е.
      выставить режим).Реализация метода в классе обогревателя : если задана температура
      выше 45 градусов, то выдать сообщение и выключиться, иначе присвоить текущему
      режиму разный номер в зависимости от температуры.В main() создать 2 кондиционера
      и 1 обогреватель, продемонстрировать полиморфизм control().*/
    setlocale(LC_ALL, "Russian");
    Device* devices[3];
    Air* a1 = new Air(2017, 11,3, "FTXZ50N", "DAIKIN",7,"OFF");
    devices[0] = a1;
    Air* a2 = new Air(2020, 12, 20, "AR 18 RSFP", "SAMSUNG",8,"2");
    devices[1] = a2;
    Heater* h1 = new Heater(2019, 10, 64, "TP-700", "TermoPlaza", 9,"OFF");
    devices[2] = h1;
    for (auto& device : devices) 
    {
       device->printInfo();
       std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    IControllable* controlable[3];
    controlable[0]= dynamic_cast<IControllable*>(devices[0]);
    controlable[1] = dynamic_cast<IControllable*>(devices[1]);
    controlable[2] = dynamic_cast<IControllable*>(devices[2]);
    if (controlable[0] != nullptr) 
    {
        controlable[0]->control(20);
        devices[0]->printInfo();
        std::cout << std::endl;
    }
    if (controlable[1] != nullptr)
    {
        controlable[1]->control(9);
        devices[1]->printInfo();
        std::cout << std::endl;
    }
    if (controlable[2] != nullptr)
    {
        controlable[2]->control(38);
        devices[2]->printInfo();
        std::cout << std::endl;
    }
    for(auto& device : devices) 
    {
        delete device;
    }
}