
#ifndef NICOLET_LABO29_CPP_UINT_H
#define NICOLET_LABO29_CPP_UINT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class Uint {

public :
    //Constructeurs
    Uint();

    Uint(uint64_t varUint64) {
        valeur.clear();
        for (uint64_t i = 1; i <= varUint64; i *= 10) {
            this->valeur.push_back(varUint64 / i % 10);
        }
        std::reverse(valeur.begin(), valeur.end());
        valeur.shrink_to_fit();
    }

    Uint(std::string varString) {
        varString.shrink_to_fit();
        valeur.clear();
        for (char i: varString) {
            this->valeur.push_back(i - '0');
        }
        std::reverse(valeur.begin(), valeur.end());
        valeur.shrink_to_fit();
    }

    //Operateurs

    Uint operator+(const Uint &addition) const;

    Uint operator-(const Uint &soustraction) const;

    Uint operator=(const Uint &egalite) const;

    Uint operator*(const Uint &multiplication) const;

    Uint operator<(const Uint &plusPetitQue) const;

    Uint operator<=(const Uint &plusPetitQueEgale) const;

    Uint operator>(const Uint &plusGrandQue) const;

    Uint operator>=(const Uint &plusGrandQueEgale) const;

    Uint operator==(const Uint &valeur) const;

    //fonctions
    //Uint comp(Uint a, Uint b);
    void affichage() {
        std::cout << std::endl << "--------------" << std::endl;

        std::cout << "le nombre est : ";

        for (int i : valeur){
            std::cout << i;
        }


        std::cout << std::endl;

        std::cout << "--------------" << std::endl;
    };

    void capacity() {
        std::cout << "--------------" << std::endl;
        std::cout << "la capacity est : ";
        std::cout << valeur.capacity();
        std::cout << std::endl;
        std::cout << "--------------" << std::endl;
    };

private :
    std::vector<int> valeur;
};


#endif //NICOLET_LABO29_CPP_UINT_H
