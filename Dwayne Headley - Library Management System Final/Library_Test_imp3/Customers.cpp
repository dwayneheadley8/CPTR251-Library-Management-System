#include "Book.h"
#include "Journal.h"
#include "Magazine.h"
#include "DigitalMedia.h"
#include "Customers.h"
#include <iostream>

Customers::Customers(int customerID, std::string customerName, int customerContact)
    : LibraryMember(customerID, customerName, customerContact), custID(customerID), custName(customerName), custContact(customerContact) {}

void Customers::displayCustomer() const {
    std::cout << "Customer ID: " << custID << std::endl;
    std::cout << "Customer Name: " << custName << std::endl;
    std::cout << "Customer Contact: " << custContact << std::endl;
}

int Customers::getCustomerID() const {
    return custID;
}

//Getter for inventory
const std::list<libraryItems*>& Customers::getInventory() const {
    return inventory;
}
// Method to add an item to the customer's inventory
void Customers::addItemToInventory(libraryItems* item) {
    inventory.push_back(item);
}

//Display customer inventory
void Customers::displayCustomerInventory() const {
    std::cout << "Customer ID: " << custID << ", Name: " << custName << std::endl;
    std::cout << "Inventory:\n";

    for (const auto& item : inventory) { //auto tells the compiler to figure out the correct data type based on what's in inventory
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

//Remove inventory item
void Customers::removeInventoryItem(int itemId) {
    for (auto iter = inventory.begin(); iter != inventory.end(); ++iter) {
        if ((*iter)->getItemID() == itemId) {
            inventory.erase(iter);
            break;
        }
    }
}

//Return item customer
void Customers::returnItemCustomer(int itemID) {
    for (auto iter = inventory.begin(); iter != inventory.end(); ++iter) {
        if ((*iter)->getItemID() == itemID) {
            inventory.erase(iter);
            return; // Exit once the item is found and removed
        }
    }
    std::cout << "Item not found in inventory!" << std::endl;
}


