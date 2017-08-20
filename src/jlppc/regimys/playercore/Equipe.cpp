#include "Equipe.hpp"

OpMon *Equipe::PNULL = new OpMon();

Equipe::Equipe(std::string const& name) {
    this->name = name;
}

void Equipe::heal() {
    for (int i = 0; i < nbreOfOp; i++) {
            if (equipe[i]->falsif != PNULL->falsif) {
                    equipe[i]->heal(equipe[i]->getStatHP());
                    equipe[i]->confus = false;
                    equipe[i]->setStatus(Status::NOTHING);
                }

        }
}

bool Equipe::addOpMon(OpMon *toAdd) {
    for (int i = 0; i < nbreOfOp; i++) {
            if (equipe[i] == PNULL) {
                    equipe[i] = toAdd;
                    return true;
                }
        }
    return false;
}

void Equipe::removeOp(int number) { //Number en partant de 0
    if (nbreOfOp == 1) {//Si un seul OpMon, ne supprime rien.
            return;
        }
    for (int i = 0; i < nbreOfOp; i++) {
            if (i >= number) {
                    if (i != 5) {
                            equipe[i] = equipe[i + 1];
                        }
                    else {
                            equipe[5] = PNULL;
                        }
                }

        }
}

OpMon *Equipe::operator[](int id) const {
    return equipe[id];
}

bool Equipe::isKo() const {
    int ko = 0;
    for (int i = 0; i < nbreOfOp; i++) {
            if (equipe[i]->falsif == PNULL->falsif) {
                    ko++;
                }
            else if (equipe[i]->getHP() <= 0) {
                    ko++;
                }
        }
    return (ko == 6);
}

int Equipe::getSize() const {
    return nbreOfOp;
}

