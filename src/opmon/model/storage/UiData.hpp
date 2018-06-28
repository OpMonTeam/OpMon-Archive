#pragma once

#include "../../view/Jukebox.hpp"

namespace OpMon {
  namespace Model {

    class UiData {
    private:

      std::vector<std::vector<sf::Texture> > opSprites;
      std::map<unsigned int, Species *> listOp;
      std::vector<std::map<int, std::string>> atkOpLvl;
      std::map<Type, sf::Texture> typesTextures;

      sf::Texture dialogArrow;
      sf::Texture dialogBackground;
      
      View::Jukebox jukebox;
      sf::Font font;
      UiData(UiData const& data);
    public:
      View::Jukebox& getJukebox() { return jukebox; }
      sf::Font const& getFont() const { return font; }
      UiData();

      sf::Texture& getOpSprite(unsigned int id, bool face) { return opSprites[id][(unsigned int)face]; }
      Species* getOp(unsigned int id) { return listOp.at(id); }
      sf::Texture& getTypeTexture(Type type) { return typesTextures[type]; }
      
      sf::Texture& getDialogArrow() { return dialogArrow; }
      sf::Texture& getDialogBackground() { return dialogBackground; }
      
    };
    
  }
}
