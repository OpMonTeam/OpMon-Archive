
#include "OpString.hpp"
#include "main.hpp"
#include "StringKeys.hpp"

UNS

OpString::OpString(string key, ...){
  va_list ap;
  va_start(ap, key);
  int instances = StringKeys::countInstances(key, '£');
  for(unsigned int i = 0; i < instances; i++){
    char* actual = va_arg(ap, char*);
    objects.push_back(string(actual));
  }
  va_end(ap);
}

sf::String OpString::getString(){
  vector<sf::String> splitted = StringKeys::split(StringKeys::get(key), '£');
  if(StringKeys::get(key).toUtf32()[StringKeys::get(key).toUtf32().size() - 1] == '£'){
    splitted.push_back(" ");
  }
  sf::String toReturn = splitted[0];
  for(unsigned int i = 0; i < instances; i++){
    toReturn+=objects[i];
    toReturn+=splitted[i + 1];
  }
  return toReturn;
}
