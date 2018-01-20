#include "Jukebox.hpp"

namespace OpMon{
  namespace View{
    Jukebox::Jukebox() : globalVolume(100) {}

    void Jukebox::addMusic(std::string name, std::string path, int volume, bool loop) {
      if(volume == -15){
	volume = globalVolume;
      }
      sf::Music* music = new sf::Music();
      music->openFromFile(path);
      music->setVolume(volume);
      music->setLoop(loop);
      musList[name] = music;
    }

    Jukebox::~Jukebox(){
      for(auto itor = musList.begin(); itor != musList.end(); ++itor){
	delete(itor->second);
      }
    }

    void Jukebox::play(std::string music){
      if(music == playingID){
	return;
      }
      if(!playingID.empty()){
	musList.at(playingID)->pause();
      }
      musList.at(music)->play();
      playingID = music;
    }

    void Jukebox::pause(std::string music){
      musList.at(music)->pause();
      playingID = std::string();
    }

    void Jukebox::stop(std::string music){
      musList.at(music)->stop();
      playingID = std::string();
    }

    void Jukebox::setGlobalVolume(int globalVolume){
      for(auto itor = musList.begin(); itor != musList.end(); ++itor){
	itor->second->setVolume((globalVolume * itor->second->getVolume()) / this->globalVolume);
      }
      this->globalVolume = globalVolume;
    }

    int Jukebox::getGlobalVolume(){
      return globalVolume;
    }
  }
}
