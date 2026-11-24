#include "ConsoleNotificationService.h"
#include "FractionApproximator.h"
#include "InMemoryBookRepository.h"
#include "Library.h"

#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>

int main() {
    InMemoryBookRepository repository;
    ConsoleNotificationService notifications;
    Library library(repository, notifications);

    library.addBook(Book("Test Title", "Test Author"));
    assert(repository.findAll().size() == 1);
    assert(repository.findAll().front().title() == "Test Title");

    assert(Rational(2, 4) == Rational(1, 2));
    assert(Rational(-2, 4) == Rational(-1, 2));
    assert(Rational(1, 3) + Rational(1, 6) == Rational(1, 2));
    assert(Rational(2, 3) * Rational(3, 4) == Rational(1, 2));
    assert(Rational(3, 4) / Rational(1, 2) == Rational(3, 2));

    bool zeroDenominatorCaught = false;
    try {
        Rational invalid(1, 0);
    } catch (const std::invalid_argument&) {
        zeroDenominatorCaught = true;
    }
    assert(zeroDenominatorCaught);

    FractionApproximator approximator(1000, 0.000001);
    Rational approximation = approximator.approximate(3.141592653589793);
    assert(std::abs(3.141592653589793 -
                    static_cast<double>(approximation.numerator()) /
                        approximation.denominator()) < 0.000001);

    std::cout << "All tests passed.\n";
    return 0;
}
