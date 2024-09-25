#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H

#include "libraryItems.h"

class DigitalMedia : public libraryItems {
private:
    std::string mediaFormat;

public:
    // Constructor
    DigitalMedia(int ID, std::string itemTitle, std::string itemAuthor, bool availability, std::string format);

    // Getter and setter for mediaFormat
    std::string getMediaFormat() const;
    void setMediaFormat(std::string format);
};

#endif /* DIGITALMEDIA_H */

