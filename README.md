![Regimys LOGO](https://raw.githubusercontent.com/OpMonTeam/OpMon/master/Resources/Other/opmon_title.png)<br>

[Voir En Français](#enfrancais)

# Welcome to Project OPMon Lazuli!

OPMon is a Pokémon-inspired game project imagined in 2012 and started in september 2016. This game is totally open source, allowing the fans to come realize their dreams! You can add OpMons, attacks, items, and many other things! You just have to submit your modifications and maybe we will add them to the game! And if you submit a lot of good changes, you can become a collaborator!<br/><br/>

### Links
* [Opmon Lazuli's website](http://opmon-game.ga)
* [Development news](https://translate.google.com/translate?act=url&depth=1&hl=fr&ie=UTF8&prev=_t&rurl=translate.google.fr&sl=fr&sp=nmt4&tl=en&u=https://github.com/OpMonTeam/OpMon/wiki/Journal-du-d%25C3%25A9veloppement)
* [Monthly Reports](https://github.com/OpMonTeam/OpMon/wiki/Monthly-reports)
* [Credits](https://github.com/OpMonTeam/OpMon/blob/master/Credits.md)
* [Github repo for the game website, opmon-game.ga](https://github.com/OpMonTeam/OpMon-Website)
* [Documentation](http://opmon-game.ga/pages/doc)

### Build

Master (Last stable build) : ![Build](https://api.travis-ci.org/OpMonTeam/OpMon.svg?branch=master)  
Develop (Development branch) : ![Build](https://api.travis-ci.org/OpMonTeam/OpMon.svg?branch=develop)

The build system use *cmake*.
Command for GNU/Linux systems :

```sh
cmake .             #If you want to build in Debug, use -DCMAKE_BUILD_TYPE=Debug
make
sudo make install   # install the game into your system
make package        # generate both .deb package and .tar.gz package
```
You can see the dependancies for GNU/Linux systems [here](https://github.com/OpMonTeam/OpMon/wiki/Dependencies).
If you want to play to the game quickly, use build-and-run.sh. The game will be built in bin/Release, and the data will be pasted in this repertory. The game will launch after building.<br/>
If you don't use build-and-run.sh, don't forget to copy the data folder in the game's folder or use `sudo make install` if you are on linux.
If you want to compile OPMon from A to Z for Windows, Mac OS or other, it's [here](https://github.com/OpMonTeam/OpMon/wiki/Compilation)
### Contact Us
* jlppcprog@ntymail.com for bugs, lags or about the code
* evandib@gmail.com for sprites, the graphics, design or graphics bugs
* [Discord server](https://discord.gg/mvS67qu)
* IRC channel on Freenode : #OpMon
<br>
English is not our native language, but we do our best! If you see some errors, don't hesitate to tell us, so we won't make them again!

If there are problems understanding the old commits or monthly reports that are in French, don't hesitate to ask!

__The current game version is Alpha 0.15.1__ Download link: <a 
href="http://opmon-game.ga/downloads"><img src="https://img.shields.io/badge/download-v0.15.1-red.svg" alt="Download Link"></a>

__The next game version will be Alpha 0.16__: Fight system update and OpMons improvements
* [Look the ROADMAP](https://github.com/OpMonTeam/OpMon/wiki/ROADMAP)
* [Look the Releases changelog](https://github.com/OpMonTeam/OpMon/wiki/Releases)

### Controls

See the controls of the game OpMon [here](http://opmon-game.ga/controls.html)
# En Français<a name="enfrancais">

# Bienvenue sur le Projet "OPMon Lazuli"!

## Bienvenue sur le dépot du jeu OPMon Lazuli! Le clone libre de la célèbre license de Nintendo !

<br/>

* [Journal de développement](https://github.com/OpMonTeam/OpMon/wiki/Journal-du-développement)
* [Bilans mensuels, récapitulatifs des nouveautés (en anglais)](https://github.com/OpMonTeam/OpMon/wiki/Monthly-reports)
* [Site web du jeu](http://opmon-game.ga)
* [Dépot du site web](https://github.com/OpMonTeam/OpMon-Website)
* [Crédits](https://github.com/OpMonTeam/OpMon/blob/master/Credits.md)

<br/>Version du jeu : Alpha 0.15.1 | Téléchargement : <a 
href="http://opmon-game.ga"><img src="https://img.shields.io/badge/download-v0.15.1-red.svg" alt="Logo Téléchargement"></a><br/><br/>

### Prochaines versions :
* Alpha 0.16 : Amelioration du système de combat et ameliorations des OpMons et de leurs stats
* [Voir la RoadMap](https://github.com/OpMonTeam/OpMon/wiki/ROADMAP)

<br/>

## Informations generales:
<br/>
OpMon vient d'un jeu imaginé en 2012 et débuté en septembre 2016, c'est un clone de la célèbre licence Pokémon, appartenant à Nintendo. 
Ce jeu est totalement open-source, ce qui permet aux gens de venir réaliser leurs rêves les plus fous! 
Vous pouvez ajouter des OpMons, des attaques, des items, et autres! 
Vous n'avez qu'à nous proposer vos modifications et nous les ajouterons peut-être au jeu. 
Si vous nous proposez beaucoup de bonnes modifications, et qu'elles sont acceptées, vous deviendrez peut-être collaborateur!<br/>
Nous sommes plusieurs sur le projet : Cyriel, le programmeur et créateur de l'histoire et des personnages ; Navet56, le graphiste et correcteur ; et d'autres contributeurs, comme Imperator Dei, qui a corrigé les fautes d'orthographe sur la version française,  merci à eux !<br/>
Contacts : jlppcprog@ntymail.com pour la programmation | evandib@gmail.com pour les graphismes<br/>
Si vous avez des questions à poser, n'hésitez pas à les demander dans la section F.A.Q. du wiki ou à nous contacter par mail!<br/>

### Les contrôles

Vous pouvez voir les contrôles du jeu OpMon [ici](http://opmon-game.ga/controls.html)

### Build

Le système de build utilise *cmake*. Voici les commandes pour compiler le jeu et l'installer (sous GNU/Linux).

```sh
cmake .
make
sudo make install   # installe le jeu sur votre système
make package        # génère deux paquets: un fichier générique .tar.gz et un paquet .deb
```

Vous pouvez aussi utiliser le build-and-run.sh pour compiler et jouer au jeu rapidement. Le jeu se trouvera alors dans le dossier bin/Release, avec le dossier data copié dedans. Il se lancera dès la fin de la compilation.<br/>
Si vous n'utilisez pas le `build-and-run.sh`, n'oubliez pas de copier le dossier data dans le dossier du jeu, ou de faire `sudo make install` si vous êtes sous linux !
Si vous voulez compiler de A à Z OpMon pour Windows, Mac OS ou autres, c'est [ici](https://github.com/OpMonTeam/OpMon/wiki/Compilation)(en anglais)
## Changelog des versions
[Voir le changelog de toutes les versions du jeu](http://github.com/OpMonTeam/OpMon/wiki/Releases)
<br/>

## Screenshot : 

![Screenshot](https://raw.githubusercontent.com/OpMonTeam/OpMon/master/Resources/Other/screenshot_2.png)


