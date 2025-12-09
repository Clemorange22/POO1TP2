#include "testsTrajetCompose.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

#include <assert.h>
#include <cstring>
#include <iostream>

using namespace std;

int testsTrajetCompose() {
  cout << "--- Initialisation des données de test ---" << endl;
  TrajetSimple ts1 = TrajetSimple("Dol de Bretagne", "Narvik", "Char à voile");
  TrajetSimple ts2 = TrajetSimple("Narvik", "Tokyo", "Luge");
  TrajetSimple ts3 = TrajetSimple("Tokyo", "Rio", "Catamaran");
  TrajetSimple trajets[3] = {ts1, ts2, ts3};

  cout << "--- Test Constructeur avec arguments ---" << endl;
  TrajetCompose *tc1 = new TrajetCompose(3, trajets);

  cout << "--- Test Constructeur de copie ---" << endl;
  TrajetCompose *tc2 = new TrajetCompose(*tc1);

  cout << "--- Test Opérateur d'affectation ---" << endl;
  TrajetCompose *tc3 = new TrajetCompose;
  *tc3 = *tc2;

  cout << "--- Test Afficher (tc1) ---" << endl;
  tc1->Afficher();

  cout << "--- Test Getters (tc1) ---" << endl;
  assert(strcmp(tc1->getDepart(), "Dol de Bretagne") == 0);
  assert(strcmp(tc1->getArrivee(), "Rio") == 0);
  cout << "Getters OK" << endl;

  cout << "--- Nettoyage tc1 ---" << endl;
  delete tc1;

  cout << "--- Test Getters (tc2 - copie de tc1) ---" << endl;
  assert(strcmp(tc2->getDepart(), "Dol de Bretagne") == 0);
  assert(strcmp(tc2->getArrivee(), "Rio") == 0);
  cout << "Getters OK" << endl;

  cout << "--- Nettoyage tc2 ---" << endl;
  delete tc2;

  cout << "--- Test Getters (tc3 - affectation de tc2) ---" << endl;
  assert(strcmp(tc3->getDepart(), "Dol de Bretagne") == 0);
  assert(strcmp(tc3->getArrivee(), "Rio") == 0);
  cout << "Getters OK" << endl;

  cout << "--- Nettoyage tc3 ---" << endl;
  delete tc3;

  return 0;
}