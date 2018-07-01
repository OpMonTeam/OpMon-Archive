#include "Jukebox.hpp"
#include "../model/storage/ResourceLoader.hpp"

namespace OpMon {
    namespace View {
        Jukebox::Jukebox()
          : globalVolume(100) {}

        void Jukebox::addMusic(std::string name, std::string path, float volume, bool loop) {
            sf::Music *music = Model::ResourceLoader::loadMusic(path.c_str());
            music->setVolume(globalVolume * volume);
            music->setLoop(loop);
	    if(musList[name] != nullptr){
	      delete(musList[name]);
	    }
            musList[name] = music;
        }

      void Jukebox::addSound(std::string name, std::string path, float volume) {
	sf::SoundBuffer *sb = new sf::SoundBuffer();
	Model::ResourceLoader::load(*sb, path.c_str());
	if(soundsList[name].first != nullptr) {
	  delete(soundsList[name]);
	}
	soundsList[name].first = sb;
	soundsList[name].second = new sf::Sound();
	soundsList[name].second->setBuffer(*soundsList[name].first);
	soundsList[name].second->setVolume(globalVolume * volume);
      }

        Jukebox::~Jukebox() {
            for(auto itor = musList.begin(); itor != musList.end(); ++itor) {
	      delete(itor->second);
            }
	    for(auto itor = soundsList.begin(); itor != soundsList.end(); ++itor) {
	      delete(itor->second.first);
	      delete(itor->second.second);
	    }
        }

        void Jukebox::play(std::string music) {
            if(music == playingID) {
                return;
            }

            if(!playingID.empty()) {
                musList.at(playingID)->stop();
            }

            if(musList[music] == nullptr) {
	      handleError(std::string("Warning - Jukebox::play : Unknown music \"") + music + "\"");
                return;
            }

	    if(!mute){
	      musList.at(music)->play();
	    }
            playingID = music;
        }

        void Jukebox::pause(std::string music) {
            musList.at(music)->pause();
            playingID = std::string();
        }

        void Jukebox::stop(std::string music) {
            musList.at(music)->stop();
            playingID = std::string();
        }

      void Jukebox::setMute() {
	mute = true;
	if(playingID != std::string()){
	  musList.at(playingID)->pause();
	}
      }

      void Jukebox::unMute() {
	mute = false;
	if(playingID != std::string()){
	  musicList.at(playingID)->play();
	}
      }
      
        void Jukebox::setGlobalVolume(float globalVolume) {
	  if(globalVolume > 100){
	    handeError(std::string("Warning - Jukebox::setGlobalVolume : Volume greater than 100"));
	    return;
	  }
	  if(globalVolume == 0){
	    setMute();
	  } else if(mute && globalVolume > 0){
	    unMute();
	  }else{
            for(auto itor = musList.begin(); itor != musList.end(); ++itor) {
                itor->second->setVolume((globalVolume * itor->second->getVolume()) / this->globalVolume);
            }
	    for(auto itor = soundsList.begin(); itor != soundsList.end(); ++itor){
	      itor->second.second->setVolume((globalVolume * itor->second.second->getVolume()) / this->globalVolume);
	    }
            this->globalVolume = globalVolume;
	  }
        }

      void Jukebox::toggleMute() {
	mute = !mute;
	if(mute){
	  setMute();
	}else{
	  unMute();
	}
      }

      void playSound(std::string sound){
	if(soundsList[sound].first == nullptr){
	  handleError(std::string("Warning - Jukebox::playSound : Unknown sound \"") + sound + "\"");
	  return;
	}
	if(!mute){
	  soundsList.at(sound).second->play();
	}
      }
      
        int Jukebox::getGlobalVolume() {
            return globalVolume;
        }
    } // namespace View
} // namespace OpMon
