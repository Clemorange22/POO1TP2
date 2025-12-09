/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Sami SHAAR - Clément BOITTIN
    e-mail               : clement.boittin@proton.me
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h)
//----------------
#if !defined(CATALOGUE_H)
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeParcours.h"
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

typedef struct Element {
  Trajet *trajet = nullptr;
  Element *next = nullptr;
} Element;

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Permet la gestion d'un catalogue de trajets (ajout, suppression, recherche)
//
//------------------------------------------------------------------------

class Catalogue {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //
  void SuppTrajet(int index);
  // Mode d'emploi :
  // Supprime le trajet situé à l'index donné (indexation commençant à 1).
  //
  // Contrat :
  // L'index doit être compris entre 1 et le nombre de trajets.
  //

  ListeParcours RechercheVoyageSimple(const char *depart, const char *arrivee);
  // Mode d'emploi :
  // Recherche les trajets directs (simples ou composés existants tels quels)
  // allant de depart à arrivee.
  //
  // Contrat :
  // Renvoie une liste de parcours contenant les trajets trouvés.
  //

  ListeParcours RechercheVoyageAvancee(const char *depart,
                                       const char *arrivee) const;
  // Mode d'emploi :
  // Recherche tous les parcours possibles (combinaisons de trajets) allant de
  // depart à arrivee. Utilise une recherche en profondeur.
  //
  // Contrat :
  // Renvoie une liste de parcours contenant les solutions trouvées.
  //

  ListeParcours RechercheVoyageAvancee(const char *depart, const char *arrivee,
                                       bool utilise[], int **trajetsTrouves,
                                       int *nTrajetsTrouves) const;

  void AjouterTrajet(Trajet *nouveauTrajet);
  // Mode d'emploi :
  // Ajoute un nouveau trajet au catalogue.
  //
  // Contrat :
  // Le trajet est copié (copie profonde) dans le catalogue.
  //

  void Afficher() const;
  // Mode d'emploi :
  // Affiche le contenu du catalogue
  //
  // Contrat :
  //
  //

  int getNTrajets() const;
  // Mode d'emploi :
  // Renvoie le nombre de trajets dans le catalogue.
  //
  // Contrat :
  //

  //------------------------------------------------- Surcharge d'opérateurs
  Catalogue &operator=(const Catalogue &unCatalogue);
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur
  Catalogue(const Catalogue &unCatalogue);
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  Catalogue();
  // Mode d'emploi :
  //
  // Contrat :
  //

  Catalogue(Trajet *unTrajets[], int unNTrajets);
  // Mode d'emploi :
  // Construit un catalogue à partir d'un tableau de pointeurs vers des trajets.
  //
  // Contrat :
  // Les trajets sont copiés.
  //

  virtual ~Catalogue();
  // Mode d'emploi :
  // Destructeur. Libère la mémoire de tous les trajets du catalogue.
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées
  Trajet *getTrajet(int i) const;

  //----------------------------------------------------- Attributs protégés
  Element *listeTrajets;
  int nTrajets;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
