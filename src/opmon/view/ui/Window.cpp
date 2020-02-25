/*
Window.cpp
Author : Cyrielle
Contributors : BAKFR, torq
File under GNU GPL v3.0 license
*/
#include "Window.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <algorithm> // for std::min and std::max
#include <string>
#include <vector>

#include "../../../utils/centerOrigin.hpp"
#include "../../../utils/log.hpp"
#include "../../core/system/OptionsSave.hpp"
#include "../../core/system/ResourceLoader.hpp"

using Utils::Log::oplog;

namespace OpMon {
    namespace Ui {
        void Window::open() {
            sf::ContextSettings settings;
            if(!System::OptionsSave::checkParam("fullscreen")) {
                System::OptionsSave::addOrModifParam("fullscreen", "false");
            }
            //settings.antialiasingLevel = 1;
            if(System::OptionsSave::getParam("fullscreen").getValue() == "true") {
                fullScreen = true;
                window.create(sf::VideoMode::getFullscreenModes().at(0), "OpMon Lazuli", sf::Style::Fullscreen, settings);
            } else {
                window.create(sf::VideoMode(960, 540), "OpMon Lazuli", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize, settings);
            }

            sf::Image icon;
            System::ResourceLoader::load(icon, "opmon.png");
            window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

            frame.create(960, 540);
            sprite.setTexture(frame.getTexture());
            updateView();

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

        void Window::reboot() {
            close();
            open();
        }

        void Window::refresh() {
            frame.display();
            window.clear(sf::Color::Black);
            window.draw(sprite);
            window.display();
        }

        void Window::updateView() {
            // unsigned int to float conversion of sizes (needed for division)
            sf::Vector2f frameSize(frame.getSize());
            sf::Vector2f windowSize(window.getSize());
            auto frameRatio = frameSize.x / frameSize.y;

            // Computing the scaling factors : the sprite shouldn't be bigger than the screen,
            // and any dimension shouldn't be bigger than the value computed from the ratio and the other dimension :
            // we take the min of the two. We then divide by the original frame size to get the scaling factor.
            auto xCoef = std::min(windowSize.y * frameRatio, windowSize.x) / frameSize.x;
            auto yCoef = std::min(windowSize.x / frameRatio, windowSize.y) / frameSize.y;
            sprite.setScale(xCoef, yCoef);

            // update the sprite position
            Utils::Origin::centerOrigin(sprite);
            sprite.setPosition(windowSize.x / 2.f, windowSize.y / 2.f);

            // prevent auto-stretching
            window.setView(sf::View({0.f, 0.f, windowSize.x, windowSize.y}));
        }

        int Window::getBaseWindowWidth() {
            return 960;
        }

        int Window::getBaseWindowHeight() {
            return 540;
        }

    } // namespace UI
} // namespace OpMon
