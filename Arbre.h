#include <iostream>
using namespace std;
#include <stdlib.h> 
#include "class.h"
/*!
 * \file Arbre.h
 * \brief Resolution d'une expression Arithmetique
 * \author Benhachani Mohamed
 * \version 1.0
 */
struct Noeud {

	string info;
	int imp;
	Noeud * fg;
	Noeud * fd;
};

/*! \class Arbre
* \brief classe representant une expression Arithmetique dans un Arbre 
*/
class Arbre{

	Noeud * R;

	public:
	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe Arbre
	*/
	Arbre();
 
    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Arbre
     */
	~Arbre();
    /*!
     *  \brief Saisie d'un Noeud dans l'Arbre
     *
     *  Methode qui permet d'ajouter un Noeud dans l'Arbre
     *
     *  \param[in] string a :  chaine de caractere contenant l'opérande ou l'opérateur
     *  \param[in] int imp  :  importance de l'operande ou de l'operateur
     */
	void saisie(string a,int imp);

    /*!
     *  \brief Affiche l'Arbre
     *
     *  Affiche l'Arbre avec un parcours en suffixe
     */
	void affiche();
    /*!
     *  \brief Renvoie une Matrice résultante de l'expression
     *
     *  \return La Matrice Resulatante  de l'expression Arithmetique
     */
	Matrice * resultat();
    /*!
     *  \brief Saisie d'un Noeud dans l'Arbre
     *
     *  Methode qui permet d'ajouter un Noeud dans l'Arbre
     *
     *  \param[in] char a   : Operateur
     *  \return Un entier qui représente l'importance de l'operateur
     */
	
	int importance(char car);
    /*!
     *  \brief Remplie l'Arbre Arithmetique apartir d'une expression
     *
     *  Methode qui permet de remplir l'Arbre Arithmetique apartir d'une expression, tant que cette expression est correcte.
     *
     *  \param[in] string exp : expression Arithmetique
     *  \return true si l'expression Arithmetique est juste
     *  false sinon
     *  \bug En cas d'expession Arithmetique incorrecte le contenu de l'Arbre n'est pas detruit 
     */
	
	bool Prior(string exp);
     /*!
     *  \brief Remplie l'Arbre Arithmetique apartir d'une expression
     *
     *  Methode qui permet de remplir l'Arbre Arithmetique apartir d'une expression, tant que cette expression est correcte, si elle n'est pas correcte l'arbre est détruit.
     *
     *  \param[in] string exp : expression Arithmetique
     *  \return true si l'expression Arithmetique est juste
     *  false sinon
     */
	bool Arithmetique(string exp);
};

































