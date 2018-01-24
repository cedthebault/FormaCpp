#ifndef FICHEETUDIANT_H
#define FICHEETUDIANT_H

#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

class FicheEtudiant
{
    public:
        FicheEtudiant();
        FicheEtudiant(string nom,string prenom,int numero);
        void Afficher() const;
        void AfficherNomPrenom() const;
        void AjouterNote(double note);
        void AjouterNotes(vector<double> listeNotes);
        virtual ~FicheEtudiant();

    protected:

    private:
        string nom_;
        string prenom_;
        int numero_;
        vector<double> notes_;
};

#endif // FICHEETUDIANT_H
