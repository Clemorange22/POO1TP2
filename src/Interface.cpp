/*************************************************************************
                           Interface  -  description
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Sami SHAAR - Clément BOITTIN
    e-mail               : clement.boittin@proton.me
*************************************************************************/

//---------- Réalisation de la classe <Interface> (fichier Interface.cpp)
//------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <cstring>
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Interface.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes
#define MAX_LENGTH 100
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Interface::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Interface::ajouterTrajetSimple() {
  char *depart = new char[MAX_LENGTH];
  char *moyenTransport = new char[MAX_LENGTH];
  char *arrivee = new char[MAX_LENGTH];

  cout << "Ville de depart : ";
  cin >> depart;
  cout << endl;

  cout << "Moyen de Transport : ";
  cin >> moyenTransport;
  cout << endl;

  cout << "Ville d'Arrivee : ";
  cin >> arrivee;
  cout << endl;

  TrajetSimple *nouveauTrajet =
      new TrajetSimple(depart, arrivee, moyenTransport);
  catalogue->AjouterTrajet(nouveauTrajet);

  delete[] depart;
  delete[] arrivee;
  delete[] moyenTransport;
}

void Interface::ajouterTrajetCompose() {
  int l;
  cout << "Longueur du Trajet Compose : ";
  cin >> l;
  cout << endl;

  TrajetSimple *trajets = new TrajetSimple[l];

  char *depart = new char[MAX_LENGTH];
  char *moyenTransport = new char[MAX_LENGTH];
  char *arrivee = new char[MAX_LENGTH];

  cout << "La ville d'arrivee du trajet i est identique a la ville de depart "
          "du trajet i+1"
       << endl;
  cout << "Ville de depart 1 : ";
  cin >> depart;
  cout << endl;

  int i;
  for (i = 1; i <= l; i++) {

    if (i > 1) {
      strcpy(depart, arrivee);
    }

    cout << "Moyen de Transport " << i << " : ";
    cin >> moyenTransport;
    cout << endl;

    cout << "Ville d'Arrivee " << i << " : ";
    cin >> arrivee;
    cout << endl;

    trajets[i - 1] = TrajetSimple(depart, arrivee, moyenTransport);
  }
  TrajetCompose *nouveauTrajet = new TrajetCompose(l, trajets);
  catalogue->AjouterTrajet(nouveauTrajet);
  delete[] depart;
  delete[] arrivee;
  delete[] moyenTransport;
}

void Interface::suppTrajet()

{

  catalogue->Afficher();
  int index;
  cout << "Index du trajet a supprimer : ";
  cin >> index;
  cout << endl;
  catalogue->SuppTrajet(index);
}

void Interface::choixVilles() {
  char *depart = new char[MAX_LENGTH];
  char *arrivee = new char[MAX_LENGTH];

  cout << "Ville de depart : ";
  cin >> depart;
  cout << endl;

  cout << "Ville d'Arrivee : ";
  cin >> arrivee;
  cout << endl;

  catalogue->RechercheVoyage(depart, arrivee);

  delete[] depart;
  delete[] arrivee;
}

void Interface::choixParcours()
// Afficher les trajets disponibles et demander à l'utilisateur de choisir un
// parcours
{
  catalogue->Afficher();
  cout << "Choisissez votre parcours :" << endl;
}

void Interface::mainloop() {
  int choix = 1;
  while (choix) {
    cout << "Menu Principal :" << endl;
    cout << "1. Ajouter un trajet simple" << endl;
    cout << "2. Ajouter un trajet compose" << endl;
    if (catalogue->getNTrajets() > 0) {
      cout << "3. Supprimer un trajet" << endl;
      cout << "4. Afficher le catalogue" << endl;
    }

    if (catalogue->getNTrajets() >= 2) {
      cout << "5. Rechercher un voyage" << endl;
    }
    cout << "0. Quitter" << endl;
    cout << "Entrez votre choix : ";
    cin >> choix;
    cout << endl;
    if (choix == 1)
      ajouterTrajetSimple();
    else if (choix == 2)
      ajouterTrajetCompose();
    else if (choix == 3 && catalogue->getNTrajets() > 0)
      suppTrajet();
    else if (choix == 4 && catalogue->getNTrajets() > 0)
      catalogue->Afficher();
    else if (choix == 5 && catalogue->getNTrajets() >= 2) {
      choixVilles();
      cout << endl;
      cout << "Parcours trouvés : " << endl;
      choixParcours();
    } else if (choix == 0)
      cout << "Au revoir !" << endl;
    else
      cout << "Choix invalide, veuillez reessayer." << endl;
  }
}

//------------------------------------------------- Surcharge d'opérateurs
Interface &Interface::operator=(const Interface &unInterface)
// Algorithme :
//
{
  if (this == &unInterface)
    return *this;

  catalogue =
      unInterface.catalogue; // On utilise le même catalogue intentionnellement

  return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Interface::Interface(const Interface &unInterface)
// Algorithme :
//
{
  catalogue = unInterface.catalogue;
#ifdef MAP
  cout << "Appel au constructeur de copie de <Interface>" << endl;
#endif
} //----- Fin de Interface (constructeur de copie)

Interface::Interface(Catalogue *unCatalogue)
// Algorithme :
//
{
  catalogue = unCatalogue;
#ifdef MAP
  cout << "Appel au constructeur de <Interface>" << endl;
#endif
} //----- Fin de Interface

Interface::~Interface()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <Interface>" << endl;
#endif
} //----- Fin de ~Interface

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
