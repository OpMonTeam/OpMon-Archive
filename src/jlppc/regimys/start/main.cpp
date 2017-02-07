#include <iostream>
#include <fstream>
#include <cstdlib>
#include "../objects/item/Item.hpp"
#include "../playercore/Player.hpp"
#include "../playercore/Equipe.hpp"
#include "../evolution/evolutionInclude.hxx"
#include "../../utils/Class.hpp"
#include "../../utils/File.hpp"
#include "../objects/item/itemInclude.hxx"
#include <string>

#include "main.hpp"
//#include "srcCpp/jlppc/regimys/gui/MainFrame.hpp"

using namespace std;




namespace Main{
void gererErreur(string errorName, bool fatal){
    errLog << "Erreur : " << errorName << endl;
    if(fatal){
        errLog << "Erreur fatale." << endl;
        Main::log.close();
        errLog.close();
        quit(1);
    }
}

int quit(int returne){
	Main::log.close();
    errLog.close();
    exit(returne);
    return returne;
}
int main(){



       if(!log || !errLog){
           exit(2);
       }

       //MainFrame.open();

       return quit(0);
   }

}
int main(int argc, char *argv[])
{
    Main::oss << "Alpha" << Main::version << "." << (Main::sousVersIs ? Main::sousVers : 0);
    Main::versionS = Main::oss.str();
	initStatic();
    return Main::main();
}

void initStatic(void){
	Equipe::PNULL = Pokemon();
}
