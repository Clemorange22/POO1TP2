#include "TrajetSimple.h"

int main() {
  Trajet **t1;
  //*t1 = new TrajetSimple;
  t1[0] = new TrajetSimple("Plouër sur Rance", "Narvik", "Char à voile");
  // t1[0]->Afficher();
  return 0;
}