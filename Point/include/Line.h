#ifndef LINE_H
#define LINE_H

#include "Point.h"

class Line
{
    public:
        Line();
        Line(Point *p1,Point *p2);
        virtual ~Line();
        void Affiche();
        void AfficheAdresse();

    protected:

    private:
    Point p1_,p2_;
};

#endif // LINE_H
