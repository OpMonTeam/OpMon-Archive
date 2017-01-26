#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>

using namespace std;

class File
{
    public:
        File(string path);
        ifstream* getIn();
        ofstream* getOut();

    protected:

    private:
        ifstream in;
        ifstream out;
        string path;
};

#endif // FILE_HPP
