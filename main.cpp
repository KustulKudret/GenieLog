#include "class.h"
#include "Arbre.h"

int main(){


	
	cout<<"\n\n\nBienvenue, \nle programe vous permet de faire des operation entre Matrice, entre entier et entre matrice est entier. \n\nLes Matrice creuse doivent etre contenue dans un ficher de type LVC avec au debut du fichier la hauteur et largeur du fichier, \nle noms des fichier ne doivent pas commencer par un chiffre ou un symbole d'une operation .\n\n\nLes operation disponible sont entre Matrice : \n		Matrice.txt + Matrice2.txt (retourne la somme de deux matrice si leur taille sont identique)\n		Matrice.txt - Matrice2.txt (retourne la soustration de deux matrice si leur taille sont identique)\n		Matrice.txt * Matrice2.txt (retourne le produit de deux matrice si hauteur de Matrice.txt est eguale a la largeur de la seconde )\n		Matrice.txt # Matrice2.txt (retourne le produit terme a terme de deux matrice)\n\n\nLes operation disponible sont entre Entier : \n		entier + entier (retourne la somme de deux entier)\n		entier - entier (retourne la soustration de deux entier)\n		entier * entier (retourne le produit de deux entier)\n		entier / entier (retourne le resultat de la division entiere des entier)\n		entier \% entier (retourne le modulo)\n		entier ^ entier2 (retourne entier pluissance entier2)\n\n\nLes operation disponible sont entre une Matrice et un entier: \n		entier * Matrice.txt (retourne la Matrice fois pour chaque terme l'entier)\n		Matrice.txt ^ entier (retourne la  Matrice.txt a la puissance de l'entier)\n\n\n\nEn cas d'erreur :\n	Si une operation entre deux entier n'existe pas un 0 sera retourner et l'operation continura un message d'avertissement sera envoyer.\n	Si une operation entre deux Matrice n'existe pas l'operation sera annule.\n	Si une operation entre une Matrice et un entier n'existe pas la Matrice sera retourner et l'operation continura un message d'avertissement sera envoyer.\n\n\n\nCas special :\n	Si le resultat de l'expression est un entier alors je cree une Matrice carre de largeur 1 contenant le resulat\n\n\nTableau des priorite croissant:\n\n------------------------\n| Operateur | Priorite |\n------------------------\n|     -     |     0    |\n------------------------\n|     +     |     0    |\n------------------------\n|     %     |     0    |\n------------------------\n|     #     |     1    |\n------------------------\n|     *     |     2    |\n------------------------\n|     /     |     2    |\n------------------------\n"<<endl;


	Matrice * C=NULL;



	Arbre Arithmetique;

	string expression="";	
	char exp[1000];

	
	string mode="";
	while(mode.empty()){
		cout<<"Tapez 0 pour que la matrice resultante soit afficher ou le nom u fichier dans lequel la matrice resultante doit etre ecrite : "<<endl;
		cin.getline(exp,100000);
		mode=exp;
	}

//((((D+D)#D)*D)*(1+2*3^4/18+5*7+9+21*3/7+9*3^2-5-2-5^2*2/5+1))^2

	while(1){
		cout<<" : ";
		cin.getline(exp,100000);
		expression=exp;
		//cout<<expression<<endl;

		if(Arithmetique.Arithmetique(expression)){
			//Arithmetique.affiche();
			C = Arithmetique.resultat();
			if(C!=NULL){
				if(mode[0] == '0')
					C->afficher();
				else
					C->ecrire(mode);

			}
			else
				cout<<"Votre expression Arithmetique n'est pas realisable"<<endl;
		}
		else
			cout<<"Votre expression Arithmetique est incorrecte"<<endl;

	}

}


























