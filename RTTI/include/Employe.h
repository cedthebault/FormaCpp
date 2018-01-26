#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <iostream>
using namespace std;

class Employe
{
    public:
        Employe();
        Employe(float salaire);

        virtual ~Employe();
        virtual void Salaire();

    protected:
        float salaireFixe;

    private:
};

#endif // EMPLOYE_H

