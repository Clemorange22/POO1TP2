#include <assert.h>
#include <cstring>
#include <iostream>

#include "Parcours.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include "testsParcours.h"

using namespace std;

int testsParcours() {
  cout << "--- Initialisation des données de test ---" << endl;
  // Structures de test
  TrajetSimple *ts1 =
      new TrajetSimple("Dol de Bretagne", "Narvik", "Char à voile");
  TrajetSimple *ts2 = new TrajetSimple("Narvik", "Tokyo", "Luge");
  TrajetSimple *ts3 = new TrajetSimple("Tokyo", "Rio", "Catamaran");
  TrajetSimple trajetsTC[2] = {*ts2, *ts3};

  TrajetCompose *tc1 = new TrajetCompose(2, trajetsTC);

  Trajet *trajets[2] = {ts1, tc1};

  cout << "--- Test Constructeur avec arguments ---" << endl;
  Parcours *p1 = new Parcours(2, trajets);

  cout << "--- Test Constructeur de copie ---" << endl;
  Parcours *p2 = new Parcours(*p1); // Constructeur de copie

  cout << "--- Test Opérateur d'affectation ---" << endl;
  Parcours *p3 = new Parcours;
  *p3 = *p2; // Opérateur d'assignation

  cout << "--- Test Afficher (p1) ---" << endl;
  p1->Afficher(); // Test d'affichage

  delete ts1;
  delete ts2;
  delete ts3;
  delete tc1;

  cout << "--- Nettoyage p1 ---" << endl;
  delete p1;

  cout << "--- Test Afficher (p2 - copie de p1) ---" << endl;
  // La suppression de p1 ne doit pas impacter p2 et p3
  p2->Afficher();

  cout << "--- Nettoyage p2 ---" << endl;
  delete p2;

  cout << "--- Test Afficher (p3 - affectation de p2) ---" << endl;
  p3->Afficher();

  cout << "--- Nettoyage p3 ---" << endl;
  delete p3;

  return 0;
};