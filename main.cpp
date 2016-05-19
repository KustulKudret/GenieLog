 /*     Copyright (C) 2016 Benhachani Mohamed
*
 *   This program is free software; you can redistribute it and/or
  *  modify it under the terms of the GNU Lesser General Public
   * License as published by the Free Software Foundation; either
    *version 2.1 of the License, or (at your option) any later version.
*
 *   This program is distributed in the hope that it will be useful,
  *  but WITHOUT ANY WARRANTY; without even the implied warranty of
   * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    *Lesser General Public License for more details.
*
 *   You should have received a copy of the GNU Lesser General Public
  *  License along with this program; if not, write to the Free Software
   * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
#include <fstream>
#include "class.h"
#include "Arbre.h"
//Faire alias,PATH,Lignedecommande
/*! \mainpage Documentation de Matrice creuse
 *
 * \section intro_sec Introduction
 *
 * Matrice creuse est une librairie qui permet la creation, la gestion, 
 * la resolution d'operertion et d'expression aritmetique sur des matrice creuse.
 *
 * \section copyright Copyright and License
 *     Copyright (C) 2016 Benhachani Mohamed
*
 *   This program is free software; you can redistribute it and/or
  *  modify it under the terms of the GNU Lesser General Public
   * License as published by the Free Software Foundation; either
    *version 2.1 of the License, or (at your option) any later version.
*
 *   This program is distributed in the hope that it will be useful,
  *  but WITHOUT ANY WARRANTY; without even the implied warranty of
   * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    *Lesser General Public License for more details.
*
 *   You should have received a copy of the GNU Lesser General Public
  *  License along with this program; if not, write to the Free Software
   * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *

 *
 */
/*!
 * \file main.cpp
 * \brief C'est le fichier apartir duquel je lance les differente fonction, et qui fait interface avec l'utilisateur
 * \author Benhachani Mohamed
 * \version 1.0
 */

/*!
     *  \brief Fonction Execute la commande 

     *  \param[in] int argc : Nombre d'argument
     *	\param[in] char *argv[] : Les argument
     *  \return True si la commande a bien etait éxecuté
     */
bool commande(int argc, char *argv[]){

	int debut=1;
	string tmp=argv[debut];

	string expression="",destination="Resultat.txt";
	string Path="./";
	int num=50;

	if(tmp!="-a" && tmp!="-p" && tmp!="-n" && tmp!="-d"){
		expression=argv[debut];

		if(++debut < argc){
			tmp=argv[debut];
			if(tmp!="-a" && tmp!="-p" && tmp!="-n" && tmp!="-d"){

				destination=argv[debut++];
			}
		}
	}

	for(int i=debut;i<argc;i++){
		
		string tmp=argv[i];

		if(tmp == "-p"){
			if(++i<argc)
				Path = argv[i];
		}
		if(tmp == "-n" ){
			if(++i<argc)
				num=atoi(argv[i]);
		}
		if(tmp == "-e")
			if(++i<argc)
				expression=argv[i];
			else
				return false;
		if(tmp == "-d")
			if(++i<argc)
				destination=argv[i];
			else
				return false;
	}

	Arbre Arithmetique(Path,num);

	string de="",a="";
	for(int i=debut;i<argc;i++){
		
		tmp=argv[i];

		if(tmp == "-a"){

			if(++i<argc)
				de=argv[i];
			else
				return false;

			if(++i<argc)
				a=argv[i];
			else
				return false;

			Arithmetique.add_alias(de,a);
		}
		
	}

	Matrice * C=NULL;
	if(Arithmetique.Arithmetique(expression)){

		C = Arithmetique.resultat();
		if(C!=NULL){

			C->ecrire(Path+destination);

		}
		else{
			cerr<<"Votre expression Arithmetique n'est pas realisable"<<endl;
			return false;
		}
	}
	else{
		cerr<<"Votre expression Arithmetique est incorrecte"<<endl;
		return false;
	}

	return true;


}

/*!
     *  \brief La Fonction main

     *  \param[in] int argc : Nombre d'argument
     *	\param[in] char *argv[] : Les argument
     */
int main(int argc, char *argv[]){

	if(argc >1){					//Partie exécuté si c'est une commande
		if(!commande(argc,argv))
			cout<<"Votre commande est incorrecte"<<endl;
	}
	else{						//Partie exécuté sui ce n'est pas une commande





		cout<<"\n\nBienvenue, \nle programe vous permet de faire des operation entre Matrice, entre entier et entre matrice est entier. \n\nLes Matrice creuse doivent etre contenue dans un ficher de type LVC avec au debut du fichier la hauteur et largeur du fichier, \nle noms des fichier ne doivent pas commencer par un chiffre ou un symbole d'une operation .\n\n\nLes operation disponible sont entre Matrice : \n		Matrice.txt + Matrice2.txt (retourne la somme de deux matrice si leur taille sont identique)\n		Matrice.txt - Matrice2.txt (retourne la soustration de deux matrice si leur taille sont identique)\n		Matrice.txt * Matrice2.txt (retourne le produit de deux matrice si hauteur de Matrice.txt est eguale a la largeur de la seconde )\n		Matrice.txt # Matrice2.txt (retourne le produit terme a terme de deux matrice)\n		Matrice.txt ^ t (retourne la transposé de Matrice.txt avec t ou T )\n\n\nLes operation disponible sont entre Entier : \n		entier + entier (retourne la somme de deux entier)\n		entier - entier (retourne la soustration de deux entier)\n		entier * entier (retourne le produit de deux entier)\n		entier / entier (retourne le resultat de la division entiere des entier)\n		entier \% entier (retourne le modulo)\n		entier ^ entier2 (retourne entier pluissance entier2)\n\n\nLes operation disponible sont entre une Matrice et un entier: \n		entier * Matrice.txt (retourne la Matrice fois pour chaque terme l'entier)\n		Matrice.txt ^ entier (retourne la  Matrice.txt a la puissance de l'entier)\n\n\n\nEn cas d'erreur :\n	Si une operation entre deux entier n'existe pas un 0 sera retourner et l'operation continura un message d'avertissement sera envoyer.\n	Si une operation entre deux Matrice n'existe pas l'operation sera annule.\n	Si une operation entre une Matrice et un entier n'existe pas la Matrice sera retourner et l'operation continura un message d'avertissement sera envoyer.\n\n\n\nCas special :\n	Si le resultat de l'expression est un entier alors je cree une Matrice carre de largeur 1 contenant le resulat\n	Il est impossible de faire la puissance d'une Matrice qui ce nomerai T ou t\n\n\nTableau des priorite croissant:\n\n------------------------\n| Operateur | Priorite |\n------------------------\n|     -     |     0    |\n------------------------\n|     +     |     0    |\n------------------------\n|     %     |     0    |\n------------------------\n|     #     |     1    |\n------------------------\n|     *     |     2    |\n------------------------\n|     /     |     2    |\n------------------------\n"<<endl;
	
		int Nombre_max_caractere=100000;

		Matrice * C=NULL;
		string expression="";
		string Path="./";
		int num = 50;
		char exp[Nombre_max_caractere];	

		cout<<"Voulez vous acceder au configuration avancé de cette outil (si oui tapez 1) : ";
		cin.getline(exp,Nombre_max_caractere);
		expression=exp;

		if(atoi(&expression[0]) == 1){
			cout<<"Les fichier modifier et appelé lors des operation seront rreferencé par raport a ce chemin relatif : " <<Path<<endl<<endl<<"Voudriez-vous le modifier (si oui tapez 1) : ";
			cin.getline(exp,Nombre_max_caractere);
			expression=exp;
			if(atoi(&expression[0]) == 1){
				cout<<"Veuillez inscrire le nouveau chemin : ";
				cin.getline(exp,Nombre_max_caractere);
				Path=exp;
			}
			cout<<"Par default vous pourez pendant l'execution du programme cree jusqu'a 50 alias, Voudriez-vous modifier ce nombre (si oui tapez 1) : ";
			cin.getline(exp,Nombre_max_caractere);
			expression=exp;

			if(atoi(&expression[0]) == 1){
				cout<<"Veuillez inscrire le nouveau nombre maximum d'alias :";
				cin.getline(exp,Nombre_max_caractere);
				expression=exp;
				num=atoi(&expression[0]);
	
			}

		}
	
		Arbre Arithmetique(Path,num);
	
		cout<<endl<<"Pour Ajouter ou Supprimer un alias, il vous suffit de tapez 0 lorsque l'on vous demande l'expession Arithmetique"<<endl<<endl<<endl;

	


		string mode="";
		while(mode.empty()){
			cout<<"Tapez 0 pour que la matrice resultante soit afficher ou le nom du fichier dans lequel la matrice resultante doit etre ecrite : "<<endl;
			cin.getline(exp,Nombre_max_caractere);
			mode=exp;
		}
	
		string de="",a="";

		while(1){
			cout<<" : ";
			cin.getline(exp,Nombre_max_caractere);
			expression=exp;
		

			if(!expression.empty() && expression[0] == '0' && (expression.length() == 1 || expression[1] == ' ')){

				Arithmetique.afficher_alias();
				cout<<"Si vous souhaitez ajouter un alias tapez 1, si vous souhaitez suprimer un alias tapez 2 : "<<endl; 
				cin.getline(exp,Nombre_max_caractere);
				expression=exp;

				if(atoi(&expression[0])==1){
					cout<<"Veuillez taper la chaine de caractere a changer dans l'expression : ";
					cin.getline(exp,Nombre_max_caractere);
					de=exp;
					cout<<"Veuillez taper la chaine de caractere qui va remplacer la chaine precédente : ";
					cin.getline(exp,Nombre_max_caractere);
					a=exp;
					if(!Arithmetique.add_alias(de,a))
						cout<<"Vous ne pouvez plus ajouter d'alias"<<endl;
				}
				if(atoi(&expression[0])==2){
					cout<<"Veuillez taper le numero de l'alias : ";
					cin.getline(exp,Nombre_max_caractere);
					expression=exp;
					if(!Arithmetique.suppr_alias(atoi(&expression[0])))
						cout<<"Cette alias n'existe pas"<<endl;
				}
			}
			else{
				if(Arithmetique.Arithmetique(expression)){
					//Arithmetique.affiche();
					C = Arithmetique.resultat();
					if(C!=NULL){
						if(mode[0] == '0')
							C->afficher();
						else
							C->ecrire(Path+mode);

					}
					else
						cout<<"Votre expression Arithmetique n'est pas realisable"<<endl;
				}
				else
					cout<<"Votre expression Arithmetique est incorrecte"<<endl;
			}
		
		}
	}
}


























