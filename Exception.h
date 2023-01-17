#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

class DeckFileNotFound {
    public:
    std::string what() const {
        return std::string("Deck File Error: File not found");
    }
};
class DeckFileFormatError {
    private:
    int m_line;
    public:
    DeckFileFormatError(int line) : m_line(line) {}
    std::string what() const {
        return (std::string("Deck File Error: File format error in line ") + std::to_string(m_line));
    }
};
class DeckFileInvalidSize {
    public:
    std::string what() const {
        return std::string("Deck File Error: Deck size is invalid");
    }
};


#endif