//
// Created by adri405 on 1/10/2022.
//

#ifndef LABO29_UINT_H
#define LABO29_UINT_H


class Uint {


public:
    // Constructeurs
    Uint(int a) { valeur = a*2;};
    Uint(string valeur) { this->valeur = valeur*2;}; // TODO: trouver une solution pour le string
    Uint(uint64_t valeur) { this->valeur = valeur*2;};

    //  constructeur de copie

    // destructeur

    int addition(Uint a, Uint b);
    int show() { return valeur; }
    int soustraction(Uint a, Uint b);
    bool comparaison(Uint a, Uint b);

private:
    int valeur = 2;

};


#endif //LABO29_UINT_H
