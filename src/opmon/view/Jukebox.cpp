/*
Jukebox.cpp
Author : Cyrion
Contributors : Samurai413x, BAKFR
File under GNU GPL v3.0 license
*/
#include "Jukebox.hpp"
#include "../start/Core.hpp"
#include <iostream>

namespace OpMon {
    namespace View {
        void Jukebox::addMusic(const std::string& name, const std::string& path, bool loop) {
            auto music = Model::ResourceLoader::loadMusic(path.c_str());
            music->setVolume(globalVolume);
            music->setLoop(loop);
            musList[name] = std::move(music);
        }

        void Jukebox::addSound(const std::string& name, const std::string& path) {
            //Sounds are saved in the code as a pair of sf::SoundBuffer and sf::Sound.
            auto sb = std::make_unique<sf::SoundBuffer>();
            Model::ResourceLoader::load(*sb, path.c_str());

            soundsList[name].first = std::move(sb);
            soundsList[name].second = std::make_unique<sf::Sound>();
            soundsList[name].second->setBuffer(*soundsList[name].first);
            soundsList[name].second->setVolume(globalVolume);
        }

        void Jukebox::play(const std::string& music) {
            if(musList[music].get() == playing) {
                return;
            }

            if(playing != nullptr) {
                playing->stop();
            }

            if(musList[music].get() == nullptr) {
                handleError(std::string("Warning - Jukebox::play : Unknown music \"") + music + "\"");
                return;
            }

            musList.at(music)->play();
            playing = musList.at(music).get();
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

        void Jukebox::playSound(const std::string& sound) {
            if(soundsList[sound].first.get() == nullptr) {
                handleError(std::string("Warning - Jukebox::playSound : Unknown sound \"") + sound + "\"");
                return;
            }
            soundsList.at(sound).second->play();
        }

        int Jukebox::getGlobalVolume() const {
            return globalVolume;
        }
    } // namespace View
} // namespace OpMon
