#pragma once

#include <iosfwd>
#include <stdexcept>

class Rational {
public:
    Rational(int numerator = 0, int denominator = 1);

    int numerator() const;
    int denominator() const;

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;
    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    bool operator<(const Rational& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Rational& value);

private:
    int numerator_;
    int denominator_;

    void reduce();
};
