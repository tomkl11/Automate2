#include <stdio.h>
#include "automate.h"
int main() {
    Etat* Automate = creerAutomate("ab",1);
    displayAutomate(Automate->listvoisins->data, creerEtat("P"));



    return 0;
}
