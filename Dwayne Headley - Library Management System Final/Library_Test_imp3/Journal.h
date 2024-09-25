#ifndef JOURNAL_H
#define JOURNAL_H

#include "libraryItems.h"

class Journal : public libraryItems {
private:
    int journalID;

public:
    // Constructor
    Journal(int ID, std::string itemTitle, std::string itemAuthor, bool availability, int journalID);

    // Getter and setter for journalID
    int getJournalID() const;
    void setJournalID(int id);
};

#endif /* JOURNAL_H */

