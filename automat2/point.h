//
// Created by tmKla on 28/01/2023.
//

#ifndef UNTITLED10_POINT_H
#define UNTITLED10_POINT_H

#endif //UNTITLED10_POINT_H
#include "stdlib.h"
#include "stdio.h"
typedef struct point{
    struct voisins* voisinsdispo;
    int nbvoisinsdispo;
    char nom;
}point;
typedef struct voisins{
    point* data;
    struct voisins* next;
}voisins;
typedef struct chemins{
    int nbchemins;
    char chemins [8][2];
}chemins;
point* creer_point(char nom);
voisins* creerVoisins();
chemins* creerChemins();
void relierPoint(point* point1, point* point2, chemins*);
