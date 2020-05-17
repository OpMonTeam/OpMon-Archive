/*!
 * \file AbstractMetaEvent.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <queue>
#include <list>
#include <SFML/System/Vector2.hpp>
#include "src/utils/i18n/ATranslatable.hpp"
#include "AbstractEvent.hpp"

namespace OpMon{
    namespace Elements {
        /*!
         * \brief An event that contains a queue of events.
         * \ingroup Events
         *
         * This pure virtual is made to manage event that are a composition of events.
         * The way of managing the queue of actions will depend according to what the MetaEvent will be doing.
         * Any AbstractMetaEvent automatically takes the basic properties of the first event in the queue given in the constructor,
         * and the update method will update them each frame.
         *
         * Note that the destructor will delete every given AbstractEvent pointer in the queue.
         */
        class AbstractMetaEvent : public AbstractEvent {
        protected:
        	/*!
        	 * \brief The queue of events to process.
        	 */
            std::queue<AbstractEvent*> eventQueue;

            /*!
             * \brief The list of events being proccessed.
             */
            std::list<AbstractEvent*> processingList = std::list<AbstractEvent*>();

            /*!
             * \brief If the queue of events is currently being processed.
             */
            bool processing = false;

            /*!
             * \brief A pointer to the main event.
             *
             * The main event is the first event of the unmodified eventQueue (the one given in the constructor).
             * AbstractMetaEvent takes the properties of this one event. Note that it is possible to redefine this
             * variable afterwards if needed to in a inherited class.
             */
            AbstractEvent* mainEvent;

        public:
            AbstractMetaEvent(std::queue<AbstractEvent*> eventQueue);
            AbstractMetaEvent(OverworldData &data, nlohmann::json jsonData);
            virtual void action(Player &player, Overworld &overworld) = 0;
            virtual void update(Player &player, Overworld &overworld);
            virtual bool isOver() const {return !processing;}
            virtual ~AbstractMetaEvent();
            /*!
             * \brief Returns the sprite of \ref mainEvent.
             */
            virtual const sf::Sprite* getSprite() const {return mainEvent->getSprite();}
            /*!
             * \brief Returns the texture of \ref mainEvent.
             */
            virtual const sf::Texture &getTexture() {return mainEvent->getTexture();}
            /*!
             * \brief Updates the texture of \ref mainEvent.
             */
            virtual void updateTexture() {mainEvent->updateTexture();}

            /*!
             * \brief Changes the position of the event.
             *
             * This method moves the event by changing \ref position, but also \ref mapPos and the position of the \ref sprite.
             * The new position has to be in squares.
             */
            virtual void setPosition(int x, int y) {setPosition(sf::Vector2i(x,y));}

            /*!
             * \brief Changes the position of the event.
             *
             * This method moves the event by changing \ref position, but also \ref mapPos and the position of the \ref sprite.
             * \param xy The new position, in squares.
             */
             virtual void setPosition(sf::Vector2i pos);
        };
    }
}
