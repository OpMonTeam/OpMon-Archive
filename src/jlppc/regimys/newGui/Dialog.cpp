
#include "Dialog.hpp"


void dialogPass(const sf::String varname[], bool &changeDialog,
                 sf::String txtEnCours[3], unsigned int &dialog, int sizeOfTxt,
                 unsigned int &line, unsigned int &i, int& phase) {
    if (changeDialog == false) {
        txtEnCours[0] = varname[dialog];
        txtEnCours[1] = varname[dialog + 1];
        txtEnCours[2] = varname[dialog + 2];
        sf::String arr[3] = {txtEnCours[0], txtEnCours[1], txtEnCours[2]};
        Main::mainframe.printText(Main::mainframe.frame, arr);
        changeDialog = true;
        Utils::wait(50);
    } else if (!(dialog + 3 >= (unsigned int) sizeOfTxt)) {
        Main::mainframe.dialogPass.play();
        line = 0;
        dialog+=3;
        i = 0;
        txtEnCours[0] = std::string(" ");
        txtEnCours[1] = std::string(" ");
        txtEnCours[2] = std::string(" ");
        changeDialog = false;
    } else {
        phase++;
    }
}
