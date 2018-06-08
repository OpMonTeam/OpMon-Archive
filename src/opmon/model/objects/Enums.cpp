#include "Enums.hpp"

namespace OpMon {
    namespace Model {

        namespace ArrayTypes {
            const float arrTypes[][18] = {

              {LO_, HI_, LO_, AVG, AVG, LO_, HI_, LO_, LO_, LO_, LO_, NOT, LO_, LO_, HI_, AVG, AVG, LO_},
              {AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, LO_, AVG, AVG, AVG, HI_, LO_, AVG, AVG, LO_, HI_},
              {AVG, AVG, HI_, LO_, LO_, HI_, LO_, HI_, AVG, AVG, LO_, AVG, AVG, AVG, AVG, AVG, AVG, AVG},
              {LO_, AVG, AVG, LO_, HI_, AVG, LO_, LO_, AVG, AVG, HI_, AVG, AVG, AVG, AVG, AVG, AVG, AVG},
              {LO_, AVG, AVG, AVG, LO_, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, LO_},
              {HI_, LO_, NOT, AVG, AVG, AVG, AVG, AVG, LO_, AVG, AVG, HI_, AVG, AVG, AVG, AVG, LO_, AVG},
              {LO_, AVG, AVG, HI_, AVG, LO_, LO_, LO_, LO_, AVG, LO_, AVG, AVG, HI_, HI_, AVG, AVG, AVG},
              {HI_, HI_, AVG, AVG, AVG, AVG, HI_, LO_, AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, AVG, AVG},
              {AVG, LO_, AVG, AVG, AVG, AVG, HI_, AVG, AVG, AVG, LO_, AVG, AVG, HI_, LO_, AVG, AVG, HI_},
              {AVG, HI_, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, AVG, NOT, AVG, AVG},
              {AVG, AVG, AVG, LO_, LO_, AVG, HI_, HI_, HI_, AVG, LO_, HI_, AVG, AVG, LO_, AVG, AVG, HI_},
              {AVG, LO_, AVG, AVG, AVG, LO_, AVG, AVG, LO_, AVG, LO_, LO_, HI_, AVG, HI_, AVG, AVG, AVG},
              {AVG, LO_, AVG, AVG, AVG, AVG, AVG, AVG, HI_, AVG, AVG, AVG, LO_, AVG, AVG, HI_, HI_, LO_},
              {HI_, HI_, AVG, HI_, AVG, AVG, LO_, AVG, AVG, LO_, HI_, LO_, AVG, AVG, HI_, AVG, AVG, LO_},
              {AVG, AVG, AVG, HI_, NOT, AVG, AVG, HI_, AVG, AVG, HI_, LO_, AVG, LO_, AVG, AVG, AVG, AVG},
              {AVG, NOT, AVG, AVG, AVG, AVG, AVG, AVG, LO_, NOT, AVG, LO_, AVG, AVG, AVG, HI_, HI_, AVG},
              {AVG, HI_, AVG, AVG, AVG, HI_, AVG, AVG, HI_, AVG, AVG, AVG, NOT, AVG, AVG, LO_, LO_, AVG},
              {AVG, LO_, AVG, AVG, HI_, AVG, AVG, HI_, LO_, AVG, LO_, AVG, AVG, HI_, NOT, AVG, AVG, AVG}};

            float calcEffectiveness(Type atk, Type def1, Type def2) {
                int atkI((int)atk), type1I((int)def1), type2I((int)def2);
                if(def2 == Type::NOTHING) {
                    return arrTypes[type1I][atkI];
                } else {
                    return arrTypes[type1I][atkI] * arrTypes[type2I][atkI];
                }
            }
        } // namespace ArrayTypes

        bool operator==(Side side, int integer) {
            if(((int)side) == integer) {
                return true;
            } else {
                return false;
            }
        }

        bool operator!=(Side side, int integer) {
            return !(side == integer);
        }

        bool operator>=(Side side, int integer) {
            int sideInt = (int)side;
            return sideInt >= integer;
        }

        bool operator>(Side side, int integer) {
            int sideInt = (int)side;
            return sideInt > integer;
        }

        bool operator<(Side side, int integer) {
            int sideInt = (int)side;
            return sideInt < integer;
        }

        bool operator<=(Side side, int integer) {
            int sideInt = (int)side;
            return sideInt <= integer;
        }

        int operator+(Side side, int integer) {
            return ((int)side) + integer;
        }

        Side getSide(int id) {
            switch(id) {
            case -1:
                return Side::NO_MOVE;
            case 0:
                return Side::TO_DOWN;
            case 1:
                return Side::TO_RIGHT;
            case 2:
                return Side::TO_LEFT;
            case 3:
                return Side::TO_UP;
            case -2:
                return Side::STAY;
            default:
                return Side::NO_MOVE;
            }
        }

        int operator-(Side side, int integer) {
            return ((int)side) - integer;
        }

    } // namespace Model
} // namespace OpMon
