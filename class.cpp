/**
 * \file class.cpp
 * \Programme de Calcul de matrices creuses
 * \author DRAME-Arouna & SALIAJ Adrian
 * \version 1
 * \ date 27
 * 
 * Programme de gestion de gestion de matrice creuse.
 */
 
#include "class.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
/**
 * @brief Constructeur 1
 * @details Constructeur qui prend en parametre le nombre de ligne et de colonne de la matrice à creer
 * 
 * @param hauteur Correspond au nombre de ligne de la matrice
 * @param largeur Correspond au nombre de colonne de la matrice
 */
Matrice::Matrice(int hauteur, int largeur)
{
	// Constructeur 1
	// Crée une matrice vide
	tete = NULL;
	this -> hauteur = hauteur;
	this -> largeur = largeur;
}
/**
 * @brief Constructeur 2
 * @details Ce Constructeur prend en parametre un fichier texte pour creer la matrice
 * 
 * @param nomFichier Corespond au nom du fichier texte 
 */

Matrice::Matrice(string nomFichier)
{
	// Constructeur 2
	// Crée une matrice à partir d'un fichier
	tete = NULL;
	string tmp1,tmp2,tmp3;
	
	ifstream fichier(nomFichier.c_str());
	if (fichier)
	{
			string contenu;
			fichier >> contenu;
		    hauteur = atoi(&contenu[0]);
		    fichier >> contenu;
		    largeur = atoi(&contenu[0]);
	        while(fichier >> contenu)
		{
			tmp1=contenu;
			fichier >> contenu; tmp2=contenu;
			fichier >> contenu; tmp3=contenu;
			inserer(atoi(&tmp1[0]), atoi(&tmp2[0]), atoi(&tmp3[0])); 
		}
	}
	else
	{
			cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }	
		
}
/**
 * @brief Le destrecteur
 * @details [long description]
 * @return [description]
 */
Matrice::~Matrice()
{
	// Destructeur
	element * tmp = tete;
	
	while(tete != NULL)
	{
		tete = tete -> suiv;
		delete tmp;
		tmp = tete;
	}
}
/**
 * @brief Permet d'inserer dans la matrice
 * @details Cette fonction permet de remplir une matrice deja crée 
 * 
 * @param ligne ligne à la quelle on veut inserer
 * @param colonne colonne à la quelle on veut inserer
 * @param valeur 
 */
void Matrice::inserer(int ligne, int colonne, int valeur)
{
	// Insére l'élément en tête de liste
	if(ligne < hauteur && colonne < largeur && ligne  >=0 , colonne >= 0)
	{
		if(vide(ligne, colonne) == NULL)
		{
			element * tmp = new element;
			tmp -> L = ligne;
			tmp -> C = colonne;
			tmp -> V = valeur;
			tmp -> suiv = tete;
			tete = tmp;
		}
}
}
/**
 * @brief Fait la transposé de la matrice 
 * @details [long description]
 */
void Matrice::transposer()
{
	// Transpose la matrice
	element * tmp = tete;
	
	while(tmp != NULL)
	{
		int tmpL = tmp -> L;
		tmp -> L = tmp -> C;
		tmp -> C = tmpL;
		tmp = tmp->suiv;
	}
	
	int temp = largeur;
	largeur = hauteur;
	hauteur = temp;
}
/**
 * @brief Fait l'addition avec la matrice recue en parametre
 * @details [long description]
 * 
 * @param seconde la seconde matrice 
 * @return Retourne NULL si le calcul ne peut pas se faire sinon le resultat de la matrice
 */
Matrice * Matrice::plus(Matrice * seconde)
{
	// Addition terme à terme de deux matrices
	if(hauteur == seconde -> hauteur and largeur == seconde -> largeur)
	{
		Matrice * res = new Matrice(hauteur, largeur);
		
		for(element * tmp = tete; tmp != NULL; tmp = tmp -> suiv)
		{
			res -> inserer(tmp -> L, tmp -> C, tmp -> V);
		}
		
		for(element * tmp = seconde -> tete; tmp != NULL; tmp = tmp -> suiv)
		{
			element * tmp2 = res -> vide(tmp -> L, tmp -> C);
			
			if(tmp2 == NULL)
			{
				res -> inserer(tmp -> L, tmp -> C, tmp -> V);
			}
			else
			{
				tmp2 -> V += tmp -> V;
				
				if(tmp2 -> V == 0)
					supprimer(tmp2);
			}
		}
		
		return res;
	}
	
	return NULL;
}
/**
 * @brief Fait la soustraction avec la matrice recue en parametre
 * @details [long description]
 * 
 * @param seconde la seconde matrice 
 * @return Retourne NULL si le calcul ne peut pas se faire sinon le resultat de la matrice
 */

Matrice * Matrice::moins(Matrice * seconde)
{
	// Soustrait terme à terme de deux matrices
	if(hauteur == seconde -> hauteur and largeur == seconde -> largeur)
	{
		Matrice * res = new Matrice(hauteur, largeur);
		
		for(element * tmp = tete; tmp != NULL; tmp = tmp -> suiv)
		{
			res -> inserer(tmp -> L, tmp -> C, tmp -> V);
		}
		
		for(element * tmp = seconde -> tete; tmp != NULL; tmp = tmp -> suiv)
		{
			element * tmp2 = res -> vide(tmp -> L, tmp -> C);
			
			if(tmp2 == NULL)
			{
				res -> inserer(tmp -> L, tmp -> C, - tmp -> V);
			}
			else
			{
				tmp2 -> V -= tmp -> V;
				
				if(tmp2 -> V == 0)
					supprimer(tmp2);
			}
		}
		
		return res;
	}
	
	return NULL;
}
/**
 * @brief Fait la multiplication  terme à terme avec la matrice recue en parametre
 * @details [long description]
 * 
 * @param seconde la seconde matrice 
 * @return Retourne NULL si le calcul ne peut pas se faire sinon le resultat de la matrice
 */
Matrice * Matrice::fois(Matrice * seconde)
{
	// Multiplication terme à terme de deux matrices
	if(hauteur == seconde -> hauteur and largeur == seconde -> largeur)
	{
		Matrice * res = new Matrice(hauteur, largeur);
	
		for(element * tmp =  tete; tmp != NULL; tmp = tmp -> suiv)
		{
			element * tmp2 = res -> vide(tmp -> L, tmp -> C);
			
			if(tmp2 != NULL)
			{
				res -> inserer(tmp -> L, tmp -> C, tmp -> V * tmp2 -> V);
			}
		}
		
		return res;
	}
	
	return NULL;
}
/**
 * @brief Verifie si un element se trouve dans la matrice 
 * @details Cette fonction verifie si un element d'indice ligne et colonne se trouve dans la matrice
 * 
 * @param ligne indice de la ligne
 * @param colonne indice de la colonne
 * 
 * @return NULL si l'element n'existe pas dans la matrice sinon il retourne son adresse
 */
element * Matrice::vide(int ligne, int colonne)
{
	// Renvoie l'élément en ligne ligne et colonne colonne
	element * tmp = tete;
	
	while(tmp != NULL)
	{
		if(tmp -> L == ligne and tmp -> C == colonne)
			return tmp;

		tmp = tmp -> suiv;
	}
	
	return NULL;
}
/**
 * @brief Permet de supprimer une elelemt de la matrice
 * @details 
 * 
 * @param girafe element à supprimer
 */
void Matrice::supprimer(element * girafe)
{
	if(tete != NULL)
	{
		if(tete == girafe)
		{
			tete = girafe -> suiv;
		}
		else
		{
			element * tmp = tete;
			
			while(tmp -> suiv != girafe)
			{
				tmp = tmp -> suiv;
			}
			
			tmp -> suiv = girafe -> suiv;
		}
		
		delete girafe;
	}
}
/**
 * @brief Produit matricel avec  la matrice recue en parametre
 * @details [long description]
* @param seconde la seconde matrice 
 * @return Retourne le resultat de la matrice
 */
 
Matrice * Matrice::produit(Matrice * seconde)
{
	// Produit matriciel avec la matrice seconde
	if(largeur == seconde -> hauteur)
	{
		Matrice * res = new Matrice(hauteur, seconde -> largeur);
		
		int valeur;
		
		for(int i = 0; i < res -> hauteur; i ++)
		{
			for(int j = 0; j < res -> largeur; j ++)
			{
				valeur = 0;
				
				for(element * tmp = tete; tmp != NULL; tmp = tmp -> suiv)
				{
					if(tmp -> L == i)
					{
						element * correspondant = seconde -> vide(tmp -> C, j);
						
						if(correspondant != NULL)
						{
							valeur += tmp -> V * correspondant -> V;
						}
					}
				}
				
				res -> inserer(i, j, valeur);
			}
		}
		
		return res;
	}
	
	return NULL;
}
