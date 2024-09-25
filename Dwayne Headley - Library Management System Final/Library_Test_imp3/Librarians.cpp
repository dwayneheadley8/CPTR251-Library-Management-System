#include "Librarians.h"
#include "Book.h"
#include "Journal.h"
#include "Magazine.h"
#include "DigitalMedia.h"
#include <iostream>

//Constructor for Librarians
Librarians::Librarians(int librarianID, std::string librarianName, int librarianContact)
    : libID(librarianID), libName(librarianName), libContact(librarianContact) {}

void Librarians::displayLibrarian() {
    std::cout << "Librarian ID: " << libID << std::endl;
    std::cout << "Librarian Name: " << libName << std::endl;
    std::cout << "Librarian Contact: " << libContact << std::endl;
}

//Creates Customer Account
void Librarians::createAccount(int customerID, std::string customerName, int customerContact) {
    Customers newCustomer(customerID, customerName, customerContact); //Creating new customer object
    customerList.push_back(newCustomer); //Creates a new entry in the customerList by adding the newCustomer object to the end of the list.
}

//Showcases list of Customers
const std::list<Customers>& Librarians::getCustomerList() const {
    return customerList;
}

// Method to add a library item to the list
void Librarians::addLibraryItem(libraryItems* newItem) {
    itemList.push_back(newItem); //push_back is a function used in C++ to add an element at the end of a std::list
}

// Method to display all library items
void Librarians::displayAllItems() const {
    std::cout << "Library Items:\n";
    for (auto item : itemList) { //Iterates through each item in the itemList using a range-based for loop.
        std::cout << "Item ID: " << item->getItemID() << ", Title: " << item->getTitle() << std::endl;
        std::cout << "Author: " << item->getAuthor() << std::endl;
        std::cout << "Availability: " << (item->getAvailStat() ? "Available" : "Not Available") << std::endl;

        // Checking the item type to display unique identifiers
        if (dynamic_cast<Book*>(item) != nullptr) {
            Book* bookItem = dynamic_cast<Book*>(item);
            std::cout << "Book ISBN: " << bookItem->getBookISBN() << std::endl;
        } else if (dynamic_cast<Journal*>(item) != nullptr) {
            Journal* journalItem = dynamic_cast<Journal*>(item);
            std::cout << "Journal ID: " << journalItem->getJournalID() << std::endl;
        } else if (dynamic_cast<Magazine*>(item) != nullptr) {
            Magazine* magazineItem = dynamic_cast<Magazine*>(item);
            std::cout << "Issue Number: " << magazineItem->getIssueNo() << std::endl;
        } else if (dynamic_cast<DigitalMedia*>(item) != nullptr) {
            DigitalMedia* digitalMediaItem = dynamic_cast<DigitalMedia*>(item);
            std::cout << "Media Format: " << digitalMediaItem->getMediaFormat() << std::endl;
        }
        std::cout << std::endl;
    }
}
/*
dynamic_cast operator was used here because I wanted to showcase the unique identifiers from the library items.
Basically what the dynamic cast is going is it's trying to convert the item pointer into derived item pointer.
So it could display the additional information from the respective classes.
*/

void Librarians::updateItemAvailability(int itemId, bool newAvailability) {
    for (auto item : itemList) {
        if (item->getItemID() == itemId) {
            item->setAvailStat(newAvailability);
            break;
        }
    }
}

// Method for checking out an item to a customer
void Librarians::checkOut(int customerId, int itemId) {
    // Find the customer
    Customers* selectedCustomer = nullptr;
    for (auto& customer : customerList) {
        if (customer.getCustomerID() == customerId) {
            selectedCustomer = &customer;
            break;
        }
    }

    // Finds the item
    libraryItems* selectedLibraryItem = nullptr;
    for (auto& item : itemList) {
        if (item->getItemID() == itemId) {
            selectedLibraryItem = item;
            break;
        }
    }

    // If both customer and item are found, proceed to checkout
    if (selectedCustomer && selectedLibraryItem) {
        // Add the item to the customer's inventory
        selectedCustomer->addItemToInventory(selectedLibraryItem); // Pass the pointer

        // Update the availability of the item
        updateItemAvailability(itemId, false); // Assuming 'false' indicates item is not available
    }
}

// Implementing the searchForItem method
libraryItems* Librarians::searchForItem(int bookID) {
    for (auto item : itemList) {
        if (item->getItemID() == bookID) {
            return item;
        }
    }
    throw std::runtime_error("Book not found!"); // Throw an exception if the book is not found
}

void Librarians::returnItem(int customerId, int itemId) {
    // Find the customer
    for (auto& customer : customerList) {
        if (customer.getCustomerID() == customerId) {
            // Find the item in the customer's inventory
            for (auto& item : customer.getInventory()) {
                if (item->getItemID() == itemId) {
                    // Remove the item from the customer's inventory
                    customer.removeInventoryItem(itemId);
                    // Update the availability of the item in the library
                    for (auto& libItem : itemList) {
                        if (libItem->getItemID() == itemId) {
                            libItem->setAvailStat(true); // Set the item as available
                            return; // Exit the function once the item is returned
                        }
                    }
                }
            }
        }
    }
    // Print an error message if the customer or item is not found
    std::cout << "Customer or item not found!" << std::endl;
}


