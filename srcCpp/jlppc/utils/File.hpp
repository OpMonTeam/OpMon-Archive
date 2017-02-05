#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>
#include "Class.hpp"

using namespace std;

class File
{
    public:
        File(string path);
        ifstream* getIn() const;
        ofstream* getOut() const;
    protected:

    private:
        ifstream in;
        ifstream out;
        string path;
};

#endif // FILE_HPP
