/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Clément BOITTIN et Sami SHAAR
    e-mail               : clement.boittin@proton.me
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h)
//----------------
#if !defined(TRAJETSIMPLE_H)
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet {
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
  //
  // Contrat :
  // Affiche les détails du trajet avec un retour à la ligne

  void AfficherInline() const;
  // Mode d'emploi :
  //
  // Contrat :
  // Affiche les détails du trajet sans retour à la ligne

  void AfficherDestinationInline() const;
  // Mode d'emploi :
  //
  // Contrat :
  // Affiche la destination et le moyen de transport du trajet seulement, avec
  // retour à la ligne

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
  TrajetSimple &operator=(const TrajetSimple &unTrajetSimple);
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur
  TrajetSimple(const TrajetSimple &unTrajetSimple);
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  TrajetSimple();
  // Mode d'emploi :
  //
  // Contrat :
  //

  TrajetSimple(const char *unDepart, const char *unArrivee,
               const char *unMoyenTransport);
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~TrajetSimple();
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
  char *depart;
  char *arrivee;
  char *moyenTransport;
};

//-------------------------------- Autres définitions dépendantes de
//<TrajetSimple>

#endif // TrajetSimple_H
