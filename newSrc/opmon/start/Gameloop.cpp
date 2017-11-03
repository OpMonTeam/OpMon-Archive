#include "GameLoop.hpp"

GameLoop::GameLoop(){
}

GameStatus GameLoop::operator()(){
  while(!endGame){
    if(GET_TICKS - oldTicks > FPS_TICKS){
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
	  status = overworld(true, frames, actualDialog);
	}else{
	  status = overworld(false, frames);
	}
      }

      Window::winRefresh();

      if(status == GameStatus::STOP){
	endGame = true;
      }
      
    }else{
      Utils::wait(FPS_TICKS - (GET_TICKS - ancientTick));
    }
  }
  //Free memory here
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
