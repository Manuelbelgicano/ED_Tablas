/**
 * @file table.h
 * @author Manuel Gachs Ballegeer
 */
 
#include<vector>
#include<string>
#include<istream>

#ifndef _TABLE_H
#define _TABLE_H
 
template <class T>
class table {
/**
 * @brief TDA table
 * Una instancia @e d del tipo de datos abstracto @c table es una representacion de una tabla de una
 * distribucion estadistica unidimensional, compuesta por una instancia de la clase distribucion, y en caso
 * de ser continua o que las modalidades no sean numeros una lista con intervalos/nombres de cada una de 
 * las modalidades. Lo representamos como una lista de modalidades y una distribucion.
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
	 * @section faConjunto Funcion de abstraccion
	 * Un objeto valido @e rep del TDA distribution representa al valor
	 * (rep.info,rep.titles,rep.dist)
	 */
	std::string info = "noname_discrete";	///> Tipo de distribucion
	std::vector<T> titles;			///> Nombres de las modalidades o intervalos
	distribution dist;			///> Distribucion de la tabla
	void copy(const table &orig);		///> Copia un objeto en otro
public:
	/**
	 * @brief Constructor primitivo
	 * @param _k Numero de modalidades
	 */
	table(const size_t &_k=0);
	/**
	 * @brief Constructor por copia
	 * @param orig Objeto table que se copia
	 */
	table(const table &orig) {copy(orig);}
	/**
	 * @brief Consulta sobre el tipo de tabla
	 * @return El tipo de tabla
	 */
	std::string get_info() const;
	/**
	 * @brief Consulta sobre el numero de modalidades
	 * @return El numero de modalidades
	 */
	size_t get_nmod() const {return dist.get_nmod();}
	/**
	 * @brief Consulta sobre la poblacion de la muestra
	 * @return La poblacion de la muestra
	 */
	size_t get_pop() const {return dist.get_pop();}
	/**
	 * @brief Consulta sobre una modalidad de la distribucion
	 * @param i Modalidad que se quiere consultar
	 * @return Un par modalidad-frecuencia
	 * @pre i debe ser una modalidad valida
	 */
	float* get_mod(const size_t &i) const {return dist.get_mod(i);}
	/**
	 * @brief Consulta sobre una modalidad de la distribucion
	 * @param i Modalidad que se quiere consultar
	 * @return El titulo o intervalo de la modalidad
	 * @pre i debe ser una modalidad valida
	 *	La distribucion debe tener titulos o intervalos
	 */
	T& get_tmod(const size_t &i) const {return titles[i];}
	/**
	 * @brief Modifica el tipo de distribucion
	 * @param ninfo Nuevo numero tipo de distribucion
	 * @post Los nombres/intervalos anteriores seran eliminados
	 */
	void set_info(const std::string &ninfo);
	/**
	 * @brief Modifica el numero de modalidades de una distribucion
	 * @param _k Nuevo numero de modalidades
	 * @pre El argumento _k debe ser no negativo
	 */
	void set_nmod(const size_t &_k);
	/**
	 * @brief Aniade una modalidad a la distribucion
	 * @param i Posicion donde se quiere aniadir la modalidad
	 * @param x Modalidad a aniadir
	 * @param n Frecuencia absoluta de la modalidad
	 * @param t Nombre o intervalo de la modalidad.
	 * @pre La frecuencia no debe ser vacia
	 */
	void add_mod(const size_t &i=-1,const float &x,const unsigned int &n,const T &t);
	/**
	 * @brief Elimina una modalidad a la distribucion
	 * @param i Modalidad a eliminar
	 * @pre i debe ser una modalidad valida
	 */
	void susbt_mod(const size_t &i);
	/**
	 * @brief Sobrecarga del operador de asignacion
	 * @param tabl Objeto que se asigna
	 * @return El objeto asignado
	 */
	table& operator=(const table &tabl);
	/**
	 * @brief Sobrecarga del operador de entrada
	 */
	friend std::istream& operator>>(std::istream &is,table &t);
}

std::istream& operator>>(std::istream &is,table &t);

#include"table.cpp"
#endif
