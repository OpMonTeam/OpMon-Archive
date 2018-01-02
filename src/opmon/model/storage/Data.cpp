#include "Data.hpp"

#include "../sysObjects/Map.hpp"
#include "../objects/Species.hpp"

namespace OpMon{
  namespace Model{
    namespace Data{
      namespace OpMons{
	std::map<unsigned int, Species> listOp;
	std::vector<std::map<int, std::string> > atkOpLvl;
      }

      namespace Elements{
	std::map<std::string, sf::Vector2i> elementPos;
	std::map<std::string, int> elementsCounter;
	std::map<std::string, std::vector<sf::Texture> > elementsTextures;
	std::map<std::string, sf::Sprite> elementsSprites;
      }
      
      namespace Ui{
	std::map<std::string, Map> maps;
	std::vector<sf::Music*> townMusics;
	std::vector<std::vector<sf::Texture> > doorsTextures;
	sf::SoundBuffer doorSoundBuffer;
	sf::SoundBuffer shopDoorSoundBuffer;
	sf::Texture tileset;
	std::map<std::string, std::vector<sf::Texture> > charaTextures;
	sf::Texture texturePP[4];
	sf::Texture walkingPP[4];
	sf::Texture walkingPP2[4];
	sf::Font font;
      }
      namespace Animations{
	sf::Texture fen[6];
      }

      namespace Sounds{
	sf::Sound nope;
      }
    }
  }
}
