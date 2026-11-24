#include "ConsoleNotificationService.h"

#include <iostream>

void ConsoleNotificationService::notifyAdded(const Book& book) {
    std::cout << "Sending email notification about the new book: "
              << book.title() << std::endl;
}
