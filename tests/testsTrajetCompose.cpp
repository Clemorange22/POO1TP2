#include "testsTrajetCompose.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

#include <assert.h>
#include <cstring>

int testsTrajetCompose() {
  TrajetSimple ts1 = TrajetSimple("Dol de Bretagne", "Narvik", "Char à voile");
  TrajetSimple ts2 = TrajetSimple("Narvik", "Tokyo", "Luge");
  TrajetSimple ts3 = TrajetSimple("Tokyo", "Rio", "Catamaran");
  TrajetSimple trajets[3] = {ts1, ts2, ts3};

  TrajetCompose *tc1 = new TrajetCompose(3, trajets);
  TrajetCompose *tc2 = new TrajetCompose(*tc1);
  TrajetCompose *tc3 = new TrajetCompose;

  *tc3 = *tc2;

  tc1->Afficher();

  assert(strcmp(tc1->getDepart(), "Dol de Bretagne") == 0);
  assert(strcmp(tc1->getArrivee(), "Rio") == 0);

  delete tc1;

  assert(strcmp(tc2->getDepart(), "Dol de Bretagne") == 0);
  assert(strcmp(tc2->getArrivee(), "Rio") == 0);

  delete tc2;

  assert(strcmp(tc3->getDepart(), "Dol de Bretagne") == 0);
  assert(strcmp(tc3->getArrivee(), "Rio") == 0);

  delete tc3;

  return 0;
}