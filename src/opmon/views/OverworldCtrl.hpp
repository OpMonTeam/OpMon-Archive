/*!
 * \file OverworldCtrl.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \copyright GNU GPL v3.0
 */
#ifndef OVERWORLDCTRL_HPP
#define OVERWORLDCTRL_HPP

#include <SFML/Window/Event.hpp>

#include "../core/Player.hpp"
#include "../core/Core.hpp"
#include "Overworld.hpp"
#include "base/AGameScreen.hpp"

namespace OpMon {

    /*!
     * \brief Manages the overworld.
     *
     * This class checks for the different SFML events the player can trigger to interact with the overworld, like the directional keys to move the player, and then calls the associated methods/functions.
     * It also manages the two overworld states : the free state where the player can move and explore, and the dialog state, when a dialog is currently on screen.
     * Finally, it updates the Event objects and manages the debug mode.
     */
    class OverworldCtrl : public AGameScreen {
    private:
        OverworldData data;

        Overworld view;
        Player &player;

        /*!
         * \brief Determines which screen has to be loaded in loadNextScreen().
         *
         * This integer is filled with some special values determined by macros in GameMenuCtrl.cpp. Currently, there is
         * - LOAD_BATTLE : Loads BattleCtrl
         * - LOAD_MENU_OPEN : Loads the opening animation for the menu. Called when the player presses the menu key.
         * - LOAD_MENU_CLOSE : Loads the closing animation for the menu. Called when OverworldCtrl::checkEvent is called right after the end of GameMenuCtrl.
         * - LOAD_MENU : Loads GameMenuCtrl. Called when OverworldCtrl::checkEvent is called right after the end of the opening animation.
         * Then, loadNextScreen() loads in _next_gs a game screen according the value of this variable.
         */
        int loadNext = 0;

        /*!
         * \brief Contains a screenshot.
         * \details A screenshot of the frame is taken in update(sf::RenderTexture&). It used as a background in GameMenu and its opening/closing animations.
         */
        sf::Texture screenTexture;

    public:
        OverworldCtrl(Player &player, UiData *uidata);

        GameStatus checkEvent(sf::Event const &event) override;
        /*!
         * \brief Checks the necessary events when a dialog is currently playing.
         */
        GameStatus checkEventsDialog(sf::Event const &events, Overworld &overworld);
        /*!
         * \brief Checks the necessary events when no dialog is currently playing.
         */
        GameStatus checkEventsNoDialog(sf::Event const &events, Player &player);
        GameStatus update(sf::RenderTexture &frame) override;

        virtual void loadNextScreen();
        virtual void suspend();
        virtual void resume();

        /*!
         * \brief Checks the key pressed on the keyboard to see if the player wants to move.
         * \details Does not check if Overworld::justTp is `true`, if the player is currently animated or if their movement is locked (Position::moveLock). If a direction key is pressed and the player is able to move, calls PlayerCtrl::move.
         */
        void checkMove(Player &player, Overworld &overworld);

        /*!
         * \brief Moves the player, and then triggers the events activated when the player is moving towards them.
         * \details Calls Position::move and EventsCtrl::actionEvents with Events::EventTrigger::GO_IN.
         */
        void move(Side direction, Player &player, Overworld &overworld);

        /*!
         * \brief Calls Event::update for each event.
         * \param events The events.
         * \param player A reference to the player object.
         * \param overworld A reference to the overworld view.
         */
        void updateEvents(std::vector<Elements::Event *> &events, Player &player, Overworld &overworld);

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
        void actionEvents(std::vector<Elements::Event *> &events, Player &player, Elements::Events::EventTrigger toTrigger, Overworld &overworld);

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
        void checkAction(sf::Event const &event, Player &player, Overworld &overworld);
    };

} // namespace OpMon

#endif
