#include "Line.h"

int main()
{
//    Point *p = new Point();
//    p->Affiche();
//    p->Saisir();
//    p->Affiche();
//    delete p;

//    *p = new Point(3,4);
//    p->Affiche();
    Point *p1,*p2;
    p1=new Point(1,1);
    p2=new Point(2,2);

    p1->Affiche();
    p2->Affiche();

    cout<<p1->Distance(p2)<<endl;
    cout<<p2->Distance(p1)<<endl;

    cout<<"Ligne"<<endl;
    cout<<"Adresse p1 "<<p1<<endl;
    cout<<"Adresse p2 "<<p2<<endl;
    Line *l1;
    l1=new Line(p1,p2);
    l1->Affiche();
    l1->AfficheAdresse();

    return 0;
}
