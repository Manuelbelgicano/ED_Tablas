/**
 * @file auxiliares.h
 * @author Manuel Gachs Ballegeer
 */

#ifndef AUXILIARES_H
#define AUXILIARES_H

/**
* @brief Crea una tabla estadística a partir de los valores que
* ha tomado la variable estadística que queremos estudiar
* @param n Tamaño de la muestra/población
* @return Tabla estadística de la variable a estudiar
*/
TablaDiscreta crearPorValores(unsigned int n);

/**
* @brief Crea una tabla estadística a partir de la distribución
* de frecuencias absolutas
* @param k Modalidades de la variable
* @return Tabla estadística de la variable a estudiar
*/
TablaDiscreta crearPorDistribucion(unsigned int k);

/**
 * @brief Escribe en formato markdown la tabla con su título, la población con el
 * tamaño y el número de modalidades
 * @param tabla Tabla estadística de la que se quiere realizar el formateo
 */
void markdown(const TablaDiscreta & tabla);

#endif