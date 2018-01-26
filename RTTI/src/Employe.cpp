#include "Employe.h"

Employe::Employe()
{
    cout<<"Employe::ConstructeurParDef"<<endl;
    salaireFixe=0;
}
Employe::Employe(float salaire)
{
    salaireFixe=salaire;
    cout<<"Employe::ConstructeurSalaire"<<endl;
}
Employe::~Employe()
{
    cout<<"Employe::DestructeurParDef"<<endl;
}

void Employe::Salaire()
{
    cout<<"Employe::Salaire():"<<salaireFixe<<endl;
}
