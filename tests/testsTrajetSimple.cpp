#include "testsTrajetSimple.h"
#include "TrajetSimple.h"
#include <assert.h>
#include <cstring>

int testsTrajetSimple() {
  TrajetSimple *t1 =
      new TrajetSimple("Dol de Bretagne", "Narvik", "Char à voile");

  t1->Afficher();
  TrajetSimple *t2 = new TrajetSimple(*t1);

  TrajetSimple *t3 = new TrajetSimple;

  *t3 = *t2;

  assert(strcmp(t1->getDepart(), "Dol de Bretagne") == 0);
  assert(strcmp(t1->getArrivee(), "Narvik") == 0);

  delete t1;

  assert(strcmp(t2->getDepart(), "Dol de Bretagne") == 0);
  assert(strcmp(t2->getArrivee(), "Narvik") == 0);

  delete t2;

  assert(strcmp(t3->getDepart(), "Dol de Bretagne") == 0);
  assert(strcmp(t3->getArrivee(), "Narvik") == 0);

  delete t3;

  return 0;
}