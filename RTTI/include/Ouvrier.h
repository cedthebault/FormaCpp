#ifndef OUVRIER_H
#define OUVRIER_H

#include <Employe.h>


class Ouvrier : public Employe
{
    public:
        Ouvrier();
        Ouvrier(float sal);
        virtual ~Ouvrier();
        void Salaire();

    protected:

    private:
};

#endif // OUVRIER_H
