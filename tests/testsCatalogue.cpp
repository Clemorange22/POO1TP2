#include "Catalogue.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include <iostream>

using namespace std;

int testsCatalogue() {
  cout << "--- Initialisation des données de test ---" << endl;
  // Structures de test
  TrajetSimple *ts1 =
      new TrajetSimple("Dol de Bretagne", "Narvik", "Char à voile");
  TrajetSimple *ts2 = new TrajetSimple("Narvik", "Tokyo", "Luge");
  TrajetSimple *ts3 = new TrajetSimple("Tokyo", "Rio", "Catamaran");

  // Composition pour tc1: Narvik -> Tokyo -> Rio
  TrajetSimple trajetsTC1[2] = {*ts2, *ts3};
  TrajetCompose *tc1 = new TrajetCompose(2, trajetsTC1);

  TrajetSimple *ts4 = new TrajetSimple("New York", "Seattle", "TGV");
  TrajetSimple *ts5 =
      new TrajetSimple("Seattle", "Santiago", "Planche à voile");
  TrajetSimple *ts6 = new TrajetSimple("Santiago", "La Paz", "Lama");

  // Composition pour tc2: Seattle -> La Paz
  TrajetSimple trajetsTC2[2] = {*ts5, *ts6};
  TrajetCompose *tc2 = new TrajetCompose(2, trajetsTC2);

  TrajetSimple *ts7 = new TrajetSimple("La Paz", "Dol de Bretagne", "Planeur");

  cout << "--- Test Constructeur par défaut ---" << endl;
  Catalogue c1;
  c1.Afficher(); // Devrait être vide

  cout << "--- Test AjouterTrajet ---" << endl;
  c1.AjouterTrajet(ts1);
  c1.AjouterTrajet(tc1);
  c1.AjouterTrajet(ts4);
  c1.AjouterTrajet(tc2);
  c1.AjouterTrajet(ts7);

  cout << "--- Test Afficher (Catalogue rempli) ---" << endl;
  c1.Afficher();

  cout << "--- Test RechercheVoyageSimple ---" << endl;
  cout << "Recherche: Dol de Bretagne -> Narvik (Attendu: 1 parcours)" << endl;
  ListeParcours resultSimple1 =
      c1.RechercheVoyageSimple("Dol de Bretagne", "Narvik");
  resultSimple1.Afficher();

  cout << "Recherche: Narvik -> Rio (Attendu: 1 parcours)" << endl;
  ListeParcours resultSimple2 = c1.RechercheVoyageSimple("Narvik", "Rio");
  resultSimple2.Afficher();

  cout << "Recherche: Inconnu -> Inconnu (Attendu: 0 parcours)" << endl;
  ListeParcours resultSimple3 = c1.RechercheVoyageSimple("Inconnu", "Inconnu");
  resultSimple3.Afficher();

  cout << "--- Test RechercheVoyageAvancee ---" << endl;
  // Dol de Bretagne -> Narvik -> Rio (ts1 + tc1)
  cout << "Recherche Avancée: Dol de Bretagne -> Rio (Attendu: au moins 1 "
          "parcours combiné)"
       << endl;
  ListeParcours resultAvancee1 =
      c1.RechercheVoyageAvancee("Dol de Bretagne", "Rio");
  resultAvancee1.Afficher();

  // New York -> Seattle -> La Paz -> Dol de Bretagne -> Narvik (ts4 + tc2 + ts7
  // + ts1)
  cout << "Recherche Avancée: New York -> Narvik (Attendu: au moins 1 parcours "
          "combiné)"
       << endl;
  ListeParcours resultAvancee2 =
      c1.RechercheVoyageAvancee("New York", "Narvik");
  resultAvancee2.Afficher();

  cout << "--- Test Constructeur de copie ---" << endl;
  Catalogue c2(c1);
  cout << "Affichage de la copie :" << endl;
  c2.Afficher();

  cout << "--- Test Opérateur d'affectation ---" << endl;
  Catalogue c3;
  c3 = c1;
  cout << "Affichage du catalogue affecté :" << endl;
  c3.Afficher();

  cout << "--- Test SuppTrajet ---" << endl;

  cout << "Suppression du premier trajet (index 1)" << endl;
  c1.SuppTrajet(1);
  c1.Afficher();

  cout << "--- Nettoyage mémoire ---" << endl;
  delete ts1;
  delete ts2;
  delete ts3;
  delete ts4;
  delete ts5;
  delete ts6;
  delete ts7;
  delete tc1;
  delete tc2;

  return 0;
}
