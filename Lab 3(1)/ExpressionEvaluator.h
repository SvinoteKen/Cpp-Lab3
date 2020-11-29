#pragma once
#include "ILoggable.h"
#include <string>

class ExpressionEvaluator : public ILoggable {
public:
    ExpressionEvaluator();
    ExpressionEvaluator(int n);
    virtual ~ExpressionEvaluator();
    void setOperand(size_t pos, double value);
    void setOperands(double ops[], size_t n);
    virtual double calculate() = 0;
    int getN();
protected:
    size_t n_;
    double* ops_;
};
