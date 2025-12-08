/*************************************************************************
                           TrajetCompose  -  Collection ordonnée de trajets
simples
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Sami SHAAR - Clément BOITTIN
    e-mail               : clement.boittin@proton.me
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h)
//----------------
#if !defined(TRAJETCOMPOSE_H)
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //
  void Afficher() const;

  const char *getDepart() const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  const char *getArrivee() const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  Trajet *Copy() const;
  // Mode d'emploi :
  //
  // Contrat : Crée une copie de l'objet par allocation dynamique et renvoie un
  // pointeur vers cette copie

  //------------------------------------------------- Surcharge d'opérateurs
  TrajetCompose &operator=(const TrajetCompose &unTrajetCompose);
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur
  TrajetCompose(const TrajetCompose &unTrajetCompose);
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  TrajetCompose();
  // Mode d'emploi :
  //
  // Contrat :
  //

  TrajetCompose(const int unLongueur, const TrajetSimple *unTrajets);
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~TrajetCompose();
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
  TrajetSimple *trajets;
  int longueur;
};

//-------------------------------- Autres définitions dépendantes de
//<TrajetCompose>

#endif // TrajetCompose_H
