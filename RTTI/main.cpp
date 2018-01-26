
#include "Employe.h"
#include "Commercial.h"
#include "Ouvrier.h"
#include "Pdg.h"


int main()
{
    //cout << "Hello world!" << endl;
    cout << "Employe simple" << endl;
    Employe *e1 = new Employe();
    e1->Salaire();
    cout << "Commercial simple" << endl;
    Commercial *c1 = new Commercial();
    c1->Salaire();
    cout << "Ouvrier simple" << endl;
    Ouvrier *o1 = new Ouvrier();
    o1->Salaire();
    cout << "Pdg simple" << endl;
    Pdg *p1 = new Pdg();
    p1->Salaire();
    delete e1;
    delete c1;
    delete o1;
    delete p1;

    cout<<endl<<"-------------------------"<<endl;

    cout << "Employe init" << endl;
    Employe *e2 = new Employe(111.1);
    e2->Salaire();
    cout << "Commercial init" << endl;
    Commercial *c2 = new Commercial(111.2,30);
    c2->Salaire();
    cout << "Ouvrier init" << endl;
    Ouvrier *o2 = new Ouvrier(111.3);
    o2->Salaire();
    cout << "Pdg init" << endl;
    Pdg *p2 = new Pdg(1200.2,500);
    p2->Salaire();

    delete e2;
    delete c2;
    delete o2;
    delete p2;

    cout<<endl<<"-------------------------"<<endl;
    Employe *t3 = new Pdg(1200.2,500);
    t3->Salaire();
    //Test plante volontairement:
    //t3->Test();


    return 0;
}
