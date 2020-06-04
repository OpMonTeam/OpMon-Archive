/*!
 * \file SoundEvent.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */

#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>

#include "AbstractEvent.hpp"
#include "src/nlohmann/json.hpp"

namespace OpMon {
    /*!
     * \brief An event that plays a sound or a music when triggered.
     * \ingroup Events
     */
    class SoundEvent : public AbstractEvent {
      private:
        /*!
         * \brief The ID of the sound/music to play.
         */
        std::string playID;

        /*!
         * \brief If the thing to play is a music.
         */
        bool music;

        /*!
         * \brief If an action toggles the music/sound or just starts it.
         */
        bool toggle;

        /*!
         * \brief If the music is playing or not.
         */
        bool playing = false;

      public:
        SoundEvent(sf::Texture &texture, std::vector<sf::IntRect> rectangles,
                   EventTrigger eventTrigger, sf::Vector2f const &position,
                   std::string const &playID, bool music, bool toggle,
                   int sides = SIDE_ALL, bool passable = true);
        SoundEvent(OverworldData &data, nlohmann::json jsonData);
        virtual void update(Overworld &overworld) {}
        virtual void action(Overworld &overworld);
        bool isOver() const { return !playing; }
    };
} // namespace OpMon
