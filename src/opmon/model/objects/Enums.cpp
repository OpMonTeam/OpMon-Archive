#include "Enums.hpp"

namespace OpMon {
    namespace Model {

        namespace ArrayTypes {
            const float arrTypes[][18] = {

              {NE, VE, NE, NM, NM, NE, VE, NE, NE, NE, NE, IN, NE, NE, VE, NM, NM, NE},
              {NM, NM, NM, NM, NM, VE, NM, NM, NE, NM, NM, NM, VE, NE, NM, NM, NE, VE},
              {NM, NM, VE, NE, NE, VE, NE, VE, NM, NM, NE, NM, NM, NM, NM, NM, NM, NM},
              {NE, NM, NM, NE, VE, NM, NE, NE, NM, NM, VE, NM, NM, NM, NM, NM, NM, NM},
              {NE, NM, NM, NM, NE, NM, NM, NM, NM, NM, NM, NM, NM, NM, VE, NM, NM, NE},
              {VE, NE, IN, NM, NM, NM, NM, NM, NE, NM, NM, VE, NM, NM, NM, NM, NE, NM},
              {NE, NM, NM, VE, NM, NE, NE, NE, NE, NM, NE, NM, NM, VE, VE, NM, NM, NM},
              {VE, VE, NM, NM, NM, NM, VE, NE, NM, NM, NM, NM, NM, VE, NM, NM, NM, NM},
              {NM, NE, NM, NM, NM, NM, VE, NM, NM, NM, NE, NM, NM, VE, NE, NM, NM, VE},
              {NM, VE, NM, NM, NM, NM, NM, NM, NM, NM, NM, NM, NM, NM, NM, IN, NM, NM},
              {NM, NM, NM, NE, NE, NM, VE, VE, VE, NM, NE, VE, NM, NM, NE, NM, NM, VE},
              {NM, NE, NM, NM, NM, NE, NM, NM, NE, NM, NE, NE, VE, NM, VE, NM, NM, NM},
              {NM, NE, NM, NM, NM, NM, NM, NM, VE, NM, NM, NM, NE, NM, NM, VE, VE, NE},
              {VE, VE, NM, VE, NM, NM, NE, NM, NM, NE, VE, NE, NM, NM, VE, NM, NM, NE},
              {NM, NM, NM, VE, IN, NM, NM, VE, NM, NM, VE, NE, NM, NE, NM, NM, NM, NM},
              {NM, IN, NM, NM, NM, NM, NM, NM, NE, IN, NM, NE, NM, NM, NM, VE, VE, NM},
              {NM, VE, NM, NM, NM, VE, NM, NM, VE, NM, NM, NM, IN, NM, NM, NE, NE, NM},
              {NM, NE, NM, NM, VE, NM, NM, VE, NE, NM, NE, NM, NM, VE, IN, NM, NM, NM}};
            /**Un tableau qui réunit tous les tables a double type*/
           
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
