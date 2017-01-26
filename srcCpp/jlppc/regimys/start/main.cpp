#include <iostream>
#include <fstream>
#include <cstdlib>
#include "srcCpp/jlppc/regimys/playercore/Player.hpp"
#include "srcCpp/jlppc/utils/File.hpp"
#include "srcCpp/jlppc/regimys/gui/MainFrame.hpp"

using namespace std;


    Main::main(){
        File errLogF = File("errLog.txt");
        File logF = File("log.txt");
        log = *logF.getOut();
        errLog = *errLogF.getOut();
        if(!log || !errLog){
            exit(2);
        }

        MainFrame.open();

        return quit();
    }

    Main::gererErreur(string errorName, bool fatal){
        errLog << "Erreur : " << errorName << endl;
        if(fatal){
            errLog << "Erreur fatale." << endl;
            log.close();
            errLog.close();
            exit(1);
        }
    }

    Main::quit(){
        log.close();
        errLog.close();
        exit(0);
        return 0;
    }

int main()
{

    return Main::main();
}
