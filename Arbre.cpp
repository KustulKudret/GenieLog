#include "Arbre.h"

//----------------------Construction et Destruction de l'Arbre-----------

Arbre::Arbre(){

	R=NULL;
}
void supprime(Noeud * R){

	if (R!= NULL){

		supprime(R->fd);
		supprime(R->fg);
		delete R;
	}
}
Arbre::~Arbre(){

	supprime(R);
	R=NULL;
}

//----------------------Saisie d'un Nouveau Noeud---------------------

Noeud * NN(int & imp,string & info){
	Noeud * tmp=new Noeud;
	tmp->imp=imp;
	tmp->info=info;
	tmp->fg=NULL;
	tmp->fd=NULL;
	return tmp;
}
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

//----------------------Affiche-----------------------------------

void aff(Noeud * R){

	if (R!= NULL){
			aff(R->fg);
			aff(R->fd);
			if(R->fg!=NULL && R->fd!=NULL)
				cout<<R->fg->info << " " << R->info << " " <<R->fd->info <<endl;
			
	}
}
void Arbre::affiche(){

	aff(R);
	
}

//----------------------Calcule du resultat ---------------------
		//------------------Fonction d'opération----------
long int puissance(int a,int b){
	
	long int resultat=1;

	for(int i=0;i<b;i++)
		resultat*=a;

	return resultat;
}
long int tobase(long int a,long int base){

	long int res=0,p=1;
	do{	
		res+=(a%base)*p;
		a/=base;
		p*=10;

	}while(a>0);

	return res;
}
		//--------------------Fin des fonction d'opération-------------
long int calcul(long int a,char operateur,long int b){

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
			else
				cerr<<"Division par 0 "<<endl;
			break;
		case '^':
			return puissance(a,b);
			break;
		case '|':
			if(a < puissance(b,19))//2^19
				return tobase(a,b);
			return a;
			break;
		case '%':
			return a%b;
			break;			
	}
	return 0;
}
long int opere(Noeud * R){
	
	if (R->fg!=NULL && R->fd!=NULL)
		return calcul(opere(R->fg),R->info[0],opere(R->fd));
	//else
	return atoi(&R->info[0]);
		
}
long int Arbre::result(){

	return opere(R);
}
























