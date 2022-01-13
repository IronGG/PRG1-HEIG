#include <iostream>
#include "Uint.h"
#include <string>

using namespace std;

int main() {


    Uint testUint(543);
    Uint testString("356");

    testUint.affichage();
    testString.affichage();

    return 0;

}