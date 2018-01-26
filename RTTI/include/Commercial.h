#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include <Employe.h>


class Commercial : public Employe
{
    public:
        Commercial();
        Commercial(float fixe,float prime);
        virtual ~Commercial();

        void Salaire();
    protected:

    private:
        float prime_;
};

#endif // COMMERCIAL_H

