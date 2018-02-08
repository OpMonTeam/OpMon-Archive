#include "OptionsMenu.hpp"
#include "../model/save/OptionsSave.hpp"
#include "../model/storage/Data.hpp"
#include "../model/storage/ResourceLoader.hpp"
#include "Window.hpp"

UNS

  namespace OpMon {
	namespace View {

		void OptionsMenu::initStrings() {
			auto kget = Utils::StringKeys::get;

			langFr.setString(L"Français");
			langFr.setFont(Model::Data::Ui::font);
			langFr.setCharacterSize(FONT_SIZE_DEFAULT);
			langEng.setString("English");
			langEng.setFont(Model::Data::Ui::font);
			langEng.setCharacterSize(FONT_SIZE_DEFAULT);
			langEsp.setString(L"Espa\u00F1ol");
			langEsp.setFont(Model::Data::Ui::font);
			langEsp.setCharacterSize(FONT_SIZE_DEFAULT);
			txtRetour.setString(kget("options.retour"));
			txtRetour.setFont(Model::Data::Ui::font);
			txtRetour.setCharacterSize(FONT_SIZE_DEFAULT);
			txtOptions.setString(kget("options.title"));
			txtOptions.setFont(Model::Data::Ui::font);
			txtOptions.setCharacterSize(FONT_SIZE_DEFAULT);
			txtOpt1.setString(kget("options.ecran"));
			txtOpt1.setFont(Model::Data::Ui::font);
			txtOpt1.setCharacterSize(FONT_SIZE_DEFAULT);
			txtOpt2.setString(kget("options.lang"));
			txtOpt2.setFont(Model::Data::Ui::font);
			txtOpt2.setCharacterSize(FONT_SIZE_DEFAULT);
			txtOpt3.setString(kget("options.vol"));
			txtOpt3.setFont(Model::Data::Ui::font);
			txtOpt3.setCharacterSize(FONT_SIZE_DEFAULT);
			txtOpt3.setColor(sf::Color::Red);
			txtOpt4.setString(kget("options.control"));
			txtOpt4.setFont(Model::Data::Ui::font);
			txtOpt4.setCharacterSize(FONT_SIZE_DEFAULT);
			txtOpt4.setColor(sf::Color::White);
			txtOpt5.setString(kget("options.credit"));
			txtOpt5.setFont(Model::Data::Ui::font);
			txtOpt5.setCharacterSize(FONT_SIZE_DEFAULT);
			txtOpt5.setColor(sf::Color::White);

			txtLang.setString(kget("options.lang.title"));
			txtLang.setFont(Model::Data::Ui::font);
			txtLang.setCharacterSize(FONT_SIZE_DEFAULT);

			txtCred.setString(kget("options.cred.title"));
			txtCred.setFont(Model::Data::Ui::font);
			txtCred.setCharacterSize(FONT_SIZE_DEFAULT);

			txtCre1.setString(kget("options.credit.1"));
			txtCre1.setFont(Model::Data::Ui::font);
			txtCre1.setCharacterSize(14);
			txtCre1.setColor(sf::Color::Black);
			txtCre2.setString(kget("options.credit.2"));
			txtCre2.setFont(Model::Data::Ui::font);
			txtCre2.setCharacterSize(14);
			txtCre2.setColor(sf::Color::Black);
			txtCre3.setString(kget("options.credit.3"));
			txtCre3.setFont(Model::Data::Ui::font);
			txtCre3.setCharacterSize(14);
			txtCre3.setColor(sf::Color::Black);
			txtCre4.setString(kget("options.credit.4"));
			txtCre4.setFont(Model::Data::Ui::font);
			txtCre4.setCharacterSize(14);
			txtCre4.setColor(sf::Color::Black);
			txtCre5.setString(kget("options.credit.5"));
			txtCre5.setFont(Model::Data::Ui::font);
			txtCre5.setCharacterSize(14);
			txtCre5.setColor(sf::Color::Black);
			txtCre6.setString(kget("options.credit.6"));
			txtCre6.setFont(Model::Data::Ui::font);
			txtCre6.setCharacterSize(22);
			txtCre6.setColor(sf::Color::Black);
			txtCre7.setString(kget("options.credit.7"));
			txtCre7.setFont(Model::Data::Ui::font);
			txtCre7.setCharacterSize(18);
			txtCre7.setColor(sf::Color::Black);
			txtCre8.setString(kget("options.credit.8"));
			txtCre8.setFont(Model::Data::Ui::font);
			txtCre8.setCharacterSize(15);
			txtCre81.setString(kget("options.credit.81"));
			txtCre81.setFont(Model::Data::Ui::font);
			txtCre81.setCharacterSize(15);
			txtCre9.setString(kget("options.credit.9"));
			txtCre9.setFont(Model::Data::Ui::font);
			txtCre9.setCharacterSize(13);
		}

		void OptionsMenu::onLangChanged() {
			initStrings();
		}

		OptionsMenu::OptionsMenu()
		  : currentOptions(OptionType::ALL) {

			Model::ResourceLoader::load(textures2[0], "backgrounds/options.png");
			Model::ResourceLoader::load(textures2[1], "sprites/misc/selectBar.png");
			Model::ResourceLoader::load(textures2[2], "backgrounds/lang.png");
			Model::ResourceLoader::load(textures2[3], "sprites/misc/yes.png");
			Model::ResourceLoader::load(textures2[4], "backgrounds/credits.png");

			bgOpt.setTexture(textures2[0]);
			rectSurb.setTexture(textures2[1]);
			bgLangues.setTexture(textures2[2]);
			coche.setTexture(textures2[3]);
			bgCredits.setTexture(textures2[4]);

			coche.setPosition(425, 88);

			initStrings();

			txtOpt1.setPosition(120, 100);
			txtOpt2.setPosition(120, 170);
			txtOpt3.setPosition(120, 240);
			txtOpt4.setPosition(120, 310);
			txtOpt5.setPosition(120, 380);

			langEsp.setPosition(45, 170);
			langEng.setPosition(45, 100);
			langFr.setPosition(45, 240);

			txtRetour.setPosition(55, 25);

			txtLang.setPosition(250, 25);
			txtOptions.setPosition(230, 25);
			txtCred.setPosition(250, 25);

			txtCre1.setPosition(200, 128);
			txtCre2.setPosition(200, 148);
			txtCre3.setPosition(200, 168);
			txtCre4.setPosition(400, 128);
			txtCre5.setPosition(400, 148);
			txtCre6.setPosition(30, 270);
			txtCre7.setPosition(201, 274);
			txtCre8.setPosition(30, 368);
			txtCre81.setPosition(30, 385);
			txtCre9.setPosition(385, 488);

			jukebox.play("Title");

			curPosOpt[0].x = 23;
			curPosOpt[0].y = 17;
			curSizeOpt[0].x = 134 / rectSurb.getGlobalBounds().width;
			curSizeOpt[0].y = 49 / rectSurb.getGlobalBounds().height;

			curPosLang[0].x = 23;
			curPosLang[0].y = 17;
			curSizeLang[0].x = 134 / rectSurb.getGlobalBounds().width;
			curSizeLang[0].y = 49 / rectSurb.getGlobalBounds().height;

			for(int i = 1, j = 86; i < 6; i++) {
				curPosOpt[i].x = 23;
				curPosOpt[i].y = j;
				curSizeOpt[i].x = 464 / rectSurb.getGlobalBounds().width;
				curSizeOpt[i].y = 57 / rectSurb.getGlobalBounds().height;
				j += 69;
			}

			for(int i = 1, j = 86; i < 4; i++) {
				curPosLang[i].x = 23;
				curPosLang[i].y = j;
				curSizeLang[i].x = 464 / rectSurb.getGlobalBounds().width;
				curSizeLang[i].y = 57 / rectSurb.getGlobalBounds().height;
				j += 69;
			}
		}

		void OptionsMenu::draw(sf::RenderTarget &frame) {
			switch(currentOptions) {
			case OptionType::ALL:
				return loop(frame);
			case OptionType::LANG:
				return langLoop(frame);
			case OptionType::CREDITS:
				return creditsLoop(frame);
			}
		}

		void OptionsMenu::moveArrow(bool move) {
			Model::Data::Sounds::arrow.play();
			switch(currentOptions) {
			case OptionType::ALL:
				if(move) {
					curPosOptI--;
				} else {
					curPosOptI++;
				}
				if(curPosOptI >= 6) {
					curPosOptI = 0;
				} else if(curPosOptI < 0) {
					curPosOptI = 5;
				}
				break;
			case OptionType::LANG:
				if(move) {
					curPosLangI--;
				} else {
					curPosLangI++;
				}
				if(curPosLangI >= 4) {
					curPosLangI = 0;
				} else if(curPosLangI < 0) {
					curPosLangI = 3;
				}
			default:
				break;
			}
		}

		void OptionsMenu::loop(sf::RenderTarget &frame) {
			frame.clear(sf::Color::White);

			frame.draw(bgOpt);
			frame.draw(txtOpt1);
			frame.draw(txtOpt2);
			frame.draw(txtOpt3);
			frame.draw(txtOpt4);
			frame.draw(txtOpt5);
			frame.draw(txtRetour);
			frame.draw(txtOptions);
			if(Model::OptionsSave::getParam("fullscreen").getValue() == "true") {
				frame.draw(coche);
			}
			rectSurb.setPosition(curPosOpt[curPosOptI]);
			rectSurb.setScale(curSizeOpt[curPosOptI]);
			frame.draw(rectSurb);
		}

		void OptionsMenu::langLoop(sf::RenderTarget &frame) {
			frame.clear(sf::Color::White);

			frame.draw(bgLangues);
			frame.draw(langEng);
			frame.draw(langEsp);
			frame.draw(langFr);
			frame.draw(txtRetour);
			frame.draw(txtLang);
			rectSurb.setPosition(curPosOpt[curPosLangI]);
			rectSurb.setScale(curSizeLang[curPosLangI]);
			frame.draw(rectSurb);
		}

		void OptionsMenu::pause() {
		}

		void OptionsMenu::play() {
			jukebox.play("Title");
		}

		OptionsMenu::~OptionsMenu() {
		}

		void OptionsMenu::creditsLoop(sf::RenderTarget &frame) {
			frame.clear(sf::Color::White);

			frame.draw(bgCredits);
			frame.draw(txtCre1);
			frame.draw(txtCre2);
			frame.draw(txtCre3);
			frame.draw(txtCre4);
			frame.draw(txtCre5);
			frame.draw(txtCre6);
			frame.draw(txtCre7);
			frame.draw(txtCre8);
			frame.draw(txtCre81);
			frame.draw(txtCre9);

			frame.draw(txtRetour);
			frame.draw(txtCred);
		}

	} // namespace View
}
