#ifndef EXCEPTION_H
#define EXCEPTION_H

const int stringLength = 44;

class DeckFileNotFound : std::exception {
    public:
    const char* what() const throw() override {
        return "Deck File Error: File not found";
    }
};
class DeckFileFormatError : std::exception{
    private:
    int m_line;
    public:
    DeckFileFormatError(int line) : m_line(line) {}
    const char* what() const throw() override {
        char what[stringLength] = "Deck File Error: File format error in line ";
        char integer_string[stringLength];
        sprintf(integer_string, "%d", m_line);
        strcat(what, integer_string);
        return what;
    }
};
class DeckFileInvalidSize : std::exception{
    public:
    const char* what() const throw() override {
        return "Deck File Error: Deck size is invalid";
    }
};


#endif