#include "OpString.hpp"
#include "StringKeys.hpp"
#include <cstdarg>

namespace Utils {
    /**
     OpString containing nothing
  */
    OpString OpString::voidStr = OpString("void");

    OpString::OpString(std::string const &key, std::vector<sf::String *> obj) {
        this->key = key;
        unsigned int instances = StringKeys::countInstances(StringKeys::get(key), '~');
        this->objects = obj;

        while(objects.size() > instances) {
            objects.pop_back();
        }
        while(objects.size() < instances) {
            objects.push_back(new sf::String(std::string("~")));
        }
    }

    OpString::OpString() {
    }

    OpString::~OpString() {
        if(created) {
            for(sf::String *object : objects) {
                delete(object);
            }
        }
    }

    sf::String OpString::quickString(std::string const &key, std::vector<std::string> vstr) {
        std::vector<sf::String *> vect;
        for(std::string str : vstr) {
            vect.push_back(new sf::String(str));
        }
        OpString op = OpString(key, vect);
        sf::String str = op.getString();

        for(sf::String *sfstr : vect) {
            delete(sfstr);
        }

        return str;
    }

    sf::String OpString::getString() const {
        if(this->key.empty()) { //If empty, it doesn't execute the algorithm. That would be useless.
            return sf::String();
        }
        if(objects.size() == 0) { //If there is not object, it just returns the string.
            return StringKeys::get(key);
        }
        //Ok, so there is some things to do
        std::vector<sf::String> splitted = StringKeys::split(StringKeys::get(key), '~'); //Split every ~
        /* Adds a space after if the last character is a ~, to avoid being out of the array.
       This can happen because the program adds the next text after adding a text to complete.
    */
        if(StringKeys::get(key).toUtf32()[StringKeys::get(key).toUtf32().size() - 1] == '~') {
            splitted.push_back(" ");
        }
        /*Let's complete!*/
        unsigned int i = 0;
        sf::String toReturn;
        toReturn += splitted[0]; //Add the first chunk. If the first character is ~, this chunk is a empty string
        /*Here we go. The completion.*/
        for(i = i; i < objects.size(); i++) {
            toReturn += *objects[i];
            if(i + 1 < splitted.size()) {
                toReturn += splitted[i + 1];
            }
        }
        //And finally return!
        return toReturn;
    }
} // namespace Utils
