/*************************************************************************
                           Interface  -  description
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Sami SHAAR - Clément BOITTIN
    e-mail               : clement.boittin@proton.me
*************************************************************************/

//---------- Réalisation de la classe <Interface> (fichier Interface.cpp)
//------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <cstring>
#include <fstream>
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Interface.h"
#include "ListeParcours.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes
#define MAX_LENGTH 100
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Interface::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Interface::ajouterTrajet()
// Algorithme :
// Demander le type de trajet (simple/compose) pour appeler la méthode
// correspondante
{
  char choix;
  cout << "Trajet Simple ou Compose (S/c) ? ";
  cin >> choix;
  if (choix == 's' || choix == 'S' || choix == '\n') {
    ajouterTrajetSimple();
  } else if (choix == 'c' || choix == 'C') {
    ajouterTrajetCompose();
  } else {
    cout << "Choix invalide, veuillez reessayer." << endl;
    ajouterTrajet();
  }
}

void Interface::ajouterTrajetSimple()
// Algorithme :
// Demander les informations du trajet simple
// Si elles sont confirmées, créer le trajet et l'ajouter au catalogue
{
  char *depart = new char[MAX_LENGTH];
  char *moyenTransport = new char[MAX_LENGTH];
  char *arrivee = new char[MAX_LENGTH];

  cout << "Ville de depart : ";
  cin.getline(depart, MAX_LENGTH);
  cout << endl;

  cout << "Moyen de Transport : ";
  cin.getline(moyenTransport, MAX_LENGTH);
  cout << endl;

  cout << "Ville d'Arrivee : ";
  cin.getline(arrivee, MAX_LENGTH);
  cout << endl;

  TrajetSimple *nouveauTrajet =
      new TrajetSimple(depart, arrivee, moyenTransport);

  while (1) // Gestion de la confirmation
  {
    nouveauTrajet->Afficher();
    cout << "Ce trajet vous semble correct ? [O/n]";
    char confirmation;
    cin >> confirmation;
    if (confirmation == 'n') {
      cout << "Trajet NON ajouté." << endl << endl;
      break;
    } else if (confirmation == 'O' || confirmation == 'o' ||
               confirmation == '\n') {
      cout << "Trajet ajouté." << endl << endl;
      catalogue->AjouterTrajet(nouveauTrajet);
      break;
    } else {
      cout << "Choix invalide, veuillez reessayer." << endl << endl;
    }
  }

  delete nouveauTrajet;
  delete[] depart;
  delete[] arrivee;
  delete[] moyenTransport;
}

void Interface::ajouterTrajetCompose()
// Algorithme :
// Demander les informations du trajet composé
// Si elles sont confirmées, créer le trajet et l'ajouter au catalogue
{
  char carl;
  cout << "Longueur du Trajet Compose (entre 2 et 9 inclus): ";
  cin >> carl;
  cout << endl;
  int l = carl - 48;
  if (l < 2 || l > 9) // Gestion de l'erreur
  {
    cout << "Choix invalide, veuillez reessayer." << endl << endl;
    ajouterTrajetCompose();
    return;
  }

  TrajetSimple *trajets = new TrajetSimple[l];

  char *depart = new char[MAX_LENGTH];
  char *moyenTransport = new char[MAX_LENGTH];
  char *arrivee = new char[MAX_LENGTH];

  cout << "La ville d'arrivee du trajet i est identique a la ville de depart "
          "du trajet i+1"
       << endl;

  cout << "Ville de depart 1 : ";
  cin.getline(depart, MAX_LENGTH);
  cout << endl;
  int i;
  for (i = 1; i <= l; i++) {
    if (i > 1) {
      strcpy(depart, arrivee); // La ville de depart du trajet i est la ville
                               // d'arrivee du trajet i-1
    }

    cout << "Moyen de Transport " << i << " : ";
    cin.getline(moyenTransport, MAX_LENGTH);
    cout << endl;

    cout << "Ville d'Arrivee " << i << " : ";
    cin.getline(arrivee, MAX_LENGTH);
    cout << endl;

    trajets[i - 1] = TrajetSimple(depart, arrivee, moyenTransport);
  }

  TrajetCompose *nouveauTrajet = new TrajetCompose(l, trajets);
  while (1) // Gestion de la confirmation
  {
    nouveauTrajet->Afficher();
    cout << "Ce trajet vous semble correct ? [O/n]";
    char confirmation;
    cin >> confirmation;
    if (confirmation == 'n') {
      cout << "Trajet NON ajouté." << endl << endl;
      break;
    } else if (confirmation == 'O' || confirmation == 'o' ||
               confirmation == '\n') {
      cout << "Trajet ajouté." << endl << endl;
      catalogue->AjouterTrajet(nouveauTrajet);
      break;
    } else {
      cout << "Choix invalide, veuillez reessayer." << endl << endl;
    }
  }

  delete nouveauTrajet;
  delete[] trajets;
  delete[] depart;
  delete[] arrivee;
  delete[] moyenTransport;
}

void Interface::suppTrajet()
// Algorithme :
// Afficher le catalogue
// Demander l'index du trajet à supprimer
// S'il est correct, le supprimer du catalogue
{
  catalogue->Afficher();
  char carIndex;
  int index;

  while (1) {
    cout << "Index du trajet a supprimer (entre 1 et "
         << catalogue->getNTrajets() << ") : ";
    cin >> carIndex;
    index = carIndex - 48; // Conversion de char à int (char 1 = 49 en ASCII)
    cout << endl;
    if (index < 1 || index > catalogue->getNTrajets()) // Gestion de l'erreur
    {
      cout << "Choix invalide, veuillez reessayer." << endl << endl;
    } else {
      catalogue->SuppTrajet(index);
      break;
    }
  }
}

void Interface::choixVilles()
// Algorithme :
// Demander les villes de départ et d'arrivée ainsi que la méthode de recherche
// Lancer la recherche dans le catalogue
{
  char *depart = new char[MAX_LENGTH];
  char *arrivee = new char[MAX_LENGTH];
  char Methode;

  cout << "Ville de depart : ";
  cin.getline(depart, MAX_LENGTH);
  cout << endl;

  cout << "Ville d'arrivee : ";
  cin.getline(arrivee, MAX_LENGTH);
  cout << endl;

  while (1) // Gestion de la méthode de recherche et des erreurs associées
  {
    cout << "Méthode de recherche Simple ou Avancée : (s/a)";
    cin >> Methode;
    cout << endl;
    if (Methode != 's' && Methode != 'a') // Gestion de l'erreur
    {
      cout << "Choix invalide, veuillez reessayer." << endl << endl;
    } else {
      cout << "Rechercher les trajets de " << depart << " a " << arrivee
           << " en recherche " << Methode << endl;
      char confirmation;
      cout << "Confirmer ? [O/n]";
      cin >> confirmation;
      cout << endl;
      if (confirmation == 'O' || confirmation == 'o' || confirmation == '\n') {
        break;
      } else if (confirmation == 'n') {
        cout << "Recherche annulee" << endl << endl;
        return;
      } else {
        cout << "Choix invalide, veuillez reessayer." << endl << endl;
      }
    }
  }

  ListeParcours parcoursTrouves;
  if (Methode == 's') {
    parcoursTrouves = catalogue->RechercheVoyageSimple(depart, arrivee);
  } else {
    parcoursTrouves = catalogue->RechercheVoyageAvancee(depart, arrivee);
  }

  parcoursTrouves.Afficher();

  delete[] depart;
  delete[] arrivee;
}

void Interface::ChargerTxt()
// Algorithme :
{

  // Choix du fichier
  char *nomfichier = new char[MAX_LENGTH];
  cout << "Nom du fichier : ";
  cin.getline(nomfichier, MAX_LENGTH);
  cout << endl;

  char *choix = nullptr;

  // Filtration du type de trajet
  TypeTrajet t;
  cout << "Filtrer selon le type de trajet? [O/n] ";
  cin >> choix;
  cout << endl;
  if (*choix == 'O' || *choix == 'o' || *choix == '\n') {
    cout << "Trajet simple ou compose? [s/c]";
    cin >> choix;
    cout << endl;
    if (*choix == 's') {
      t = SIMPLE;
    } else {
      t = COMPOSE;
    }
  } else {
    t = TOUS;
  }

  // Filtration ville de depart
  char *depart;
  cout << "Filtrer selon la ville de depart? [O/n]";
  cin >> choix;
  cout << endl;
  if (*choix == 'O' || *choix == 'o' || *choix == '\n') {
    depart = new char[MAX_LENGTH];
    cout << "Ville de depart :";
    cin.getline(depart, MAX_LENGTH);
    cout << endl;
  } else {
    depart = nullptr;
  }

  // Filtration ville d'arrivee
  char *arrivee;
  cout << "Filtrer selon la ville d'arrivee? [O/n]";
  cin >> choix;
  cout << endl;
  if (*choix == 'O' || *choix == 'o' || *choix == '\n') {
    arrivee = new char[MAX_LENGTH];
    cout << "Ville d'arrivee :";
    cin.getline(arrivee, MAX_LENGTH);
    cout << endl;
  } else {
    arrivee = nullptr;
  }

  // Selection de trajets :
  cout << "Selectionner des trajets? [O/n]";
  cin >> choix;
  cout << endl;
  int n;
  int m;
  if (*choix == 'O' || *choix == 'o' || *choix == '\n') {
    while (1) {
      cout << "Indice du premier trajet : ";
      cin >> n;
      // Gestion de l'erreur
      if (cin.fail() || n < 0) {
        cin.clear();
        cin.ignore();
        cout << endl;
        cout << "Choix incorrect, veuillez reessayer" << endl;
      } else {
        cout << endl;
        break;
      }
    }

    while (1) {
      cout << "Indice du second trajet : ";
      cin >> m;
      // Gestion de l'erreur
      if (cin.fail() || m < n) {
        cin.clear();
        cin.ignore();
        cout << endl;
        cout << "Choix incorrect, veuillez reessayer" << endl;
      } else {
        cout << endl;
        break;
      }
    }
  } else {
    n = 0;
    m = -1;
  }

  FiltreTrajets filtres;
  filtres.typeTrajet = t;
  filtres.depart = depart;
  filtres.arrivee = arrivee;
  filtres.iMin = n;
  filtres.iMax = m;

  statutCharger res;
  res = catalogue->ChargerTxt(nomfichier, filtres);
  cout << res;
}

void Interface::SauvegarderTxt()
// Algorithme :
{
  // Nom du fichier a ecrire
  cout << "Sauvegarde du catalogue :" << endl;
  char *nomfichier = new char[MAX_LENGTH];
  cout << "Nom du fichier : ";
  cin.getline(nomfichier, MAX_LENGTH);
  cout << endl;

  char *choix = nullptr;

  // Filtration du type de trajet
  TypeTrajet t;
  cout << "Sauvegarder seulement un type de trajet? [O/n] ";
  cin >> choix;
  cout << endl;
  if (*choix == 'O' || *choix == 'o' || *choix == '\n') {
    cout << "Trajet simple ou compose? [s/c]";
    cin >> choix;
    cout << endl;
    if (*choix == 's') {
      t = SIMPLE;
    } else {
      t = COMPOSE;
    }
  } else {
    t = TOUS;
  }

  // Filtration ville de depart
  char *depart;
  cout << "Filtrer selon la ville de depart? [O/n]";
  cin >> choix;
  cout << endl;
  if (*choix == 'O' || *choix == 'o' || *choix == '\n') {
    depart = new char[MAX_LENGTH];
    cout << "Ville de depart :";
    cin.getline(depart, MAX_LENGTH);
    cout << endl;
  } else {
    depart = nullptr;
  }

  // Filtration ville d'arrivee
  char *arrivee;
  cout << "Filtrer selon la ville d'arrivee? [O/n]";
  cin >> choix;
  cout << endl;
  if (*choix == 'O' || *choix == 'o' || *choix == '\n') {
    arrivee = new char[MAX_LENGTH];
    cout << "Ville d'arrivee :";
    cin.getline(arrivee, MAX_LENGTH);
    cout << endl;
  } else {
    arrivee = nullptr;
  }

  // Selection de trajets :
  cout << "Selectionner des trajets? [O/n]";
  cin >> choix;
  cout << endl;
  int n;
  int m;
  if (*choix == 'O' || *choix == 'o' || *choix == '\n') {
    while (1) {
      cout << "Indice du premier trajet : ";
      cin >> n;
      // Gestion de l'erreur
      if (cin.fail() || n < 0) {
        cin.clear();
        cin.ignore();
        cout << endl;
        cout << "Choix incorrect, veuillez reessayer" << endl;
      } else {
        cout << endl;
        break;
      }
    }

    while (1) {
      cout << "Indice du second trajet : ";
      cin >> m;
      // Gestion de l'erreur
      if (cin.fail() || m < n) {
        cin.clear();
        cin.ignore();
        cout << endl;
        cout << "Choix incorrect, veuillez reessayer" << endl;
      } else {
        cout << endl;
        break;
      }
    }
  } else {
    n = 0;
    m = -1;
  }

  FiltreTrajets filtres;
  filtres.typeTrajet = t;
  filtres.depart = depart;
  filtres.arrivee = arrivee;
  filtres.iMin = n;
  filtres.iMax = m;

  statutCharger res;
  res = catalogue->SauvegarderTxt(nomfichier, filtres);
  cout << res;
}

void Interface::mainloop()
// Algorithme :
// Afficher le menu principal
// Gérer les choix de l'utilisateur
{
  char choix = '1';
  cout << "Bienvenue dans le Planificateur de vacances =)" << endl;
  while (choix != '0') {
    if (catalogue->getNTrajets() == 0) {
      cout << "Le catalogue est vide." << endl << endl;
    }
    cout << "--------- Menu Principal : ---------" << endl;
    cout << "1. Ajouter un trajet" << endl;
    cout << "2. Charger depuis une sauvegarde" << endl;
    if (catalogue->getNTrajets() > 0) {
      cout << "3. Supprimer un trajet" << endl;
      cout << "4. Afficher le catalogue" << endl;
      cout << "5. Rechercher un voyage" << endl;
      cout << "6. Sauvegarder le catalogue" << endl;
    }
    cout << "0. Quitter" << endl;
    cout << "------------------------------------" << endl;

    cout << "Entrez votre choix : ";
    cin >> choix;
    cout << endl;
    if (choix == '1') {
      ajouterTrajet();
    } else if (choix == '2') {
      ChargerTxt();
    } else if (choix == '3') {
      suppTrajet();
    } else if (choix == '4' && catalogue->getNTrajets() > 0) {
      catalogue->Afficher();
    } else if (choix == '5' && catalogue->getNTrajets() > 0) {
      choixVilles();
    } else if (choix == '6' && catalogue->getNTrajets() > 0) {
      SauvegarderTxt();
    } else if (choix == '0')
      cout << "Au revoir !" << endl;
    else
      cout << "Choix invalide, veuillez reessayer." << endl << endl;
  }
}

//------------------------------------------------- Surcharge d'opérateurs
Interface &Interface::operator=(const Interface &unInterface)
// Algorithme :
//
{
  if (this == &unInterface)
    return *this;

  catalogue =
      unInterface.catalogue; // On utilise le même catalogue intentionnellement

  return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Interface::Interface(const Interface &unInterface)
// Algorithme :
//
{
  catalogue = unInterface.catalogue;
#ifdef MAP
  cout << "Appel au constructeur de copie de <Interface>" << endl;
#endif
} //----- Fin de Interface (constructeur de copie)

Interface::Interface(Catalogue *unCatalogue)
// Algorithme :
//
{
  catalogue = unCatalogue;
#ifdef MAP
  cout << "Appel au constructeur de <Interface>" << endl;
#endif
} //----- Fin de Interface

Interface::~Interface()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <Interface>" << endl;
#endif
} //----- Fin de ~Interface

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
