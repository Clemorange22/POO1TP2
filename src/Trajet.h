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
//
//------------------------------------------------------------------------

class Trajet {
  //----------------------------------------------------------------- PUBLIC

public:
  virtual void Afficher() const = 0; // Méthode virtuelle
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
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
