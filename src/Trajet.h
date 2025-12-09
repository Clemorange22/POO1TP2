/*************************************************************************
                           Trajet  -  Classe virtuelle pour différents types de
trajets
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Sami SHAAR - Clément BOITTIN
    e-mail               : clement.boittin@proton.me
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if !defined(TRAJET_H)
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Permet d'en dériver différent types de trajets par héritage
// Classe abstraite
//
//------------------------------------------------------------------------

class Trajet {
  //----------------------------------------------------------------- PUBLIC

public:
  // Méthodes virtuelles, communes à tous les trajets mais dont l'implémentation
  // est différente
  virtual void Afficher() const = 0;
  // Mode d'emploi :
  // Affiche le trajet sur la sortie standard.
  //
  // Contrat :
  // Méthode virtuelle pure.
  //

  virtual const char *getDepart() const = 0;
  // Mode d'emploi :
  // Renvoie la ville de départ.
  //
  // Contrat :
  // Méthode virtuelle pure.
  //

  virtual const char *getArrivee() const = 0;
  // Mode d'emploi :
  // Renvoie la ville d'arrivée.
  //
  // Contrat :
  // Méthode virtuelle pure.
  //

  virtual Trajet *Copy() const = 0;
  // Mode d'emploi :
  // Crée une copie de l'objet.
  //
  // Contrat :
  // Méthode virtuelle pure.
  //

  //------------------------------------------------- Surcharge d'opérateurs
  Trajet &operator=(const Trajet &unTrajet);
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur
  Trajet(const Trajet &unTrajet);
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  Trajet();
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~Trajet();
  // Mode d'emploi :
  // Destructeur virtuel
  // Contrat :
  // Assure la destruction correcte des objets dérivés.
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
