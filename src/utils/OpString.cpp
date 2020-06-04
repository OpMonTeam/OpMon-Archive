/*
OpString.cpp
Author : Cyrielle
Contributors : BAKFR, JonnyPtn, torq
File under GNU GPL v3.0 license
*/
#include "OpString.hpp"

#include <cstddef>

#include "./log.hpp"
#include "src/utils/StringKeys.hpp"

namespace Utils {

    OpString::OpString(StringKeys &instance, std::string const &key,
                       std::vector<sf::String *> obj) {
        this->key = key;
        unsigned int instances = (key == "void") ? 0 :
                                                   StringKeys::countInstances(
                                                       instance.get(key), '~');
        this->objects = obj;

        if(objects.size() != instances) {
            Log::warn("OpString: number of '~' placeholders and arguments "
                      "mismatch for key \"" +
                      key + "\"");
        }
    }

    OpString::OpString() {}

    sf::String OpString::quickString(StringKeys &instance,
                                     std::string const &key,
                                     std::vector<std::string> vstr) {
        std::vector<sf::String *> vect;
        for(std::string str : vstr) {
            vect.push_back(new sf::String(str));
        }
        OpString op = OpString(instance, key, vect);
        sf::String str = op.getString(instance);

        for(sf::String *sfstr : vect) {
            delete(sfstr);
        }

        return str;
    }

    sf::String OpString::getString(StringKeys &instance) const {
        if(this->key.empty() ||
           this->key == "void") { // If empty or void, it doesn't execute the
                                  // algorithm. That would be useless.
            return sf::String();
        }
        if(objects.size() ==
           0) { // If there is not object, it just returns the string.
            return instance.get(key);
        }
        // Ok, so there is some things to do
        std::vector<sf::String> splitted =
            StringKeys::split(instance.get(key), '~'); // Split every ~

        sf::String toReturn;
        for(size_t i = 0; i < splitted.size(); ++i) {
            toReturn += splitted[i];
            if(i < objects.size()) {
                toReturn += *objects[i];
            } else if(i != splitted.size() - 1) {
                // This case only happens when there isn't enough objects to
                // fill all placeholders.
                toReturn += '~';
            }
        }

        return toReturn;
    }
} // namespace Utils
