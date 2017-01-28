#include <iostream>
#include <fstream>
#include <cstdlib>
#include "srcCpp/jlppc/regimys/playercore/Player.hpp"
#include "srcCpp/jlppc/utils/File.hpp"
#include "srcCpp/jlppc/regimys/gui/MainFrame.hpp"

using namespace std;


    int Main::main(){
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

    void Main::gererErreur(string errorName, bool fatal){
        errLog << "Erreur : " << errorName << endl;
        if(fatal){
            errLog << "Erreur fatale." << endl;
            log.close();
            errLog.close();
            quit(1);
        }
    }

    int Main::quit(int returne){
        log.close();
        errLog.close();
        delete(Pokemon::classe);
        delete(Espece::classe);
        delete(File::classe);
        delete(RegimysObject::classe);
        exit(returne);
        return returne;
    }

int main()
{

    return Main::main();
}
