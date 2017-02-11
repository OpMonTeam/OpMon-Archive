#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>
#include "Class.hpp"

using namespace std;

class RFile
{
    public:
        RFile(string path);
        ifstream* getIn() const;
        ofstream* getOut() const;
    protected:

    private:
        string path;
};

#endif // FILE_HPP
