#pragma once

#include "../../view/Jukebox.hpp"

namespace OpMon {
  namespace Model {

    class UiData {
    private:
      View::Jukebox jukebox;
    public:
      View::Jukebox& getJukebox() { return jukebox; }
      UiData();
    };
    
  }
}
