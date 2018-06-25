#pragma once

namespace OpMon {
  namespace Model {

    class StartSceneData {
    private:

      sf::Texture background;
      sf::Texture prof;
      sf::Texture nameBg;
      
      UiData* uidata;


      StartSceneData(StartSceneData const&);
    public:

      UiData* getUiDataPtr() { return uidata; }
      sf::Texture& getBackground() { return background; }
      sf::Texture& getProf() { return prof; }
      sf::Texture& getNameBg() { return nameBg; }
      
      StartSceneData(UiData* data);
    };
    
  }
}
