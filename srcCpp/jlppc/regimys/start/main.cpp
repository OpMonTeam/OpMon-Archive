#include <iostream>
#include <fstream>
#include <cstdlib>
#include "srcCpp/jlppc/regimys/playercore/Player.hpp"
#include "srcCpp/jlppc/utils/File.hpp"
#include "srcCpp/jlppc/regimys/gui/MainFrame.hpp"

using namespace std;




    void Main::gererErreur(string errorName, bool fatal){
        errLog << "Erreur : " << errorName << endl;
        if(fatal){
            errLog << "Erreur fatale." << endl;
            Main::log.close();
            errLog.close();
            quit(1);
        }
    }

    int Main::quit(int returne){
    	Main::log.close();
        errLog.close();
        delete(Pokemon::classe);
        delete(Espece::classe);
        delete(File::classe);
        delete(E_Item::classe);
        delete(E_Level::classe);
        delete(Equipe::classe);
        delete(Player::classe);
        exit(returne);
        return returne;
    }
    int Main::main(){

   #ifdef WINDOWS
           File errLogF = File("logs\\errLog.txt");
           File logF = File("logs\\log.txt");
   #else
           File errLogF = File("logs/errLog.txt");
           File logF = File("logs/log.txt");
   #endif

           Main::log = *logF.getOut();
           errLog = *errLogF.getOut();
           if(!log || !errLog){
               exit(2);
           }

           MainFrame.open();

           return quit(0);
       }

int main()
{

    return Main::main();
}
