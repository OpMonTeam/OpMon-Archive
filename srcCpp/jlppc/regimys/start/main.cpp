#include <iostream>
#include <fstream>
#include <cstdlib>
#include "srcCpp/jlppc/regimys/playercore/Player.hpp"
#include "srcCpp/jlppc/utils/File.hpp"
#include "srcCpp/jlppc/regimys/gui/MainFrame.hpp"

using namespace std;

namespace Main{
    bool connected = false;
    string trainers[] = {"Brice", "Evan", "Mael", "Jlppc", "Red", "Blue", "Nikolaϯ", "N", "Belladonis", "Aristote", "Giovanni", "Flora", "Silver", "Jules Cesar", "Gwendal", "Brahim"};
    float version = 0.07;
    int preNbre = 0;
    bool pre = (preNbre != 0);
    int sousVers = 0;
    bool sousVersIs = (sousVers != 0);
    string versionS = "Alpha " + version + (sousVersIs ? "." + sousVers : "") + (pre ? (" pre " + preNbre) : "") + commits;
    Player joueur;
    File playerSave;
    File params;
    ofstream log;
    ofstream errLog;

    int main(){
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

    void gererErreur(string errorName, bool fatal){
        errLog << "Erreur : " << errorName << endl;
        if(fatal){
            errLog << "Erreur fatale." << endl;
            log.close();
            errLog.close();
            exit(1);
        }
    }

    int quit(){
        log.close();
        errLog.close();
        exit(0);
        return 0;
    }
}

int main()
{

    return Main::main();
}
