#ifndef BOOK_H
#define BOOK_H

#include "libraryItems.h"

class Book : public libraryItems {
private:
    int bookISBN;

public:
    // Constructor
    Book(int ID, std::string itemTitle, std::string itemAuthor, bool availability, int isbn);

    // Getter and setter for bookISBN
    int getBookISBN() const;
    void setBookISBN(int isbn);
};

#endif /* BOOK_H */

