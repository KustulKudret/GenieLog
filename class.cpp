#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>

#include "class.h"

using namespace std;

Matrice::Matrice(int hauteur, int largeur)
{
	// Constructeur 1
	// Crée une matrice vide
	tete = NULL;
	this -> hauteur = hauteur;
	this -> largeur = largeur;
}

Matrice::Matrice(string nomFichier)
{
	// Constructeur 2
	// Crée une matrice à partir d'un fichier
	tete = NULL;
	string tmp1,tmp2,tmp3;

	ifstream fichier(nomFichier.c_str());
	if(fichier)
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

Matrice * Matrice::fois(Matrice * seconde)
{
	// Multiplication terme à terme de deux matrices
	if(hauteur == seconde -> hauteur and largeur == seconde -> largeur)
	{
		Matrice * res = new Matrice(hauteur, largeur);

		for(element * tmp =  tete; tmp != NULL; tmp = tmp -> suiv)
		{
			element * tmp2 = seconde -> vide(tmp -> L, tmp -> C);

			if(tmp2 != NULL)
			{
				res -> inserer(tmp -> L, tmp -> C, tmp -> V * tmp2 -> V);
			}
		}

		return res;
	}

	return NULL;
}

Matrice * Matrice::moins(Matrice * seconde)
{
	// Soustraction terme à terme de deux matrices
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
					res -> supprimer(tmp2);
			}
		}

		return res;
	}

	return NULL;
}

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
					res -> supprimer(tmp2);
			}
		}

		return res;
	}

	return NULL;
}

Matrice * Matrice::produit(Matrice * seconde)
{
	// Produit matriciel de deux matrices
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

                if(valeur != 0)
                    res -> inserer(i, j, valeur);
			}
		}

		return res;
	}

	return NULL;
}

Matrice * Matrice::puissance(int P)
{
	// Calcul la puissance d'une matrice
	if(hauteur == largeur)
	{
		if(P < 0)
			return NULL;
		if(P == 0)
			return identite(hauteur);
		if(P == 1)
			return this;

		Matrice * res = new Matrice(hauteur, largeur);

		for(element * tmp = tete; tmp != NULL; tmp = tmp -> suiv)
		{
			res -> inserer(tmp -> L, tmp -> C, tmp -> V);
		}

		for(int i = 1; i < P; i ++)
		{
			res = res -> produit(this);
		}

		return res;
	}

	return NULL;
}

Matrice * Matrice::scalaireFois(int L)
{
	// Multiplication d'une matrice par un scalaire
	if(L != 0)
	{
		Matrice * res = new Matrice(hauteur, largeur);

		for(element * tmp = tete; tmp != NULL; tmp = tmp -> suiv)
		{
			res -> inserer(tmp -> L, tmp -> C, L * tmp -> V);
		}

		return res;
	}
	else
		return NULL;
}


void Matrice::inserer(int ligne, int colonne, int valeur)
{
	// Insére l'élément en tête de liste
	if(ligne < hauteur && colonne < largeur && ligne  >=0 && colonne >= 0 && valeur != 0)
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

Matrice * Matrice::transposer()
{
	// Transposition de la matrice
	Matrice * res = new Matrice(largeur, hauteur);

    for(element * tmp = tete; tmp != NULL; tmp = tmp -> suiv)
	{
		res -> inserer(tmp -> C, tmp -> L, tmp -> V);
	}

	return res;
}


element * Matrice::vide(int ligne, int colonne)
{
	// Renvoie l'élément en ligne ligne et colonne colonne
	for(element * tmp =  tete; tmp != NULL; tmp = tmp -> suiv)
	{
		if(tmp -> L == ligne && tmp -> C == colonne)
			return tmp;
	}

	return NULL;
}



Matrice * identite(int N)
{
	// Crée une matrice identité de taille N
	Matrice * res = new Matrice(N, N);

	for(int i = 0; i < N; i ++)
	{
		res -> inserer(i, i, 1);
	}

	return res;
}
void  Matrice::afficher(){

	cout<<"hauteur:"<<hauteur<<endl;
	cout<<"largeur:"<<largeur<<endl;

	for(element * tmp=tete;tmp!= NULL; tmp =tmp-> suiv)
		cout<<"["<<tmp->C<<"]"<<"["<<tmp->L<<"]"<<" = "<<tmp->V<<endl;



}
bool  Matrice::ecrire(string fichier)
{
	  element *tmp = tete;
	  //string const fichier("M.txt");
      fstream monFlux(fichier.c_str(),ios::out);
      if(monFlux) //On teste si tout est OK
        {
        	monFlux << hauteur<<endl;
        	monFlux << largeur<<endl;
            while(tmp!= NULL)
            {
            	monFlux << tmp->L<<" ";
	            monFlux << tmp->C<<" ";
	            monFlux << tmp->V<<" "<<endl;
	            tmp=tmp->suiv;
            }
            monFlux.close();
            return true;
        }
     else
     return false;
}

