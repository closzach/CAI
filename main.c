#include "listes_chainees.h"

int main() {
    int elt = 0;
    ma mes_elements = creer_maillon(elt);

    for (int i=0; i<9; i++) {
        ajouter_maillon_fin(mes_elements, i);
    }

    afficher_tout(mes_elements);
    supprimer_maillon_fin(&mes_elements);
    afficher_tout(mes_elements);

    liberer_tout(&mes_elements);

    return EXIT_SUCCESS;
}
