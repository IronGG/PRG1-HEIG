//
// Created by adri405 on 1/10/2022.
//

#include "Uint.h"

//int soustraction(Uint a, Uint b)
//{
//    // Si a est
//
//    if (Uint a -)
//}
//
//
//bool comparaison(Uint a, Uint b)
//{
//    if(a < b)
//    {
//        return -1;
//    }
//    else if(a == b)
//    {
//        return 0;
//    }
//    else
//    {
//        return 1;
//    }
//
//}
Uint Uint::operator+(const Uint &val) const {

    int retenue = 0;
    Uint temp = 0;

    for (int i = 0; i < 499; ++i) {

        if (this->valeur[i] + val.valeur[i] <= 10) {
            temp.valeur[i] = (this->valeur[i] + val.valeur[i]) % 10 + retenue;
            retenue = (this->valeur[i] + val.valeur[i]) / 10;
        } else {
            temp.valeur[i] = this->valeur[i] + val.valeur[i] + retenue;
            retenue = 0;
        }

    }

        return temp;

    }

    //Uint temp;
    //temp.valeur = this->valeur + val.valeur;

    //return temp;

