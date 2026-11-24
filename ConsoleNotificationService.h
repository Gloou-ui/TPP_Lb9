#pragma once

#include "INotificationService.h"

class ConsoleNotificationService : public INotificationService {
public:
    void notifyAdded(const Book& book) override;
};
