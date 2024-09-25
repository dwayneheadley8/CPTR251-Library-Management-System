#ifndef LIBRARY_ITEMS_H
#define LIBRARY_ITEMS_H

#include <string>

class libraryItems {
protected:
    int itemID;
    std::string title;
    std::string author;
    bool availStat;

public:
    // Constructor
    libraryItems(int ID, std::string itemTitle, std::string itemAuthor, bool availability);

    // Getters and setters
    int getItemID() const;
    void setItemID(int ID);
    std::string getTitle() const;
    void setTitle(std::string itemTitle);
    std::string getAuthor() const;
    void setAuthor(std::string itemAuthor);
    bool getAvailStat() const;
    void setAvailStat(bool availability);

    virtual ~libraryItems() {}

};

#endif /* LIBRARY_ITEMS_H */
