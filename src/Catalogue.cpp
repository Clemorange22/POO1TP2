/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Sami SHAAR - Clément BOITTIN
    e-mail               : clement.boittin@proton.me
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp)
//------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Catalogue::Afficher() const {

};

//------------------------------------------------- Surcharge d'opérateurs
Catalogue &Catalogue::operator=(const Catalogue &unCatalogue)
// Algorithme :
//
{
  if (this == &unCatalogue)
    return *this;

  nTrajets = unCatalogue.nTrajets;
  trajets = new Trajet *[nTrajets];
  for (int i = 0; i < nTrajets; i++) {
    trajets[i] = unCatalogue.trajets[i];
  }
  return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue(const Catalogue &unCatalogue)
// Algorithme :
//
{
  nTrajets = unCatalogue.nTrajets;
  trajets = new Trajet *[nTrajets];
  for (int i = 0; i < nTrajets; i++) {
    trajets[i] = unCatalogue.trajets[i];
  }
#ifdef MAP
  cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)

Catalogue::Catalogue()
// Algorithme :
//
{
  nTrajets = 0;
  trajets = new Trajet *[nTrajets];
#ifdef MAP
  cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue

Catalogue::Catalogue(Trajet *unTrajets[], int unNTrajets)
// Algorithme :
//
{
  nTrajets = unNTrajets;
  trajets = new Trajet *[nTrajets];
  for (int i = 0; i < nTrajets; i++) {
    trajets[i] = unTrajets[i];
  }
#ifdef MAP
  cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue

Catalogue::~Catalogue()
// Algorithme :
//
{
  delete[] trajets;
#ifdef MAP
  cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
