#include "Point.h"

Point::Point()
{
    x_=0;
    y_=0;
}
Point::Point(int x,int y)
{
    x_=x;
    y_=y;
}
Point::Point(Point &p)
{
    x_=p.getX();
    y_=p.getY();
}
Point::~Point()
{
    //dtor
}

int Point::getX(){return x_;}

int Point::getY(){return y_;}

void Point::Affiche(){
    cout<<"(x,y):"<<x_<<","<<y_<<endl;
}

void Point::Saisir(){
    cout<<"x?"<<endl;
    cin>>x_;
    cout<<"y?"<<endl;
    cin>>y_;
}

void Point::Translate(int dx,int dy){
    x_+=dx;
    y_+=dy;
}

float Point::Distance(Point *cible){
    return sqrt(pow(cible->getX()-x_,2)+pow(cible->getY()-y_,2));
}
