#include "FicheEtudiant.h"

FicheEtudiant::FicheEtudiant()
{
    //ctor
}

FicheEtudiant::FicheEtudiant(string nom,string prenom,int numero)
{
    nom_=nom;
    prenom_=prenom;
    numero_=numero;
    //notes_
}

FicheEtudiant::~FicheEtudiant()
{
    //Prendre en compte la liste de vector;
}

void FicheEtudiant::Afficher() const
{
    cout << "No : " << numero_ << " - " << nom_ << " - " << prenom_ << endl;
    for(int i =0; i< notes_.size() ; i++)
        cout << notes_[i]<< " " ;
    cout << endl;
}

void FicheEtudiant::AfficherNomPrenom() const
{
    cout << nom_ << " - " << prenom_ << endl;
}

void FicheEtudiant::AjouterNote(double note){
    notes_.push_back(note);
}

void FicheEtudiant::AjouterNotes(vector<double> listeNotes){
    for(int i=0;i<listeNotes.size();i++)
        AjouterNote(listeNotes[i]);
}
