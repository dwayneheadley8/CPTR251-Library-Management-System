#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "libraryItems.h"

class Magazine : public libraryItems {
private:
    int issueNo;

public:
    // Constructor
    Magazine(int ID, std::string itemTitle, std::string itemAuthor, bool availability, int issueNumber);

    // Getter and setter for issueNo
    int getIssueNo() const;
    void setIssueNo(int issueNumber);
};

#endif /* MAGAZINE_H */

