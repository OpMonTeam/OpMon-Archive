#ifndef USTRING_HPP
#define USTRING_HPP

#include <iostream>

class ustring : public std::string{
    public:
        ustring(std::string &str);
        ustring(char *car);
        basic_string& operator+=(char toAdd);

    protected:

    private:
};

#endif // USTRING_HPP
