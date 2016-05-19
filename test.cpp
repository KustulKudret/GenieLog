
void M_creator(int taille_l , int taille_c , double densite , string nom_fichier)
{
	ofstream fichier(nom_fichier.c_str(), ios::out | ios::app);
	if(fichier)
	{	
		fichier<<taille_l<<endl;
		fichier<<taille_c<<endl;
	}
	else
		cerr<<"impossible d'ouvrir le fichier"<<endl;
	int l , c , v ;
	int n_e_t(taille_l * taille_c);
	int n_e(densite * n_e_t);
	int e_l [n_e] ;
	int e_c [n_e] ;
	for(int i(0); i < n_e ; i++)
	{
jump:
		l = rand()%(taille_l+1);
		c = rand()%(taille_c+1);
		v = rand()%1000;
		for(int j (0) ; j < i ; j++)
		{
			if(e_l [j] == l && e_c [j] == c)
					goto jump;
		}
		e_l [i] = l;
		e_c [i] = c;
		rempl(l,c,v,nom_fichier);
	}
}

void rempl(int l , int c ,int valeur , string nom_fichier)
{
	ofstream fichier(nom_fichier.c_str(), ios::out | ios::app);
	if(fichier)
	{	
		fichier<<l<<" "<<c<<" "<<valeur<<endl;	
	}
	else
		cerr<<"Impossible d'ouvrir le fichier"<<endl;
}

void test( int nbr_l, double densite )
{
	string operation = "";
	Arbre Arithmetique ;
	
	Matrice * res = NULL;
	M_creator(nbr_l,nbr_l,densite,"A");
	M_creator(nbr_l,nbr_l,densite,"B");
	operation = "A+B";
	Arithmetique.Arithmetique(operation);
	res = Arithmetique.resultat();
	operation = "A-B";
	Arithmetique.Arithmetique(operation);
	res = Arithmetique.resultat();
	operation = "A*B";
	Arithmetique.Arithmetique(operation);
	res = Arithmetique.resultat();
	operation = "A^2";
	Arithmetique.Arithmetique(operation);
	res = Arithmetique.resultat();
	operation = "A^t";
	Arithmetique.Arithmetique(operation);
	res = Arithmetique.resultat();
	if(res != NULL)
		delete res;
	remove("A");
	remove("B");
}
