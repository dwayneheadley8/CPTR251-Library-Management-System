#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include "libraryItems.h"
#include "libraryMember.h"
#include <string>
#include <list>

class libraryItems; // Forward declaration of libraryItems class

class Customers : public LibraryMember {
private:
    int custID;
    std::string custName;
    int custContact;
    std::list<libraryItems*> inventory; // Declaration of inventory


public:
    Customers(int customerID, std::string customerName, int customerContact);

    int getCustomerID() const;

    // Method to display customer information (const method)
    void displayCustomer() const;

    //Getter for inventory
    const std::list<libraryItems*>& getInventory() const; // Getter for inventory

    //Functions to manipulate inventory
    // Method to add an item to the customer's inventory
    void addItemToInventory(libraryItems* item); // Change the parameter to a pointer
    //Display items in customer's inventory
    void displayCustomerInventory() const;
    //Remove item from customer inventory
    void removeInventoryItem(int itemId); // Remove item from inventory

    //Method for customer to remove an item
    void returnItemCustomer(int itemID); // Method to remove an item from the inventory


};

#endif /* CUSTOMERS_H */
