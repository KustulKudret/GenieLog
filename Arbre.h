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
#ifndef ARBRE_ARITMETIQUE_SUR_MATRICE_CREUSE
#define ARBRE_ARITMETIQUE_SUR_MATRICE_CREUSE

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
/*! \struct Noeud
* \brief Noeud pour la creation d'un Arbre   
*/
struct Noeud {

	string info;
	int imp;
	Noeud * fg;
	Noeud * fd;
};

/*! \class Arbre
* \brief Classe representant une expression Arithmetique dans un Arbre.
*/
class Arbre{

	Noeud * R;
	string Path;
	string ** alias;
	int nb_max_alias,nb_alias;
	public:
	/*!
	*  \brief Constructeur de la classe Arbre.
	*/
	Arbre(string chemin="",int tnb_max_alias=50);
 
    /*!
     *  \brief Destructeur de la classe Arbre.
     */
	~Arbre();
    /*!
     *  \brief Methode qui permet d'ajouter un Noeud dans l'Arbre.
     *
     *  \param[in] string a :  chaine de caractere contenant l'opérande ou l'opérateur
     *  \param[in] int imp  :  importance de l'operande ou de l'operateur
     */
	void saisie(string a,int imp);

    /*!
     *  \brief Affiche l'Arbre avec un parcours en suffixe.
     */
	void affiche();
    /*!
     *  \brief Renvoie une Matrice résultante de l'expression.
     *
     *  \return La Matrice Resulatante  de l'expression Arithmetique
     */
	Matrice * resultat();
	/*!
     *  \brief Ajoute un alias dans la matrice alias
     *
     *  \param[in] string & original :  string qui devra etre substitué
     *  \param[in] string & objectif :  string qui va substitué l'ancien
     *	\return True si l'operation est possible False sinon
     */
	bool add_alias(string & original,string & objectif);
    /*!
     *  \brief Supprime un alias dans la matrice alias
     *
     *  \param[in] int num : numero de l'alias
     *	\return True si l'operation est possible False sinon
     */
	bool suppr_alias(int num);
    /*!
     *  \Affiche la matrice d'alias
     *
     */
	void afficher_alias();
    /*!
     *  \brief Substitue les string en raport avec les alias
     *
     *  \param[in,out] string & s : string que je recherche dans alias pour le substitué
     */
	void substitue(string & s);
    /*!
     *  \brief Methode qui renvoie l'importance d'un operateur
     *
     *  \param[in] char a   : Operateur
     *  \return Un entier qui représente l'importance de l'operateur
     */
	
	int importance(char car);
    /*!
     *  \brief Methode qui permet de remplir l'Arbre Arithmetique apartir d'une expression, tant que cette expression est correcte.
     *  En cas d'expession Arithmetique incorrecte le contenu de l'Arbre n'est pas detruit.
     *  \param[in] string exp : expression Arithmetique
     *  \return true si l'expression Arithmetique est juste
     *  false sinon.
    
     */
	
	bool Prior(string exp);
     /*!
     *  \brief Methode qui permet de remplir l'Arbre Arithmetique apartir d'une expression, tant que cette expression est correcte, si elle n'est pas correcte le contenu l'arbre est détruit.
     *
     *  \param[in] string exp : expression Arithmetique
     *  \return true si l'expression Arithmetique est juste
     *  false sinon
     */
	bool Arithmetique(string exp);
};




#endif




























