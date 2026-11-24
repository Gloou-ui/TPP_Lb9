#include "InMemoryBookRepository.h"

void InMemoryBookRepository::save(const Book& book) {
    books_.push_back(book);
}

std::vector<Book> InMemoryBookRepository::findAll() const {
    return books_;
}
