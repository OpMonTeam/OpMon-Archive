#include "OpString.hpp"
#include "main.hpp"
#include "StringKeys.hpp"

UNS
/**
OpString containing nothing
*/
OpString OpString::voidStr = OpString("void");

OpString::OpString(string const& key, ...) {//If you have other solutions to have an undefined number of arguments (Except arrays), please tell me!
    va_list ap;
    this->key = key;
    va_start(ap, key);
    int instances = StringKeys::countInstances(StringKeys::get(key), '~');
    for(int i = 0; i < instances; i++) {
      sf::String *actual = va_arg(ap, sf::String*);
        objects.push_back(actual);
    }
    va_end(ap);
}

OpString::OpString() {

}

sf::String OpString::getString() {
    if(this->key.empty()) {//If empty, don't do execute the algorithm. It would be useless.
        return sf::String();
    }
    if(objects.size() == 0) {//If there is not object, idem. Just return the string.
        return StringKeys::get(key);
    }
    //Ok, so there is some things to do
    vector<sf::String> splitted = StringKeys::split(StringKeys::get(key), '~');//Split every ~
    /* Add a space after if the last character is a ~, to avoid being out of the array.
       This can happen because the program adds the next text after adding a text to complete.
    */
    if(StringKeys::get(key).toUtf32()[StringKeys::get(key).toUtf32().size() - 1] == '~') {
        splitted.push_back(" ");
    }
    /*Let's complete!*/
    unsigned int i = 0;
    sf::String toReturn;
    /*If the first character isn't a ~, don't add the completion first. Don't swap text chunks.*/
    if(StringKeys::get(key).toUtf32()[0] != '~') {
        toReturn+=splitted[0];
    }
    /*Here we go. The completion.*/
    for(i = i; i < objects.size(); i++) {
        toReturn+=*objects[i];
        toReturn+=splitted[i + ((StringKeys::get(key).toUtf32()[0] != '~') ? 1 : 0)];
    }
    /*If the first characters is a ~, complete the string, because we have started a bit in advance.*/
    if(StringKeys::get(key).toUtf32()[0] == '~') {
        toReturn+=splitted[splitted.size() - 1];
    }
    //And finally return!
    return toReturn;
}
