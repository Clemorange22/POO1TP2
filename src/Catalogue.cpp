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
#include <cstring>
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "ListeParcours.h"
#include "Parcours.h"
#include "Trajet.h"

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
  int i = index - 1;
  Element *ppt = nullptr;
  Element *pt = listeTrajets;
  if (i < nTrajets) {
    for (int j = 0; j < i; j++) {
      ppt = pt;
      pt = pt->next;
    }
    delete pt->trajet;
    if (i != 0) {
      ppt->next = pt->next;
    } else {
      listeTrajets = pt->next;
    }
    delete pt;
    nTrajets--;
  }
};

ListeParcours Catalogue::RechercheVoyageSimple(const char *depart,
                                               const char *arrivee)
// Algorithme :
// parcourir la liste des trajets
// Si depart et arrivee correspondent, afficher le trajet

{
  int cptParcours = 0;
  Parcours parcoursArray[100];
  ListeParcours parcoursTrouves;

  int i;
  Element *pt = listeTrajets;
  for (i = 0; i < nTrajets; i++) {
    if (strcmp(pt->trajet->getDepart(), depart) == 0 &&
        strcmp(pt->trajet->getArrivee(), arrivee) == 0) {
      Parcours p(1, &pt->trajet);
      parcoursArray[cptParcours] = p;
      cptParcours++;
    }

    pt = pt->next;
  }
  parcoursTrouves = ListeParcours(cptParcours, parcoursArray);

  return parcoursTrouves;
};

ListeParcours Catalogue::RechercheVoyageAvancee(const char *depart,
                                                const char *arrivee) const
// Algorithme :
{
  return Catalogue::RechercheVoyageAvancee(depart, arrivee, nullptr, nullptr,
                                           nullptr);
}

ListeParcours Catalogue::RechercheVoyageAvancee(
    const char *depart, const char *arrivee, bool utilise[] = nullptr,
    int **trajetsTrouves = nullptr, int *nTrajetsTrouves = nullptr) const
// Algorithme :
// parcourir la liste des trajets
// pour chaque trajet, si le point de départ correspond, lancer une recherche
// récursive avec comme départ, l'arrivée du précédent, jusqu'à atteindre la
// destination finale Recenser tous les parcours trouvés dans trajetsTrouves

{
  // S'il s'agit de la première exécution, on alloue dynamiquement les tableaux
  // permettant de conserver l'état de la recherche d'un appel à l'autre
  bool first = false;
  if (utilise == nullptr) {
    first = true;
    utilise = new bool[nTrajets];
    for (int i = 0; i < nTrajets; i++)
      utilise[i] = false;
    trajetsTrouves = new int *[nTrajets];
    trajetsTrouves[0] = new int[nTrajets + 1];
    for (int i = 0; i < nTrajets + 1; i++)
      trajetsTrouves[0][i] = -1;
    nTrajetsTrouves = new int;
    *nTrajetsTrouves = 0;
  }

  // On parcours tous les trajets disponibles
  int i;
  for (i = 0; i < nTrajets; i++) {
    if (!utilise[i] && strcmp(getTrajet(i)->getDepart(), depart) == 0) {
      int j = 0;
      while (j < nTrajets && trajetsTrouves[*nTrajetsTrouves][j] != -1)
        j++;
      trajetsTrouves[*nTrajetsTrouves][j] = i;
      utilise[i] = true;
      // Trouvé un trajet qui commence à 'depart'
      if (strcmp(getTrajet(i)->getArrivee(), arrivee) == 0) {
        // C'est un trajet direct, on le garde en mémoire et on utilise un
        // nouveau pointeur pour continuer la recherche
        trajetsTrouves[*nTrajetsTrouves + 1] = new int[nTrajets + 1];
        for (int k = 0; k <= j; k++) {
          trajetsTrouves[*nTrajetsTrouves + 1][k] =
              trajetsTrouves[*nTrajetsTrouves][k];
        }
        for (int k = j + 1; k < nTrajets + 1; k++) {
          trajetsTrouves[*nTrajetsTrouves + 1][k] = -1;
        }
        (*nTrajetsTrouves)++;

        // On revient à l'étape précédente pour chercher d'autres trajets
        trajetsTrouves[*nTrajetsTrouves][j] = -1;
        utilise[i] = false;
      } else {
        // Rechercher des trajets à partir de l'arrivée de ce trajet
        RechercheVoyageAvancee(getTrajet(i)->getArrivee(), arrivee, utilise,
                               trajetsTrouves, nTrajetsTrouves);
      }
    }
  }

  // On convertit les résultats en un objet ListeParcours indépendant de
  // Catalogue
  ListeParcours lp = ListeParcours();
  if (first) {
    Parcours *parcours = new Parcours[*nTrajetsTrouves];
    for (int i = 0; i < *nTrajetsTrouves; i++) {
      int lTrajet = 0;
      while (lTrajet <= nTrajets && trajetsTrouves[i][lTrajet] != -1) {
        lTrajet++;
      }
      Trajet **ptTrajets = new Trajet *[lTrajet];
      for (int j = 0; j < lTrajet; j++) {
        ptTrajets[j] = getTrajet(trajetsTrouves[i][j]);
      }
      parcours[i] = Parcours(lTrajet, ptTrajets);
      delete[] ptTrajets;
    }
    lp = ListeParcours(*nTrajetsTrouves, parcours);
    delete[] parcours;
    delete[] utilise;
    for (int i = 0; i < *nTrajetsTrouves + 1; i++)
      delete[] trajetsTrouves[i];
    delete[] trajetsTrouves;
    delete nTrajetsTrouves;
  }

  return lp;
};

void Catalogue::AjouterTrajet(Trajet *nouveauTrajet)
// Algorithme :
// créer nouvelle liste de la bonne taille
// copie trajets dans nouveau trajets
// ajouter nouveauTrajet à la fin
// supprimer ancienne liste
// incrémente nTrajets

{
  Element *elem = new Element;
  elem->trajet = nouveauTrajet->Copy();
  elem->next = nullptr;

  if (nTrajets == 0) {
    listeTrajets = elem;
  } else {
    int i;
    Element *pt = listeTrajets;
    for (i = 0; i < nTrajets - 1; i++) {
      pt = pt->next;
    }
    pt->next = elem;
  }
  nTrajets++;
};

void Catalogue::Afficher() const {
  int i;
  Element *pt = listeTrajets;
  for (i = 0; i < nTrajets; i++) {
    cout << i + 1 << ": ";
    pt->trajet->Afficher();
    pt = pt->next;
  }
};

int Catalogue::getNTrajets() const { return nTrajets; };

//------------------------------------------------- Surcharge d'opérateurs
Catalogue &Catalogue::operator=(const Catalogue &unCatalogue)
// Algorithme :
//
{
  if (this == &unCatalogue)
    return *this;

  // Suppression des élémément contenus précédemment
  Element *pt = listeTrajets;
  Element *tmp = nullptr;
  while (pt != nullptr) {
    delete pt->trajet;
    tmp = pt->next;
    delete pt;
    pt = tmp;
  }

  nTrajets = unCatalogue.nTrajets;

  Element *unPt = unCatalogue.listeTrajets;

  for (int i = 0; i < nTrajets; i++) {
    if (i == 0) {
      listeTrajets = new Element;
      pt = listeTrajets;
    } else {
      pt->next = new Element;
      pt = pt->next;
    }
    pt->trajet = unPt->trajet->Copy();
    pt->next = nullptr;
    unPt = unPt->next;
  }
  return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue(const Catalogue &unCatalogue)
// Algorithme :
//
{
  nTrajets = unCatalogue.nTrajets;

  Element *pt;
  Element *unPt = unCatalogue.listeTrajets;

  for (int i = 0; i < nTrajets; i++) {
    if (i == 0) {
      listeTrajets = new Element;
      pt = listeTrajets;
    } else {
      pt->next = new Element;
      pt = pt->next;
    }
    pt->trajet = unPt->trajet->Copy();
    pt->next = nullptr;
    unPt = unPt->next;
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
  listeTrajets = nullptr;
#ifdef MAP
  cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue

Catalogue::Catalogue(Trajet *unTrajets[], int unNTrajets)
// Algorithme :
//
{
  nTrajets = unNTrajets;
  Element *pt;

  for (int i = 0; i < nTrajets; i++) {
    if (i == 0) {
      listeTrajets = new Element;
      pt = listeTrajets;
    } else {
      pt->next = new Element;
      pt = pt->next;
    }
    pt->trajet = unTrajets[i]->Copy();
    pt->next = nullptr;
  }

#ifdef MAP
  cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue

Catalogue::~Catalogue()
// Algorithme :
//
{
  Element *pt = listeTrajets;
  Element *tmp = nullptr;
  while (pt != nullptr) {
    delete pt->trajet;
    tmp = pt->next;
    delete pt;
    pt = tmp;
  }

#ifdef MAP
  cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
Trajet *Catalogue::getTrajet(int i) const {
  Element *pt = listeTrajets;
  for (int j = 0; j < i; j++) {
    pt = pt->next;
  }
  return pt->trajet;
}