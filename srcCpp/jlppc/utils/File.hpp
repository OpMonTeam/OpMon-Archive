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
        static Class<File> *classe = new Class<File>("File", 7624735);
        virtual Class* getClass() const {return classe;}
    protected:

    private:
        ifstream in;
        ifstream out;
        string path;
};

#endif // FILE_HPP
