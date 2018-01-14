
#include <SFML/Window/Event.hpp>
#include "./Gameloop.hpp"
#include "../view/Window.hpp"
#include "../controller/MainMenuCtrl.hpp"


namespace OpMon {

  GameLoop::GameLoop() {
  }

  GameStatus GameLoop::operator()() {

    // TODO: add first item outside of the Gameloop.
    Controller::AGameScreen *first_ctrl = new Controller::MainMenuCtrl();


    _gameScreens.push(first_ctrl);

    GameStatus status = GameStatus::CONTINUE;
    while (status != GameStatus::STOP) {
      status = GameStatus::CONTINUE;

      auto ctrl = _gameScreens.top();
      sf::Event event;


      //process all pending SFML events
      while (View::window.pollEvent(event)) {
        status = _checkQuit(event);
        if (status == GameStatus::STOP)
          break;
        status = ctrl->checkEvent(event);
        if (status == GameStatus::STOP)
          break;
      }

      if (status == GameStatus::STOP)
        break;

      // frame update & draw
      status = ctrl->update();

      switch (status) {
        case GameStatus::NEXT:
          ctrl->suspend();
          _gameScreens.push(ctrl->getNextGameScreen());
          break;
        case GameStatus::PREVIOUS:
          _gameScreens.pop();
          _gameScreens.top()->resume();
        default:
          break;
      }

      View::winRefresh();
    }

    while (auto *ctrl = _gameScreens.top()) {
      delete (ctrl);
      _gameScreens.pop();
    }

    return GameStatus::STOP;
  }

  GameStatus GameLoop::_checkQuit(const sf::Event &event) {
    switch (event.type) {
      case sf::Event::Closed:
        return GameStatus::STOP;
      default:
        break;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      return GameStatus::STOP;
    }

    return GameStatus::CONTINUE;
  }

}
