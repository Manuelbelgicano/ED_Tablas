#ifndef _DISCRETA_H
#define _DISCRETA_H
/**
 * @brief Clase que representa la representación en una tabla discreta de la distribución de
 * frecuencias de una variable estadística
 * @warning La variable puede tener como máximo solamente 100 modalidades
 */

 class Discreta{
   private:
     Tabla tabla;
     double xi[tabla.TAMANO]; ///< Array de calculo;


   public:
     /**
     * @brief Modifica la tabla estadística a partir de los valores que
     * ha tomado la variable estadística que queremos estudiar.
     * @param n Tamaño de la muestra/población
     */
     void crearPorValores (unsigned int n);

     /**
     * @brief Modifica la tabla estadística a partir de los valores que
     * ha tomado la variable estadística que queremos estudiar
     * @param n Tamaño de la muestra/población
     */
     void crearPorDistribucion (unsigned int k);

 };
 #endif
