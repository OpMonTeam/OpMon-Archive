#include "Window.hpp"
#include "../model/storage/Data.hpp"
#include "src/utils/fs.hpp"
#include "src/utils/log.hpp"
#include "../model/save/OptionsSave.hpp"
#include "../start/Core.hpp"
#include "../../utils/StringKeys.hpp"

#include <SFML/Graphics/Text.hpp>


using Utils::Log::oplog;


namespace OpMon{
  namespace View{
    sf::RenderTexture frame;
    sf::RenderWindow window;
    bool init;
    bool fullScreen;
    void open(){
      init = true;


      sf::ContextSettings settings;
      //settings.antialiasingLevel = 8;
      if(!Model::OptionsSave::checkParam("fullscreen")) {
        Model::OptionsSave::addOrModifParam("fullscreen", "false");
      }
      if(Model::OptionsSave::getParam("fullscreen").getValue() == "true") {
        fullScreen = true;
        window.create(sf::VideoMode::getFullscreenModes().at(0), "OpMon Lazuli", sf::Style::Fullscreen, settings);
      } else {
        window.create(sf::VideoMode(512, 512), "OpMon Lazuli", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize, settings);
      }

      frame.create(512, 512);
      window.clear(sf::Color::White);
      sf::Texture loadTexture;
      if(! loadTexture.loadFromFile(Utils::Fs::getPath(RESSOURCES_PATH + "backgrounds/loading.png"))) {
        handleError("Unable to open the loading screen.", false);
      }
      sf::Sprite spriteLoad;
      spriteLoad.setTexture(loadTexture);
      sf::Text textLoad;
      textLoad.setString(Utils::StringKeys::get("load.txt"));
      textLoad.setCharacterSize(45);
      textLoad.setFont(Model::Data::Ui::font);
      textLoad.setFillColor(sf::Color::White);
      textLoad.setPosition(30, 400);
      frame.draw(spriteLoad);
      frame.draw(textLoad);
      frame.display();
      winRefresh();

      oplog("Window initialized!");
#if 0
      window.setVerticalSyncEnabled(true);
#endif
      window.setFramerateLimit(30);
      window.setKeyRepeatEnabled(false);
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

      frame.clear(sf::Color::Black);
      

    }

    void close(){
      /*oplog("Deleting the variables...");
	destroyAll();*/
      oplog("Closing the window...");
      window.close();
      init = false;
      oplog("Window closed. No error detected. Goodbye.");
    }

    void winRefresh() {
      sf::Sprite sprite(frame.getTexture());

      if(fullScreen) {
        float coef = window.getSize().y / (sprite.getGlobalBounds().height);
        sprite.setScale(coef, coef);
        sprite.setPosition(((window.getSize().x / 2) - (sprite.getGlobalBounds().width / 2)), 0);
      }
      
      window.clear(sf::Color::Black);
      window.draw(sprite);
      window.display();
    }


  }
}
