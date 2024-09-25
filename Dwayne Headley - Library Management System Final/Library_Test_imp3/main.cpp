#include <iostream>
#include "Customers.h"
#include "Librarians.h"
#include "Book.h"
#include "Journal.h"
#include "Magazine.h"
#include "DigitalMedia.h"

int main() {
    //Displaying Librarian Information
    Librarians librarian(101, "John Doe", 987654321);
    std::cout << "Librarian Information:\n";
    librarian.displayLibrarian();

    //Creation of accounts
    librarian.createAccount(201, "John Doe", 123456);
    librarian.createAccount(502, "Bob Johnson", 987654321); // Adding another customer account

    //Displaying list of created accounts
    std::cout << "\nCustomer Accounts Created by the Librarian:\n";
    const std::list<Customers>& customers = librarian.getCustomerList();

    for (const auto& customer : customers) {
        customer.displayCustomer();
        std::cout << std::endl;
    }

    // Creating different library items
    Book* book1 = new Book(101, "Book Title 1", "Author 1", true, 123456789);
    Journal* journal1 = new Journal(102, "Journal Title 1", "Author 2", true, 9876);
    Magazine* magazine1 = new Magazine(103, "Magazine Title 1", "Author 3", true, 25);
    DigitalMedia* digitalMedia1 = new DigitalMedia(12, "Media Title 1", "Author 4", true, "DVD");

    // Adding library items to the list
    librarian.addLibraryItem(book1);
    librarian.addLibraryItem(journal1);
    librarian.addLibraryItem(magazine1);
    librarian.addLibraryItem(digitalMedia1);

    // Displaying all library items
    librarian.displayAllItems();

    // Librarian checks out an item to a customer
    librarian.checkOut(201, 101); // customer ID 201 and book ID 101

    // Display the updated list of library items after checkout
    std::cout << "\nList of Library Items after Checkout:\n";
    librarian.displayAllItems();

    // Display the updated list of customer inventories after checkout
    std::cout << "\nList of Customers after Checkout:\n";
    const std::list<Customers>& customerList = librarian.getCustomerList();

    for (const auto& customer : customerList) {
        customer.displayCustomerInventory();
        std::cout << std::endl;
    }

    //Search for item
    int bookIDToSearch = 101; // Change this to the ID you want to search for

    try {
        libraryItems* foundBook = librarian.searchForItem(bookIDToSearch);

        // Book found, print its information
        std::cout << "Searching for Item..." << std::endl;
        std::cout << "===========================" << std::endl;
        std::cout << "Book Found!" << std::endl;
        std::cout << "Book information:\n";
        std::cout << "Item ID: " << foundBook->getItemID() << std::endl;
        std::cout << "Title: " << foundBook->getTitle() << std::endl;
        // ... Print other information as needed
    } catch (const std::runtime_error& e) {
        // Book not found, handle the error
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "Book not found!" << std::endl;
    }


    //Returns library item
    std::cout << "=========================\n";
    std::cout << "Returning Library Item...";
    std::cout << "\n=========================\n";
    librarian.returnItem(201, 101);
    std::cout << "=========================\n";
    std::cout << "Item Successfully Returned\n";
    std::cout << "=========================";


    // Display the updated list of library items after returning an item
    std::cout << "\nList of Library Items after Return:\n";
    librarian.displayAllItems();


    // Display the updated list of customer inventories after returning an item
    std::cout << "=========================";
    std::cout << "\nList of Customer Inventories after Return:\n";
    std::cout << "=========================\n";
    const std::list<Customers>& updatedCustomerList = librarian.getCustomerList();

    for (const auto& customer : updatedCustomerList) {
        customer.displayCustomerInventory();
        std::cout << std::endl;
    }


//Freeing up memory allocation to prevent memory leaks
    delete book1;
    delete journal1;
    delete magazine1;
    delete digitalMedia1;

    return 0;
}
