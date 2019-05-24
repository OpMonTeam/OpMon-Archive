/*
Window.cpp
Author : Cyriel
Contributors : BAKFR, torq, PyroFlareX
File under GNU GPL v3.0 license
*/
#include "Window.hpp"
#include "../../utils/StringKeys.hpp"
#include "../../utils/log.hpp"
#include "../model/save/OptionsSave.hpp"
#include "../model/storage/ResourceLoader.hpp"
#include "../start/Core.hpp"
#include "../start/GameStatus.hpp"

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
                window.create(sf::VideoMode(512, 512), "OpMon Lazuli", sf::Style::Default, settings);
            }

            sf::Image icon;
            Model::ResourceLoader::load(icon, "opmon.png");
            window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

            frame->create(window.getSize().x, window.getSize().y);

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
            frame->display();
	        sf::Texture frameTexture = frame->getTexture();
	        frameTexture.setSmooth(true);
            frameTexture.setRepeated(true);
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
        void Window::handleEvent(sf::Event* event){

            // catch the resize events
            if (event->type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0.f, 0.f, event->size.width, event->size.height);

                sf::View view(visibleArea);

                delete frame;
                frame = new sf::RenderTexture();
                frame->create(window.getSize().x, window.getSize().y);
                //frame->setView(view);

                window.setView(view);
            }
        
        }

    } // namespace View
} // namespace OpMon
