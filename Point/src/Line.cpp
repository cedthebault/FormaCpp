#include "Line.h"

Line::Line()
{
    p1_=Point();
    p2_=Point();
}

Line::~Line()
{
    //delete p1_;
    //delete p2_;
}

Line::Line(Point *p1,Point *p2){
    p1_=Point(*p1);
    p2_=Point(*p2);
}

void Line::Affiche(){
    cout<<"Ligne de ";
    p1_.AfficheP();
    cout<<" a ";
    p2_.AfficheP();
    cout<<endl;
}

void Line::AfficheAdresse(){
    cout<<"Adresses:"<<endl;
    cout<<"P1: "<<&p1_<<endl;
    p1_.AfficheAdressesXY();
    cout<<"P2: "<<&p2_<<endl;
    p2_.AfficheAdressesXY();

}

float Line::Taille(){
    return sqrt(pow(p2_.getX()-p1_.getX(),2)+pow(p2_.getY()-p1_.getY(),2));
}

float Line::Angle(){
     Point *pP=new Point(p2_.getX(),p1_.getY());

     float angle= asin(p2_.Distance(pP)/this->Taille())*180/M_PI;
     cout << "angle: " << angle<<endl;
     return 0.0;
}
