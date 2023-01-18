#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

class DeckFileNotFound : std::exception {
    public:
    const char* what() const throw() override {
        return "Deck File Error: File not found";
    }
};
class DeckFileFormatError : std::exception{
    private:
    std::string m_error;
    public:
    DeckFileFormatError(int line) {
        std::string error = "Deck File Error: File format error in line ";
        m_error = error + std::to_string(line);
    }
    const char* what() const throw() override {
        return m_error.c_str();
    }
};
class DeckFileInvalidSize : std::exception{
    public:
    const char* what() const throw() override {
        return "Deck File Error: Deck size is invalid";
    }
};


#endif