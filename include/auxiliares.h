#ifndef AUXILIARES_H
#define AUXILIARES_H
//ESTA PARTE ES LA QUE CAMBIA SEGÚN SEA DISCRETA O CONTINUA



/**
* @brief Crea una tabla estadística a partir de los valores que
* ha tomado la variable estadística que queremos estudiar
* @param n Tamaño de la muestra/población
* @return Tabla estadística de la variable a estudiar
*/
Tabla crearPorValores(unsigned int n);

/**
* @brief Crea una tabla estadística a partir de la distribución
* de frecuencias absolutas
* @param k Modalidades de la variable
* @return Tabla estadística de la variable a estudiar
*/
Tabla crearPorDistribucion(unsigned int k);


//ESTA FUNCION ES GENERICA A TODAS LAS DISTRIBUCIONES

/**
 * @brief Escribe en formato markdown la tabla con su título, la población con el
 * tamaño y el número de modalidades
 * @param tabla Tabla estadística de la que se quiere realizar el formateo
 */
void markdown(const Tabla & tabla);

#endif
