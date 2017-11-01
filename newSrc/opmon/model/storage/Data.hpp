/**
   Data.hpp : Contains the global variables used in the program.
*/
#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <vector>
#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/Music.hpp>

namespace OpMon{
  namespace Model{
    namespace Data{
      namespace OpMons{
	extern std::map<unsigned int, Species> listOp;
	extern std::vector<std::map<int, std::string> > atkOpLvl; 
      }

      namespace Ui{
	extern std::map<std::string, Map *> maps;
	extern std::vector<sf::Music *> townMusics;
	extern sf::Texture texturePP[4];
	extern sf::Texture walkingPP[4];
	extern sf::Texture walkingPP2[4];
	extern sf::Texture backPP;//Not init yet
    
	extern std::map<std::string, std::vector<sf::Texture> > charaTextures;
      
	extern sf::Texture tileset;
	//Battle
	extern sf::Texture bActButtons[4];
	extern sf::Texture bHpBar;
	extern sf::Texture bHpBg;
	extern std::vector<sf::Texture> battleBackgrounds;
      
	extern std::vector<sf::Texture> charaFront;
      
	extern std::vector<std::vector<sf::Texture> > doorsTextures;
	//std::string backgrounds[];

      }
      extern Player player;
      extern bool endGame;
      namespace Animations{
	sf::Texture fen[6];
      }
    }
  }
}

#endif
