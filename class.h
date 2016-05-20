/**
 * \file class.h
 * \Programme de Calcul de matrices creuses
 * \author DRAME-Arouna & SALIAJ Adrian
 * \version 1
 * \ date 27
 * 
 * Programme de gestion de gestion de matrice creuse.
 */
#include <iostream>
#include <string>
#ifndef CLASS
#define CLASS

#define PLUS 1
#define MOINS 2
#define FOIS 3
#define DIVISER 4
/**
 * @brief type element contenant 3 valeurs L: indice ligne C: indice colonne et V : la valeur associée
 * @details 
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
 * @details Contient un pointeur de type element
 * 
 * @param hauteur Nombre de ligne de la matrice
 * @param largeur Nombre de colonne de la matrice
 * 
 * @return [description]
 */
class Matrice
{   
	element * tete;
	int hauteur; // Nombre de ligne
	int largeur; // Nombre de colonne
	
	public:
		Matrice(int hauteur, int largeur);
		Matrice(std::string nomFichier);
		~ Matrice();
		Matrice * plus(Matrice * seconde);
		Matrice * moins(Matrice * seconde);
		Matrice * fois(Matrice * seconde);
	    void ecrire(std::string nomFichier);
		void inserer(int ligne, int colonne, int valeur);
		void supprimer(element * girafe);
		void transposer();
		
		element * vide(int ligne, int colonne);
		
		Matrice * produit(Matrice * seconde);
};

#endif