#ifndef OPSTRING_PROTECTED
#define OPSTRING_PROTECTED
#include <iostream>
#include <cstdarg>
#include <vector>
#include <SFML/System.hpp>

class OpString{
private:
  std::string key;
  std::vector<std::string*> objects;
public:
  OpString(std::string const& key, ...);
  OpString();

  std::string getObject(int const& index){return *(objects[0]);}
  std::string getKey(){return key;}
  sf::String getString();
  static OpString voidStr;
};
#endif
