
#ifndef NICOLET_LABO29_CPP_UINT_H
#define NICOLET_LABO29_CPP_UINT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <stdexcept>

using std::string;
using std::vector;

class Uint {

public :
    //Constructeurs
    Uint();

    Uint(std::uint64_t varUint64) {
        valeur.clear();
        for (uint64_t i = 1; i <= varUint64; i *= 10) {
            this->valeur.push_back(varUint64 / i % 10);
        }
        //std::reverse(valeur.begin(), valeur.end());
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
    Uint &operator+=(const Uint &addition);

    friend Uint operator+(Uint gauche, const Uint &droite) { return (gauche += droite); }

    Uint &operator++(int) {
        Uint temp = *this;
        temp += 1;
        return (*this = temp);
    }

    Uint &operator++() {
        Uint temp = *this;
        temp += 1;
        return (*this = temp);
    }

    Uint operator-=(const Uint &soustraction);

    friend Uint operator-(Uint gauche, const Uint &droite) { return gauche -= droite; }

    Uint operator*=(const Uint &multiplication);

    friend Uint operator*(Uint gauche, const Uint &droite) { return gauche *= droite; }

    //booléens
    bool operator<(const Uint &droite) const;

    bool operator<=(const Uint &droite) const;

    bool operator>(const Uint &droite) const;

    bool operator>=(const Uint &droite) const;

    bool operator==(const Uint &droite) const;

    bool operator!=(const Uint &droite) const;

    //affectation

    //affichage
    friend std::ostream &operator<<(std::ostream &os, const Uint &a) {
        for (auto k = a.valeur.crbegin(); k != a.valeur.crend(); k++) {
            os << *k;
        }
        return os;
    }

    //fonctions
    //Uint comp(Uint a, Uint b);
    void affichage() {
        std::cout << std::endl;
        std::cout << "le nombre est : ";
        for (int i = valeur.size() - 1; i >= 0; i--) {
            std::cout << valeur.at(i);
        }
        std::cout << std::endl;
    };

    void capacity() {
        std::cout << "--------------" << std::endl;
        std::cout << "la capacity est : ";
        std::cout << valeur.capacity();
        std::cout << std::endl;
        std::cout << "--------------" << std::endl;
    };

    static Uint comp(Uint a, Uint b);

private :
    std::vector<int> valeur;
};


#endif //NICOLET_LABO29_CPP_UINT_H
