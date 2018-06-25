#pragma once

#include "../../view/Jukebox.hpp"

namespace OpMon {
  namespace Model {

    class UiData {
    private:
      View::Jukebox jukebox;
      sf::Font font;
      UiData(UiData const& data);
    public:
      View::Jukebox& getJukebox() { return jukebox; }
      sf::Font const& getFont() const { return font; }
      UiData();
     
    };
    
  }
}