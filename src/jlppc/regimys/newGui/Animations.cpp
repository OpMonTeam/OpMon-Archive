#include "Animations.hpp"
#include "MainFrame.hpp"
UNS

namespace Animations {

    bool init = false;
    sf::Event events;
    int ancientTick = 0;
    bool continuer = false;
    bool joypressed = false;
    sf::Texture fen[6];

    void initAnims() {
        for(int i = 0; i < 6; i++) {
                ostringstream oss;
#ifdef _WIN32
                oss << "ressources\\animations\\winChange\\animWindowFrame" << i + 1 << ".png";
#else
                oss << RESSOURCES_PATH + "animations/winChange/animWindowFrame" << i + 1 << ".png";
#endif // _WIN32
                fen[i].loadFromFile(oss.str());
            }
        init = true;
    }

    void deleteAnims() {
        init = false;
    }

    int animFenOpen(sf::RenderTexture &window, sf::Sprite const &bg) {
        ANIM_CHECK_INIT//Verification of animation initialization
        //Variables declaration
        sf::Sprite anim[6];
        int ancientChrono = 0;

        //Frame by frame
        for (int i = 0; i < 6; i++) {
                if ((ticks.getElapsedTime().asMilliseconds() - ancientChrono) >= 33) {
                        MainFrame::window.pollEvent(events);
                        ancientChrono = ticks.getElapsedTime().asMilliseconds();
                        switch (events.type) {
                                    QUIT
			default:
			  break;
                            }

                        ECHAP
                        anim[i].setTexture(fen[i]);
                        window.clear(sf::Color::White);
                        window.draw(bg);
                        window.draw(anim[i]);

                        window.display();
                        MainFrame::winRefresh();
                    }
                else {
                        Utils::wait(200 - (ticks.getElapsedTime().asMilliseconds() - ancientTick));
                        i--;
                    }
            }
        return 0;
    }

    int animFenClose(sf::RenderTexture &window, sf::Sprite const &bg) {
        //Se réferer aux commentaires de la fonction précédente
        ANIM_CHECK_INIT
        //Variables declaration
        sf::Sprite anim[6];
        int ancientChrono = 0;
        for (int i = 5; i >= 0; i--) {
                if ((ticks.getElapsedTime().asMilliseconds() - ancientChrono) >= 33) {
                        MainFrame::window.pollEvent(events);
                        ancientChrono = ticks.getElapsedTime().asMilliseconds();
                        switch (events.type) {
                                    QUIT
			default:
			  break;
                            }

                        ECHAP

                        anim[i].setTexture(fen[i]);

                        window.clear(sf::Color::White);

                        window.draw(bg);
                        window.draw(anim[i]);

                        window.display();
                        MainFrame::winRefresh();
                    }
                else {
                        Utils::wait(200 - (ticks.getElapsedTime().asMilliseconds() - ancientTick));
                        i++;
                    }
            }
        return 0;
    }


}
