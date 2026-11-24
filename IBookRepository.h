#pragma once

#include "Book.h"
#include <vector>

class IBookRepository {
public:
    virtual ~IBookRepository() = default;
    virtual void save(const Book& book) = 0;
    virtual std::vector<Book> findAll() const = 0;
};
