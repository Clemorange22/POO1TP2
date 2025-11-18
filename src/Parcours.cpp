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

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Parcours::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Parcours &Parcours::operator=(const Parcours &unParcours)
// Algorithme :
//
{} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Parcours::Parcours(const Parcours &unParcours)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <Parcours>" << endl;
#endif
} //----- Fin de Parcours (constructeur de copie)

Parcours::Parcours()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <Parcours>" << endl;
#endif
} //----- Fin de Parcours

Parcours::~Parcours()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <Parcours>" << endl;
#endif
} //----- Fin de ~Parcours

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
