//
// Created by victo on 12.01.2022.
//

#include "Uint.h"

Uint::Uint() {

}

bool Uint::operator<(const Uint &droite) const { return comp(*this, droite) < -1; }

bool Uint::operator<=(const Uint &droite) const { return comp(*this, droite) == 0 || comp(*this, droite) < -1; }

bool Uint::operator>(const Uint &droite) const { return comp(*this, droite) > 1; }

bool Uint::operator>=(const Uint &droite) const { return comp(*this, droite) == 0 || comp(*this, droite) > 1; }

bool Uint::operator==(const Uint &droite) const { return comp(*this, droite) == 0; }

bool Uint::operator!=(const Uint &droite) const { return comp(*this, droite) != 0; }


Uint &Uint::operator+=(const Uint &addition) {
    Uint temp;
    Uint additionTemp = addition;
    int retenu = 0;

    //test si le vector est egale à 0
    if (valeur.size() == 1 && valeur.at(0) == 0) {
        return (*this = addition);
    }
    if (additionTemp.valeur.size() == 1 && additionTemp.valeur.at(0) == 0) {
        return *this;
    }

    // Permet de resize le vecteur additionner si il est plus petit que l'additionneur
    if (additionTemp.valeur.size() > this->valeur.size()) {
        valeur.resize(additionTemp.valeur.size());
    }
    if (additionTemp.valeur.size() < this->valeur.size()) {
        additionTemp.valeur.resize(valeur.size());
    }

    //addition avec test de retenu
    for (int i = 0; i < this->valeur.size(); i++) {
        if ((this->valeur.at(i) + additionTemp.valeur.at(i) + retenu) >= 10) {
            temp.valeur.push_back((this->valeur.at(i) + additionTemp.valeur.at(i) + retenu) % 10);
            retenu = 1;
        } else {
            temp.valeur.push_back(this->valeur.at(i) + additionTemp.valeur.at(i) + retenu);
            retenu = 0;
        }
    }

    //permet d'ajouter la retenu si présente
    if (retenu != 0) {
        temp.valeur.push_back(retenu);
    }

    return (*this = temp);
}

Uint Uint::operator-=(const Uint &soustraction) {

    Uint temp;
    Uint soustractionTemp = soustraction;
    //a = 100 b = 1000 si 4 > 3 ERROR
    // || a = 100 b = 102 si 100 < 102 ERROR
    //test si le soustracter est plus petit que le soustracteur
    if (this->valeur < soustractionTemp.valeur) {
        throw std::underflow_error("Resultat negatif");
    }

    if (soustraction.valeur == this->valeur) {
        return *this = 0;
    }

    // Permet de resize les vecteur
    if (soustractionTemp.valeur.size() < this->valeur.size()) {
        soustractionTemp.valeur.resize(valeur.size());
    }

    //réglé 192 - 187 (A PATCH !!!!!!!!!!!!!!)
    for (int i = 0; i < this->valeur.size(); i++) {
        if (soustractionTemp.valeur.at(i) > this->valeur.at(i)) {
            this->valeur.at(i + 1) -= 1;
            this->valeur.at(i) += 10;
            temp.valeur.push_back(this->valeur.at(i) - soustractionTemp.valeur.at(i));
        } else if (soustractionTemp.valeur.at(i) == this->valeur.at(i)) {
            temp.valeur.push_back(0);
        } else if (soustractionTemp.valeur.at(i) < this->valeur.at(i)) {
            temp.valeur.push_back(this->valeur.at(i) - soustractionTemp.valeur.at(i));
        }
    }

    size_t j = temp.valeur.size() - 1;

    while (!temp.valeur.at(j)) {
        temp.valeur.pop_back();
        j--;
    }

    return (*this = temp);
}

Uint Uint::operator*=(const Uint &multiplication) {

    Uint digit;
    Uint carry;
    Uint result;

    size_t taille = this->valeur.size() + multiplication.valeur.size();
    digit.valeur.resize(taille);
    carry.valeur.resize(taille);

    // Tester si un des deux nombre est égale à 0
    if ((valeur.size() == 1 && valeur.at(0) == 0) ||
        (multiplication.valeur.size() == 1 && multiplication.valeur.at(0) == 0)) {
        return *this = 0;
    }
    // Ajoute des digits et des carrys
    for (int i = 0; i <= this->valeur.size() - 1; i++) {
        for (int j = 0; j <= multiplication.valeur.size() - 1; j++) {
            digit.valeur.at(i + j) += this->valeur.at(i) * multiplication.valeur.at(j) % 10;
            carry.valeur.at(i + j + 1) += this->valeur.at(i) * multiplication.valeur.at(j) / 10;
        }
    }
    //  Permet de merge les digits et les carrys
    int carrFlag = 0;
    for (int i = 0; i <= taille - 1; i++) {
        int sum = digit.valeur.at(i) + carry.valeur.at(i) + carrFlag;
        result.valeur.push_back(sum % 10);
        carrFlag = sum / 10;
    }
    // Permet d'enlever les zeros en trop
    size_t pos = result.valeur.size() - 1;
    while (!result.valeur.at(pos)) {
        result.valeur.pop_back();
        pos--;
    }

    return (*this = result);
}

Uint Uint::comp(Uint a, Uint b) {
    //permet déjà de comparer les vector selon leur taille
    if (a.valeur.size() > b.valeur.size()) {
        return 1;
    }
    if (a.valeur.size() < b.valeur.size()) {
        return -1;
    }
    if (a.valeur == b.valeur) {
        return 0;
    }
    //compare l'interieur des vector si il sont de taille egale
    for (size_t i = (a.valeur.size() - 1); i >= 0; i--) {
        if (a.valeur.at(i) > b.valeur.at(i)) {
            return 1;
        }
        if (a.valeur.at(i) < b.valeur.at(i)) {
            return -1;
        }
    }
    return 0;
}