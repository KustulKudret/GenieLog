#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

void test(int taille_l , int taille_c , double densite , string nom_fichier);
void rempl(int l , int c ,int valeur , string nom_fichier);

void test(int taille_l , int taille_c , double densite , string nom_fichier)
{
	int l , c , v ;
	int n_e_t(taille_l * taille_c);
	int n_e(densite * n_e_t);
	int e_l [n_e] ;
	int e_c [n_e] ;
	for(int i(0); i <n_e ; i++)
	{
jump:
		l = rand()%(taille_l+1);
		c = rand()%(taille_c+1);
		v = rand();
		for(int j (0) ; j < i ; j++)
		{
			for(int k(0) ; k < i ; k++)
			{
				if(e_l [j] == l && e_c [k] == c)
					goto jump;
			}		
		}
		e_l [i] = l;
		e_c [i] = c;
		rempl(l,c,v,nom_fichier);
	}
}
void rempl(int l , int c ,int valeur , string nom_fichier)
{
	ofstream fichier("A.txt", ios::out | ios::app);
	if(fichier)
	{	
		fichier<<l<<" "<<c<<" "<<valeur<<endl;	
	}
	else
		cerr<<"impossible d'ouvrir le fichier"<<endl;
}
int main()
{
	srand (time(NULL));
	test(10,10,1,"A.txt");
	return 0;
}
