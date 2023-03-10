#include <stdio.h>
#define Pi 3.14

// Implementation de la fonction factorielle
float Perimetre_cercle(int r)
{
    float Peri=r*2*Pi;
// retoruner la variable Peri
    return Peri;
}
void main() {
    printf("Calculer le perimetre d'un cercle!\n");
    int r=4;


    //Appeler la fonction permimetre et afficher le résultat
    printf ("Le perimetre du cercle avec le rayon %d est %f",r, Perimetre_cercle(r));

}
