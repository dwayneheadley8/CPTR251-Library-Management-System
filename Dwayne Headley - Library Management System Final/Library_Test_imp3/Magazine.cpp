#include "Magazine.h"

// Constructor implementation
Magazine::Magazine(int ID, std::string itemTitle, std::string itemAuthor, bool availability, int issueNumber)
    : libraryItems(ID, itemTitle, itemAuthor, availability), issueNo(issueNumber) {}

// Getter and setter for issueNo
int Magazine::getIssueNo() const {
    return issueNo;
}

void Magazine::setIssueNo(int issueNumber) {
    issueNo = issueNumber;
}

