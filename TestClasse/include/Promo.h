#ifndef PROMO_H
#define PROMO_H

#include "FicheEtudiant.h"


class Promo
{
    public:
        Promo();
        virtual ~Promo();
        void AjouterEtudiant();
        void AjouterEtudiant(string nom,string prenom);
        void AfficherEtudiants();
        void EntrerNotes();

    protected:

    private:
        int nmbEtudiants_;
        int nmbCours_;
        vector<string> listeCours_;
        vector<FicheEtudiant> listeFiches_;
};

#endif // PROMO_H
