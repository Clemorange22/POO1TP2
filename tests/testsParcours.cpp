#include <assert.h>
#include <cstring>

#include "Parcours.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include "testsParcours.h"

int testsParcours() {

  // Structures de test
  TrajetSimple *ts1 =
      new TrajetSimple("Dol de Bretagne", "Narvik", "Char à voile");
  TrajetSimple *ts2 = new TrajetSimple("Narvik", "Tokyo", "Luge");
  TrajetSimple *ts3 = new TrajetSimple("Tokyo", "Rio", "Catamaran");
  TrajetSimple trajetsTC[2] = {*ts2, *ts3};

  TrajetCompose *tc1 = new TrajetCompose(2, trajetsTC);

  Trajet *trajets[2] = {ts1, tc1};

  Parcours *p1 = new Parcours(2, trajets);
  Parcours *p2 = new Parcours(*p1); // Constructeur de copie
  Parcours *p3 = new Parcours;

  *p3 = *p2; // Opérateur d'assignation

  p1->Afficher(); // Test d'affichage

  delete ts1;
  delete ts2;
  delete ts3;
  delete tc1;

  delete p1;

  // La suppression de p1 ne doit pas impacter p2 et p3
  p2->Afficher();

  delete p2;

  p3->Afficher();

  delete p3;

  return 0;
};