#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
class Divisor:public ExpressionEvaluator, public IShuffle
{
public:
	Divisor();
	Divisor(int n);
	double calculate();
	void logToScreen();
	void logToFile(const std::string& filename);
	void shuffle() const override;
	void shuffle(size_t i, size_t j) const override;
};

