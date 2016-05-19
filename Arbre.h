#include <iostream>
using namespace std;
#include <stdlib.h> 
struct Noeud {

	string info;
	int imp;
	Noeud * fg;
	Noeud * fd;
};


class Arbre{

	Noeud * R;

	public:

	Arbre();
	~Arbre();
	void saisie(string a,int imp);
	void affiche();
	long int result();

};






