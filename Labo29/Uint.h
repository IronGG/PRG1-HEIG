//
// Created by adri405 on 1/10/2022.
//

#ifndef LABO29_UINT_H
#define LABO29_UINT_H

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Uint {

public:
    // Constructeurs
    Uint();
    Uint(std::string stringVal) {

        // TODO: Inverser l'ordre !!

        std::cout << stringVal[0];
        std::cout << stringVal[1];
        std::cout << stringVal[2];
        std::cout << stringVal.length();

        for (int i = 0; i <= stringVal.length() - 1; ++i) {

            std::cout << std::endl;

            this->valeur[i] = stringVal[i] - '0';

            std::cout << stringVal[0];
            std::cout << stringVal[1];
            std::cout << stringVal[2];
            std::cout << "---";
            std::cout << this->valeur[0];
            std::cout << this->valeur[1];
            std::cout << this->valeur[2];
        }

    } // TODO: trouver une solution pour le string


    Uint(uint64_t uintVal) {

        std::cout << "uintVal = " << uintVal % 10 << std::endl;

        int j = 0;
        int temp = 0;
        std::cout << "uintVal = " << uintVal % 10 << std::endl;
        for(int i = 1; i <= uintVal; i *= 10)
        {
            this->valeur[j] = (uintVal / i) % 10;
            //uintVal = uintVal / 10;
            j++;
        }
        //this->valeur = valeur;
    }

    //  constructeur de copie

    // destructeur


    //opérateurs
    Uint operator+(const Uint& valeur) const;
    Uint operator-(const Uint& valeur) const;
    Uint operator=(const Uint& valeur) const;
    Uint operator*(const Uint& valeur) const;

    Uint operator<(const Uint& valeur) const;
    Uint operator<=(const Uint& valeur) const;
    Uint operator>(const Uint& valeur) const;
    Uint operator>=(const Uint& valeur) const;
    Uint operator==(const Uint& valeur) const;

    affichage() {


/*        int x = 0;
        while(valeur[x] != 0)
        {
            std::cout << valeur[x];
            x++;
        }*/

        std::cout << std::endl << "--------------" << std::endl;

        std::cout << "le nombre est : ";

        bool display = false;
        for (int i = 499; i >= 0; i--) {
            if(display){
                std::cout << valeur[i];
            }
            else if(valeur[i] != 0)
            {
                std::cout << valeur[i];
                display = true;
            }
        }

        std::cout << std::endl;

        std::cout << "--------------" << std::endl;
        //std::cout << valeur[0];
        //std::cout << valeur[1];

    };

private:
    int valeur[500] = {0}; // taille a changer ou trouver solution

};


#endif //LABO29_UINT_H
