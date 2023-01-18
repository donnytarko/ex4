#ifndef EXCEPTION_H
#define EXCEPTION_H

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
        std::string error = "Deck File Error: File format error in line ";
        error += std::to_string(m_line);
        return error.c_str();
    }
};
class DeckFileInvalidSize : std::exception{
    public:
    const char* what() const throw() override {
        return "Deck File Error: Deck size is invalid";
    }
};


#endif