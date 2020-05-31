/*!
 * \dir src/opmon/view/ui
 * \brief Contains the elements of the user interface
 *
 * This directory contains the elements that are directly used in the user
 * interface.
 */
/*!
 * \file Jukebox.hpp
 * \authors Cyrielle
 * \authors Samurai413x
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <unordered_map>
#include <utility>

#include "src/utils/ResourceLoader.hpp"

namespace sf {
    class Music;
    class Sound;
    class SoundBuffer;
} // namespace sf

namespace OpMon {
    namespace Ui {

        /*!
         * \brief Class managing the audio in the game.
         */
        class Jukebox {
          private:
            /*!
             * \brief A map of the different musics in the game.
             */
            std::unordered_map<std::string, std::unique_ptr<sf::Music>> musList;
            /*!
             * \brief A map of the different sounds in the game.
             */
            std::unordered_map<std::string,
                               std::pair<std::unique_ptr<sf::SoundBuffer>,
                                         std::unique_ptr<sf::Sound>>>
                soundsList;
            /*!
             * \brief A pointer to the currently playing music.
             */
            sf::Music *playing {nullptr};
            /*!
             * \brief The global volume of the musics and sounds.
             */
            float globalVolume {50.0};

          public:
            Jukebox() = default;
            ~Jukebox() = default;

            /*!
             * \brief Adds a music to the jukebox.
             * \param name The string to associate with the music.
             * \param path The path of the music.
             * \param loop Sets if the music has to loop or not.
             */
            void addMusic(const std::string &name, const std::string &path,
                          bool loop = true);

            /*!
             * \brief Plays the selected music.
             * \param music The string identifier of the music.
             * \details If the music to play is already playing, the method will not restart the music. The method will replace any other music currently playing.
             */
            void play(const std::string &music);
            /*!
             * \brief Pauses the current music.
             */
            void pause();
            /*!
             * \brief Stops the current music.
             */
            void stop();

            void setGlobalVolume(float globalVolume);
            int getGlobalVolume() const;

            /*!
             * \brief Plays the selected sound.
             * \param sound The string identifier of the sound to play.
             */
            void playSound(const std::string &sound);
            /*!
             * \brief Adds a sound to the jukebox.
             * \param name The string to associate with the sound.
             * \param path The path of the sound.
             */
            void addSound(const std::string &name, const std::string &path);
        };

    } // namespace Ui
} // namespace OpMon
