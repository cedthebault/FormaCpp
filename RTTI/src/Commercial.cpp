#include "Commercial.h"

Commercial::Commercial()
{
    cout<<"Commercial::ConstructeurParDef"<<endl;
    prime_=0;
}
Commercial::Commercial(float fixe,float prime):Employe(fixe)
{
    prime_=prime;
    cout<<"Commercial::ConstructeurSalaire"<<endl;
}
Commercial::~Commercial()
{
    cout<<"Commercial::Destructeur"<<endl;
}
void Commercial::Salaire()
{
    cout<<"Commercial::Salaire():"<<salaireFixe+prime_<<endl;
}
