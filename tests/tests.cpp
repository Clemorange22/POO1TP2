#include "testsParcours.h"
#include "testsTrajetCompose.h"
#include "testsTrajetSimple.h"
#include <iostream>

using namespace std;

void printTestName(const char *c) {
  cout << "##### Test de " << c << " #####" << endl;
}

int main() {
  int count = 0;
  printTestName("TrajetSimple");
  count += testsTrajetSimple();
  printTestName("TrajetCompose");
  count += testsTrajetCompose();
  printTestName("Parcours");
  count += testsParcours();

  return count;
}