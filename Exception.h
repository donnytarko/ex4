#ifndef EXCEPTION_H
#define EXCEPTION_H

class DeckFileNotFound {
    public:
    const char* what() const {
        return "Deck File Error: File not found";
    }
};
class DeckFileFormatError {
    private:
    int m_line;
    public:
    DeckFileFormatError(int line) : m_line(line) {}
    const char* what() const {
        std::string what = "Deck File Error: File format error in line " + m_line;
        return what.c_str();
    }
};
class DeckFileInvalidSize {
    public:
    const char* what() const {
        return "Deck File Error: Deck size is invalid";
    }
};


#endif