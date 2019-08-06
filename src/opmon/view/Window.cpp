/*
Window.cpp
Author : Cyrielle
Contributors : BAKFR, torq
File under GNU GPL v3.0 license
*/
#include "Window.hpp"
#include "../../utils/StringKeys.hpp"
#include "../../utils/log.hpp"
#include "../model/save/OptionsSave.hpp"
#include "../model/storage/ResourceLoader.hpp"
#include "../start/Core.hpp"

#include <SFML/Graphics.hpp>

using Utils::Log::oplog;

namespace OpMon {
    namespace View {
        void Window::open() {
            sf::ContextSettings settings;
            if(!Model::OptionsSave::checkParam("fullscreen")) {
                Model::OptionsSave::addOrModifParam("fullscreen", "false");
            }
	    //settings.antialiasingLevel = 1;
            if(Model::OptionsSave::getParam("fullscreen").getValue() == "true") {
                fullScreen = true;
                window.create(sf::VideoMode::getFullscreenModes().at(0), "OpMon Lazuli", sf::Style::Fullscreen, settings);
            } else {
                window.create(sf::VideoMode(512, 512), "OpMon Lazuli", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize, settings);
            }

            sf::Image icon;
            Model::ResourceLoader::load(icon, "opmon.png");
            window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

            frame.create(512, 512);

            oplog("Window initialized!");
            //window.setVerticalSyncEnabled(true);
            window.setFramerateLimit(30);
            window.setKeyRepeatEnabled(false);
        }

        void Window::close() {
            oplog("Closing the window...");
            window.close();
            oplog("Window closed. No error detected. Goodbye.");
        }

	void Window::reboot(){
	    close();
	    open();
	}
	

        void Window::refresh() {
            frame.display();
	    sf::Texture frameTexture = frame.getTexture();
	    frameTexture.setSmooth(true);
            sf::Sprite sprite(frameTexture);
	    
            if(fullScreen) {
                const float coef = window.getSize().y / (sprite.getGlobalBounds().height);
                sprite.setScale(coef, coef);
                sprite.setPosition(((window.getSize().x / 2) - (sprite.getGlobalBounds().width / 2)), 0);
            }

            window.clear(sf::Color::Black);
            window.draw(sprite);
            window.display();
        }

    } // namespace View
} // namespace OpMon
