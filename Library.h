#pragma once

#include "IBookRepository.h"
#include "INotificationService.h"

class Library {
public:
    Library(IBookRepository& repository,
            INotificationService& notificationService);

    void addBook(const Book& book);
    void displayBooks() const;

private:
    IBookRepository& repository_;
    INotificationService& notificationService_;
};
