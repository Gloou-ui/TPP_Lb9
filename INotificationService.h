#pragma once

#include "Book.h"

class INotificationService {
public:
    virtual ~INotificationService() = default;
    virtual void notifyAdded(const Book& book) = 0;
};
