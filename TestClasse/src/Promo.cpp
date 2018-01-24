#include "Promo.h"

Promo::Promo()
{
    nmbEtudiants_=0;
    listeCours_.push_back("math");
    listeCours_.push_back("fr");
    listeCours_.push_back("geo");

}

Promo::~Promo()
{
    //dtor
}

void Promo::AjouterEtudiant(){
    string prenom,nom;
    cout<<"Ajout de l'etudiant"<<endl;
    cout<<"Prenom?"<<endl;
    cin>>prenom;
    cout<<"Nom?"<<endl;
    cin>>nom;
    AjouterEtudiant(nom,prenom);
}

void Promo::AjouterEtudiant(string nom,string prenom){
    listeFiches_.push_back(FicheEtudiant(nom,prenom,++nmbEtudiants_));
}

void Promo::AfficherEtudiants(){
    for(int i=0;i<listeFiches_.size();i++){
        cout<<"Etudiant:"<<endl;
        listeFiches_[i].Afficher();
    }
}

void Promo::EntrerNotes(){
    for(int i=0;i<listeFiches_.size();i++){
        cout << "Pour l'etudiant: ";
        listeFiches_[i].AfficherNomPrenom();
        for(int j=0;j<listeCours_.size();j++){
            cout << "Note en "<<listeCours_[j]<<endl;
            double note;
            cin>>note;
            listeFiches_[i].AjouterNote(note);
        }
    }
}
