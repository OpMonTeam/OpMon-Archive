
#include <ostream>
#include <sstream>
#include "Core.hpp"
#include "../../utils/defines.hpp"
#include "../../utils/log.hpp"
#include "../model/save/OptionsSave.hpp"
#include "./Initializer.hpp"

using namespace OpMon::Model;
using Utils::Log::oplog;

UNS


namespace OpMon{
  //std::thread bgtask = nullptr;
  /*
    Logs and save files initialization
  */
  string optSave(SAVE_PATH + "optSave.oparams");

  bool debugMode = false;

  sf::Vector2i vec2fTo2i(sf::Vector2f const &toTrans) {
    return sf::Vector2i(toTrans.x, toTrans.y);
  }

  //The number of errors handeled in the program.
  int errors = 0;

  void handleError(string const& errorName, bool fatal) {
    errors++;
    ostringstream osslog;
    osslog << string("Error  n°") << errors << (string(" : ") + errorName);
    oplog(osslog.str(), true);
    cerr << "Error n°" << errors << " : " << errorName << endl;
    if(errors > 20) { //If the program gets more than 20 errors, it stops.
      cerr << "Too many errors. Closing program. Please verify your installation." << endl;
      oplog("Too many errors. Closing program. Please verify your installation. If the problems persists, warn us.", true);
      fatal = true;
    }
    if (fatal) {
      ostringstream ossslog;
      ossslog << "Fatal error. Total errors : " << errors;
      oplog(ossslog.str(), true);
      cerr << "Fatal error." << endl;
      oplog("Crash.");
      quit(1);
    }
  }

  int quit(int const& returns) {
    OptionsSave::saveParams(optSave);//Saving parameters
    oplog("Deleting resources in the memory");
    for(std::map<std::string, Map*>::iterator map = Initializer::maps.begin(); map!=Initializer::maps.end(); ++map){
      if(map->second != nullptr){
	delete(map->second);
      }
    }
    for(sf::Music *mus : Initializer::townMusics) {//Deleting the maps' music
      delete(mus);
    }
    for(unsigned short i = 0; i < 6; i++){
      if(Main::player.getOp(i) != nullptr){
	delete(Main::player.getOp(i));
      }
    }
    ostringstream osslog;
    osslog << "End of the program. Return " << returns;
    oplog(osslog.str());
    if(returns != 0) {
      oplog("There is a problem. Create an issue on github!");
    }
    exit(returns);
    return returns;
  }

  /*void bgTask(){
    if(Model::Data::endGame){
      quit(0);
    }
    }*/
  
  std::string& operator<<(std::string &str, int const& nbre) {
    ostringstream oss;
    oss << str << nbre;
    str = oss.str();
    return str;
  }

  std::string& operator<<(std::string &str, std::string const& thing) {
    ostringstream oss;
    oss << str << thing;
    str = oss.str();
    return str;
  }

  std::string& operator<<(std::string &str, char thing[]) {
    string strThing(thing);
    ostringstream oss;
    oss << str << strThing;
    str = oss.str();
    return str;
  }

  template<typename Base, typename T>
  bool instanceOf(const Base *toTest){
    return dynamic_cast<const T*>(toTest) != nullptr;
  }
  
}
