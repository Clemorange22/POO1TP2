/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Sami SHAAR - Clément BOITTIN
    e-mail               : clement.boittin@proton.me
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier
// TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TrajetCompose::Afficher() const
//
{
  cout << "Longueur :" << longueur << endl;
  trajets[0].AfficherInline();
  int i;
  for (i = 1; i < longueur; i++) {
    trajets[i].AfficherDestinationInline();
  }
  cout << endl;
} // Fin de Afficher

//------------------------------------------------- Surcharge d'opérateurs
TrajetCompose &TrajetCompose::operator=(const TrajetCompose &unTrajetCompose)
// Algorithme :
//
{
  if (this == &unTrajetCompose)
    return *this;

  longueur = unTrajetCompose.longueur;
  trajets = new TrajetSimple[longueur];
  int i;
  for (i = 0; i < longueur; i++) {
    trajets[i] = unTrajetCompose.trajets[i];
  }

  return *this;

} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(const TrajetCompose &unTrajetCompose)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif

  longueur = unTrajetCompose.longueur;
  trajets = new TrajetSimple[longueur];
  int i;
  for (i = 0; i < longueur; i++) {
    trajets[i] = unTrajetCompose.trajets[i];
  }
} //----- Fin de TrajetCompose (constructeur de copie)

TrajetCompose::TrajetCompose(const int unLongueur, const TrajetSimple *unTrajet)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif

  trajets = new TrajetSimple[unLongueur];
  longueur = unLongueur;
  int i;
  for (i = 0; i < longueur; i++) {
    trajets[i] = unTrajet[i];
  }

} //----- Fin de TrajetCompose

TrajetCompose::TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
  longueur = 0;
  trajets = new TrajetSimple[0];
}

TrajetCompose::~TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
  delete[] trajets;
} //----- Fin de ~TrajetCompose

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
