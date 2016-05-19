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
/*!
 * \file Arbre.cpp
 * \brief Fonction lié a Arbre
 * \author Benhachani Mohamed
 * \version 1.0
 */
#include "Arbre.h"
//----------------------Une petite fonction pour converir un en string-----------
 /*!
     *  \brief Concatène un entier a un string 
     *
     *  \param[in,out] string & s : string auquel je concatène l'entier
     *  \param[in] string & s : l'entier que je concatène au string
     */
void to_string(string & s,int a){

	if(a!=0){
		to_string(s,a/10);
		s+=(char('0'+(a%10)));
	}
}

//----------------------Construction et Destruction de l'Arbre-----------
	/*!
	*  \brief Constructeur de la classe Arbre.
	*/
Arbre::Arbre(){

	R=NULL;
}
 /*!
     *  \brief Fonction qui supprime les Noeud parcouru apartir de R

     *  \param[in] Noeud * R : Noeud pour le debut du parcours de l'arbre
     */
void supprime(Noeud * R){

	if (R!= NULL){

		supprime(R->fd);
		supprime(R->fg);
		delete R;
	}
}
     /*!
     *  \brief Destructeur de la classe Arbre.
     */
Arbre::~Arbre(){

	supprime(R);
	R=NULL;
}

//----------------------Saisie d'un Nouveau Noeud---------------------

    /*!
     *  \brief Fonction qui crée est retourne un nouveau Noeud
     *
     *  \param[in] int & imp : entier représentant l'importance du nouveau Noeud
     *  \param[in] string & info : chaine de caractere contenant l'opérande ou l'opérateur
     *  \return Un pointeur vers le nouveau Noeud
     */
Noeud * NN(int & imp,string & info){
	Noeud * tmp=new Noeud;
	tmp->imp=imp;
	tmp->info=info;
	tmp->fg=NULL;
	tmp->fd=NULL;
	return tmp;
}
//----------------------Insertion dans l'arbre d'un nouveau Noeud-----------
    /*!
     *  \brief Fonction qui insert un nouveau Noeud dans l'arbre apartir du noeud R

     *  \param[in] Noeud * R : Noeud pour le debut du parcours de l'arbre
     *  \param[in] int & imp : entier représentant l'importance du nouveau Noeud
     *  \param[in] string & info : chaine de caractere contenant l'opérande ou l'opérateur
     *  \return True si le Noeud a était inseré False sinon
     */
bool insert(Noeud * R,int & imp,string & info){

	if(R->imp < imp){				//Si le Noeud courant est inferieur au nouveau alors
		if (R->fg == NULL){				//Si le fils gauche est libre alors je l'insert gauche
			R->fg=NN(imp,info);
			return true;
		}	

		if (R->fd == NULL){				//Si le fils drot est libre je l'insert a droite
			R->fd=NN(imp,info);
			return true;
		}

		if(R->fd->imp >= imp){	//Si les noeud droit est superieur alors je cree un nouveau noeud 

			Noeud * tmp = NN(imp,info) ;		//avec comme pere R, et comme fils gauche le fils droit du pere
			tmp ->fg = R->fd;		
			R->fd=tmp;
			return true;
		}
		if ( insert(R->fd,imp,info)) return true;	//Sinon je parcour a droite		
	} 
	return false;
}
    /*!
     *  \brief Fonction qui insert un nouveau Noeud dans l'arbre
     *
     *  \param[in] int & imp : entier représentant l'importance du nouveau Noeud
     *  \param[in] string & info : chaine de caractere contenant l'opérande ou l'opérateur
     */
void Arbre::saisie(string info,int imp){
	if (R== NULL)				//Si la racinne est NULL 
		R=NN(imp,info);			//je met le noeud a racinne 
	else{					//Sinon
		if(R->imp >= imp){			//Si le nouveau noeud a une importance inferieur alors je le met a la racinne
			Noeud * tmp = NN(imp,info) ;
			tmp -> fg = R;
			R=tmp;	
		}
		else					//Sinon j'appele insert
			insert (R,imp,info);		
	}
}
//---------------------------------Analyse d'une chaine de caractere, et insertion dans l'arbre
  /*!
     *  \brief Methode qui renvoie l'importance d'un operateur
     *
     *  \param[in] char a   : Operateur
     *  \return Un entier qui représente l'importance de l'operateur
     */
	
int Arbre::importance(char car){

	if(car == '-' || car == '+' || car == '%')
		return 0;
	if(car == '#')
		return 1;
	if(car == '*' || car == '/')
		return 2;
	return 3;



}
  /*!
     *  \brief Methode qui permet de remplir l'Arbre Arithmetique apartir d'une expression, tant que cette expression est correcte.
     *  En cas d'expession Arithmetique incorrecte le contenu de l'Arbre n'est pas detruit.
     *  \param[in] string exp : expression Arithmetique
     *  \return true si l'expression Arithmetique est juste
     *  false sinon.
    
     */
	
bool Arbre::Prior(string exp){

	string nomf="";	
	string operateur="";				
	int size=exp.size();		
	int priorite=0;
	unsigned int negatif=0;
	
	for(int i=0;i<size;i++){

		if(exp[i] == '+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^'|| exp[i]=='%' || exp[i]=='#'){	//Si c'est un opertateur alors
			
			if(!nomf.empty()){							//Si y'a un nom de fichier 


				if(operateur[0] == '/' && atoi(&nomf[0])==0){
					cerr<<"Division par 0"<<endl;
					return false;

				}
				saisie(nomf,priorite+100);			
				nomf="";
				if(negatif > 0){
					negatif--;
					priorite-=100;
				
				}
			}else{

				if(exp[i]=='-' || exp[i]=='+'){
					priorite+=100;
					operateur=exp[i];
					saisie(operateur,priorite+importance(exp[i]));
					saisie("0",priorite+100);


					negatif++;
				
				}
				if(exp[i]=='*' || exp[i]=='/' || exp[i]=='^' || exp[i]=='%' || exp[i]=='#')
					return false;

			}
			
			if(exp[i-1]==')' )
				priorite-=100;

			operateur=exp[i];
			saisie(operateur,priorite+importance(exp[i]));
			while(exp[i+1]=='-' || exp[i+1]=='+'){
					priorite+=100;
					operateur=exp[i+1];
					saisie(operateur,priorite+importance(exp[i+1]));
					saisie("0",priorite+100);

					i++;
					negatif++;
				
			}
			if(exp[i+1]=='*' || exp[i+1]=='/' || exp[i+1]=='^' || exp[i+1]=='%' || exp[i+1]=='#')
				return false;
			
		}
		else{
			if(exp[i]=='(' )
				priorite+=100;
			else
				if(exp[i]!=')' && exp[i]!=' ')
					nomf+=exp[i];

			

		}
	}
	if(nomf.empty())
		return false;
	if(operateur[0] == '/' && atoi(&nomf[0])==0){
		cerr<<"Division par 0"<<endl;
		return false;

	}
	saisie(nomf,priorite+100);

	return true;			

}
    /*!
     *  \brief Methode qui permet de remplir l'Arbre Arithmetique apartir d'une expression, tant que cette expression est correcte, si elle n'est pas correcte le contenu l'arbre est détruit.
     *
     *  \param[in] string exp : expression Arithmetique
     *  \return true si l'expression Arithmetique est juste
     *  false sinon
     */
bool Arbre::Arithmetique(string exp){

	bool no_error=Prior(exp);

	if(!no_error){
		supprime(R);
		R=NULL;
	}

	return no_error;
}

//----------------------Affiche-----------------------------------
  /*!
     *  \brief Affiche un Arbre apartir du Noeud R avec un parcours en suffixe.
     *  \param[in] Noeud * R : Noeud que parcours la fonction
     */
void aff(Noeud * R){

	if (R!= NULL){
			aff(R->fg);
			aff(R->fd);
			if(R->fg!=NULL && R->fd!=NULL)
				cout<<R->fg->info << " " << R->info << " " <<R->fd->info <<endl;
			
	}
}
    /*!
     *  \brief Affiche l'Arbre avec un parcours en suffixe.
     */
void Arbre::affiche(){

	aff(R);
	
}

//----------------------Calcule du resultat ---------------------
		//------------------Fonction d'opération----------
    /*!
     *  \brief Fonction qui revoie a puissance b
     *
     *  \param[in] int a : entier a
     *  \param[in] int b : entier b exposant de a
     *  \return a puissance b
     */
long int puissance(int a,int b){
	
	long int resultat=1;

	for(int i=0;i<b;i++)
		resultat*=a;

	return resultat;
}
		//--------------------Fin des fonction d'opération-------------
    /*!
     *  \brief Fonction qui revoie le resultat de l'operation que represente le caractère operateur de a et b.
     *
     *  \param[in] long int a : entier a
     *  \param[in] char operateur : operation
     *  \param[in] long int b : entier b
     *  \param[out] bool & no_error : True si il y'a une error False sinon
     *  \return le resultat de l'operation que represente le caractère operateur de a et b.
     */
long int calcul(long int a,char operateur,long int b,bool & no_error){

	switch(operateur){

		case '+':
			return a+b; 
			break;
		case '-':
			return a-b; 
			break;
		case '*':
			return a*b;
			break;
		case '/':
			if(b!=0)
				return a/b;

			cerr<<"Division par 0 "<<endl;
			no_error = false;
				
			break;
		case '^':
			return puissance(a,b);
			break;
		case '%':
			return a%b;
			break;			
	}
cerr << "Il impossible de faire " << a << " " << operateur << " "<< b << "cette operation a retourner 0"<<endl;
	return 0;
}
    /*!
     *  \brief Fonction qui revoie le resultat de l'operation que represente le caractère operateur de a et b.
     *
     *  \param[in] Matrice * a : Matrice a
     *  \param[in] char operateur : operation
     *  \param[in] Matrice * b : Matrice b
     *  \return Un pointeur vers une Matrice resultante de l'operation que represente le caractère operateur de a et b.
     */
Matrice * calcul(Matrice * a,char operateur,Matrice * b){

	Matrice * tmp ;

	switch(operateur){

		case '+':
			tmp = a->plus(b);
			delete a ;
			delete b ;
			return tmp; 
			break;
		case '-':
			tmp = a->moins(b);
			delete a ;
			delete b ;
			return tmp; 
			break;
		case '*':
			tmp = a->produit(b);
			delete a ;
			delete b ;
			return tmp; 
			break;

		case '#':
			tmp = a->fois(b);
			delete a ;
			delete b ;
			return tmp; 
			break;
				
	}
	delete a ;
	delete b ;
	return NULL;
}
/*!
     *  \brief Fonction qui revoie le resultat de l'operation operateur de a et b.
     *
     *  \param[in] int a : entier a
     *  \param[in] char operateur : operation
     *  \param[in] Matrice * b : Matrice b
     *  \return Un pointeur vers une Matrice resultante de l'operation que represente le caractère operateur de a et b.
     */
Matrice * calcul(int a,char operateur,Matrice * b){

	Matrice * tmp ;

	switch(operateur){

		case '*':
			tmp = b->scalaireFois(a);
			delete b ;
			return tmp; 
			break;

		case '^':
			tmp = b->puissance(a);
			delete b ;
			return tmp; 
			break;
				
	}
	cerr << "Il impossible de faire " << a << " " << operateur << " une Matrice cette operation a donc etait annule"<<endl;
	return b;
}
/*!
     *  \brief Fonction qui revoie le resultat de l'operation operateur de a et b.
     *
     *  \param[in] int b : entier b
     *  \param[in] char operateur : operation
     *  \param[in] Matrice * a : Matrice a
     *  \return Un pointeur vers une Matrice resultante de l'operation que represente le caractère operateur de a et b.
     */
Matrice * calcul(Matrice * a,char operateur,int b){

	return calcul(b,operateur,a);
}


    /*!
     *  \brief Parcours l'arbre est realise les operation lié au Matrice
     *
     *  \param[in] Noeud * R : Noeud que parcours la fonction
     *  \param[out] bool & no_error : True si il y'a une error False sinon
     *  \return le resultante au parcours 
     */

Matrice * opere_Matrice(Noeud * R,bool & no_error){

	if (R->fg!=NULL && R->fd!=NULL){

		Matrice * tmp;

		if(R->fg->info[0] >= '0' && R->fg->info[0] <= '9'){
			tmp=calcul(atoi(&R->fg->info[0]),R->info[0],opere_Matrice(R->fd,no_error));
			if(tmp == NULL && no_error){
				cerr<<"Il est impossible de faire "<<R->fg->info <<" "<<R->info[0] <<" "<< R->fd->info<<endl;
				no_error=false;
			}
			return tmp;
		}
		if(R->fd->info[0] >= '0' && R->fd->info[0] <= '9'){
			tmp= calcul(opere_Matrice(R->fg,no_error),R->info[0],atoi(&R->fd->info[0]));
			if(tmp == NULL && no_error){
				cerr<<"Il est impossible de faire "<<R->fg->info <<" "<<R->info[0] <<" "<< R->fd->info<<endl;
				no_error=false;
			}
			return tmp;
		}
		tmp = calcul(opere_Matrice(R->fg,no_error),R->info[0],opere_Matrice(R->fd,no_error));
		if(tmp == NULL && no_error){
			cerr<<"Il est impossible de faire "<<R->fg->info <<" "<<R->info[0] <<" "<< R->fd->info<<endl;
			no_error=false;
		}
		return tmp;

	}
	//else
	return new Matrice(R->info);
		
} 
  /*!
     *  \brief Parcours l'arbre est realise les operation composer d'Entier
     *
     *  \param[in] Noeud * R : Noeud que parcours la fonction
     *  \param[in,out] bool & c : Resultat des operation entre entier
     *  \param[out] bool & no_error : True si il y'a une error False sinon
     *  \return True si l'operation est entre deux entier False sinon
     */
bool opere(Noeud * R, int & c,bool & no_error){
	
	if (R->fg!=NULL && R->fd!=NULL){
		bool r=opere(R->fd,c,no_error);
		if(opere(R->fg,c,no_error) && r ){
			c = calcul(atoi(&R->fg->info[0]),R->info[0],atoi(&R->fd->info[0]),no_error);

			R->info="";
			to_string(R->info,c) ;
			delete R->fg;
			delete R->fd;
			R->fg=NULL;
			R->fd=NULL;
			return true;
		}
		//else
		return false;

	}
	//else
	return (R->info[0] >= '0' && R->info[0] <= '9');
		
}
   /*!
     *  \brief Renvoie une Matrice résultante de l'expression.
     *
     *  \return La Matrice Resulatante  de l'expression Arithmetique
     */
Matrice * Arbre::resultat(){

	Matrice * resultante=NULL;
	if(R != NULL){
		if (R->fg != NULL && R->fd != NULL){
			int c=0;
			bool no_error=true;
			opere(R,c,no_error);//Je fait toute les operation qui implique des int
	

			if(no_error){
				if (R->fg != NULL && R->fd != NULL){

					resultante = opere_Matrice(R,no_error);

				}
				if(resultante==NULL && no_error){
					resultante=new Matrice(1,1);
					resultante -> inserer(0, 0,c);
				}
			}
		}
		else{
			if(R->info[0] >= '0' && R->info[0] <= '9'){
				resultante=new Matrice(1,1);
				resultante -> inserer(0, 0,atoi(&R->info[0]));

			}
			else
				resultante=new Matrice(R->info);

		}
		supprime(R);
		R=NULL;

	}
	return resultante;
}













