#ifndef CLASS
	#define CLASS

	#include <iostream>
	#include <string>

	struct element
	{
		int L; // Ligne
		int C; // Colonne
		int V; // Valeur
		element * suiv;
	};

	class Matrice
	{
		element * tete;
		int hauteur; // Nombre de lignes
		int largeur; // Nombre de colonnes

		public:
			Matrice(int hauteur, int largeur);
			Matrice(std::string nomFichier);

			~ Matrice();

			Matrice * fois(Matrice * seconde);
			Matrice * moins(Matrice * seconde);
			Matrice * plus(Matrice * seconde);
			Matrice * produit(Matrice * seconde);
			Matrice * puissance(int P);
			Matrice * scalaireFois(int L);
			Matrice * transposer();

            void afficher(); // Uniquement pour les tests, à supprimer ensuite

			bool ecrire(std::string fichier); // ecrit lzs donnees d'une matrice sur un un fichier texte
			void inserer(int ligne, int colonne, int valeur);
			

        private:
            void supprimer(element * girafe);
			element * vide(int ligne, int colonne);
	};

    Matrice * identite(int N);

#endif
