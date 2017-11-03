#include "Window.hpp"

namespace OpMon{
  namespace View{
    sf::RenderTexture frame;
    sf::RenderWindow window;
    bool fullscreen;
    GameStatus open(){
      if(!font.loadFromFile(getPath(RESSOURCES_PATH + "fonts/Default.ttf"))) {
        handleError("Font cannot be opened.", true);
      }
      oplog("Font opened");

      init = true;


      sf::ContextSettings settings;
      //settings.antialiasingLevel = 8;
      if(!OptionsSave::checkParam("fullscreen")) {
        OptionsSave::addOrModifParam("fullscreen", "false");
      }
      if(OptionsSave::getParam("fullscreen").getValue() == "true") {
        fullScreen = true;
        window.create(sf::VideoMode::getFullscreenModes().at(0), "OpMon Lazuli", sf::Style::Fullscreen, settings);
      } else {
        window.create(sf::VideoMode(512, 512), "OpMon Lazuli", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize, settings);
      }

      frame.create(512, 512);
      window.clear(sf::Color::White);
      sf::Texture loadTexture;
      if(! loadTexture.loadFromFile(getPath(RESSOURCES_PATH + "backgrounds/loading.png"))) {
        handleError("Unable to open the loading screen.", false);
      }
      sf::Sprite spriteLoad;
      spriteLoad.setTexture(loadTexture);
      sf::Text textLoad;
      textLoad.setString(StringKeys::get("load.txt"));
      textLoad.setCharacterSize(45);
      textLoad.setFont(font);
      textLoad.setColor(sf::Color::White);
      textLoad.setPosition(30, 400);
      frame.draw(spriteLoad);
      frame.draw(textLoad);
      frame.display();
      winRefresh();

      oplog("Window initialized!");
      sf::SoundBuffer buf;
#if 0
      window.setVerticalSyncEnabled(true);
#endif
      window.setFramerateLimit(180);
      if(!buf.loadFromFile(getPath(RESSOURCES_PATH + "audio/sounds/dialogChange.ogg"))) {
        handleError("Unable to open dialog sound.", false);
      }
      window.setKeyRepeatEnabled(false);
      dialogPass.setBuffer(buf);
      oplog("Loading variables");
      initAll();
      frame.clear(sf::Color::White);
      //#define TEST
#ifdef TEST
      ifstream strm(RESSOURCES_PATH + "keys/francais.rkeys");
      string read;
      getline(strm, read);
      getline(strm, read);
      getline(strm, read);
      getline(strm, read);
      getline(strm, read);
      getline(strm, read);
      getline(strm, read);
      getline(strm, read);
      getline(strm, read);
      getline(strm, read);
      getline(strm, read);
      sf::String sfstr = sf::String::fromUtf8(read.begin(), read.end());
      sf::Text txt;
      txt.setString(sfstr);
      txt.setColor(sf::Color::Blue);
      frame.clear(sf::Color::White);
      cout << read << endl;
      frame.draw(txt);
      frame.display();
      winRefresh();
      Utils::wait(1000 * 5);
#endif
      frame.clear(sf::Color::White);
      frame.display();
      winRefresh();

      dialogPass.setVolume(50);
      frame.clear(sf::Color::Black);
      oplog("Launching the main menu.");
      if(mainmenu.mainMenu() != -1) {
        mainmenu.bruitPush.play();
        mainmenu.bgMusTitle.stop();
        if(startscene.startScene() != -1) {
	  startscene.bgMus.stop();
	  frame.draw(spriteLoad);
	  frame.draw(textLoad);
	  frame.display();
	  winRefresh();
	  if(Main::player.getName().isEmpty()){
	    Main::player.setName("Céchine");
	  }
	  //Initializating opmons
	  OpMon *op1 = new OpMon("", Initializer::listOp.at(4), 20, {new Attacks::Belier(), new Attacks::Charge(), nullptr, nullptr}, Nature::BOLD);
	  OpMon *op2 = new OpMon("", Initializer::listOp.at(1), 22, {new Attacks::Belier(), new Attacks::Charge(), nullptr, nullptr}, Nature::NAIVE);
	  Main::player.addOpToOpTeam(op1);
	  Main::player.addOpToOpTeam(op2);
	  if(overworld.overworld() != -1) {
	    if(overworld.overworld() == 2) {


	    }
	  }
        }
      } else {
        mainmenu.bruitPush.play();
      }

      oplog("Deleting the variables...");
      destroyAll();
      oplog("Closing the window...");
      window.close();
      init = false;
      delete(windowRefresh);
      oplog("Window closed. No error detected. Goodbye.");
    }

    void MainFrame::winRefresh() {
      sf::Texture txture = frame.getTexture();
      sf::Sprite sprite;
      sprite.setTexture(txture);

      if(fullScreen) {
        float coef = window.getSize().y / ((float) sprite.getGlobalBounds().height);
        sprite.setScale(coef, coef);
        sprite.setPosition(((window.getSize().x / 2) - (sprite.getGlobalBounds().width / 2)), 0);
      }
      
      window.clear(sf::Color::Black);
      window.draw(sprite);
      window.display();
      /*int ancientTick = 0;
	while(window.isOpen()){
	if(GET_TICKS - ancientTick < FPS_TICKS){

	}else{
	Utils::wait(GET_TICKS - ancientTick);
	}
	}*/
    }


  }
}
