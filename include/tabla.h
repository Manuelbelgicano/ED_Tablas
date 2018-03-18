
#include <string>

#ifndef _TABLA_H
#define _TABLA_H
/**
 * @brief Clase que representa la representación en una tabla de la distribución de
 * frecuencias de una variable estadística.
 * @warning La variable puede tener como máximo solamente 100 modalidades
 */
class Tabla{
	private:
		unsigned int n;///< Tamaño de la población
		unsigned int k;///< Número de modalidades de la variable
		std::string xi[100];///< Modalidades de la variable estadística. Array de representación;
		unsigned int ni[100];///< Frecuencias absolutas de las modalidades
		double fi[100];///< Frecuencias relativas de las modalidades
		unsigned int Ni[100];///< Frecuencias absolutas acumuladas
		double Fi[100];///< Frecuencias relativas acumuladas
	public:
		/**
		* @brief Constructor primitivo a partir de la distribución de frecuencias
		* absolutas de la variable
		* @param x_i Valores de las modalidades
		* @param n_i Valores de las frecuencias absolutas
		* @pre n_i[i]!=0
		*/
		Tabla( std::string x_i[], unsigned int n_i[], unsigned int K);
		/**
		* @brief Constructor primitivo a partir de la distribución de frecuencias
		* relativas de la variable
		* @param x_i Valores de las modalidades
		* @param f_i Valores de las frecuencias relativas
		* @param N Tamaño de la población
		* @pre f_i[i]!=0
		*/
		Tabla( std::string x_i[], double f_i[], unsigned int N, unsigned int K);
		/**
		* @brief Devuelve el tamaño de la población
		* @return El tamaño de la población
		*/
		unsigned int get_n() const;
		/**
		* @brief Devuelve el número de modalidades de la variable
		* @return El número de modalidades de la variable
		*/
		unsigned int get_k() const;
		/**
		* @brief Escribe la tabla en formato de Markdown
		*/
		void escribeMD() const;
		/**
		* @brief Imprime la tabla en la salida estándar
		*/
		void escribe() const;
};

#endif
