#include "ExpressionEvaluator.h"
ExpressionEvaluator::ExpressionEvaluator() 
{
    n_ = 20;
    ops_ = new double[n_];
    for (int i = 0; i < n_; ++i) 
    {
        ops_[i] = 0;
    }
}
ExpressionEvaluator::ExpressionEvaluator(int n) 
{
    n_ = n;
    ops_ = new double[n];
    for (int i = 0; i < n; ++i) 
    {
        ops_[i] = 0;
    }
}
ExpressionEvaluator::~ExpressionEvaluator() 
{
    delete[] ops_;
}
void ExpressionEvaluator::setOperand(size_t pos, double value) 
{
    ops_[pos] = value;
}
void ExpressionEvaluator::setOperands(double ops[], size_t n) 
{
    for (int i = 0; i < n; ++i) 
    {
        ops_[i] = ops[i];
    }
}
int ExpressionEvaluator::getN() 
{
    return n_;
}
