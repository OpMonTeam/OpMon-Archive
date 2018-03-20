/**
  Jukebox.hpp
  Author : Cyrion
  File under licence GNU GPL-3.0
  http://opmon-game.ga
*/
#pragma once

#include <map>

#include <SFML/Audio/Music.hpp>

namespace OpMon {
    namespace View {

        class Jukebox {
          private:
            std::map<std::string, sf::Music *> musList;
            std::string playingID;
            int globalVolume;

          public:
            Jukebox();

            ~Jukebox();

            void addMusic(std::string name, std::string path, int volume = -15, bool loop = true);

            void play(std::string music);

            void pause(std::string music);

            void stop(std::string music);

            void setGlobalVolume(int globalVolume);

            int getGlobalVolume();
        };

    } // namespace View
} // namespace OpMon
