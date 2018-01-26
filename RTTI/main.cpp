#include <iostream>

using namespace std;

class Employe
{
protected:
    float salaireFixe;
public:
    Employe()
    {
        cout<<"Employe::ConstructeurParDef"<<endl;
        salaireFixe=0;
    }
    Employe(float salaire)
    {
        salaireFixe=salaire;
        cout<<"Employe::ConstructeurSalaire"<<endl;
    }
    virtual ~Employe(){
        cout<<"Employe::DestructeurParDef"<<endl;
    }

    virtual void Salaire()
    {
        cout<<"Employe::Salaire():"<<salaireFixe<<endl;
    }
};

class Commercial :public Employe
{
private:
    float prime_;
public:
    Commercial()
    {
        cout<<"Commercial::ConstructeurParDef"<<endl;
        prime_=0;
    }
    Commercial(float fixe,float prime):Employe(fixe)
    {
        prime_=prime;
        cout<<"Commercial::ConstructeurSalaire"<<endl;
    }
    ~Commercial(){cout<<"Commercial::Destructeur"<<endl;}
    void Salaire()
    {
        cout<<"Commercial::Salaire():"<<salaireFixe+prime_<<endl;
    }
};

class Ouvrier :public Employe
{
public:
    Ouvrier()
    {
        cout<<"Ouvrier::ConstructeurParDef"<<endl;
    }
    Ouvrier(float sal):Employe(sal)
    {
        cout<<"Ouvrier::ConstructeurSalaire"<<endl;
    }
    ~Ouvrier(){cout<<"Ouvrier::Destructeur"<<endl;}
    void Salaire()
    {
        cout<<"Ouvrier::Salaire():"<<salaireFixe<<endl;
    }
};

class Pdg :public Employe
{
private:
    float dividende_;
public:
    Pdg()
    {
        cout<<"Pdg::ConstructeurParDef"<<endl;
        dividende_=0;
    }
    Pdg(float fixe,float dividende):Employe(fixe)
    {
        dividende_=dividende;
        cout<<"Pdg::ConstructeurSalaire"<<endl;
    }
    ~Pdg(){cout<<"Pdg::Destructeur"<<endl;}
    void Salaire()
    {
        cout<<"Pdg::Salaire():"<<salaireFixe+dividende_<<endl;
    }
    void Test()
    {
        cout<<"Pdg::Test():"<<endl;
    }
};

int main()
{
    //cout << "Hello world!" << endl;
    cout << "Employe simple" << endl;
    Employe *e1 = new Employe();
    e1->Salaire();
    cout << "Commercial simple" << endl;
    Commercial *c1 = new Commercial();
    c1->Salaire();
    cout << "Ouvrier simple" << endl;
    Ouvrier *o1 = new Ouvrier();
    o1->Salaire();
    cout << "Pdg simple" << endl;
    Pdg *p1 = new Pdg();
    p1->Salaire();
    delete e1;
    delete c1;
    delete o1;
    delete p1;

    cout<<endl<<"-------------------------"<<endl;

    cout << "Employe init" << endl;
    Employe *e2 = new Employe(111.1);
    e2->Salaire();
    cout << "Commercial init" << endl;
    Commercial *c2 = new Commercial(111.2,30);
    c2->Salaire();
    cout << "Ouvrier init" << endl;
    Ouvrier *o2 = new Ouvrier(111.3);
    o2->Salaire();
    cout << "Pdg init" << endl;
    Pdg *p2 = new Pdg(1200.2,500);
    p2->Salaire();

    delete e2;
    delete c2;
    delete o2;
    delete p2;

    cout<<endl<<"-------------------------"<<endl;
    Employe *t3 = new Pdg(1200.2,500);
    t3->Salaire();
    t3->Test();


    return 0;
}
