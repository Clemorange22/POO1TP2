#include "ListeParcours.h"
#include "Parcours.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include <iostream>

using namespace std;

int testsListeParcours() {
  cout << "--- Initialisation des données de test ---" << endl;
  // Structures de test
  TrajetSimple *ts1 =
      new TrajetSimple("Dol de Bretagne", "Narvik", "Char à voile");
  TrajetSimple *ts2 = new TrajetSimple("Narvik", "Tokyo", "Luge");
  TrajetSimple *ts3 = new TrajetSimple("Tokyo", "Rio", "Catamaran");
  TrajetSimple trajetsTC1[2] = {*ts2, *ts3};

  TrajetSimple *ts4 = new TrajetSimple("New York", "Seattle", "TGV");
  TrajetSimple *ts5 =
      new TrajetSimple("Seattle", "Santiago", "Planche à voile");
  TrajetSimple *ts6 = new TrajetSimple("Santiago", "La Paz", "Lama");
  TrajetSimple *ts7 = new TrajetSimple("La Paz", "Dol de Bretagne", "Planeur");

  TrajetSimple trajetsTC2[2] = {*ts5, *ts6};

  TrajetCompose *tc1 = new TrajetCompose(2, trajetsTC1);
  TrajetCompose *tc2 = new TrajetCompose(2, trajetsTC2);

  Trajet *trajets1[2] = {ts1, tc1};
  Trajet *trajets2[3] = {ts4, tc2, ts7};

  Parcours *p1 = new Parcours(2, trajets1);
  Parcours *p2 = new Parcours(3, trajets2);

  delete ts1;
  delete ts2;
  delete ts3;
  delete ts4;
  delete ts5;
  delete ts6;
  delete ts7;
  delete tc1;
  delete tc2;

  Parcours parcours[2] = {*p1, *p2};

  cout << "--- Test Constructeur avec arguments ---" << endl;
  ListeParcours *lp1 = new ListeParcours(2, parcours);

  cout << "--- Test Constructeur de copie ---" << endl;
  ListeParcours *lp2 = new ListeParcours(*lp1);

  cout << "--- Test Opérateur d'affectation ---" << endl;
  ListeParcours *lp3 = new ListeParcours;
  *lp3 = *lp2;

  delete p1;
  delete p2;

  cout << "--- Test Afficher (lp1) ---" << endl;
  lp1->Afficher();

  cout << "--- Nettoyage lp1 ---" << endl;
  delete lp1;

  cout << "--- Test Afficher (lp2 - copie de lp1) ---" << endl;
  lp2->Afficher();

  cout << "--- Nettoyage lp2 ---" << endl;
  delete lp2;

  cout << "--- Test Afficher (lp3 - affectation de lp2) ---" << endl;
  lp3->Afficher();

  cout << "--- Nettoyage lp3 ---" << endl;
  delete lp3;

  return 0;
}