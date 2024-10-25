#ifndef LISTES_CHAINEES_H
#define LISTES_CHAINEES_H

#include <stdlib.h>
#include <stdio.h>

struct maillon {
    int val;
    struct maillon* suivant;
};

typedef struct maillon* ma;

ma creer_maillon(int elt);
void ajouter_maillon_fin(ma maillon, int i);
void afficher_tout(ma maillon);
void liberer_tout(ma* maillon);
void supprimer_maillon_fin(ma *maillon);

#endif