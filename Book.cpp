#include "Book.h"

#include <utility>

Book::Book(std::string title, std::string author)
    : title_(std::move(title)), author_(std::move(author)) {}

const std::string& Book::title() const {
    return title_;
}

const std::string& Book::author() const {
    return author_;
}

std::ostream& operator<<(std::ostream& out, const Book& book) {
    out << "Title: " << book.title_ << ", Author: " << book.author_;
    return out;
}
