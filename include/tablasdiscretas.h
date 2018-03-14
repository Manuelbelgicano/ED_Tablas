/**
* @file tabladiscreta.h
* @author Manuel Gachs Ballegeer
*/

#ifndef _TABLADISCRETA_H
#define _TABLADISCRETA_H
/**
 * @brief Clase que representa la representación en una tabla de la distribución de
 * frecuencias de una variable estadística
 * @warning La variable puede tener como máximo solamente 100 modalidades
 */
class TablaDiscreta {
	private:
		unsigned int n;///< Tamaño de la población
		unsigned int k;///< Número de modalidades de la variable
		double xi[100];///< Modalidades de la variable estadística
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
		TablaDiscreta(double x_i[], unsigned int n_i[], unsigned int K);
		/**
		* @brief Constructor primitivo a partir de la distribución de frecuencias
		* relativas de la variable
		* @param x_i Valores de las modalidades
		* @param f_i Valores de las frecuencias relativas
		* @param N Tamaño de la población
		* @pre f_i[i]!=0
		*/
		TablaDiscreta(double x_i[], double f_i[], unsigned int N, unsigned int K);
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
