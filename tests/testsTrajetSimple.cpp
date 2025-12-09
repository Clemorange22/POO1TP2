#include "testsTrajetSimple.h"
#include "TrajetSimple.h"
#include <assert.h>
#include <cstring>
#include <iostream>

using namespace std;

int testsTrajetSimple() {
  cout << "--- Initialisation des données de test ---" << endl;
  cout << "--- Test Constructeur avec arguments ---" << endl;
  TrajetSimple *t1 =
      new TrajetSimple("Dol de Bretagne", "Narvik", "Char à voile");

  cout << "--- Test Afficher (t1) ---" << endl;
  t1->Afficher();

  cout << "--- Test Constructeur de copie ---" << endl;
  TrajetSimple *t2 = new TrajetSimple(*t1);

  cout << "--- Test Opérateur d'affectation ---" << endl;
  TrajetSimple *t3 = new TrajetSimple;
  *t3 = *t2;

  cout << "--- Test Getters (t1) ---" << endl;
  assert(strcmp(t1->getDepart(), "Dol de Bretagne") == 0);
  assert(strcmp(t1->getArrivee(), "Narvik") == 0);
  cout << "Getters OK" << endl;

  cout << "--- Nettoyage t1 ---" << endl;
  delete t1;

  cout << "--- Test Getters (t2 - copie de t1) ---" << endl;
  assert(strcmp(t2->getDepart(), "Dol de Bretagne") == 0);
  assert(strcmp(t2->getArrivee(), "Narvik") == 0);
  cout << "Getters OK" << endl;

  cout << "--- Nettoyage t2 ---" << endl;
  delete t2;

  cout << "--- Test Getters (t3 - affectation de t2) ---" << endl;
  assert(strcmp(t3->getDepart(), "Dol de Bretagne") == 0);
  assert(strcmp(t3->getArrivee(), "Narvik") == 0);
  cout << "Getters OK" << endl;

  cout << "--- Nettoyage t3 ---" << endl;
  delete t3;

  return 0;
}