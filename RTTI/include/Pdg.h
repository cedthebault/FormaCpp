#ifndef PDG_H
#define PDG_H

#include <Employe.h>


class Pdg : public Employe
{
    public:
        Pdg();
        Pdg(float fixe,float dividende);
        virtual ~Pdg();
        void Salaire();
        void Test();

    protected:
        float dividende_;

    private:
};

#endif // PDG_H
