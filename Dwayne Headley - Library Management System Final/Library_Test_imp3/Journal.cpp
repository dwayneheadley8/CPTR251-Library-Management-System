#include "Journal.h"

// Constructor implementation
Journal::Journal(int ID, std::string itemTitle, std::string itemAuthor, bool availability, int jID)
    : libraryItems(ID, itemTitle, itemAuthor, availability), journalID(jID) {}

// Getter and setter for journalID
int Journal::getJournalID() const {
    return journalID;
}

void Journal::setJournalID(int id) {
    journalID = id;
}

