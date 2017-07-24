#include "Enums.hpp"


namespace TableTypes {
    float tabUnType[][18] = {

        {PE, TE, PE, NE, NE, PE, TE, PE, PE, PE, PE, IN, PE, PE, TE, NE, NE, PE},
        {NE, NE, NE, NE, NE, TE, NE, NE, PE, NE, NE, NE, TE, PE, NE, NE, PE, TE},
        {NE, NE, TE, PE, PE, TE, PE, TE, NE, NE, PE, NE, NE, NE, NE, NE, NE, NE},
        {PE, NE, NE, PE, TE, NE, PE, PE, NE, NE, TE, NE, NE, NE, NE, NE, NE, NE},
        {PE, NE, NE, NE, PE, NE, NE, NE, NE, NE, NE, NE, NE, NE, TE, NE, NE, PE},
        {TE, PE, IN, NE, NE, NE, NE, NE, PE, NE, NE, TE, NE, NE, NE, NE, PE, NE},
        {PE, NE, NE, TE, NE, PE, PE, PE, PE, NE, PE, NE, NE, TE, TE, NE, NE, NE},
        {TE, TE, NE, NE, NE, NE, TE, PE, NE, NE, NE, NE, NE, TE, NE, NE, NE, NE},
        {NE, PE, NE, NE, NE, NE, TE, NE, NE, NE, PE, NE, NE, TE, PE, NE, NE, TE},
        {NE, TE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, IN, NE, NE},
        {NE, NE, NE, PE, PE, NE, TE, TE, TE, NE, PE, TE, NE, NE, PE, NE, NE, TE},
        {NE, PE, NE, NE, NE, PE, NE, NE, PE, NE, PE, PE, TE, NE, TE, NE, NE, NE},
        {NE, PE, NE, NE, NE, NE, NE, NE, TE, NE, NE, NE, PE, NE, NE, TE, TE, PE},
        {TE, TE, NE, TE, NE, NE, PE, NE, NE, PE, TE, PE, NE, NE, TE, NE, NE, PE},
        {NE, NE, NE, TE, IN, NE, NE, TE, NE, NE, TE, PE, NE, PE, NE, NE, NE, NE},
        {NE, IN, NE, NE, NE, NE, NE, NE, PE, IN, NE, PE, NE, NE, NE, TE, TE, NE},
        {NE, TE, NE, NE, NE, TE, NE, NE, TE, NE, NE, NE, IN, NE, NE, PE, PE, NE},
        {NE, PE, NE, NE, TE, NE, NE, TE, PE, NE, PE, NE, NE, TE, IN, NE, NE, NE}
    };
    /**Un tableau qui réunit tous les tables a double type*/
    float tableDeuxTypes[][18][18] = {{
            {TP, SE, TP, NE, NE, TP, SE, TP, TP, TP, TP, IN, TP, TP, SE, NE, NE, TP},
            {PE, TE, PE, NE, NE, NE, TE, PE, TP, PE, PE, IN, NE, TP, TE, NE, PE, NE},
            {PE, TE, NE, PE, PE, NE, NE, NE, PE, PE, TP, IN, PE, PE, TE, NE, NE, PE},
            {TP, TE, PE, PE, TE, PE, NE, TP, PE, PE, NE, IN, PE, PE, TE, NE, NE, PE},
            {TP, TE, PE, NE, PE, PE, TE, PE, PE, PE, PE, IN, PE, PE, SE, NE, NE, TP},
            {NE, NE, IN, NE, NE, PE, TE, PE, TP, PE, PE, IN, PE, PE, TE, NE, PE, PE},
            {TP, TE, PE, TE, NE, TP, NE, TP, TP, PE, TP, IN, PE, NE, SE, NE, NE, PE},
            {NE, SE, PE, NE, NE, PE, SE, TP, PE, PE, PE, IN, PE, NE, TE, NE, NE, PE},
            {PE, NE, PE, NE, NE, TP, SE, PE, PE, PE, TP, IN, NE, NE, NE, PE, PE, NE},
            {PE, SE, PE, NE, NE, PE, TE, PE, PE, PE, PE, IN, PE, PE, TE, IN, NE, PE},
            {PE, TE, PE, PE, PE, PE, SE, NE, NE, PE, TP, IN, PE, PE, NE, NE, NE, NE},
            {PE, NE, PE, NE, NE, TP, TE, PE, TP, PE, TP, IN, NE, PE, SE, NE, NE, PE},
            {PE, NE, PE, NE, NE, PE, TE, PE, NE, PE, PE, IN, TP, PE, TE, TE, TE, PE},
            {NE, SE, PE, TE, NE, PE, NE, PE, PE, TP, NE, IN, PE, PE, SE, NE, NE, TP},
            {PE, TE, PE, TE, IN, PE, TE, NE, PE, PE, NE, IN, PE, TP, TE, NE, NE, PE},
            {PE, IN, PE, NE, NE, PE, TE, PE, TP, IN, PE, IN, PE, PE, TE, TE, TE, PE},
            {PE, SE, PE, NE, NE, NE, TE, PE, NE, PE, PE, IN, IN, PE, TE, PE, PE, PE},
            {PE, NE, PE, NE, TE, PE, TE, NE, TP, PE, TP, IN, PE, NE, IN, NE, NE, PE}
        }, {

            {PE, TE, PE, NE, NE, NE, TE, PE, TP, PE, PE, IN, NE, TP, TE, NE, PE, NE},
            {NE, NE, NE, NE, NE, TE, NE, NE, PE, NE, NE, NE, TE, PE, NE, NE, PE, TE},
            {NE, NE, TE, PE, PE, SE, PE, TE, PE, NE, PE, NE, TE, PE, NE, NE, PE, TE},
            {PE, NE, NE, PE, TE, TE, PE, PE, PE, NE, TE, NE, TE, PE, NE, NE, PE, TE},
            {PE, NE, NE, NE, PE, TE, NE, NE, PE, NE, NE, NE, TE, PE, TE, NE, PE, NE},
            {TE, PE, IN, NE, NE, TE, NE, NE, TP, NE, NE, TE, TE, PE, NE, NE, TP, TE},
            {PE, NE, NE, TE, NE, NE, PE, PE, TP, NE, PE, NE, TE, NE, TE, NE, PE, TE},
            {TE, TE, NE, NE, NE, TE, TE, PE, PE, NE, NE, NE, TE, NE, NE, NE, PE, TE},
            {NE, PE, NE, NE, NE, TE, TE, NE, PE, NE, PE, NE, TE, NE, PE, NE, PE, SE},
            {NE, TE, NE, NE, NE, TE, NE, NE, PE, NE, NE, NE, TE, PE, NE, IN, PE, TE},
            {NE, NE, NE, PE, PE, TE, TE, TE, NE, NE, PE, TE, TE, PE, PE, NE, PE, SE},
            {NE, PE, NE, NE, NE, NE, NE, NE, TP, NE, PE, PE, SE, PE, TE, NE, PE, TE},
            {NE, PE, NE, NE, NE, TE, NE, NE, NE, NE, NE, NE, NE, PE, NE, TE, NE, TE},
            {TE, TE, NE, TE, NE, TE, PE, NE, PE, PE, TE, PE, TE, PE, TE, NE, PE, NE},
            {NE, NE, NE, TE, IN, TE, NE, TE, PE, NE, TE, PE, TE, TP, NE, NE, PE, TE},
            {NE, IN, NE, NE, NE, TE, NE, NE, TP, IN, NE, PE, TE, PE, NE, TE, NE, TE},
            {NE, TE, NE, NE, NE, SE, NE, NE, NE, NE, NE, NE, IN, PE, NE, PE, TP, TE},
            {NE, PE, NE, NE, TE, TE, NE, TE, TP, NE, PE, NE, TE, NE, IN, NE, PE, TE}
        }, {

            {PE, TE, NE, PE, PE, NE, NE, NE, PE, PE, TP, IN, PE, PE, TE, NE, NE, PE},
            {NE, NE, TE, PE, PE, SE, PE, TE, PE, NE, PE, NE, TE, PE, NE, NE, PE, TE},
            {NE, NE, TE, PE, PE, TE, PE, TE, NE, NE, PE, NE, NE, NE, NE, NE, NE, NE},
            {PE, NE, TE, TP, NE, TE, TP, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE},
            {PE, NE, TE, PE, TP, TE, PE, TE, NE, NE, PE, NE, NE, NE, TE, NE, NE, PE},
            {TE, PE, IN, PE, PE, TE, PE, TE, PE, NE, PE, TE, NE, NE, NE, NE, PE, NE},
            {PE, NE, TE, NE, PE, NE, TP, NE, PE, NE, TP, NE, NE, TE, TE, NE, NE, NE},
            {TE, TE, TE, PE, PE, TE, NE, NE, NE, NE, PE, NE, NE, TE, NE, NE, NE, NE},
            {NE, PE, TE, PE, PE, TE, NE, TE, NE, NE, TP, NE, NE, TE, PE, NE, NE, TE},
            {NE, TE, TE, PE, PE, TE, PE, TE, NE, NE, PE, NE, NE, NE, NE, IN, NE, NE},
            {NE, NE, TE, TP, TP, TE, NE, SE, TE, NE, TP, TE, NE, NE, PE, NE, NE, TE},
            {NE, PE, TE, PE, PE, NE, PE, TE, PE, NE, TP, PE, TE, NE, TE, NE, NE, NE},
            {NE, PE, TE, PE, PE, TE, PE, TE, TE, NE, PE, NE, PE, NE, NE, TE, TE, NE},
            {TE, TE, TE, NE, PE, TE, TP, TE, NE, PE, NE, PE, NE, NE, TE, NE, NE, PE},
            {NE, NE, TE, NE, IN, TE, PE, SE, NE, NE, NE, PE, NE, PE, NE, NE, NE, NE},
            {NE, IN, TE, PE, PE, TE, PE, TE, PE, IN, PE, PE, NE, NE, NE, TE, TE, NE},
            {NE, IN, TE, PE, PE, TE, PE, TE, PE, IN, PE, PE, NE, NE, NE, TE, TE, NE},
            {NE, PE, TE, PE, NE, TE, PE, SE, PE, NE, TP, NE, NE, TE, IN, NE, NE, NE}
        }, {

            {TP, TE, PE, PE, TE, PE, NE, TP, PE, PE, NE, IN, PE, PE, TE, NE, NE, PE},
            {PE, NE, NE, PE, TE, TE, PE, PE, PE, NE, TE, NE, TE, PE, NE, NE, PE, TE},
            {PE, NE, TE, TP, NE, TE, TP, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE},
            {PE, NE, NE, PE, TE, NE, PE, PE, NE, NE, TE, NE, NE, NE, NE, NE, NE, NE},
            {TP, NE, NE, PE, NE, NE, PE, PE, NE, NE, TE, NE, NE, NE, TE, NE, NE, PE},
            {NE, PE, IN, PE, TE, NE, PE, PE, PE, NE, TE, TE, NE, NE, NE, NE, PE, NE},
            {TP, NE, NE, NE, TE, PE, TP, TP, PE, NE, NE, NE, NE, TE, TE, NE, NE, NE},
            {NE, TE, NE, PE, TE, NE, NE, TP, NE, NE, TE, NE, NE, TE, NE, NE, NE, NE},
            {PE, PE, NE, PE, TE, NE, NE, PE, NE, NE, NE, NE, NE, TE, PE, NE, NE, TE},
            {PE, TE, NE, PE, TE, NE, PE, PE, NE, NE, TE, NE, NE, NE, NE, IN, NE, NE},
            {PE, NE, NE, TP, NE, NE, NE, NE, TE, NE, NE, TE, NE, NE, PE, NE, NE, TE},
            {PE, PE, NE, PE, TE, PE, PE, PE, PE, NE, NE, PE, TE, NE, TE, NE, NE, NE},
            {PE, PE, NE, PE, TE, NE, PE, PE, TE, NE, TE, NE, PE, NE, NE, TE, TE, NE},
            {NE, TE, NE, NE, TE, NE, TP, PE, NE, PE, SE, PE, NE, NE, TE, NE, NE, PE},
            {PE, NE, NE, NE, IN, NE, PE, NE, NE, NE, SE, PE, NE, PE, NE, NE, NE, NE},
            {PE, IN, NE, PE, TE, NE, PE, PE, PE, IN, TE, PE, NE, NE, NE, TE, TE, NE},
            {PE, TE, NE, PE, TE, TE, PE, PE, TE, NE, TE, NE, IN, NE, NE, PE, PE, NE},
            {PE, PE, NE, PE, SE, NE, PE, NE, PE, NE, NE, NE, NE, TE, IN, NE, NE, NE}
        }, {
            {TP, TE, PE, NE, PE, PE, TE, PE, PE, PE, PE, IN, PE, PE, SE, NE, NE, TP},
            {PE, NE, NE, NE, PE, TE, NE, NE, PE, NE, NE, NE, TE, PE, TE, NE, PE, NE},
            {PE, NE, TE, PE, TP, TE, PE, TE, NE, NE, PE, NE, NE, NE, TE, NE, NE, PE},
            {TP, NE, NE, PE, NE, NE, PE, PE, NE, NE, TE, NE, NE, NE, TE, NE, NE, PE},
            {PE, NE, NE, NE, PE, NE, NE, NE, NE, NE, NE, NE, NE, NE, TE, NE, NE, PE},
            {NE, PE, IN, NE, PE, NE, NE, NE, PE, NE, NE, TE, NE, NE, TE, NE, PE, PE},
            {TP, NE, NE, TE, PE, PE, PE, PE, PE, NE, PE, NE, NE, TE, SE, NE, NE, PE},
            {NE, TE, NE, NE, PE, NE, TE, PE, NE, NE, NE, NE, NE, TE, TE, NE, NE, PE},
            {PE, PE, NE, NE, PE, NE, TE, NE, NE, NE, PE, NE, NE, TE, NE, NE, NE, NE},
            {PE, TE, NE, NE, PE, NE, NE, NE, NE, NE, NE, NE, NE, NE, TE, IN, NE, PE},
            {PE, NE, NE, PE, TP, NE, TE, TE, TE, NE, PE, TE, NE, NE, NE, NE, NE, NE},
            {PE, PE, NE, NE, PE, PE, NE, NE, PE, NE, PE, PE, TE, NE, SE, NE, NE, PE},
            {PE, PE, NE, NE, PE, NE, NE, NE, TE, NE, NE, NE, PE, NE, TE, TE, TE, PE},
            {NE, TE, NE, TE, PE, NE, PE, NE, NE, PE, TE, PE, NE, NE, SE, NE, NE, TP},
            {PE, NE, NE, TE, IN, NE, NE, TE, NE, NE, TE, PE, NE, PE, TE, NE, NE, PE},
            {PE, IN, NE, NE, PE, NE, NE, NE, PE, IN, NE, PE, NE, NE, TE, TE, TE, PE},
            {PE, TE, NE, NE, PE, TE, NE, NE, TE, NE, NE, NE, IN, NE, TE, PE, PE, PE},
            {PE, PE, NE, NE, NE, NE, NE, TE, PE, NE, PE, NE, NE, TE, IN, NE, NE, PE}
        }, {
            {NE, NE, IN, NE, NE, PE, TE, PE, TP, PE, PE, IN, PE, PE, TE, NE, PE, PE},
            {TE, PE, IN, NE, NE, TE, NE, NE, TP, NE, NE, TE, TE, PE, NE, NE, TP, TE},
            {TE, PE, IN, PE, PE, TE, PE, TE, PE, NE, PE, TE, NE, NE, NE, NE, PE, NE},
            {NE, PE, IN, PE, TE, NE, PE, PE, PE, NE, TE, TE, NE, NE, NE, NE, PE, NE},
            {NE, PE, IN, NE, PE, NE, NE, NE, PE, NE, NE, TE, NE, NE, TE, NE, PE, PE},
            {TE, PE, IN, NE, NE, NE, NE, NE, PE, NE, NE, TE, NE, NE, NE, NE, PE, NE},
            {NE, PE, IN, TE, NE, PE, PE, PE, TP, NE, PE, TE, NE, TE, TE, NE, PE, NE},
            {SE, NE, IN, NE, NE, NE, TE, PE, PE, NE, NE, TE, NE, TE, NE, NE, PE, NE},
            {TE, TP, IN, NE, NE, NE, TE, NE, PE, NE, PE, TE, NE, TE, PE, NE, PE, TE},
            {TE, NE, IN, NE, NE, NE, NE, NE, PE, NE, NE, TE, NE, NE, NE, IN, PE, NE},
            {TE, PE, IN, PE, PE, NE, TE, TE, NE, NE, PE, SE, NE, NE, PE, NE, PE, TE},
            {TE, TP, IN, NE, NE, PE, NE, NE, TP, NE, PE, NE, TE, NE, TE, NE, PE, NE},
            {TE, TP, IN, NE, NE, NE, NE, NE, NE, NE, NE, TE, PE, NE, NE, TE, NE, PE},
            {SE, NE, IN, TE, NE, NE, PE, NE, PE, PE, TE, NE, NE, NE, TE, NE, PE, PE},
            {TE, NE, IN, TE, IN, NE, NE, TE, PE, NE, TE, NE, NE, PE, NE, NE, PE, NE},
            {TE, IN, IN, NE, NE, NE, NE, NE, TP, IN, NE, NE, NE, NE, NE, TE, NE, NE},
            {TE, NE, IN, NE, NE, TE, NE, NE, NE, NE, NE, TE, IN, NE, NE, PE, TP, NE},
            {TE, TP, IN, NE, TE, NE, NE, TE, TP, NE, PE, TE, NE, TE, IN, NE, PE, NE}
        }, {
            {TP, TE, PE, TE, NE, TP, NE, TP, TP, PE, TP, IN, PE, NE, SE, NE, NE, PE},
            {PE, NE, NE, TE, NE, NE, PE, PE, TP, NE, PE, NE, TE, NE, TE, NE, PE, TE},
            {PE, NE, TE, NE, PE, NE, TP, NE, PE, NE, TP, NE, NE, TE, TE, NE, NE, NE},
            {TP, NE, NE, NE, TE, PE, TP, TP, PE, NE, NE, NE, NE, TE, TE, NE, NE, NE},
            {TP, NE, NE, TE, PE, PE, PE, PE, PE, NE, PE, NE, NE, TE, SE, NE, NE, PE},
            {NE, PE, IN, TE, NE, PE, PE, PE, TP, NE, PE, TE, NE, TE, TE, NE, PE, NE},
            {PE, NE, NE, TE, NE, PE, PE, PE, PE, NE, PE, NE, NE, TE, TE, NE, NE, NE},
            {NE, TE, NE, TE, NE, PE, NE, TP, PE, NE, PE, NE, NE, SE, TE, NE, NE, NE},
            {PE, PE, NE, TE, NE, PE, NE, PE, PE, NE, TP, NE, NE, SE, NE, NE, NE, TE},
            {PE, TE, NE, TE, NE, PE, PE, PE, PE, NE, PE, NE, NE, TE, TE, IN, NE, NE},
            {PE, NE, NE, NE, PE, PE, NE, NE, NE, NE, TP, TE, NE, TE, NE, NE, NE, TE},
            {PE, PE, NE, TE, NE, TP, PE, PE, TP, NE, TP, PE, TE, TE, SE, NE, NE, NE},
            {PE, PE, NE, TE, NE, PE, PE, PE, NE, NE, PE, NE, PE, TE, TE, TE, TE, NE},
            {NE, TE, NE, SE, NE, PE, TP, PE, PE, PE, NE, PE, NE, TE, SE, NE, NE, PE},
            {PE, NE, NE, SE, IN, PE, PE, NE, PE, NE, NE, PE, NE, NE, TE, NE, NE, NE},
            {PE, IN, NE, TE, NE, PE, PE, PE, TP, IN, PE, PE, NE, TE, TE, TE, TE, NE},
            {PE, TE, NE, TE, NE, NE, PE, PE, NE, NE, PE, NE, IN, TE, TE, PE, PE, NE},
            {PE, PE, NE, TE, TE, PE, PE, NE, TP, NE, TP, NE, NE, SE, IN, NE, NE, NE}
        }, {
            {NE, SE, PE, NE, NE, PE, SE, TP, PE, PE, PE, IN, PE, NE, TE, NE, NE, PE},
            {TE, TE, NE, NE, NE, TE, TE, PE, PE, NE, NE, NE, TE, NE, NE, NE, PE, TE},
            {TE, TE, TE, PE, PE, TE, NE, NE, NE, NE, PE, NE, NE, TE, NE, NE, NE, NE},
            {NE, TE, NE, PE, TE, NE, NE, TP, NE, NE, TE, NE, NE, TE, NE, NE, NE, NE},
            {NE, TE, NE, NE, PE, NE, TE, PE, NE, NE, NE, NE, NE, TE, TE, NE, NE, PE},
            {SE, NE, IN, NE, NE, NE, TE, PE, PE, NE, NE, TE, NE, TE, NE, NE, PE, NE},
            {NE, TE, NE, TE, NE, PE, NE, TP, PE, NE, PE, NE, NE, SE, TE, NE, NE, NE},
            {TE, TE, NE, NE, NE, NE, TE, PE, NE, NE, NE, NE, NE, TE, NE, NE, NE, NE},
            {TE, NE, NE, NE, NE, NE, SE, PE, NE, NE, PE, NE, NE, SE, PE, NE, NE, TE},
            {TE, SE, NE, NE, NE, NE, TE, PE, NE, NE, NE, NE, NE, TE, NE, IN, NE, NE},
            {TE, TE, NE, PE, PE, NE, SE, NE, TE, NE, PE, TE, NE, TE, PE, NE, NE, TE},
            {TE, NE, NE, NE, NE, PE, TE, PE, PE, NE, PE, PE, TE, TE, TE, NE, NE, NE},
            {TE, NE, NE, NE, NE, NE, TE, PE, TE, NE, NE, NE, PE, TE, NE, TE, TE, NE},
            {SE, SE, NE, TE, NE, NE, NE, PE, NE, PE, TE, PE, NE, TE, TE, NE, NE, PE},
            {TE, TE, NE, TE, IN, NE, TE, NE, NE, NE, TE, PE, NE, NE, NE, NE, NE, NE},
            {TE, IN, NE, NE, NE, NE, TE, PE, PE, IN, NE, PE, NE, TE, NE, TE, TE, NE},
            {TE, SE, NE, NE, NE, TE, TE, PE, TE, NE, NE, NE, IN, TE, NE, PE, PE, NE},
            {TE, NE, NE, NE, TE, NE, TE, NE, PE, NE, PE, NE, NE, SE, IN, NE, NE, NE}
        }, {
            {PE, NE, PE, NE, NE, PE, SE, PE, PE, PE, TP, IN, PE, NE, NE, NE, NE, NE},
            {NE, PE, NE, NE, NE, TE, TE, NE, PE, NE, PE, NE, TE, NE, PE, NE, PE, SE},
            {NE, PE, TE, PE, PE, TE, NE, TE, NE, NE, TP, NE, NE, TE, PE, NE, NE, TE},
            {PE, PE, NE, PE, TE, NE, NE, PE, NE, NE, NE, NE, NE, TE, PE, NE, NE, TE},
            {PE, PE, NE, NE, PE, NE, TE, NE, NE, NE, PE, NE, NE, TE, NE, NE, NE, NE},
            {TE, TP, IN, NE, NE, NE, TE, NE, PE, NE, PE, TE, NE, TE, PE, NE, PE, TE},
            {PE, PE, NE, TE, NE, PE, NE, PE, PE, NE, TP, NE, NE, SE, NE, NE, NE, TE},
            {TE, NE, NE, NE, NE, NE, SE, PE, NE, NE, PE, NE, NE, SE, PE, NE, NE, TE},
            {NE, PE, NE, NE, NE, NE, TE, NE, NE, NE, PE, NE, NE, TE, PE, NE, NE, TE},
            {NE, NE, NE, NE, NE, NE, TE, NE, NE, NE, PE, NE, NE, TE, PE, IN, NE, TE},
            {NE, PE, NE, PE, PE, NE, SE, TE, TE, NE, TP, TE, NE, TE, TP, NE, NE, SE},
            {NE, TP, NE, NE, NE, PE, TE, NE, PE, NE, TP, PE, TE, TE, NE, NE, NE, TE},
            {NE, TP, NE, NE, NE, NE, TE, NE, TE, NE, PE, NE, PE, TE, PE, TE, TE, TE},
            {TE, NE, NE, TE, NE, NE, NE, NE, NE, PE, NE, PE, NE, TE, NE, NE, NE, NE},
            {NE, PE, NE, TE, IN, NE, TE, TE, NE, NE, NE, PE, NE, NE, PE, NE, NE, TE},
            {NE, IN, NE, NE, NE, NE, TE, NE, PE, IN, PE, PE, NE, TE, PE, TE, TE, TE},
            {NE, NE, NE, NE, NE, TE, TE, NE, TE, NE, PE, NE, IN, TE, PE, PE, PE, TE},
            {NE, TP, NE, NE, TE, NE, TE, TE, PE, NE, TP, NE, NE, SE, IN, NE, NE, TE}
        }, {
            {PE, SE, PE, NE, NE, PE, TE, PE, PE, PE, PE, IN, NE, PE, TE, IN, PE, PE},
            {NE, TE, NE, NE, NE, TE, NE, NE, PE, NE, NE, NE, TE, PE, NE, IN, PE, TE},
            {NE, TE, TE, PE, PE, TE, PE, TE, NE, NE, PE, NE, NE, NE, NE, IN, NE, NE},
            {PE, TE, NE, PE, TE, NE, PE, PE, NE, NE, TE, NE, NE, NE, NE, IN, NE, NE},
            {PE, TE, NE, NE, PE, NE, NE, NE, NE, NE, NE, NE, NE, NE, TE, IN, NE, PE},
            {TE, NE, IN, NE, NE, NE, NE, NE, PE, NE, NE, TE, NE, NE, NE, IN, PE, NE},
            {PE, TE, NE, TE, NE, PE, PE, PE, PE, NE, PE, NE, NE, TE, TE, IN, NE, NE},
            {TE, SE, NE, NE, NE, NE, TE, PE, NE, NE, NE, NE, NE, TE, NE, IN, NE, NE},
            {NE, NE, NE, NE, NE, NE, TE, NE, NE, NE, PE, NE, NE, TE, PE, IN, NE, TE},
            {NE, TE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, IN, IN, IN},
            {NE, TE, NE, PE, PE, NE, TE, TE, TE, NE, PE, TE, NE, NE, PE, IN, NE, TE},
            {NE, NE, NE, NE, NE, PE, NE, NE, PE, NE, PE, PE, TE, NE, TE, IN, NE, NE},
            {NE, NE, NE, NE, NE, NE, NE, NE, TE, NE, NE, NE, PE, NE, NE, IN, TE, NE},
            {TE, SE, NE, TE, NE, NE, PE, NE, NE, PE, TE, PE, NE, NE, TE, IN, NE, PE},
            {NE, TE, NE, TE, IN, NE, NE, TE, NE, NE, TE, PE, NE, PE, NE, IN, NE, NE},
            {NE, IN, NE, NE, NE, NE, NE, NE, PE, IN, NE, PE, NE, NE, NE, IN, TE, NE},
            {NE, SE, NE, NE, NE, TE, NE, NE, TE, NE, NE, NE, IN, NE, NE, IN, PE, NE},
            {NE, NE, NE, NE, TE, NE, NE, TE, PE, NE, PE, NE, NE, TE, IN, IN, NE, NE}
        }, {
            {PE, TE, PE, PE, PE, PE, SE, NE, NE, PE, TP, IN, PE, PE, NE, NE, NE, NE},
            {NE, NE, NE, PE, PE, TE, TE, TE, NE, NE, PE, TE, TE, PE, PE, NE, PE, SE},
            {NE, NE, TE, TP, TP, TE, NE, SE, TE, NE, TP, TE, NE, NE, PE, NE, NE, TE},
            {PE, NE, NE, TP, NE, NE, NE, NE, TE, NE, NE, TE, NE, NE, PE, NE, NE, TE},
            {PE, NE, NE, PE, TP, NE, TE, TE, TE, NE, PE, TE, NE, NE, NE, NE, NE, NE},
            {TE, PE, IN, PE, PE, NE, TE, TE, NE, NE, PE, SE, NE, NE, PE, NE, PE, TE},
            {PE, NE, NE, NE, PE, PE, NE, NE, NE, NE, TP, TE, NE, TE, NE, NE, NE, TE},
            {TE, TE, NE, PE, PE, NE, SE, NE, TE, NE, PE, TE, NE, TE, PE, NE, NE, TE},
            {NE, PE, NE, PE, PE, NE, SE, TE, TE, NE, TP, TE, NE, TE, TP, NE, NE, SE},
            {NE, TE, NE, PE, PE, NE, TE, TE, TE, NE, PE, TE, NE, NE, PE, IN, NE, TE},
            {NE, NE, NE, PE, PE, NE, TE, TE, TE, NE, PE, TE, NE, NE, PE, NE, NE, TE},
            {NE, PE, NE, PE, PE, PE, TE, TE, NE, NE, TP, NE, TE, NE, NE, NE, NE, TE},
            {NE, PE, NE, PE, PE, NE, TE, TE, SE, NE, PE, TE, PE, NE, PE, TE, TE, TE},
            {TE, TE, NE, NE, PE, NE, NE, TE, TE, PE, NE, NE, NE, NE, NE, NE, NE, NE},
            {NE, NE, NE, NE, IN, NE, TE, SE, TE, NE, NE, NE, NE, PE, PE, NE, NE, TE},
            {NE, IN, NE, PE, PE, NE, TE, TE, NE, IN, PE, NE, NE, NE, PE, TE, TE, TE},
            {NE, TE, NE, PE, PE, TE, TE, TE, SE, NE, PE, TE, IN, NE, PE, PE, PE, TE},
            {NE, PE, NE, PE, NE, NE, TE, SE, NE, NE, TP, TE, NE, TE, IN, NE, NE, TE}
        }, {
            {PE, NE, PE, NE, NE, TP, TE, PE, TP, PE, TP, IN, NE, PE, SE, NE, NE, PE},
            {NE, PE, NE, NE, NE, NE, NE, NE, TP, NE, PE, PE, SE, PE, TE, NE, PE, TE},
            {NE, PE, TE, PE, PE, NE, PE, TE, PE, NE, TP, PE, TE, NE, TE, NE, NE, NE},
            {PE, PE, NE, PE, TE, PE, PE, PE, PE, NE, NE, PE, TE, NE, TE, NE, NE, NE},
            {PE, PE, NE, NE, PE, PE, NE, NE, PE, NE, PE, PE, TE, NE, SE, NE, NE, PE},
            {TE, TP, IN, NE, NE, PE, NE, NE, TP, NE, PE, NE, TE, NE, TE, NE, PE, NE},
            {PE, PE, NE, TE, NE, TP, PE, PE, TP, NE, TP, PE, TE, TE, SE, NE, NE, NE},
            {TE, NE, NE, NE, NE, PE, TE, PE, PE, NE, PE, PE, TE, TE, TE, NE, NE, NE},
            {NE, TP, NE, NE, NE, PE, TE, NE, PE, NE, TP, PE, TE, TE, NE, NE, NE, TE},
            {NE, NE, NE, NE, NE, PE, NE, NE, PE, NE, PE, PE, TE, NE, TE, IN, NE, NE},
            {NE, PE, NE, PE, PE, PE, TE, TE, NE, NE, TP, NE, TE, NE, NE, NE, NE, TE},
            {NE, PE, NE, NE, NE, PE, NE, NE, PE, NE, PE, PE, TE, NE, TE, NE, NE, NE},
            {NE, TP, NE, NE, NE, PE, NE, NE, NE, NE, PE, PE, NE, NE, TE, TE, TE, NE},
            {TE, NE, NE, TE, NE, PE, PE, NE, PE, PE, NE, TP, TE, NE, SE, NE, NE, PE},
            {NE, PE, NE, TE, IN, PE, NE, TE, PE, NE, NE, TP, TE, PE, TE, NE, NE, NE},
            {NE, IN, NE, NE, NE, PE, NE, NE, TP, IN, PE, TP, TE, NE, TE, TE, TE, NE},
            {NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, PE, PE, IN, NE, TE, PE, PE, NE},
            {NE, TP, NE, NE, TE, PE, NE, TE, TP, NE, TP, PE, TE, TE, IN, NE, NE, NE}
        }, {
            {PE, NE, PE, NE, NE, PE, TE, PE, NE, PE, PE, IN, TP, PE, TE, TE, TE, PE},
            {NE, PE, NE, NE, NE, TE, NE, NE, NE, NE, NE, NE, NE, PE, NE, TE, NE, TE},
            {NE, PE, TE, PE, PE, TE, PE, TE, TE, NE, PE, NE, PE, NE, NE, TE, TE, NE},
            {PE, PE, NE, PE, TE, NE, PE, PE, TE, NE, TE, NE, PE, NE, NE, TE, TE, NE},
            {PE, PE, NE, NE, PE, NE, NE, NE, TE, NE, NE, NE, PE, NE, TE, TE, TE, PE},
            {TE, TP, IN, NE, NE, NE, NE, NE, NE, NE, NE, TE, PE, NE, NE, TE, NE, PE},
            {PE, PE, NE, TE, NE, PE, PE, PE, NE, NE, PE, NE, PE, TE, TE, TE, TE, NE},
            {TE, NE, NE, NE, NE, NE, TE, PE, TE, NE, NE, NE, PE, TE, NE, TE, TE, NE},
            {NE, TP, NE, NE, NE, NE, TE, NE, TE, NE, PE, NE, PE, TE, PE, TE, TE, TE},
            {NE, NE, NE, NE, NE, NE, NE, NE, TE, NE, NE, NE, PE, NE, NE, IN, TE, NE},
            {NE, PE, NE, PE, PE, NE, TE, TE, SE, NE, PE, TE, PE, NE, PE, TE, TE, TE},
            {NE, TP, NE, NE, NE, PE, NE, NE, NE, NE, PE, PE, NE, NE, TE, TE, TE, NE},
            {NE, PE, NE, NE, NE, NE, NE, NE, TE, NE, NE, NE, PE, NE, NE, TE, TE, NE},
            {TE, NE, NE, TE, NE, NE, PE, NE, TE, PE, TE, PE, PE, NE, TE, TE, TE, PE},
            {NE, PE, NE, TE, IN, NE, NE, TE, TE, NE, TE, PE, PE, PE, NE, TE, TE, NE},
            {NE, IN, NE, NE, NE, NE, NE, NE, NE, IN, NE, PE, PE, NE, NE, SE, SE, NE},
            {NE, NE, NE, NE, NE, TE, NE, NE, SE, NE, NE, NE, IN, NE, NE, IN, IN, IN},
            {NE, TP, NE, NE, TE, NE, NE, TE, NE, NE, PE, NE, PE, TE, IN, TE, TE, NE}
        }, {
            {NE, SE, PE, TE, NE, PE, NE, PE, PE, TP, NE, IN, PE, PE, SE, NE, NE, TP},
            {TE, TE, NE, TE, NE, TE, PE, NE, PE, PE, TE, PE, TE, PE, TE, NE, PE, NE},
            {TE, TE, TE, NE, PE, TE, TP, TE, NE, PE, NE, PE, NE, NE, TE, NE, NE, PE},
            {NE, TE, NE, NE, TE, NE, TP, PE, NE, PE, SE, PE, NE, NE, TE, NE, NE, PE},
            {NE, TE, NE, TE, PE, NE, PE, NE, NE, PE, TE, PE, NE, NE, SE, NE, NE, TP},
            {SE, NE, IN, TE, NE, NE, PE, NE, PE, PE, TE, NE, NE, NE, TE, NE, PE, PE},
            {NE, TE, NE, SE, NE, PE, TP, PE, PE, PE, NE, PE, NE, TE, SE, NE, NE, PE},
            {SE, SE, NE, TE, NE, NE, NE, PE, NE, PE, TE, PE, NE, TE, TE, NE, NE, PE},
            {TE, NE, NE, TE, NE, NE, NE, NE, NE, PE, NE, PE, NE, TE, NE, NE, NE, NE},
            {TE, SE, NE, TE, NE, NE, PE, NE, NE, PE, TE, PE, NE, NE, TE, IN, NE, PE},
            {TE, TE, NE, NE, PE, NE, NE, TE, TE, PE, NE, NE, NE, NE, NE, NE, NE, NE},
            {TE, NE, NE, TE, NE, PE, PE, NE, PE, PE, NE, TP, TE, NE, SE, NE, NE, PE},
            {TE, NE, NE, TE, NE, NE, PE, NE, TE, PE, TE, PE, PE, NE, TE, TE, TE, PE},
            {TE, TE, NE, TE, NE, NE, PE, NE, NE, PE, TE, PE, NE, NE, TE, NE, NE, PE},
            {TE, TE, NE, SE, IN, NE, PE, TE, NE, PE, SE, TP, NE, PE, TE, NE, NE, PE},
            {TE, IN, NE, TE, NE, NE, PE, NE, PE, IN, TE, TP, NE, NE, TE, TE, TE, PE},
            {TE, SE, NE, TE, NE, TE, PE, NE, TE, PE, TE, PE, IN, NE, TE, PE, PE, PE},
            {TE, NE, NE, TE, TE, NE, PE, TE, PE, PE, NE, PE, NE, TE, IN, NE, NE, PE}
        }, {
            {PE, TE, PE, TE, IN, PE, TE, NE, PE, PE, NE, IN, PE, TP, TE, NE, NE, PE},
            {NE, NE, NE, TE, IN, TE, NE, TE, PE, NE, TE, PE, TE, TP, NE, NE, PE, TE},
            {NE, NE, TE, NE, IN, TE, PE, SE, NE, NE, NE, PE, NE, PE, NE, NE, NE, NE},
            {PE, NE, NE, NE, IN, NE, PE, NE, NE, NE, SE, PE, NE, PE, NE, NE, NE, NE},
            {PE, NE, NE, TE, IN, NE, NE, TE, NE, NE, TE, PE, NE, PE, TE, NE, NE, PE},
            {TE, NE, IN, TE, IN, NE, NE, TE, PE, NE, TE, NE, NE, PE, NE, NE, PE, NE},
            {PE, NE, NE, SE, IN, PE, PE, NE, PE, NE, NE, PE, NE, NE, TE, NE, NE, NE},
            {TE, TE, NE, TE, IN, NE, TE, NE, NE, NE, TE, PE, NE, NE, NE, NE, NE, NE},
            {NE, PE, NE, TE, IN, NE, TE, TE, NE, NE, NE, PE, NE, NE, PE, NE, NE, TE},
            {NE, TE, NE, TE, IN, NE, NE, TE, NE, NE, TE, PE, NE, PE, NE, IN, NE, NE},
            {NE, NE, NE, NE, IN, NE, TE, SE, TE, NE, NE, NE, NE, PE, PE, NE, NE, TE},
            {NE, PE, NE, TE, IN, PE, NE, TE, PE, NE, NE, TP, TE, PE, TE, NE, NE, NE},
            {NE, PE, NE, TE, IN, NE, NE, TE, TE, NE, TE, PE, PE, PE, NE, TE, TE, NE},
            {TE, TE, NE, SE, IN, NE, PE, TE, NE, PE, SE, TP, NE, PE, TE, NE, NE, PE},
            {NE, NE, NE, TE, IN, NE, NE, TE, NE, NE, TE, PE, NE, PE, NE, NE, NE, NE},
            {NE, IN, NE, TE, IN, NE, NE, TE, PE, IN, TE, TP, NE, PE, NE, TE, TE, NE},
            {NE, TE, NE, TE, IN, TE, NE, TE, TE, NE, TE, PE, IN, PE, NE, PE, PE, NE},
            {NE, PE, NE, TE, IN, NE, NE, SE, PE, NE, NE, PE, NE, NE, IN, NE, NE, NE}
        }, {
            {PE, IN, PE, NE, NE, PE, TE, PE, TP, IN, PE, IN, PE, PE, TE, TE, TE, PE},
            {NE, IN, NE, NE, NE, TE, NE, NE, TP, IN, NE, PE, TE, PE, NE, TE, NE, TE},
            {NE, IN, TE, PE, PE, TE, PE, TE, PE, IN, PE, PE, NE, NE, NE, TE, TE, NE},
            {PE, IN, NE, PE, TE, NE, PE, PE, PE, IN, TE, PE, NE, NE, NE, TE, TE, NE},
            {PE, IN, NE, NE, PE, NE, NE, NE, PE, IN, NE, PE, NE, NE, TE, TE, TE, PE},
            {TE, IN, IN, NE, NE, NE, NE, NE, TP, IN, NE, NE, NE, NE, NE, TE, NE, NE},
            {PE, IN, NE, TE, NE, PE, PE, PE, TP, IN, PE, PE, NE, TE, TE, TE, TE, NE},
            {TE, IN, NE, NE, NE, NE, TE, PE, PE, IN, NE, PE, NE, TE, NE, TE, TE, NE},
            {NE, IN, NE, NE, NE, NE, TE, NE, PE, IN, PE, PE, NE, TE, PE, TE, TE, TE},
            {NE, IN, NE, NE, NE, NE, NE, NE, PE, IN, NE, PE, NE, NE, NE, IN, TE, NE},
            {NE, IN, NE, PE, PE, NE, TE, TE, NE, IN, PE, NE, NE, NE, PE, TE, TE, TE},
            {NE, IN, NE, NE, NE, PE, NE, NE, TP, IN, PE, TP, TE, NE, TE, TE, TE, NE},
            {NE, IN, NE, NE, NE, NE, NE, NE, NE, IN, NE, PE, PE, NE, NE, SE, SE, NE},
            {TE, IN, NE, TE, NE, NE, PE, NE, PE, IN, TE, TP, NE, NE, TE, TE, TE, PE},
            {NE, IN, NE, TE, IN, NE, NE, TE, PE, IN, TE, TP, NE, PE, NE, TE, TE, NE},
            {NE, IN, NE, NE, NE, NE, NE, NE, PE, IN, NE, PE, NE, NE, NE, TE, TE, NE},
            {NE, IN, NE, NE, NE, TE, NE, NE, NE, IN, NE, PE, IN, NE, NE, NE, NE, NE},
            {NE, IN, NE, NE, TE, NE, NE, TE, TP, IN, PE, PE, NE, TE, IN, TE, TE, NE}
        }, {
            {PE, SE, PE, NE, NE, NE, TE, PE, NE, PE, PE, IN, IN, PE, TE, PE, PE, PE},
            {NE, TE, NE, NE, NE, SE, NE, NE, NE, NE, NE, NE, IN, PE, NE, PE, TP, TE},
            {NE, TE, TE, PE, PE, SE, PE, TE, TE, NE, PE, NE, IN, NE, NE, PE, PE, NE},
            {PE, TE, NE, PE, TE, TE, PE, PE, TE, NE, TE, NE, IN, NE, NE, PE, PE, NE},
            {PE, TE, NE, NE, PE, TE, NE, NE, TE, NE, NE, NE, IN, NE, TE, PE, PE, PE},
            {TE, NE, IN, NE, NE, TE, NE, NE, NE, NE, NE, TE, IN, NE, NE, PE, TP, NE},
            {PE, TE, NE, TE, NE, NE, PE, PE, NE, NE, PE, NE, IN, TE, TE, PE, PE, NE},
            {TE, SE, NE, NE, NE, TE, TE, PE, TE, NE, NE, NE, IN, TE, NE, PE, PE, NE},
            {NE, NE, NE, NE, NE, TE, TE, NE, TE, NE, PE, NE, IN, TE, PE, PE, PE, TE},
            {NE, SE, NE, NE, NE, TE, NE, NE, TE, NE, NE, NE, IN, NE, NE, IN, PE, NE},
            {NE, TE, NE, PE, PE, TE, TE, TE, SE, NE, PE, TE, IN, NE, PE, PE, PE, TE},
            {NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, PE, PE, IN, NE, TE, PE, PE, NE},
            {NE, NE, NE, NE, NE, TE, NE, NE, SE, NE, NE, NE, IN, NE, NE, IN, IN, IN},
            {TE, SE, NE, TE, NE, TE, PE, NE, TE, PE, TE, PE, IN, NE, TE, PE, PE, PE},
            {NE, TE, NE, TE, IN, TE, NE, TE, TE, NE, TE, PE, IN, PE, NE, PE, PE, NE},
            {NE, IN, NE, NE, NE, TE, NE, NE, NE, IN, NE, PE, IN, NE, NE, NE, NE, NE},
            {NE, TE, NE, NE, NE, TE, NE, NE, TE, NE, NE, NE, IN, NE, NE, PE, PE, NE},
            {NE, NE, NE, NE, TE, TE, NE, TE, NE, NE, PE, NE, IN, TE, IN, PE, PE, NE}
        }, {
            {PE, NE, PE, NE, TE, PE, TE, NE, TP, PE, TP, IN, PE, NE, IN, NE, NE, PE},
            {NE, PE, NE, NE, TE, TE, NE, TE, TP, NE, PE, NE, TE, NE, IN, NE, PE, TE},
            {NE, PE, TE, PE, NE, TE, PE, SE, PE, NE, TP, NE, NE, TE, IN, NE, NE, NE},
            {PE, PE, NE, PE, SE, NE, PE, NE, PE, NE, NE, NE, NE, TE, IN, NE, NE, NE},
            {PE, PE, NE, NE, NE, NE, NE, TE, PE, NE, PE, NE, NE, TE, IN, NE, NE, PE},
            {TE, TP, IN, NE, TE, NE, NE, TE, TP, NE, PE, TE, NE, TE, IN, NE, PE, NE},
            {PE, PE, NE, TE, TE, PE, PE, NE, TP, NE, TP, NE, NE, SE, IN, NE, NE, NE},
            {TE, NE, NE, NE, TE, NE, TE, NE, PE, NE, PE, NE, NE, SE, IN, NE, NE, NE},
            {NE, TP, NE, NE, TE, NE, TE, TE, PE, NE, TP, NE, NE, SE, IN, NE, NE, TE},
            {NE, NE, NE, NE, TE, NE, NE, TE, PE, NE, PE, NE, NE, TE, IN, IN, NE, NE},
            {NE, PE, NE, PE, NE, NE, TE, SE, NE, NE, TP, TE, NE, TE, IN, NE, NE, TE},
            {NE, TP, NE, NE, TE, PE, NE, TE, TP, NE, TP, PE, TE, TE, IN, NE, NE, NE},
            {NE, TP, NE, NE, TE, NE, NE, TE, NE, NE, PE, NE, PE, TE, IN, TE, TE, NE},
            {TE, NE, NE, TE, TE, NE, PE, TE, PE, PE, NE, PE, NE, TE, IN, NE, NE, PE},
            {NE, PE, NE, TE, IN, NE, NE, SE, PE, NE, NE, PE, NE, NE, IN, NE, NE, NE},
            {NE, IN, NE, NE, TE, NE, NE, TE, TP, IN, PE, PE, NE, TE, IN, TE, TE, NE},
            {NE, NE, NE, NE, TE, TE, NE, TE, NE, NE, PE, NE, IN, TE, IN, PE, PE, NE},
            {NE, PE, NE, NE, TE, NE, NE, TE, PE, NE, PE, NE, NE, TE, IN, NE, NE, NE}
        }
    };


    float calcEfficacite(int atk, int def1, int def2) {
        int atkI(atk), type1I(def1), type2I(def2);
        if (def2 == Type::NOTHING) {
                return tabUnType[type1I][atkI];
            }
        else {
                return tableDeuxTypes[type1I][type2I][atkI];
            }
    }
}

