#include "ConsoleNotificationService.h"
#include "FractionApproximator.h"
#include "InMemoryBookRepository.h"
#include "Library.h"

#include <iostream>

int main() {
    InMemoryBookRepository repository;
    ConsoleNotificationService notifications;
    Library library(repository, notifications);

    library.addBook(Book("The Catcher in the Rye", "J.D. Salinger"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee"));

    std::cout << "\nLibrary books:\n";
    library.displayBooks();

    FractionApproximator approximator(1000, 0.000001);
    Rational pi = approximator.approximate(3.141592653589793);
    Rational sum = Rational(1, 3) + Rational(1, 6);
    Rational product = Rational(2, 3) * Rational(3, 4);

    std::cout << "\nPi approximation: " << pi << '\n';
    std::cout << "1/3 + 1/6 = " << sum << '\n';
    std::cout << "(2/3) * (3/4) = " << product << '\n';

    return 0;
}
