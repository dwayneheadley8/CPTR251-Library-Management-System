#include "libraryItems.h"

// Constructor implementation
libraryItems::libraryItems(int ID, std::string itemTitle, std::string itemAuthor, bool availability)
    : itemID(ID), title(itemTitle), author(itemAuthor), availStat(availability) {}

// Getter and setter implementations
int libraryItems::getItemID() const {
    return itemID;
}

void libraryItems::setItemID(int ID) {
    itemID = ID;
}

std::string libraryItems::getTitle() const {
    return title;
}

void libraryItems::setTitle(std::string itemTitle) {
    title = itemTitle;
}

std::string libraryItems::getAuthor() const {
    return author;
}

void libraryItems::setAuthor(std::string itemAuthor) {
    author = itemAuthor;
}

bool libraryItems::getAvailStat() const {
    return availStat;
}

void libraryItems::setAvailStat(bool availability) {
    availStat = availability;
}
