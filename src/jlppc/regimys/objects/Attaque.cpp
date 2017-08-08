#include "Attaque.hpp"
#include "OpMon.hpp"
#include <sstream>

Class <Attaque> *Attaque::classe = new Class<Attaque>("Attaque", 0x00000000);

Attaque::Attaque(std::string nom, int puissance, int type, int precision, bool special, bool status, int chanceDeCoups, bool rateJamais, int ppMax, int priorite, std::string className) :
  className(className), nom(nom) {
    this->puissance = puissance;
    this->type = type;
    this->precision = precision;
    this->special = special;
    this->status = status;
    this->chanceDeCoups = chanceDeCoups;
    this->rateJamais = rateJamais;
    this->pp = this->ppMax = ppMax;
    this->priorite = priorite;
}

/*Pour les returns, equivalent exceptions java : Soit SameAtkPartTwo, qui ordonne de lancer la meme attaque au prochain tour (1)
 * soit EndOfTurn, qui met fin a l'attaque tout simplement (2).
 * Dans effetAprès, il n'est pas obligé de retourner 2 pour finir l'attaque :
 * Tout les nombres sont possible (Il est tout de même conseillé de mettre 0). Si 1 est revoyé, par contre,
 * ce sera le meme effet que 1 dans effetAvant.
 */
int Attaque::attack(OpMon &atk, OpMon &def) {
    pp--;
    //Fail d'attaque
    if ((Utils::randU(100)) > (precision * (atk.getStatPRE() / def.getStatESQ())) && rateJamais == false) {
            siEchoue(atk, def);
            return -2;
        }
    int effetAv = effetAvant(atk, def);
    if (effetAv == 1 || effetAv == 2) {//Si renvoi spécial, arrêt de l'attaque.
            return effetAv;
        }
    //Fail de types
    if (TableTypes::calcEfficacite(type, def.getType1(), def.getType2()) == 0 && (rateJamais == false || status == false)) {
            siEchoue(atk, def);
            return -1;
        }
    if (!status) {//Attaque de PV si ce n'est pas une attaque de status
            pvPerdus = (((atk.getLevel() * 0.4 + 2) * (special ? atk.getStatATKSPE() : atk.getStatATK()) * puissance) / ((special ? def.getStatDEFSPE() : def.getStatDEF()) * 50) + 2);
            if (type == atk.getType1() || type == atk.getType2()) {
                    pvPerdus = round(pvPerdus * 1.5);
                }
            float efficacite = (TableTypes::calcEfficacite(type, def.getType1(), def.getType2()));
            //if(efficacite)//A utiliser pour les dialogues
            pvPerdus = round(pvPerdus * efficacite);
            if (Utils::randU(chanceDeCoups) == 1) {
                    pvPerdus = round(pvPerdus * 1.5);
                }
            pvPerdus = round(pvPerdus * (Utils::randU(100 - 85 + 1) + 85) / 100);
            def.attacked(pvPerdus);
        }
    return effetApres(atk, def);
}
#include "../start/main.hpp"
#include "../save/Save.hpp"
std::string Attaque::save() {
    UNS
    ostringstream oss;
    oss << this->className << endl;
    oss << Save::intToChar(pp) << endl;
    oss << Save::intToChar(ppMax) << endl;
    return oss.str();
}

