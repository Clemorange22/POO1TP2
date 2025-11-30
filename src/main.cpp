#include "TrajetSimple.h"
#include "Interface.h"
#include "Catalogue.h"

int main() 
// Il suffit d'appeler Interface.mainloop() pour démarrer le programme
{
  Catalogue catalogue;
  Interface interface(&catalogue);
  interface.mainloop();
  //Trajet **t1;
  //*t1 = new TrajetSimple;
  //t1[0] = new TrajetSimple("Plouër sur Rance", "Narvik", "Char à voile");
  // t1[0]->Afficher();
  return 0;
}