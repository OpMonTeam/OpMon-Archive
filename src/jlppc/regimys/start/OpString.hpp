#include <iostream>
#include <cstdarg>


class OpString{
private:
  std::string key;
  std::vector<std::string> objects;
public:
  OpString(std::string key, ...);

  std::string getObject(int index){return objects[0];}
  std::string getKey(){return key;}
  sf::String getString();
  
}
