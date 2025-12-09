#include "Catalogue.h"
#include "Interface.h"
#include "TrajetSimple.h"

int main()
// Il suffit d'appeler Interface.mainloop() pour démarrer le programme
{
  Catalogue catalogue;
  Interface interface(&catalogue);
  interface.mainloop();

  return 0;
}