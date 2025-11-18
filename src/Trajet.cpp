/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Sami SHAAR - Clément BOITTIN
    e-mail               : clement.boittin@proton.me
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
Trajet &Trajet::operator=(const Trajet &unTrajet)
// Algorithme :
//
{

  return *this;

} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet(const Trajet &unTrajet)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
} //----- Fin de Trajet (constructeur de copie)

Trajet::Trajet()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet

Trajet::~Trajet()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
