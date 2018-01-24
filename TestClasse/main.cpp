
#include "Promo.h"

int main()
{
//    FicheEtudiant f = FicheEtudiant("nom","plip",1);
//    f.AjouterNote(10);
//    f.AjouterNote(11);
//    f.AjouterNote(12);
//    f.Afficher();
    Promo *p = new Promo();
    p->AjouterEtudiant("n","p");
    p->AjouterEtudiant("q","r");
    p->EntrerNotes();
    p->AfficherEtudiants();
    return 0;
}
