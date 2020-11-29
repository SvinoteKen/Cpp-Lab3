#include "Divisor.h"
#include <iostream>
#include <fstream>
using namespace std;
Divisor::Divisor() : ExpressionEvaluator()
{

}

Divisor::Divisor(int n) : ExpressionEvaluator(n)
{

}
double Divisor::calculate()
{
	double res = ops_[0];
	for (int i = 1;i < n_;++i)
	{
		res /= ops_[i];
	}
	return res;
}
void Divisor::logToScreen()
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
			cout <<'/'<< ops_[i] ;
		}
		else
		{
			cout << '/' << '(' << ops_[i] << ')' ;
		}
	}

}

void Divisor::logToFile(const string& filename)
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
			myfile << '/' << ops_[i];
		}
		else
		{
			myfile << '/' << '(' << ops_[i] << ')';
		}
	}
	myfile << "< Total " << getN() << " >";
	myfile << "< Result " << calculate() << " >\n";
}
void Divisor::shuffle() const
{
	double temp;
	for (int i = 0; i < n_; i++)
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
void Divisor::shuffle(size_t i, size_t j) const
{
	if (ops_[i] == ((double)((int)ops_[i])) || ops_[j] == ((double)((int)ops_[j])))
	{
		swap(ops_[i], ops_[j]);
	}
}