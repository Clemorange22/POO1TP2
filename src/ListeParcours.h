/*************************************************************************
                           ListeParcours  -  description
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Sami SHAAR - Clément BOITTIN
    e-mail               : clement.boittin@proton.me
*************************************************************************/

//---------- Interface de la classe <ListeParcours> (fichier ListeParcours.h)
//----------------
#if !defined(LISTEPARCOURS_H)
#define LISTEPARCOURS_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeParcours>
//
//
//------------------------------------------------------------------------

class ListeParcours {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------- Surcharge d'opérateurs
  ListeParcours &operator=(const ListeParcours &unListeParcours);
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur
  ListeParcours(const ListeParcours &unListeParcours);
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  ListeParcours();
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~ListeParcours();
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de
//<ListeParcours>

#endif // LISTEPARCOURS_H
