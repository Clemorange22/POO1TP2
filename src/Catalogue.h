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
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
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

  void RechercheVoyage(char * depart, char * arrivee);

  void AjouterTrajet(Trajet * nouveauTrajet);

  void Afficher() const;

  int getNTrajets() const;

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

  virtual ~Catalogue();
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
  Trajet **trajets;
  int nTrajets;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
