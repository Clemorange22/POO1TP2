#include "TrajetSimple.h"
#include <assert.h>

int testsTrajetSimple() {
  TrajetSimple *t1 =
      new TrajetSimple("Dol de Bretagne", "Narvik", "Char à voile");

  t1->Afficher();
  TrajetSimple *t2 = new TrajetSimple(*t1);

  TrajetSimple *t3 = new TrajetSimple;

  *t3 = *t2;

  delete t1;
  delete t2;
  delete t3;

  return 0;
}