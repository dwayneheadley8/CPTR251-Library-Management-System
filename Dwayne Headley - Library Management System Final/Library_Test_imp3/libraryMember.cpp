#include "libraryMember.h"

// Default constructor implementation
LibraryMember::LibraryMember() : libraryMemberID(0), libraryMemberName(""), contact(0) {}

// Parameterized constructor implementation
LibraryMember::LibraryMember(int memberID, std::string memberName, int memberContact)
    : libraryMemberID(memberID), libraryMemberName(memberName), contact(memberContact) {
}
// Getter implementations
int LibraryMember::getLibraryMemberID() const {
    return libraryMemberID;
}

std::string LibraryMember::getLibraryMemberName() const {
    return libraryMemberName;
}

int LibraryMember::getContact() const {
    return contact;
}

// Setter implementations
void LibraryMember::setLibraryMemberID(int memberID) {
    libraryMemberID = memberID;
}

void LibraryMember::setLibraryMemberName(std::string memberName) {
    libraryMemberName = memberName;
}

void LibraryMember::setContact(int memberContact) {
    contact = memberContact;
}
