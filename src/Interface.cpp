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
#include "Interface.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Interface::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Interface &Interface::operator=(const Interface &unInterface)
// Algorithme :
//
{} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Interface::Interface(const Interface &unInterface)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <Interface>" << endl;
#endif
} //----- Fin de Interface (constructeur de copie)

Interface::Interface()
// Algorithme :
//
{
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
