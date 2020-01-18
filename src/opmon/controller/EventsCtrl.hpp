/*!
 * \file EventsCtrl.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \copyright GNU GPL v3.0
*/
#ifndef EVENTSCTRL_HPP
#define EVENTSCTRL_HPP

#include <vector>

#include <SFML/Window/Event.hpp>

#include "../model/sysObjects/Events.hpp"

namespace OpMon {
    namespace Controller {
        /*!
	 * \brief Activates and updates the events in the current map.
	 *
	 * This class only contains static methods which are used to
	 * manage all the events of a map.
	 */
        class EventsCtrl {
          public:
	    /*!
	     * \brief Calls Event::update for each event.
	     * \param events The events.
	     * \param player A reference to the player object.
	     * \param overworld A reference to the overworld view.
	     */
            static void updateEvents(std::vector<Model::Event *> &events, Model::Player &player, View::Overworld &overworld);
	    /*!
	     * \brief Calls Event::action for some events.
	     * \details The method checks two things first :
	     * - If the EventTrigger of the event matches with the
	     * given EventTrigger.
	     * - If the side of interaction of the event matches with
	     * the player's direction.
	     * \param events The events.
	     * \param player A reference to the player object.
	     * \param toTrigger The method will only call
	     * Event::action for the events with this EventTrigger.
	     * \param overworld A reference to the overworld view.
	     */
            static void actionEvents(std::vector<Model::Event *> &events, Model::Player &player, Model::Events::EventTrigger toTrigger, View::Overworld &overworld);
	    /*!
	     * \brief Calls actionEvents for some events.
	     * \details This method does two things :
	     * - If the player has pressed the interaction key, it
	     * calls actionEvents for with all the events in the square
	     * ahead of the player, with EventTrigger::PRESS
	     * - It calls actionEvents with all the events in the
	     * square where the player currently is, with EventTrigger::BE_IN.
	     * \param event The events.
	     * \param player A reference to the player object.
	     * \param overworld A reference to the overworld view.
	     */
            static void checkAction(sf::Event const &event, Model::Player &player, View::Overworld &overworld);
        };
    } // namespace Controller
} // namespace OpMon

#endif
