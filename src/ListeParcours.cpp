/*************************************************************************
                           ListeParcours  -  description
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Sami SHAAR - Clément BOITTIN
    e-mail               : clement.boittin@proton.me
*************************************************************************/

//---------- Réalisation de la classe <ListeParcours> (fichier
// ListeParcours.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ListeParcours.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ListeParcours::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void ListeParcours::Afficher() const {
  cout << "-----Nombre de parcours : " << nParcours << " -----" << endl;
  int i;
  for (i = 0; i < nParcours; i++) {
    parcours->Afficher();
    cout << endl;
  }
}

//------------------------------------------------- Surcharge d'opérateurs
ListeParcours &ListeParcours::operator=(const ListeParcours &unListeParcours)
// Algorithme :
//
{
  if (this == &unListeParcours) {
    return *this;
  }
  nParcours = unListeParcours.nParcours;
  parcours = new Parcours[nParcours];
  int i;
  for (i = 0; i < nParcours; i++) {
    parcours[i] = unListeParcours.parcours[i];
  }
  return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
ListeParcours::ListeParcours(const ListeParcours &unListeParcours)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <ListeParcours>" << endl;
#endif
  nParcours = unListeParcours.nParcours;
  parcours = new Parcours[nParcours];
  int i;
  for (i = 0; i < nParcours; i++) {
    parcours[i] = unListeParcours.parcours[i];
  }
} //----- Fin de ListeParcours (constructeur de copie)

ListeParcours::ListeParcours(int unNParcours, Parcours *unParcours)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <ListeParcours>" << endl;
#endif
  nParcours = unNParcours;
  parcours = new Parcours[unNParcours];
  int i;
  for (i = 0; i < nParcours; i++) {
    parcours[i] = unParcours[i];
  }
} //----- Fin de ListeParcours

ListeParcours::ListeParcours()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <ListeParcours>" << endl;
#endif
  nParcours = 0;
  parcours = new Parcours[nParcours];
}

ListeParcours::~ListeParcours()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <ListeParcours>" << endl;
#endif
  delete[] parcours;
} //----- Fin de ~ListeParcours

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
