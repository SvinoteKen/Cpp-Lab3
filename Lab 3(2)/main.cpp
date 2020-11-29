#include <iostream>
#include <fstream>
#include "Device.h"
#include "Air.h"
#include "Heater.h"
/*��������� ��� ������� 3 ������������ ������ � 2, ������� ��� ��� ������ ��
���������� �������, � ������������ � ���������.��������� � ��������� �����������
����� ������������ �������.� ������� ������� ������������������ ����������
����������, ����������� � RTTI �� ������� 3 - 4 �������� �������, �� �������� �
�������� 1.*/
int main()
{
   /* ����� ����������� + ������ ������� ����������, ������������.
      ����������� ����� ������������ ������� � ��������� ������������ �� ������� ������ :
      �����, ������, ���, �����������, �����, ��� �������, ��������.
      ��������� ����������� ���������� / ����������� ���������� IControllable �
      ������� void control(int temperature) � �������������� ���������� � �����������
      �� ������������� � ��������� �����������.���������� ������ � ������ ������������ :
      ���� ����������� ������ ������ 10 ��������, �� ������ ��������� � �����������,
      ����� ��������� �������� ������ ������ ����� � ����������� �� �����������(�.�.
      ��������� �����).���������� ������ � ������ ������������ : ���� ������ �����������
      ���� 45 ��������, �� ������ ��������� � �����������, ����� ��������� ��������
      ������ ������ ����� � ����������� �� �����������.� main() ������� 2 ������������
      � 1 ������������, ������������������ ����������� control().*/
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