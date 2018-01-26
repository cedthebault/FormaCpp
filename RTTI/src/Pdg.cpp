#include "Pdg.h"

Pdg::Pdg()
{
    cout<<"Pdg::ConstructeurParDef"<<endl;
    dividende_=0;
}
Pdg::Pdg(float fixe,float dividende):Employe(fixe)
{
    dividende_=dividende;
    cout<<"Pdg::ConstructeurSalaire"<<endl;
}
Pdg::~Pdg()
{
    cout<<"Pdg::Destructeur"<<endl;
}
void Pdg::Salaire()
{
    cout<<"Pdg::Salaire():"<<salaireFixe+dividende_<<endl;
}
void Pdg::Test()
{
    cout<<"Pdg::Test():"<<endl;
}
