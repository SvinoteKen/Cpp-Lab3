#include "CustomExpressionEvaluator.h"
#include <iostream>
#include <fstream>
using namespace std;
CustomExpressionEvaluator::CustomExpressionEvaluator() : ExpressionEvaluator() 
{

}

CustomExpressionEvaluator::CustomExpressionEvaluator(int n) : ExpressionEvaluator(n) 
{

}
double CustomExpressionEvaluator::calculate() {
    double res= ops_[0];
    for (int i = 1;i < n_;++i) 
    {
        if (i % 2 != 0) 
        {
            res += ops_[i];
        }
        else 
        { 
            res *= ops_[i];
        }
           
    }
    return res;
}
void CustomExpressionEvaluator::logToScreen() 
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
        if (i % 2 == 0)
        {
            cout << "+";
        }
        else
        {
            cout << "*";
        }

        if (ops_[i] >= 0)
        {
            cout << ops_[i] ;
        }
        else
        {
            cout << '(' << ops_[i] << ')' ;
        }
        
    }
}

void CustomExpressionEvaluator::logToFile(const string& filename)
{
    ofstream myfile(filename, std::ios_base::app | std::ios_base::out);
    //log << "Log Record\n";
    //myfile.open(filename);
    for (int i = 0; i < n_;++i) 
    {
        if (ops_[i] >= 0)
        {
            myfile << ops_[i];
        }
        else
        {
            myfile << '(' << ops_[i] << ')';
        }
        if (i % 2 == 0)
        {
            myfile << "+";
        }
        else
        {
            myfile << "*";
        }
    }
    myfile << "< Total " << getN() << " >";
    myfile << "< Result " << calculate() << " >\n" ;

}
void CustomExpressionEvaluator::shuffle() const 
{
    double temp;
    for (int i = 0; i < n_; ++i)
    {
        for (int j = i; j < n_; j++)
        {
            if (ops_[j] < ops_[i])
            {
                temp = ops_[j];
                ops_[j] = ops_[i];
                ops_[i] = temp;
            }
        }
    }
}
void CustomExpressionEvaluator::shuffle(size_t i, size_t j) const 
{
    if (ops_[i] == ((double)((int)ops_[i])) || ops_[j] == ((double)((int)ops_[j])))
    {
        swap(ops_[i], ops_[j]);
    }
}
