#ifndef OPSTRING_HPP
#define OPSTRING_HPP

#include <iostream>


class opString : public std::string
{
    public:
        opString(std::string str);
        opString(char *tab);
        opString(char uniqueChar);
        opString(int *tabs, int lenght);
        opString();
        opString(int lenght);

        opString operator+(opString const& toAdd) const;
        opString& operator+=(opString const& toAdd);
        opString operator*(int toMulti) const;
        opString& operator*=(int toMulti) const;

        friend opString& operator<<=(opString &str, std::string sstr);
        friend opString& operator<<=(opString &str, int toAdd);
        friend opString& operator<<=(opString &str, char toAdd);
        friend opString& operator<<=(opString &str, char *toAdd);
        friend opString& operator<<=(opString &str, opString toAdd);

        friend opString operator<<(opString const& str, std::string sstr);
        friend opString operator<<(opString const& str, int toAdd);
        friend opString operator<<(opString const& str, char toAdd);
        friend opString operator<<(opString const& str, char *toAdd) ;
        friend opString operator<<(opString const& str, opString toAdd) ;


        std::string toString() const;
        std::string* split(char splitter) const;


    protected:

    private:
};

#endif // OPSTRING_HPP
