#include <iostream>

using namespace std;

class vehicule
{
public:
    vehicule()
    {
        cout<<"constr vehicule"<<endl;
    }
    virtual void start()=0;
};

class voiture:virtual public vehicule
{
public:
voiture():vehicule()
    {
        cout<<"constr voiture"<<endl;
    }
    virtual void start()
    {
        cout<<"voiture demarre"<<endl;
    }
};

class bato:virtual public vehicule
{
public:
bato():vehicule()
    {
        cout<<"constr bato"<<endl;
    }
    virtual void start()
    {
        cout<<"bato demarre"<<endl;
    }
};

class amphibie:virtual public vehicule,public voiture,public bato
{
public:
    amphibie():vehicule(),voiture(),bato()
    {
        cout<<"constr amphibie"<<endl;
    }
    void start()
    {
        cout<<"amphibie demarre"<<endl;
    }
};

int main()
{
    vehicule* amph= new amphibie();
    amph->start();

    vehicule* ba1to= new bato();
    ba1to->start();

    return 0;
}
