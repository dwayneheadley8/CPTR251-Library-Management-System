#ifndef LIBRARY_MEMBER_H
#define LIBRARY_MEMBER_H

#include <string>

class LibraryMember {
private:
    int libraryMemberID;
    std::string libraryMemberName;
    int contact;

public:
    // Default constructor
    LibraryMember();

    // Parameterized constructor
    LibraryMember(int memberID, std::string memberName, int memberContact);

    // Getters and setters
    int getLibraryMemberID() const;
    std::string getLibraryMemberName() const;
    int getContact() const;
    void setLibraryMemberID(int memberID);
    void setLibraryMemberName(std::string memberName);
    void setContact(int memberContact);
};

#endif /* LIBRARY_MEMBER_H */
