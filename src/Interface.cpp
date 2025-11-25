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
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Interface.h"
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

  // catalogue->AjouterTrajetSimple(depart, arrivee, moyenTransport);

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
      depart = arrivee;
    }

    cout << "Moyen de Transport " << i << " : ";
    cin >> moyenTransport;
    cout << endl;

    cout << "Ville d'Arrivee " << i << " : ";
    cin >> arrivee;
    cout << endl;

    trajets[i] = TrajetSimple(depart, arrivee, moyenTransport);
  }

  delete[] depart;
  delete[] arrivee;
  delete[] moyenTransport;
}

void Interface::suppTrajet() {

  catalogue->Afficher();
  int index;
  cout << "Index du trajet a supprimer : ";
  cin >> index;
  cout << endl;
  catalogue->SupprimerTrajet(index);
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

void Interface::choixParcours() {}
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
