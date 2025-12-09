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
// Permet d'interagir avec l'utilisateur via une interface en ligne de commande
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

  void ajouterTrajet();
  // Mode d'emploi :
  // Demande à l'utilisateur s'il souhaite ajouter un trajet simple ou composé,
  // puis appelle la méthode correspondante.
  //
  // Contrat :
  //

  void ajouterTrajetSimple();
  // Mode d'emploi :
  // Guide l'utilisateur pour la saisie des informations d'un trajet simple
  // et l'ajoute au catalogue.
  //
  // Contrat :
  //

  void ajouterTrajetCompose();
  // Mode d'emploi :
  // Guide l'utilisateur pour la saisie des informations d'un trajet composé
  // (succession de trajets simples) et l'ajoute au catalogue.
  //
  // Contrat :
  //

  void suppTrajet();
  // Mode d'emploi :
  // Affiche la liste des trajets et demande à l'utilisateur l'index du trajet à
  // supprimer.
  //
  // Contrat :
  //

  void choixVilles();
  // Mode d'emploi :
  // Demande à l'utilisateur les villes de départ et d'arrivée, ainsi que le
  // type de recherche (simple ou avancée), puis lance la recherche et affiche
  // les résultats.
  //
  // Contrat :
  //

  void mainloop();
  // Mode d'emploi :
  // Boucle principale de l'application. Affiche le menu et gère les
  // interactions utilisateur.
  //
  // Contrat :
  //

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
