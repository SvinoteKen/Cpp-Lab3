#pragma once
#include "ExpressionEvaluator.h"

class Multiplier : public ExpressionEvaluator 
{
public:
    Multiplier();
    Multiplier(int n);
    double calculate();
    void logToScreen();
    void logToFile(const std::string& filename);
};

