#include "GameLoop.hpp"

GameLoop::GameLoop(){
}

GameStatus GameLoop::operator()(){
  while(!endGame){
    frames++;
    oldTicks = GET_TICKS;
    if(wait){
      Window::window.waitEvent(events);
    }else{
      Window::window.pollEvent(events);
    }
    if(checkQuit() == GameStatus::STOP){
      endGame = true;
    }

    GameStatus status = GameStatus::CONTINUE;
    switch(gamepart){
    case GamePart::OVERWORLD:
      if(dialog){
	if(overworld.getDialog()->isDialogOver()){
	  dialog = false;
	}
      }
      Controller::OverworldCtrl::checkEvents(events, overworld, dialog, player);
      Controller::PlayerCtrl::checkMove(player, events);
      status = overworld(dialog, frames);
    }

    Window::winRefresh();

    endGame = (status == GameStatus::STOP);

  }

  if(overworld.isLaunched()){
    overworld.del();
  }
  
  return GameStatus::STOP;
}

GameStatus GameLoop::checkQuit(){
  switch (events.type) {
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
