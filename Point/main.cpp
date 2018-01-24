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
//    p1=new Point(152,164);
//    p2=new Point(278,224);

    p1=new Point(0,0);
    p2=new Point(0,-10);

    p1->Affiche();
    p2->Affiche();

    cout<<p1->Distance(p2)<<endl;
    cout<<p2->Distance(p1)<<endl;

    cout<<"Ligne : "<<endl;
    cout<<"Adresse p1 "<<p1<<endl;
    p1->AfficheAdressesXY();
    cout<<"Adresse p2 "<<p2<<endl;
    p2->AfficheAdressesXY();

    Line *l1;
    l1=new Line(p1,p2);
    l1->Affiche();
    l1->AfficheAdresse();

    cout<<"Taille de la ligne:"<<endl;
    cout<<l1->Taille()<<endl;

    l1->Angle();

    return 0;
}
