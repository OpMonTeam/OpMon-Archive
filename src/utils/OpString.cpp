#include "OpString.hpp"
#include "StringKeys.hpp"

UNS

  namespace Utils {
    /**
OpString containing nothing
*/
    OpString OpString::voidStr = OpString("void");

    OpString::OpString(string const& key, std::vector<sf::String*> const& objects) {
        this->key = key;
        int instances = StringKeys::countInstances(StringKeys::get(key), '~');
        this->objects = objects;
	while(this->objects.size() != instances){
	  objects.pop_back();
	}
    }

    OpString::OpString(string const& key, std::vector<std::string*> const& objects) {
        this->key = key;
        int instances = StringKeys::countInstances(StringKeys::get(key), '~');
	if(objects.size() >= instances){
	  for(unsigned int i = 0; i < instances; i++){
	    this->objects.push_back(new sf::String(objects[i]));
	  }
	}else{
	  key = "";
	}
	created = true;
    }

    OpString(std::string const& key, std::string const& object)
      : OpString(key, std::vector<std::string*>(new std::string(object)))
    {}
    
    OpString::OpString() {
    }

    OpString::~OpString(){
      if(created){
	for(sf::String *object : objects){
	  delete(object);
	}
      }
    }
    
    sf::String OpString::getString() {
        if(this->key.empty()) { //If empty, don't do execute the algorithm. It would be useless.
            return sf::String();
        }
        if(objects.size() == 0) { //If there is not object, idem. Just return the string.
            return StringKeys::get(key);
        }
        //Ok, so there is some things to do
        vector<sf::String> splitted = StringKeys::split(StringKeys::get(key), '~'); //Split every ~
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
            toReturn += splitted[0];
        }
        /*Here we go. The completion.*/
        for(i = i; i < objects.size(); i++) {
            toReturn += *objects[i];
            toReturn += splitted[i + ((StringKeys::get(key).toUtf32()[0] != '~') ? 1 : 0)];
        }
        /*If the first characters is a ~, complete the string, because we have started a bit in advance.*/
        if(StringKeys::get(key).toUtf32()[0] == '~') {
            toReturn += splitted[splitted.size() - 1];
        }
        //And finally return!
        return toReturn;
    }
}
