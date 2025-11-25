/*************************************************************************
                           Interface  -  description
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Sami SHAAR - Clément BOITTIN
    e-mail               : clement.boittin@proton.me
*************************************************************************/

//---------- Interface de la classe <Interface> (fichier Interface.h)
//----------------
#if !defined(INTERFACE_H)
#define INTERFACE_H

//--------------------------------------------------- Interfaces utilisées
#include "Catalogue.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Interface>
//
//
//------------------------------------------------------------------------

class Interface {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //

  void ajouterTrajetSimple();

  void ajouterTrajetCompose();

  void suppTrajet();

  void choixVilles();

  void choixParcours();

  //------------------------------------------------- Surcharge d'opérateurs
  Interface &operator=(const Interface &unInterface);
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur
  Interface(const Interface &unInterface);
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  Interface(Catalogue *unCatalogue);
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~Interface();
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
  Catalogue *catalogue;
};

//-------------------------------- Autres définitions dépendantes de <Interface>

#endif // INTERFACE_H
