#include "Ouvrier.h"

Ouvrier::Ouvrier()
{
    cout<<"Ouvrier::ConstructeurParDef"<<endl;
}
Ouvrier::Ouvrier(float sal):Employe(sal)
{
    cout<<"Ouvrier::ConstructeurSalaire"<<endl;
}
Ouvrier::~Ouvrier()
{
    cout<<"Ouvrier::Destructeur"<<endl;
}
void Ouvrier::Salaire()
{
    cout<<"Ouvrier::Salaire():"<<salaireFixe<<endl;
}
