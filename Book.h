#pragma once

#include <string>
#include <ostream>

class Book {
public:
    Book(std::string title, std::string author);

    const std::string& title() const;
    const std::string& author() const;

    friend std::ostream& operator<<(std::ostream& out, const Book& book);

private:
    std::string title_;
    std::string author_;
};
