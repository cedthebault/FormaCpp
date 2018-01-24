#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    public:
        Point();
        Point(int x,int y);
        Point(Point &p);
        virtual ~Point();
        int getX();
        int getY();
        void Affiche();
        void Saisir();
        void Translate(int dx,int dy);
        float Distance(Point *cible);


    protected:

    private:
        int x_;
        int y_;
};

#endif // POINT_H
