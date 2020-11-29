#include "Multiplier.h"
#include <iostream>
#include <fstream>
using namespace std;
Multiplier::Multiplier() : ExpressionEvaluator() 
{

}

Multiplier::Multiplier(int n) : ExpressionEvaluator(n) 
{

}
double Multiplier::calculate() 
{
    double res=ops_[0];
    for (int i = 1;i < n_;++i) 
    {
         res *= ops_[i]; 
    }
    return res;
}
void Multiplier::logToScreen() 
{
    if (ops_[0] >= 0)
    {
        cout << ops_[0];
    }
    else
    {
        cout << '(' << ops_[0] << ')';
    }
    for (int i = 1; i < n_;++i) 
    {
        if (ops_[i] >= 0) 
        {
            cout << "*"<< ops_[i] ;
        }
        else
        {
            cout << '(' << ops_[i] << ')' << "*";
        }
    }
}

void Multiplier::logToFile(const string& filename)
{
    ofstream myfile(filename, std::ios_base::app | std::ios_base::out);
    //myfile.open(filename);
    if (ops_[0] >= 0)
    {
        myfile << ops_[0];
    }
    else
    {
        myfile << '(' << ops_[0] << ')';
    }
    for (int i = 1; i < n_;++i) 
    {
        if (ops_[i] >= 0)
        {
            myfile << "*" << ops_[i] ;
        }
        else
        {
            myfile << "*" << '(' << ops_[i] << ')';
        }
    }
    myfile << "< Total " << getN() << " >";
    myfile <<"< Result "<< calculate()<<" >\n";

}
