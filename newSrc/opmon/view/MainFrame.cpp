#include "MainFrame.hpp"
#include <iostream>
#include "../start/main.hpp"
#include <SFML/Graphics.hpp>
#include <cstring>
#include "../start/StringKeys.hpp"
#include "../start/main.hpp"
#include <string>
#include <SFML/Audio.hpp>
#include "MainMenu.hpp"
#include "../start/Initializer.hpp"
#include "Overworld.hpp"
#include "OptionsMenu.hpp"
#include "../save/OptionsSave.hpp"
#include "../objects/Attacks.hpp"

#include "StartScene.hpp"
#include "Events.hpp"

bool keyPressed = false;

UNS

MainFrame::MainFrame(){}

void MainFrame::initAllStrings() {
    optionsmenu.initStrings();
    mainmenu.initStrings();
    startscene.initStrings();
}
