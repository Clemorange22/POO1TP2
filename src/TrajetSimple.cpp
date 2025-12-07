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
#include "Trajet.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TrajetSimple::AfficherInline() const
// Algorithme :
//
{
  cout << depart << " --(" << moyenTransport << ")--> " << arrivee;
} // Fin de Afficher

void TrajetSimple::Afficher() const
// Algorithme :
//
{
  AfficherInline();
  cout << endl;
} // Fin de Afficher

void TrajetSimple::AfficherDestinationInline() const
// Algorithme :
//
{
  cout << " --(" << moyenTransport << ")--> " << arrivee;
} // Fin de Afficher

const char* TrajetSimple::getDepart() const
{
  return depart;
}

const char* TrajetSimple::getArrivee() const
{
  return arrivee;
}

//------------------------------------------------- Surcharge d'opérateurs
TrajetSimple &TrajetSimple::operator=(const TrajetSimple &unTrajetSimple)
// Algorithme :
//
{
  if (this == &unTrajetSimple)
    return *this;

  delete[] depart;
  delete[] arrivee;
  delete[] moyenTransport;

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
  strcpy(depart, "");
  strcpy(arrivee, "");
  strcpy(moyenTransport, "");
} //----- Fin de TrajetSimple

TrajetSimple::TrajetSimple(const char *unDepart, const char *unArrivee,
                           const char *unMoyenTransport)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
  depart = new char[strlen(unDepart) + 1];
  arrivee = new char[strlen(unArrivee) + 1];
  moyenTransport = new char[strlen(unMoyenTransport) + 1];
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
