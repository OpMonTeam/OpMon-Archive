
#include "Map.hpp"
#include "Events.hpp"
#include "../../start/Core.hpp"

namespace OpMon {
  namespace Model {

    Map::Map(const int layer1[], const int layer2[], const int layer3[], int w, int h, const char *const *collision,
             std::string const &bg, std::vector<std::string> const &animatedElements)
            : layer1(layer1), layer2(layer2), layer3(layer3), bg(bg), animatedElements(animatedElements) {


      if (animatedElements.size() != elementsPos.size()) {
        handleError("Error: Map() - elementsPos size is not equal to animatedElements.", true);
      }

      for (unsigned int i = 0; i < animatedElements.size(); i++) {
        elementsCount.push_back(0);
        elementsSprites.push_back(sf::Sprite());
        elementsSprites[i].setTexture(animatedElements[i][0]);
        elementsSprites[i].setPosition(elementsPos[i]);
      }
      this->w = w;
      this->h = h;

      //Définition de la table de la collision
      this->passArr = (char **) malloc(h * sizeof(char *));
      for (int i = 0; i < h; i++) {
        this->passArr[i] = (char *) malloc(w * sizeof(char));
      }
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          passArr[i][j] = collision[i][j];
        }
      }
    }

    Map::~Map() {
      for (int i = 0; i < h; i++) {
        free(passArr[i]);
      }
      free(passArr);
      delete (layer1);
      delete (layer2);
      delete (layer3);
      for (Event *event : events) {
        delete (event);
      }
    }

    std::vector<Event *> &Map::getEvent(sf::Vector2i position) const {
      std::vector<Event *> toReturn;
      for (Event *event : events) {
        if (event->getPosition().x * CASES == position.x && event->getPosition().y * CASES == position.y) {
          toReturn.push_back(event);
        }
      }
      return toReturn;
    }

    void Map::updateEvents(Player &player) {

    }

  }
}
