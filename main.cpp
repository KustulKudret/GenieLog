#include <iostream>
using namespace std;
#include "Arbre.h"



int importance(char car){

	if(car == '|')
		return 0;
	if(car == '-' || car == '+' || car == '%')
		return 1;
	if(car == '*' || car == '/')
		return 2;
	return 3;



}
bool Prior(Arbre & Arithmetique,string exp){

	string nomf="";	
	string operateur="";				
	int size=exp.size();		
	int priorite=0;
	unsigned int negatif=0;
	
	for(int i=0;i<size;i++){

		if(exp[i] == '+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^' || exp[i]=='|' || exp[i]=='%'){	//Si c'est un opertateur alors
			
			if(!nomf.empty()){							//Si y'a un nom de fichier 
				//cout<<nomf<<"   "<<priorite+100 <<endl;


				if(operateur[0] == '/' && atoi(&nomf[0])==0){
					cerr<<"Division par 0"<<endl;
					return false;

				}
				Arithmetique.saisie(nomf,priorite+100);			
				nomf="";
				if(negatif > 0){
					negatif--;
					priorite-=100;
				
				}
			}else{


				if(exp[i]=='-' || exp[i]=='+'){
					priorite+=100;
					operateur=exp[i];
					Arithmetique.saisie(operateur,priorite+importance(exp[i]));
					Arithmetique.saisie("0",priorite+100);


					negatif++;
					//cout<<exp[i]<<endl;
				
				}
				if(exp[i]=='*' || exp[i]=='/' || exp[i]=='^' || exp[i]=='|' || exp[i]=='%')
					return false;

			}
			
			if(exp[i-1]==')' )
				priorite-=100;
			//cout<<exp[i]<<"   "<<priorite+importance(exp[i]) <<endl;
			operateur=exp[i];
			Arithmetique.saisie(operateur,priorite+importance(exp[i]));
			while(exp[i+1]=='-' || exp[i+1]=='+'){
					priorite+=100;
					operateur=exp[i+1];
					Arithmetique.saisie(operateur,priorite+importance(exp[i+1]));
					Arithmetique.saisie("0",priorite+100);

					i++;
					negatif++;
					//cout<<exp[i]<<endl;
				
			}
			if(exp[i+1]=='*' || exp[i+1]=='/' || exp[i+1]=='^' || exp[i+1]=='|' || exp[i+1]=='%')
				return false;
			
		}
		else{
			if(exp[i]=='(' )
				priorite+=100;
			else
				if(exp[i]!=')' )
					nomf+=exp[i];

			

		}
	}
	if(nomf.empty())
		return false;
	if(operateur[0] == '/' && atoi(&nomf[0])==0){
		cerr<<"Division par 0"<<endl;
		return false;

	}
	Arithmetique.saisie(nomf,priorite+100);			
	//cout<<nomf<<"   "<<priorite+100<<endl;

}

int main(){
Arbre * Arithmetique = new Arbre;
//string expression="A*B+C-D*E+F-G*H";
string expression;//="1+2*3^4/18+5*7+9+21*3/7+9*3^2-5-2-5^2*2/5+1+1+1-7*2*2*2*1*4*5*6/3";
char exp[1000];
while(1){

	cout<<" : ";
	cin.getline(exp,100000);
	expression=exp;
	if(Prior((*Arithmetique),expression)){

		Arithmetique -> affiche();

		cout<<" = "<<Arithmetique -> result()<<endl;
	}
	else
		cout<<"Votre expresion est incorrecte"<<endl;
	delete Arithmetique;
	Arithmetique = new Arbre;
}












}
