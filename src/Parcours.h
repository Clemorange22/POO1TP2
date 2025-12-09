/*************************************************************************
                           Parcours  -  description
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Sami SHAAR - Clément BOITTIN
    e-mail               : clement.boittin@proton.me
*************************************************************************/

//---------- Interface de la classe <Parcours> (fichier Parcours.h)
//----------------
#if !defined(PARCOURS_H)
#define PARCOURS_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Parcours>
//
//
//------------------------------------------------------------------------

class Parcours {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //

  void Afficher() const;
  // Mode d'emploi :
  // Affiche les détails du parcours (nombre de trajets et liste des trajets)
  //
  // Contrat :
  //

  //------------------------------------------------- Surcharge d'opérateurs
  Parcours &operator=(const Parcours &unParcours);
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur
  Parcours(const Parcours &unParcours);
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  Parcours(int unNTrajets, Trajet *unTrajets[]);
  // Mode d'emploi :
  // Crée un parcours composé des trajets passés en argument.
  //
  // Contrat :
  // Les trajets sont copiés (copie profonde).
  //

  Parcours();
  // Constructeur

  virtual ~Parcours();
  // Mode d'emploi :
  // Destructeur. Libère la mémoire allouée pour les trajets.
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

//-------------------------------- Autres définitions dépendantes de <Parcours>

#endif // PARCOURS_H
