/*************************************************************************
                           TrajetSimple  -
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Sami SHAAR - Clément BOITTIN
    e-mail               : clement.boittin@proton.me
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp)
//------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <cstring>
#include <iostream>
//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TrajetSimple::Afficher() const
// Algorithme :
//
{
  cout << depart << " --(" << moyenTransport << ")--> " << arrivee << endl;
} // Fin de Afficher

//------------------------------------------------- Surcharge d'opérateurs
TrajetSimple &TrajetSimple::operator=(const TrajetSimple &unTrajetSimple)
// Algorithme :
//
{
  if (this == &unTrajetSimple)
    return *this;

  depart = new char[strlen(unTrajetSimple.depart) + 1];
  arrivee = new char[strlen(unTrajetSimple.arrivee) + 1];
  moyenTransport = new char[strlen(unTrajetSimple.moyenTransport) + 1];

  strcpy(depart, unTrajetSimple.depart);
  strcpy(arrivee, unTrajetSimple.arrivee);
  strcpy(moyenTransport, unTrajetSimple.moyenTransport);

  return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple(const TrajetSimple &unTrajetSimple)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
  depart = new char[strlen(unTrajetSimple.depart) + 1];
  arrivee = new char[strlen(unTrajetSimple.arrivee) + 1];
  moyenTransport = new char[strlen(unTrajetSimple.moyenTransport) + 1];

  strcpy(depart, unTrajetSimple.depart);
  strcpy(arrivee, unTrajetSimple.arrivee);
  strcpy(moyenTransport, unTrajetSimple.moyenTransport);
} //----- Fin de TrajetSimple (constructeur de copie)

TrajetSimple::TrajetSimple()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
  depart = new char[1];
  arrivee = new char[1];
  moyenTransport = new char[1];
  strcpy(depart, "\0");
  strcpy(arrivee, "\0");
  strcpy(moyenTransport, "\0");
} //----- Fin de TrajetSimple

TrajetSimple::TrajetSimple(const char *unDepart, const char *unArrivee,
                           const char *unMoyenTransport)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
  depart = new char[strlen(unDepart)];
  arrivee = new char[strlen(unArrivee)];
  moyenTransport = new char[strlen(unMoyenTransport)];
  strcpy(depart, unDepart);
  strcpy(arrivee, unArrivee);
  strcpy(moyenTransport, unMoyenTransport);
} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
  delete[] depart;
  delete[] arrivee;
  delete[] moyenTransport;
} //----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
