#include "Rational.h"

#include <numeric>
#include <ostream>
#include <stdexcept>

Rational::Rational(int numerator, int denominator)
    : numerator_(numerator), denominator_(denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    reduce();
}

int Rational::numerator() const {
    return numerator_;
}

int Rational::denominator() const {
    return denominator_;
}

void Rational::reduce() {
    if (denominator_ < 0) {
        numerator_ = -numerator_;
        denominator_ = -denominator_;
    }
    const int divisor = std::gcd(numerator_, denominator_);
    numerator_ /= divisor;
    denominator_ /= divisor;
}

Rational Rational::operator+(const Rational& other) const {
    return Rational(numerator_ * other.denominator_ +
                        other.numerator_ * denominator_,
                    denominator_ * other.denominator_);
}

Rational Rational::operator-(const Rational& other) const {
    return Rational(numerator_ * other.denominator_ -
                        other.numerator_ * denominator_,
                    denominator_ * other.denominator_);
}

Rational Rational::operator*(const Rational& other) const {
    return Rational(numerator_ * other.numerator_,
                    denominator_ * other.denominator_);
}

Rational Rational::operator/(const Rational& other) const {
    if (other.numerator_ == 0) {
        throw std::domain_error("Cannot divide by zero");
    }
    return Rational(numerator_ * other.denominator_,
                    denominator_ * other.numerator_);
}

bool Rational::operator==(const Rational& other) const {
    return numerator_ == other.numerator_ &&
           denominator_ == other.denominator_;
}

bool Rational::operator!=(const Rational& other) const {
    return !(*this == other);
}

bool Rational::operator<(const Rational& other) const {
    return static_cast<long long>(numerator_) * other.denominator_ <
           static_cast<long long>(other.numerator_) * denominator_;
}

std::ostream& operator<<(std::ostream& out, const Rational& value) {
    out << value.numerator_;
    if (value.denominator_ != 1) {
        out << '/' << value.denominator_;
    }
    return out;
}
