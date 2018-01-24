#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

using namespace std;

struct FicheEtudiant{
string nom,prenom;
int numero;
vector<double> notes;
};

void Afficher(const FicheEtudiant &v )
{
    cout << "No : " << v.numero << " - " << v.prenom << endl;
    for(int i =0; i< v.notes.size() ; i++)
    cout << v.notes[i]<< " " ;
    cout << endl;
}

int main()
{
    cout << "Hello world!" << endl;

    FicheEtudiant fiche;

    fiche.nom = "Taki s";
    fiche.prenom = "Jean";
    fiche.numero = 1234;
    fiche.notes.push_back(12.3);
    fiche.notes.push_back(12.4);

    Afficher(fiche);

    return 0;
}
