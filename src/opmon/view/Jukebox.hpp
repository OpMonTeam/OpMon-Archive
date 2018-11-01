/**
  Jukebox.hpp
  Author : Cyrion
  Contributor  : Samurai413x
  File under GNU GPL v3.0 license
*/
#pragma once

#include <unordered_map>
#include <memory>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "../model/storage/ResourceLoader.hpp"

namespace OpMon {
    namespace View {

        class Jukebox {
          private:
            std::unordered_map<std::string, std::unique_ptr<sf::Music>> musList;
            std::unordered_map<std::string, std::pair<std::unique_ptr<sf::SoundBuffer>, std::unique_ptr<sf::Sound>>> soundsList;
            sf::Music *playing{nullptr};
            float globalVolume{50.0};

          public:
            Jukebox() = default;
            ~Jukebox() = default;

            void addMusic(const std::string& name, const std::string& path, bool loop = true);

            void play(const std::string& music);
            void pause();
            void stop();

            void setGlobalVolume(float globalVolume);
            int getGlobalVolume() const;

            void playSound(const std::string& sound);
            void addSound(const std::string& name, const std::string& path);
        };

    } // namespace View
} // namespace OpMon
