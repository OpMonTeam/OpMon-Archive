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

    if(instanceOf<View::Overworld*>(interfaces.top())){
      View::Overworld& overworld = *dynamic_cast<View::Overworld*>(interfaces.top());
      if(dialog){
	if(overworld.getDialog()->isDialogOver()){
	  dialog = false;
	}
      }
      Controller::OverworldCtrl::checkEvents(events, overworld, dialog, player);
      if(overworld->getCurrent() != nullptr){
	Controller::EventsCtrl::updateEvent(overworld->getCurrent->getEvents(), player);
      }
      Controller::PlayerCtrl::checkMove(player, events);
      
    }else if(instanceOf<View::MainMenu*>(interfaces.top())){
      View::MainMenu& mainmenu = *dynamic_cast<View::MainMenu*>(interfaces.top());
      status = Controller::MenuCtrl::checkEvents(events, mainmenu);
    }

    if(status != GameStatus::STOP){
    
      if(!instanceOf<View::Overworld*>(interface.top())){
	status = (*interfaces.top())();
      }else{
	status = (*dynamic_cast<View::Overworld*>(interfaces.top()))(dialog, frames);
      }

    
      if(status == GameStatus::NEXT){
	status == GameStatus::CONTINUE;
	interfaces.top()->pause();
	interfaces.push(interfaces.top()->getNextPanel());
      }else if(status == GameStatus::PREVIOUS){
	status == GameStatus::CONTINUE;
	delete(interfaces.top());
	interfaces.pop();
	interfaces.top()->play();
      }

    }
    
    Window::winRefresh();

    endGame = (status == GameStatus::STOP);

  }

  for(Interface* interface : interfaces){
    delete(interface);
    interfaces.pop();
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
