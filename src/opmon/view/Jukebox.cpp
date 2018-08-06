#include "Jukebox.hpp"
#include "../model/storage/ResourceLoader.hpp"
#include "../start/Core.hpp"
#include <iostream>

namespace OpMon {
    namespace View {
        Jukebox::Jukebox()
          : globalVolume(100) {}

        void Jukebox::addMusic(std::string name, std::string path, bool loop) {
            sf::Music *music = Model::ResourceLoader::loadMusic(path.c_str());
            music->setVolume(globalVolume);
            music->setLoop(loop);
            if(musList[name] != nullptr) {
                delete(musList[name]);
            }
            musList[name] = music;
        }

        void Jukebox::addSound(std::string name, std::string path) {
            sf::SoundBuffer *sb = new sf::SoundBuffer();
            Model::ResourceLoader::load(*sb, path.c_str());
            if(soundsList[name].first != nullptr) {
                delete(soundsList[name].second);
            }
            soundsList[name].first = sb;
            soundsList[name].second = new sf::Sound();
            soundsList[name].second->setBuffer(*soundsList[name].first);
            soundsList[name].second->setVolume(globalVolume);
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
            if(musList[music] == playing) {
                return;
            }

            if(playing != nullptr) {
                playing->stop();
            }

            if(musList[music] == nullptr) {
                handleError(std::string("Warning - Jukebox::play : Unknown music \"") + music + "\"");
                return;
            }

            musList.at(music)->play();
            playing = musList.at(music);
        }

        void Jukebox::pause() {
            if(playing != nullptr) {
                playing->pause();
            }
            playing = nullptr;
        }

        void Jukebox::stop() {
            if(playing != nullptr) {
                playing->stop();
            }
            playing = nullptr;
        }

        void Jukebox::setGlobalVolume(float globalVolume) {
            if(globalVolume > 100) {
                handleError(std::string("Warning - Jukebox::setGlobalVolume : Volume greater than 100"));
                return;
            }

            for(auto itor = musList.begin(); itor != musList.end(); ++itor) {
                itor->second->setVolume(globalVolume);
            }
            for(auto itor = soundsList.begin(); itor != soundsList.end(); ++itor) {
                itor->second.second->setVolume(globalVolume);
            }
            this->globalVolume = globalVolume;
        }

        void Jukebox::playSound(std::string sound) {
            if(soundsList[sound].first == nullptr) {
                handleError(std::string("Warning - Jukebox::playSound : Unknown sound \"") + sound + "\"");
                return;
            }
            soundsList.at(sound).second->play();
        }

        int Jukebox::getGlobalVolume() {
            return globalVolume;
        }
    } // namespace View
} // namespace OpMon
