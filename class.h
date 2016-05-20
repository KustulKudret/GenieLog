/**
 * \file class.h
 * \Programme de Calcul de matrices creuses
 * \author DRAME-Arouna & SALIAJ Adrian
 * \version 1
 * \ date 15 Mai 
 * 
 * Programme de gestion de matrice creuse.
 */
 	#ifndef CLASS
	#define CLASS

	#include <iostream>
	#include <string>
/**
 * @brief  Un element de la matrice
 * @details Un element de la matrice composee de l'indice de la ligne L, l'indice de la colonne C, sa valeur V
 * et l'element suivant  
 * 
 */
	struct element
	{
		int L; // Ligne
		int C; // Colonne
		int V; // Valeur
		element * suiv;
	};
/**
 * @brief Classe matrice
 * @details Composee d'un element tete, du nombre de ligne : hauteur et le nombre de colonne :largeur
 * 
 */
	class Matrice
	{
		element * tete;
		int hauteur; // Nombre de lignes
		int largeur; // Nombre de colonnes

		public:
/**
 * @brief Constructeur 1
 * @details Constructeur qui prend en parametre le nombre de ligne et de colonne de la matrice à creer
 * 
 * @param hauteur Correspond au nombre de ligne de la matrice
 * @param largeur Correspond au nombre de colonne de la matrice
 */

			Matrice(int hauteur, int largeur);


/**
 * @brief Constructeur 2
 * @details Ce Constructeur prend en parametre un fichier texte pour creer la matrice
 * 
 * @param nomFichier Corespond au nom du fichier texte 
 */
			Matrice(std::string nomFichier);

			~ Matrice();
/**
 * @brief Fait la multiplication  terme a terme avec la matrice recue en parametre
 * @details [long description]
 * 
 * @param seconde la seconde matrice 
 * @return Retourne NULL si le calcul ne peut pas se faire sinon le resultat de la matrice
 */			

			Matrice * fois(Matrice * seconde);
/**
 * @brief Fait la soustraction avec la matrice recue en parametre
 * @details [long description]
 * 
 * @param seconde la seconde matrice 
 * @return Retourne NULL si le calcul ne peut pas se faire sinon le resultat de la matrice
 */			
			Matrice * moins(Matrice * seconde);
/**
 * @brief Fait l'addition avec la matrice recue en parametre
 * @details [long description]
 * 
 * @param seconde la seconde matrice 
 * @return Retourne NULL si le calcul ne peut pas se faire sinon le resultat de la matrice
 */			
			Matrice * plus(Matrice * seconde);
/**
 * @brief Produit matricel avec  la matrice recue en parametre
 * @details [long description]
* @param seconde la seconde matrice 
 * @return Retourne le resultat de la matrice
 */

			Matrice * produit(Matrice * seconde);
/**
 * @brief Puissance d'une matrice 
 * @details [long description]
* @param P Represente la puissance
 * @return Retourne le resultat de la matrice
 */
 
			Matrice * puissance(int P);
/**
 * @brief Multiplication d'un matrice par un scalaire
 * @details Permet de multiplier une matrice par un scalaire 
 * 
 * @param L La valeur du scalaire
 * @return Retourne le resultat de la matrice
 */			
			Matrice * scalaireFois(int L);
/**
 * @brief Fait la transpose de la matrice 
 * @details [long description]
 */			
			Matrice * transposer();
/**
 * @brief Affiche la matrice
 * @details [long description]
 */

            void afficher(); // Uniquement pour les tests, à supprimer ensuite
/**
 * @brief Ecrit la matrice sur un fichier
 * @details Elle permet d'enregistrer tous les elent de la matrice dans un fichier texte
 * 
 * @param fichier nom du fichier ou sera enregistre la matrice
 * @return Retourne true si l'ecriture c'est bien passe sinon false
 */            

			bool ecrire(std::string fichier); // ecrit les donnees d'une matrice sur un un fichier texte
/**
 * @brief Permet d'inserer dans la matrice
 * @details Cette fonction permet de remplir une matrice deja cree 
 * 
 * @param ligne ligne à la quelle on veut inserer
 * @param colonne colonne à la quelle on veut inserer
 * @param valeur 
 */			
			void inserer(int ligne, int colonne, int valeur);			
/**
 * @brief Permet de supprimer une elelemt de la matrice
 * @details 
 * 
 * @param girafe element à supprimer
 */
        private:
            void supprimer(element * girafe);
			element * vide(int ligne, int colonne);
	};
/**
 * @brief Cree une matrice identité
 * @details Elle est utilisée pour la fonction puissance dans le cas de la puissance 0
 * 
 * @param N dimension de la matrice identité
 * @return Retourne la matrice identité.
 */

    Matrice * identite(int N);

#endif
