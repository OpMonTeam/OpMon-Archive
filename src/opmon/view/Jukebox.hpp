/**
  Jukebox.hpp
  Author : Cyrion
  File under licence GNU GPL-3.0
  http://opmon-game.ga
*/
#pragma once

#include <map>

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

namespace OpMon {
    namespace View {

        class Jukebox {
          private:
            std::map<std::string, sf::Music *> musList;
	  std::map<std::string, std::pair<sf::SoundBuffer *, sf::Sound *> > soundsList;
            std::string playingID;
	  bool mute = false;
            float globalVolume;
#define DEFAULT_VOLUME 1

	  void setMute();
	  void unMute();

          public:
            Jukebox();

            ~Jukebox();

            void addMusic(std::string name, std::string path, bool loop = true);

            void play(std::string music);

            void pause(std::string music);

            void stop(std::string music);

            void setGlobalVolume(float globalVolume);

            int getGlobalVolume();

	  void playSound(std::string sound);

	  void addSound(std::string name, std::string path);

	  void toggleMute();

	  bool isMute() { return mute; }
        };

    } // namespace View
} // namespace OpMon
