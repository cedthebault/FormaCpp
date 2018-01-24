#include "Line.h"

Line::Line()
{
    p1_=Point();
    p2_=Point();
}

Line::~Line()
{
    //dtor
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
    cout<<"Adresses:";
    cout<<"P1: "<<&p1_<<endl;
    cout<<"-- x:"<<(int*)(p1_.getX())<<endl;
    cout<<"-- y:"<<(int*)(p1_.getY())<<endl;
    cout<<"P2: "<<&p2_<<endl;
    cout<<"-- x:"<<(int*)(p2_.getX())<<endl;
    cout<<"-- y:"<<(int*)(p2_.getY())<<endl;

}
