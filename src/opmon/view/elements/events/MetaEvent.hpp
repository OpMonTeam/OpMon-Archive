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
         * \brief An event that calls a queue of other events.
         *
         * This event takes the properties of the first event of the queue.
         */
        class MetaEvent : public AbstractEvent {
        private:
            std::queue<AbstractEvent*> eventQueue;
        public:
            MetaEvent(sf::Vector2i position, std::queue<AbstractEvent*> eventQueue);
        };
    }
}
