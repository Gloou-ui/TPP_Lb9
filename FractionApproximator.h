#pragma once

#include "Rational.h"

class FractionApproximator {
public:
    explicit FractionApproximator(int maxDenominator = 1000,
                                  double epsilon = 0.000001);

    Rational approximate(double value) const;

private:
    int maxDenominator_;
    double epsilon_;
};
