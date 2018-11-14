

#ifndef _CONTINUO_H
#define _CONTINUO_H
/**
 * @brief Clase que representa la representación en una tabla continuo de la distribución de
 * frecuencias de una variable estadística
 * @warning La variable puede tener como máximo solamente 100 modalidades
 */
class Continua{
  private:
    Tabla tabla;
    Intervalo xi[tabla.TAMANO];
    double marcas_clase[tabla.TAMANO];


  public:
    /**
    * @brief Modifica la tabla estadística a partir de los valores que
    * ha tomado la variable estadística que queremos estudiar.
    * @param n Tamaño de la muestra/población
    * @param amplitud: Amplitud de los intervalos.Si no se dan se calculan automáticamente
    */
    void crearPorValores (unsigned int n, unsigned int amplitud = 0);

    /**
    * @brief Modifica la tabla estadística a partir de los valores que
    * ha tomado la variable estadística que queremos estudiar
    * @param n Tamaño de la muestra/población
    */
    void crearPorDistribucion (unsigned int k);

};
#endif
