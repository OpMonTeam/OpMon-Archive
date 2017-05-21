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

#include "StartScene.hpp"



UNS

namespace MainFrame {
    sf::RenderWindow frame;
    sf::Sprite fond;
    sf::Event events;
    sf::Font font;
    sf::Sprite dialog;
    sf::Text dialogText[3];
    bool init = false;
    sf::Sprite ppSprite;
    sf::Sprite ppAnim;
    sf::Sound dialogPass;


int printChoice(string text, string choice1, string choice2, string choix3) {
    //Non fini
    /*bool triple = true;
    if(choix3 == ""){
        triple = false;
    }
    if(text == "" || choice1 == "" || choice2 == ""){
        gererErreur("MainFrame::printChoice : Chaine de caractère vide.", true);
    }
    SDL_Rect placeChoix[3];
    SDL_Texture *choix[3];
    SDL_Texture *texte;
    SDL_Texture *fondDialogue;
    texte = renderText(renderer, text, font, noir, textPlace);*/
    return 0;
}

void printText(sf::RenderWindow &framee, sf::String text[]) {
    int minusPos = 32;
    FOR_EACH(sf::String, text, 3, {)
        dialogText[itor].setString(text[itor]);
        dialogText[itor].setFont(font);
        dialogText[itor].setCharacterSize(FONT_SIZE_DEFAULT);
        dialogText[itor].setColor(sf::Color::Black);
        dialogText[itor].setPosition(25, dialog.getPosition().y + minusPos);
        minusPos+=32;

        framee.draw(dialogText[itor]);
    }

}

void initAll(){
    MainMenu::initVars();
    StartScene::initVars();
    Overworld::initVars();
}

void destroyAll(){
    MainMenu::deleteVars();
    StartScene::destroyVars();
    Overworld::deleteVars();
}

void open() {
#ifdef _WIN32
        if(!font.loadFromFile("ressources\\fonts\\Default.ttf"))
#else
        if(!font.loadFromFile("ressources/fonts/Default.ttf"))
#endif // _WIN32
    {
        gererErreur("Erreur d'initialisation de la police d'écriture.", true);
    }
    rlog << PRINT_TICKS << "Initialisation de la police terminée" << endl;

    init = true;
    //Ouverture de la fenetre
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

    frame.create(sf::VideoMode(512, 512), "OpMon Lazuli", sf::Style::Titlebar | sf::Style::Close, settings);
    //Création du renderer.
    rlog << PRINT_TICKS << "Initialisation de la fenetre et du renderer terminée" << endl;
    //Ouverture d'un son
    sf::SoundBuffer buf;
    frame.setFramerateLimit(60);
#ifdef _WIN32
    if(!buf.loadFromFile("ressources\\audio\\sounds\\dialogChange.ogg"))
#else
    if(!buf.loadFromFile("ressources/audio/sounds/dialogChange.ogg"))
#endif
    {
        gererErreur("Impossible d'ouvrir le son de changement de dialogue.", false);
    }
    dialogPass.setBuffer(buf);
    rlog << PRINT_TICKS << "Chargement des sprites globaux (Initializer)" << endl;
    Initializer::initSprites();
    rlog << PRINT_TICKS << "Chargement des variables de chaque partie" << endl;
    initAll();
    frame.clear(sf::Color::White);
    #define TEST
    #ifdef TEST
    ifstream strm("ressources/keys/francais.rkeys");
    string read;
    getline(strm, read);
    getline(strm, read);
    getline(strm, read);
    getline(strm, read);
    getline(strm, read);
    getline(strm, read);
    getline(strm, read);
    getline(strm, read);
    getline(strm, read);
    getline(strm, read);
    getline(strm, read);
    sf::String sfstr = sf::String::fromUtf8(read.begin(), read.end());
    sf::Text txt;
    txt.setString(sfstr);
    txt.setColor(sf::Color::Blue);
    frame.clear(sf::Color::White);
    cout << read << endl;
    frame.draw(txt);
    frame.display();
    Utils::wait(1000 * 5);
    #endif
    frame.clear(sf::Color::White);
    frame.display();

    dialogPass.setVolume(50);
    frame.clear(sf::Color::Black);
    rlog << PRINT_TICKS << "Lancement du menu." << endl;
    //Lancement du jeu
    if(MainMenu::mainMenu() != -1) {
        MainMenu::bruitPush.play();
        if(StartScene::startScene() != -1) {
            if(Overworld::overworld() != -1){
                if(Overworld::overworld() == 2){
                    Main::reboot = true;

                }
            }
        }
    } else {
        MainMenu::bruitPush.play();
    }

    rlog << PRINT_TICKS << "Suppression des variables de chaque partie" << endl;
    destroyAll();
    rlog << PRINT_TICKS << "Fermeture de la fenetre" << endl;
    frame.close();
    init = false;
}


/*
SDL_Texture *renderText(SDL_Renderer *renderer, char text[], TTF_Font *police, SDL_Color color, SDL_Rect *pos) {
    SDL_Surface *sfce = TTF_RenderText_Blended(police, text, color);
    if (sfce == NULL) {
        rerrLog << "MainFrame::renderText() : ";
        gererErreur(TTF_GetError(), true);
    }
    pos->h = sfce->h;
    pos->w = sfce->w;
    SDL_Texture *toReturn = SDL_CreateTextureFromSurface(renderer, sfce);
    SDL_FreeSurface(sfce);
    return toReturn;
}

SDL_Texture *renderText(SDL_Renderer *renderer, string text, TTF_Font *police, SDL_Color color, SDL_Rect *pos) {
    ;
    return renderText(renderer, text, police, color, pos, Encoding::LATIN);
}

J_Texture renderText(SDL_Renderer *renderer, std::string text, TTF_Font *police, SDL_Color color) {
    J_Texture toReturn;
    toReturn.texture = renderText(renderer, text, police, color, &(toReturn.rect));
    return toReturn;
}

SDL_Texture *renderText(SDL_Renderer *renderer, std::string text, TTF_Font *police, SDL_Color color, SDL_Rect *pos, int encodage) {
    if(text == "") {
        gererErreur("Texte vide dans renderText encodage.", false);
        text+=" ";
    }
    SDL_Surface *sfce = NULL;
    Uint16 *tab;
    switch(encodage) {
    case Encoding::LATIN:
        sfce = TTF_RenderText_Blended(police, text.c_str(), color);
        break;
    case Encoding::UNICODE:
        tab = (Uint16*)malloc(sizeof(Uint16) * text.size());
        for(unsigned int i = 0; i < text.size(); i++) {
            tab[i] = text[i];
        }
        sfce = TTF_RenderUNICODE_Blended(police, tab, color);
        free(tab);
        break;
    case Encoding::UTF8:
        sfce = TTF_RenderUTF8_Blended(police, text.c_str(), color);
        break;
    default:
        sfce = TTF_RenderText_Blended(police, text.c_str(), color);
        break;
    }

    if (sfce == NULL) {
        rerrLog << "MainFrame::renderText() : ";
        gererErreur(TTF_GetError(), true);
    }
    pos->h = sfce->h;
    pos->w = sfce->w;
    SDL_Texture *toReturn = SDL_CreateTextureFromSurface(renderer, sfce);
    SDL_FreeSurface(sfce);
    return toReturn;
}

J_Texture renderText(SDL_Renderer *renderer, std::string text, TTF_Font *police, SDL_Color color, int encodage) {
    J_Texture toReturn;
    toReturn.texture = renderText(renderer, text, police, color, &(toReturn.rect), encodage);
    return toReturn;
}*/


}
