#include "DigitalMedia.h"

// Constructor implementation
DigitalMedia::DigitalMedia(int ID, std::string itemTitle, std::string itemAuthor, bool availability, std::string format)
    : libraryItems(ID, itemTitle, itemAuthor, availability), mediaFormat(format) {}

// Getter and setter for mediaFormat
std::string DigitalMedia::getMediaFormat() const {
    return mediaFormat;
}

void DigitalMedia::setMediaFormat(std::string format) {
    mediaFormat = format;
}

