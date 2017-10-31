#include "Data.hpp"

namespace OpMon{
  namespace Model{
    namespace Data{
      namespace OpMons{
	std::map<unsigned int, Species> listOp;
	std::vector<std::map<int, std::string> > atkOpLvl;
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
      }
      Player player;
    }
  }
}
