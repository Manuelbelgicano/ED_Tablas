/**
 * @file distribution.h
 * @author Manuel Gachs Ballegeer
 */

#include<vector>

#ifndef _DISTRIBUTION_H
#define _DISTRIBUTION_H

class distribution {
/**
 * @brief TDA distribution
 * Una instancia @e d del tipo de datos abstracto @c distribution es una distribucion estadistica
 * unidimensional, compuesta por su numero de modalidades, sus modalidades y la frecuencia absoluta asociada
 * a cada una de las modalidades. Lo representamos como una lista de modalidades y otra de frecuencias.
 *
 * Ejemplo de su uso
 * @include
 *
 * @author Manuel Gachs Ballegeer
 */
private:
	/**
	 * @page repConjunto Representacion del TDA distribution
	 * @section invConjunto Invariante de la representacion
	 * El invariante es \e rep.k>=0
	 * @section faConjunto Funcion de abstraccion
	 * Un objeto valido @e rep del TDA distribution representa al valor
	 * (rep.k,rep.xi,rep.ni)
	 */
	std::vector<float> xi;				///> Lista de modalidades
	std::vector<unsigned int> ni;			///> Frecuencia absoluta de las modalidades
	size_t k;					///> Numero de modalidades
	void copy(const distribution &orig);		///> Copia una distribucion en otra
	void set(const size_t &_k);			///> Redistribuye el tamaño de una distribucion
	void sort();					///> Ordena una distribucion de menor a mayor
public:
	/**
	 * @brief Constructor primitivo
	 * @param _k Numero de modalidades de la distribucion
	 */
	distribution(const size_t &_k=0);
	/**
	 * @brief Constructor por copia
	 * @param orig Distribucion que se va a copiar
	*/
	distribution(const distribution &orig);
	/**
	 * @brief Consulta sobre el numero de modalidades
	 * @return El numero de modalidades
	 */
	size_t get_nmod() {return k};
	/**
	 * @brief Consulta sobre una modalidad de la distribucion
	 * @param i Modalidad que se quiere consultar
	 * @return Un par modalidad-frecuencia
	 * @pre i debe ser una modalidad valida
	 */
	float *get_mod(const size_t &i);
	/**
	 * @brief Modifica el numero de modalidades de una distribucion
	 * @param _k Nuevo numero de modalidades
	 * @pre El argumento _k debe ser no negativo
	 */
	void set_nmod(const size_t &_k);
	/**
	 * @brief Aniade una modalidad a la distribucion
	 * @param x Modalidad a aniadir
	 * @param n Frecuencia absoluta de la modalidad
	 * @pre La frecuencia no debe ser vacia
	 */
	void add_mod(const float &x,const unsigned int &n);
};

#endif
