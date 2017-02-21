#include "File.hpp"

UNS

RFile::RFile(string path) {
	this->path = path;
}

ifstream *RFile::getIn() const {
	return new ifstream(path.c_str());
}

ofstream *RFile::getOut() const {
	return new ofstream(path.c_str());
}
