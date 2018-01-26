#include <iostream>
#include <string>
//#include <string>
#include <vector>
#include <memory>
using namespace std;

/* **********************************************************************
 * La classe Employe
 */
class Employe {
public:
  Employe(string prenom, string nom, unsigned int age,
          string date)
    : nom(nom), prenom(prenom), age(age), date(date) {}
  virtual ~Employe() {}
  virtual double calculer_salaire()  = 0;
  virtual string get_nom() ;
protected:
   string nom;
   string prenom;
  unsigned int age;
   string date;
};

string Employe::get_nom() { return "L'employé " + prenom + ' ' + nom; }

/* **********************************************************************
 * La classe Commercial (factorise Vendeur et Représentant)
 */
class Commercial : public Employe {
public:
  Commercial(string prenom, string nom, unsigned int age,
             string date, double chiffre_affaire)
    : Employe(prenom, nom, age, date), chiffre_affaire(chiffre_affaire)
  {}

protected:
  double  chiffre_affaire;
};

/* **********************************************************************
 * La classe Vendeur
 */
class Vendeur : public Commercial {
public:
  using Commercial::Commercial;
  double calculer_salaire()  ;
  string get_nom()  ;
};

double Vendeur::calculer_salaire()  {
  return (0.2 * chiffre_affaire) + 400;
}

string Vendeur::get_nom()  {
  return "Le vendeur " + prenom + ' ' + nom;
}

/* **********************************************************************
 * La classe Représentant
 */
class Representant : public Commercial {
public:
  using Commercial::Commercial;
  double calculer_salaire()  ;
  string get_nom()  ;
};

double Representant::calculer_salaire()  {
  return (0.2 * chiffre_affaire) + 800;
}

string Representant::get_nom()  {
  return "Le représentant " + prenom + ' ' + nom;
}

/* **********************************************************************
 * La classe Technicien (Production)
 */
class Technicien: public Employe {
public:
  Technicien(string prenom, string nom, unsigned int age,
             string date, unsigned int unites)
    : Employe(prenom, nom, age, date), unites(unites)
  {}
  double calculer_salaire()  ;
  string get_nom()  ;
protected:
  unsigned int unites;
};

double Technicien::calculer_salaire()  {
   return 5.0 * unites;
}

string Technicien::get_nom()  {
  return "Le technicien " + prenom + ' ' + nom;
}

/* **********************************************************************
 * La classe Manutentionnaire
 */
class Manutentionnaire: public Employe {
public:
  Manutentionnaire(string prenom, string nom, unsigned int age,
                   string date, unsigned int heures)
    : Employe(prenom, nom, age, date), heures(heures)
  {}
  double calculer_salaire()  ;
  string get_nom()  ;
protected:
  unsigned int heures;
};

double Manutentionnaire::calculer_salaire()  {
  return 65.0 * heures;
}

string Manutentionnaire::get_nom()  {
  return "Le manut. " + prenom + ' ' + nom;
}

/* **********************************************************************
 * La classe d'employés à risque
 */
class ARisque {
public:
  ARisque(double prime = 100) : prime(prime) {}
protected:
  double prime;
};

/* **********************************************************************
 * Une première sous-classe d'employés à risque
 */
class TechnARisque : public Technicien, public ARisque {
public:
  TechnARisque(string prenom, string nom, unsigned int age,
               string date, unsigned int unites, double prime)
    : Technicien(prenom, nom, age, date, unites), ARisque(prime)
  {}
  double calculer_salaire()  ;
};

double TechnARisque::calculer_salaire()  {
   return Technicien::calculer_salaire() + prime;
}

/* **********************************************************************
 * Une autre sous-classe d'employés à risque
 */
class ManutARisque: public Manutentionnaire, public ARisque {
public:
  ManutARisque(string prenom, string nom, unsigned int age,
               string date, unsigned int heures, double prime)
    : Manutentionnaire(prenom, nom, age, date, heures), ARisque(prime)
  {}
  double calculer_salaire()  ;
};

double ManutARisque::calculer_salaire()  {
  return Manutentionnaire::calculer_salaire() + prime;
}

/* **********************************************************************
 * La classe Personnel
 */
class Personnel {
public:
  void ajouter_employe(Employe* p) { staff.push_back(unique_ptr<Employe>(p)); }
  void licencie();
  void afficher_salaires() ;
  double salaire_moyen() ;
protected:
  vector<unique_ptr<Employe>> staff;
};

void Personnel::licencie() {
  staff.clear();
}

double Personnel::salaire_moyen()  {
  double somme(0.0);
  for (auto & p : staff) {
    somme += p->calculer_salaire();
  }
  if (staff.size() != 0) somme /= staff.size();
  return somme;
}

void Personnel::afficher_salaires()  {
  for (auto & p : staff) {
    cout << p->get_nom() << " gagne " << p->calculer_salaire() << " francs."
         << endl;
  }
}

// ======================================================================
int main () {
  Personnel p;
  p.ajouter_employe(new Vendeur("Pierre", "Business", 45, "1995", 30000));
  p.ajouter_employe(new Representant("Léon", "Vendtout", 25, "2001", 20000));
  p.ajouter_employe(new Technicien("Yves", "Bosseur", 28, "1998", 1000));
  p.ajouter_employe(new Manutentionnaire("Jeanne", "Stocketout", 32, "1998", 45));
  p.ajouter_employe(new TechnARisque("Jean", "Flippe", 28, "2000", 1000, 200));
  p.ajouter_employe(new ManutARisque("Al", "Abordage", 30, "2001", 45, 120));

  p.afficher_salaires();
  cout << "Le salaire moyen dans l'entreprise est de "
       << p.salaire_moyen() << " francs." << endl;

  // libération mémoire
  p.licencie();
}

