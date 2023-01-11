#ifndef EXCEPTION_H
#define EXCEPTION_H

class DeckFileNotFound {
    public:
    const char* what() const {
        return "Deck File Error: File not found";
    }
};

class DeckFileInvalidSize {
    public:
    const char* what() const {
        return "Deck File Error: Deck size is invalid";
    }
};


#endif