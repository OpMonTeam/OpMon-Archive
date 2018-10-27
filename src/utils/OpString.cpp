/*
OpString.cpp
Author : Cyrion
Contributors : BAKFR, JonnyPtn, torq
File under GNU GPL v3.0 license
*/
#include "OpString.hpp"
#include "./log.hpp"
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

        if(objects.size() != instances) {
            Log::warn("OpString: number of '~' placeholders and arguments mismatch for key \"" + key + "\"");
        }
    }

    OpString::OpString() {
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

        sf::String toReturn;
        for(size_t i = 0; i < splitted.size(); ++i) {
            toReturn += splitted[i];
            if(i < objects.size()) {
                toReturn += *objects[i];
            } else if(i != splitted.size() - 1) {
                // This case only happens when there isn't enough objects to fill all placeholders.
                toReturn += '~';
            }
        }

        return toReturn;
    }
} // namespace Utils
