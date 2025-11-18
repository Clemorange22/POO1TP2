/*************************************************************************
                           ListeParcours  -  description
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Sami SHAAR - Clément BOITTIN
    e-mail               : clement.boittin@proton.me
*************************************************************************/

//---------- Réalisation de la classe <ListeParcours> (fichier
//ListeParcours.cpp) ------------

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

//------------------------------------------------- Surcharge d'opérateurs
ListeParcours &ListeParcours::operator=(const ListeParcours &unListeParcours)
// Algorithme :
//
{} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
ListeParcours::ListeParcours(const ListeParcours &unListeParcours)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <ListeParcours>" << endl;
#endif
} //----- Fin de ListeParcours (constructeur de copie)

ListeParcours::ListeParcours()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <ListeParcours>" << endl;
#endif
} //----- Fin de ListeParcours

ListeParcours::~ListeParcours()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <ListeParcours>" << endl;
#endif
} //----- Fin de ~ListeParcours

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
