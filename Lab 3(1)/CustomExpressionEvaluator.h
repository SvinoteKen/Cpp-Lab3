#pragma once
#include <string>
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
class CustomExpressionEvaluator : public ExpressionEvaluator, public IShuffle 
{
public:
    CustomExpressionEvaluator();
    CustomExpressionEvaluator(int n);
    double calculate();
    void logToScreen();
    void logToFile(const std::string& filename);
    void shuffle() const override;
    void shuffle(size_t i, size_t j) const override;
};

