
#include <SFML/Window/Event.hpp>
#include "./Gameloop.hpp"
#include "../view/Window.hpp"
#include "../controller/MainMenuCtrl.hpp"


namespace OpMon{

  GameLoop::GameLoop()
    : frames(0){
  }

  GameLoop::~GameLoop(){
    while(!_gameScreens.empty()){
      delete(_gameScreens.top());
      _gameScreens.pop();
    }
  }

  int* GameLoop::getFrames(){
    return &this->frames;
  }
  
  GameStatus GameLoop::operator()(){

    // TODO: add first item outside of the Gameloop.
    Controller::AGameScreen *first_ctrl = new Controller::MainMenuCtrl();


    _gameScreens.push(first_ctrl);

    GameStatus status = GameStatus::CONTINUE;
    while(status != GameStatus::STOP){
      status = GameStatus::CONTINUE;

      frames++;
      
      auto ctrl = _gameScreens.top();
      sf::Event event;


      //process all pending SFML events
      while(status == GameStatus::CONTINUE && View::window.pollEvent(event)){
        status = _checkQuit(event);
        if (status == GameStatus::STOP)
          break;
        status = ctrl->checkEvent(event);
      }

      if (status == GameStatus::CONTINUE){
        // frame update & draw
        status = ctrl->update();
      }

      switch(status){
        case GameStatus::NEXT:
          ctrl->suspend();
          _gameScreens.push(ctrl->getNextGameScreen());
          break;
        case GameStatus::PREVIOUS:
          delete(ctrl);
          _gameScreens.pop();
          _gameScreens.top()->resume();
        case GameStatus::CONTINUE:
          View::frame.display();
          View::winRefresh();
        default:
          break;
      }
    }

    return GameStatus::STOP;
  }

  GameStatus GameLoop::_checkQuit(const sf::Event &event){
    switch(event.type){
      case sf::Event::Closed:
        return GameStatus::STOP;
      default:
        break;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
      return GameStatus::STOP;
    }

    return GameStatus::CONTINUE;
  }

}
