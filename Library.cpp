#include "Library.h"

#include <iostream>

Library::Library(IBookRepository& repository,
                 INotificationService& notificationService)
    : repository_(repository), notificationService_(notificationService) {}

void Library::addBook(const Book& book) {
    repository_.save(book);
    notificationService_.notifyAdded(book);
}

void Library::displayBooks() const {
    for (const Book& book : repository_.findAll()) {
        std::cout << book << '\n';
    }
}
