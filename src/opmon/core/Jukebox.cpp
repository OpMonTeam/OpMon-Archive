/*
Jukebox.cpp
Author : Cyrielle
Contributors : Samurai413x, BAKFR
File under GNU GPL v3.0 license
*/
#include "Jukebox.hpp"

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include "src/utils/ResourceLoader.hpp"
#include "src/utils/exceptions.hpp"
#include "src/utils/log.hpp"

namespace OpMon {

    void Jukebox::addMusic(const std::string &name, const std::string &path,
                           bool loop) {
        try {
            auto music = Utils::ResourceLoader::loadMusic(path.c_str());
            music->setVolume(globalVolume);
            music->setLoop(loop);
            musList[name] = std::move(music);
        } catch(Utils::LoadingException &e) {
            Utils::Log::oplog(e.desc(), true);
            Utils::Log::warn(std::string("Music '") + name +
                             "' failed to load.");
        }
    }

    void Jukebox::addSound(const std::string &name, const std::string &path) {
        try {
            // Sounds are saved in the code as a pair of sf::SoundBuffer and
            // sf::Sound.
            auto sb = std::make_unique<sf::SoundBuffer>();
            Utils::ResourceLoader::load(*sb, path.c_str());

            soundsList[name].first = std::move(sb);
            soundsList[name].second = std::make_unique<sf::Sound>();
            soundsList[name].second->setBuffer(*soundsList[name].first);
            soundsList[name].second->setVolume(globalVolume);
        } catch(Utils::LoadingException &e) {
            Utils::Log::oplog(e.desc(), true);
            Utils::Log::warn(std::string("Sound '") + name +
                             "' failed to load.");
        }
    }

    void Jukebox::play(const std::string &music) {
        if(musList[music].get() == playing) {
            return;
        }

        if(playing != nullptr) {
            playing->stop();
        }

        if(musList[music].get() == nullptr) {
            Utils::Log::warn(std::string("Unknown music '") + music + "'");
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
        if(globalVolume > 100 || globalVolume < 0) {
            Utils::Log::warn(
                std::string("Volume greater than 100 or lesser than 0."));
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

    void Jukebox::playSound(const std::string &sound) {
        if(soundsList[sound].first.get() == nullptr) {
            Utils::Log::warn(std::string("Unknown sound '") + sound + "'");
            return;
        }
        soundsList.at(sound).second->play();
    }

    int Jukebox::getGlobalVolume() const { return globalVolume; }

} // namespace OpMon
