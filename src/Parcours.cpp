/*************************************************************************
                           Parcours  -  description
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Sami SHAAR - Clément BOITTIN
    e-mail               : clement.boittin@proton.me
*************************************************************************/

//---------- Réalisation de la classe <Parcours> (fichier Parcours.cpp)
//------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Parcours.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Parcours::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Parcours::Afficher() const {
  cout << "Parcours long de " << nTrajets << " trajets :" << endl;
  int i;
  for (i = 0; i < nTrajets; i++) {
    cout << "Trajet " << i + 1 << ": ";
    trajets[i]->Afficher();
  }
}

//------------------------------------------------- Surcharge d'opérateurs
Parcours &Parcours::operator=(const Parcours &unParcours)
// Algorithme :
//
{
  if (this == &unParcours) {
    return *this;
  }

  for (int i = 0; i < nTrajets; i++) {
    delete trajets[i];
  }
  delete[] trajets;

  nTrajets = unParcours.nTrajets;
  trajets = new Trajet *[nTrajets];
  int i;
  for (i = 0; i < nTrajets; i++) {
    trajets[i] = unParcours.trajets[i]->Copy();
  }
  return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Parcours::Parcours(const Parcours &unParcours)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <Parcours>" << endl;
#endif
  nTrajets = unParcours.nTrajets;
  trajets = new Trajet *[nTrajets];
  int i;
  for (i = 0; i < nTrajets; i++) {
    trajets[i] = unParcours.trajets[i]->Copy();
  }
} //----- Fin de Parcours (constructeur de copie)

Parcours::Parcours(int unNTrajets, Trajet *unTrajets[])
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <Parcours>" << endl;
#endif
  nTrajets = unNTrajets;
  trajets = new Trajet *[nTrajets];
  int i;
  for (i = 0; i < nTrajets; i++) {
    trajets[i] = unTrajets[i]->Copy();
  }
} //----- Fin de Parcours

Parcours::Parcours()
// Constructeur par défaut
{
#ifdef MAP
  cout << "Appel au constructeur de <Parcours>" << endl;
#endif
  trajets = nullptr;
  nTrajets = 0;
}

Parcours::~Parcours()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <Parcours>" << endl;
#endif
  if (trajets != nullptr) {
    for (int i = 0; i < nTrajets; i++) {
      delete trajets[i];
    }
  }
  delete[] trajets;
} //----- Fin de ~Parcours

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
