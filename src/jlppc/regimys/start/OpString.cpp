
#include "OpString.hpp"
#include "main.hpp"
#include "StringKeys.hpp"

UNS

OpString OpString::voidStr = OpString("void");

OpString::OpString(string key, ...){
  va_list ap;
  this->key = key;
  va_start(ap, key);
  int instances = StringKeys::countInstances(StringKeys::get(key), '~');
  for(unsigned int i = 0; i < instances; i++){
    std::string *actual = va_arg(ap, std::string*);
    objects.push_back(actual);
  }
  va_end(ap);
}

sf::String OpString::getString(){
  if(key == "ppHouse")cout << *objects[0] << endl;
  if(objects.size() == 0){
    return StringKeys::get(key);
  }
  vector<sf::String> splitted = StringKeys::split(StringKeys::get(key), '~');
  if(StringKeys::get(key).toUtf32()[StringKeys::get(key).toUtf32().size() - 1] == '~'){
    splitted.push_back(" ");
  }
  int i = 0;
  sf::String toReturn;
  if(StringKeys::get(key).toUtf32()[0] != '~'){
    toReturn+=splitted[0];
  }
  for(i = i; i < objects.size(); i++){
    toReturn+=sf::String((*objects[i]));
    toReturn+=splitted[i + ((StringKeys::get(key).toUtf32()[0] != '~') ? 1 : 0)];
  }
  cout << StringKeys::sfStringtoStdString(toReturn) << endl;
  return toReturn;
}
