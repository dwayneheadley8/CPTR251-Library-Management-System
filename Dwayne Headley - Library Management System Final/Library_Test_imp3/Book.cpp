#include "Book.h"

// Constructor implementation
Book::Book(int ID, std::string itemTitle, std::string itemAuthor, bool availability, int isbn)
    : libraryItems(ID, itemTitle, itemAuthor, availability), bookISBN(isbn) {}

// Getter and setter for bookISBN
int Book::getBookISBN() const {
    return bookISBN;
}

void Book::setBookISBN(int isbn) {
    bookISBN = isbn;
}

