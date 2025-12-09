/*************************************************************************
                           TrajetSimple  -  Un trajet avec un départ, un moyende
transport et une arrivée
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
// Représente un trajet d'un endroit à un autre avec un moyen de transport donné
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
  // Affiche le trajet simple sur la sortie standard avec un retour à la ligne.
  // Format : Depart --(MoyenTransport)--> Arrivee
  //
  // Contrat :
  //

  void AfficherInline() const;
  // Mode d'emploi :
  // Affiche le trajet simple sur la sortie standard sans retour à la ligne.
  // Format : Depart --(MoyenTransport)--> Arrivee
  //
  // Contrat :
  //

  void AfficherDestinationInline() const;
  // Mode d'emploi :
  // Affiche la destination et le moyen de transport sans retour à la ligne.
  // Format : --(MoyenTransport)--> Arrivee
  //
  // Contrat :
  //

  const char *getDepart() const;
  // Mode d'emploi :
  // Renvoie un pointeur vers la chaîne de caractères représentant la ville de
  // départ.
  //
  // Contrat :
  //

  const char *getArrivee() const;
  // Mode d'emploi :
  // Renvoie un pointeur vers la chaîne de caractères représentant la ville
  // d'arrivée.
  //
  // Contrat :
  //

  Trajet *Copy() const;
  // Mode d'emploi :
  // Crée une copie profonde du TrajetSimple.
  //
  // Contrat :
  // L'appelant est responsable de la gestion de la mémoire de l'objet retourné
  // (delete).
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
  // Construit un TrajetSimple avec les villes de départ, d'arrivée et le moyen
  // de transport spécifiés.
  //
  // Contrat :
  // Les chaînes de caractères sont copiées profondément.
  //

  virtual ~TrajetSimple();
  // Mode d'emploi :
  //
  //
  // Contrat :
  //
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
