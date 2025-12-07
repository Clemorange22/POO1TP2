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
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "Parcours.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Catalogue::SuppTrajet(int index)
// Algorithme :
//  trouver le trajet à l'index donné
 // le supprimer de la liste des trajets
 // ajuster le nombre total de trajets
 // déplacer les trajets suivants pour combler le vide

{
  int i = index -1;
  delete trajets[i];
  for (; i < nTrajets - 1; i++) {
    trajets[i] = trajets[i + 1];
  }
  nTrajets--;
};


void Catalogue::RechercheVoyageSimple(const char * depart, const char * arrivee)
// Algorithme :
//parcourir la liste des trajets
// Si depart et arrivee correspondent, afficher le trajet

{
  int cpt = 0;
  int i;
  for (i = 0; i < nTrajets; i++) 
  {
    if (strcmp(trajets[i]->getDepart(), depart) == 0 &&
        strcmp(trajets[i]->getArrivee(), arrivee) == 0) 
    {
      cpt++;
      cout << "Trajet trouvé " << cpt << ":" << endl;
      trajets[i]->Afficher();
      cout << endl;      
    }
  }
  if (!cpt)
  {
    cout << "Aucun trajet trouvé entre " << depart << " et " << arrivee << "." << endl;
  }
};


void Catalogue::RechercheVoyageAvancee(const char * depart, const char * arrivee)
// Algorithme :
//parcourir la liste des trajets
// pour chaque trajet, si le point de départ correspond, lancer une recherche récursive avec comme départ, l'arrivée du précédent, jusqu'à atteindre la destination finale
// attention aux boucles
// afficher tous les parcours trouvés


{
  static int cpt = 0;
  static Parcours res;
  int i;
  for (i = 0; i < nTrajets; i++) 
  {
    if (strcmp(trajets[i]->getDepart(), depart) == 0) 
    {
      // Trouvé un trajet qui commence à 'depart'
      if (strcmp(trajets[i]->getArrivee(), arrivee) == 0) 
      {
        // C'est un trajet direct
        cpt++;
        cout << "Trajet trouvé " << cpt << ":" << endl;
        trajets[i]->Afficher();
        cout << endl;
      } 
      else 
      {
        // Rechercher des trajets à partir de l'arrivée de ce trajet
        RechercheVoyageAvancee(trajets[i]->getArrivee(), arrivee);
      }
    }
  }

  if (!cpt)
  {
    cout << "Aucun trajet trouvé entre " << depart << " et " << arrivee << "." << endl;
  }

};



void Catalogue::AjouterTrajet(Trajet * nouveauTrajet)
  // Algorithme :
  // créer nouvelle liste de la bonne taille
  // copie trajets dans nouveau trajets
  // ajouter nouveauTrajet à la fin
  // supprimer ancienne liste
  // incrémente nTrajets

{
  Trajet ** nouveauTrajetsArray = new Trajet * [nTrajets + 1];
  int i;
  for (i = 0; i < nTrajets; i++)
  {
    nouveauTrajetsArray[i] = trajets[i];
  }
  nouveauTrajetsArray[nTrajets] = nouveauTrajet;
  delete[] trajets;
  trajets = nouveauTrajetsArray;
  nTrajets++;
};

void Catalogue::Afficher() const 
{
  int i;
  for (i = 0; i < nTrajets; i++)
  {
    cout << i + 1 << " : " << endl;
    trajets[i]->Afficher();
    cout << endl;
  }
};

int Catalogue::getNTrajets() const 
{
  return nTrajets;
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
