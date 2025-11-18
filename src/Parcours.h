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

  Parcours();
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~Parcours();
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Parcours>

#endif // PARCOURS_H
