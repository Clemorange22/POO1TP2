#include "testsParcours.h"
#include "testsTrajetCompose.h"
#include "testsTrajetSimple.h"
#include <iostream>

int main() {
  int count = 0;
  count += testsTrajetSimple();
  count += testsTrajetCompose();
  count += testsParcours();

  return count;
}