#ifndef LIBRARIANS_H
#define LIBRARIANS_H
#include "libraryItems.h"
#include "libraryMember.h"
#include "Customers.h"
#include <list>

class Librarians : public LibraryMember { //Showcases Inheritance
private:
    int libID;
    std::string libName;
    int libContact;
    std::list<Customers> customerList; //List to hold customers
    std::list<libraryItems*> itemList; // List to hold library items

    // Helper method to update item availability after it is added to a customer's inventory
    void updateItemAvailability(int itemId, bool newAvailability);

public:
    Librarians(int librarianID, std::string librarianName, int librarianContact);
    void displayLibrarian(); //Displays Librarian Details
    void createAccount(int customerID, std::string customerName, int customerContact); //Create account method

    //Add library item
    void addLibraryItem(libraryItems* newItem);

    // Method to display all library items
    void displayAllItems() const;

    // Getter for customerList
    const std::list<Customers>& getCustomerList() const;

    //Checks out book to Customer's Inventory
    void checkOut(int customerId, int itemId);

    //Search for Item method
    libraryItems* searchForItem(int bookID);

    //Return item method
    void returnItem(int customerId, int itemId);


};


#endif /* LIBRARIANS_H */
