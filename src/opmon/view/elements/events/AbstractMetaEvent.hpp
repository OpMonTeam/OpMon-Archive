/*!
 * \file MetaEvent.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <queue>
#include <SFML/System/Vector2.hpp>
#include "src/utils/i18n/ATranslatable.hpp"
#include "AbstractEvent.hpp"

namespace OpMon{
    namespace Elements {
        /*!
         * \brief An event that contains a queue of events.
         *
         * This pure virtual is made to manage event that are a composition of events.
         * The way of managing the queue of actions will depend according to what the MetaEvent will be doing.
         * Any AbstractMetaEvent automatically takes the basic properties of the first event in the queue (
         */
        class AbstractMetaEvent : public AbstractEvent {
        private:
            std::queue<AbstractEvent*> eventQueue;
        public:
            AbstractMetaEvent(std::queue<AbstractEvent*> eventQueue);
            void action(Player &player, Overworld &overworld) = 0;
            void update(Player &player, Overworld &overworld) = 0;
        };
    }
}
