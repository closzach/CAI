#include "listes_chainees.h"

ma creer_maillon(int elt) {
    ma maillon = malloc(sizeof(struct maillon));
    maillon->val = elt;
    maillon->suivant = NULL;
    return maillon;
}

void ajouter_maillon_fin(ma maillon, int i) {
    ma maillon_courant = maillon;
    while (maillon_courant->suivant != NULL) {
        maillon_courant = maillon_courant->suivant;
    }
    maillon_courant->suivant = creer_maillon(i);
}

void afficher_tout(ma maillon) {
    printf("[ %d ", maillon->val);
    ma maillon_courant = maillon;
    while (maillon_courant->suivant != NULL) {
        maillon_courant = maillon_courant->suivant;
        printf("%d ", maillon_courant->val);
    }
    printf("]\n");
}

void liberer_tout(ma *maillon) {
    if ((*maillon) != NULL) {
        if ((*maillon)->suivant != NULL) {
            liberer_tout(&(*maillon)->suivant);
        }
        free((*maillon));
        (*maillon) = NULL;
    }
}

void supprimer_maillon_fin(ma *maillon) {
    if (maillon == NULL) {
        return;
    }
    ma maillon_courant = (*maillon);
    ma precedent = (*maillon)->suivant;
    while (maillon_courant->suivant != NULL) {
        precedent = maillon_courant;
        maillon_courant =maillon_courant->suivant;
    }

    free(maillon_courant);
    precedent->suivant = NULL;
}
