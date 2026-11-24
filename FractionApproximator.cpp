#include "FractionApproximator.h"

#include <cmath>
#include <limits>
#include <stdexcept>

FractionApproximator::FractionApproximator(int maxDenominator,
                                           double epsilon)
    : maxDenominator_(maxDenominator), epsilon_(epsilon) {
    if (maxDenominator < 1) {
        throw std::invalid_argument("Max denominator must be positive");
    }
    if (!std::isfinite(epsilon) || epsilon < 0.0) {
        throw std::invalid_argument("Epsilon must be a finite non-negative value");
    }
}

Rational FractionApproximator::approximate(double value) const {
    if (!std::isfinite(value)) {
        throw std::invalid_argument("Value must be finite");
    }

    const int sign = value < 0.0 ? -1 : 1;
    const double absoluteValue = std::abs(value);
    int bestNumerator = 0;
    int bestDenominator = 1;
    double bestError = absoluteValue;

    for (int denominator = 1; denominator <= maxDenominator_; ++denominator) {
        const int numerator = static_cast<int>(std::llround(
            absoluteValue * denominator));
        const double error = std::abs(
            absoluteValue - static_cast<double>(numerator) / denominator);

        if (error < bestError ||
            (error == bestError && denominator < bestDenominator)) {
            bestNumerator = numerator;
            bestDenominator = denominator;
            bestError = error;
        }

        if (error <= epsilon_) {
            return Rational(sign * bestNumerator, bestDenominator);
        }
    }

    return Rational(sign * bestNumerator, bestDenominator);
}
