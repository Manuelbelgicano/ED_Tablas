#include <iostream>
#include <assert.h>

#ifndef _INTERVALO_H
#define _INTERVALO_H

/**@brief Define la clase Intervalo

*/
class Intervalo{
private:
    bool cerradoInf;
    bool cerradoSup;
    double cotaInf;
    double cotaSup;

    /**
     * @brief comprueba que los argumentos definen un intervalo correcto
     * @param cotaInferior
     * @param cotaSuperior
     * @param cerradoInferior
     * @param cerradoSuperior
     * @pre cotaInferior < cotaSuperior
     * @pre cotaInferior == cotaSuperior && cerradoInferior == cerradoSuperior
     * @return @retval true si correcto @retval false en otro caso
     */
    bool validar(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior);
public:
    /**
     *  @brief Crea un intervalo vacio
     */
    Intervalo();
    /**
     * @brief Crea un Intervalo cerrado
     * @param cotaInferior
     * @param cotaSuperior
     * @pre El intervalo es válido
     */
    Intervalo(double cotaInferior, double cotaSuperior);
    /**
     * @brief Crea un intervalo cualquiera
     * @param cotaInferior
     * @param cotaSuperior
     * @param cerradoInferior
     * @param cerradoSuperior
     * @pre El intervalo es válido
     */
    Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior);
    /**
     * @brief Devuelve la cota inferior del intervalo
     * @return El valor de la cota
     */
    double getCotaInf()const ;
    /**
     * @brief Devuelve la cota superior del intervalo
     * @return El valor de la cota
     */
    double getCotaSup()const ;

    /**@brief Obtiene el valor medio del intervalo.
       @return Valor medio del intervalo
    */
    double getValorIntermedio()const;
    /**
     * @brief Consulta si el intervalo es cerrado en su cota inferior
     * @return @retval true si es cerrado @retval false si es cerrado
     */
    bool esCerradoInf()const ;
    /**
     * @brief Consulta si el intervalo es cerrado en su cota superior
     * @return @retval true si es cerrado @retval false si es cerrado
     */
    bool esCerradoSup()const ;
    /**
     * @brief Consulta si el intervalo almacenado es vacío o no
     * @return @retval true si es un intervalo vacío, @retval false en otro caso
     */
    bool esVacio()const ;
    /**
     * @brief Consulta si un determinado valor está dentro del intervalo
     * @param n El valor consultado
     * @return @retval true si el valor @p n pertenece al intervalo, @retval false en otro caso
     */
    bool estaDentro(double n)const ;
    /**
     * @brief Convierte un intervalo en un string
     * @return La representación del intervalo en forma de tipo de dato string
    */
    std::string aString() const;
    /**
     * @brief realiza la interseccion de dos intervalos, puede
     * resultar un intervalo vacı́o en caso de que no tengan cotas
     * comunes, en caso contrario se revisan las cotas.
     * @param i1 primer intervalo de entrada
     * @param i2 segundo intervalo de entrada
     * @return devuelve el intervalo resultante de realizar la
     * interseccion entre los dos intervalos de entrada
    */
    friend Intervalo interseccion(const Intervalo & intervalo1, const Intervalo & intervalo2);
};

//FUNCIONES AUXILIARES

/**
* @brief Imprime los valores de un intervalo de forma visual según lo indicado en el guión
* @param i El intervalo
*/
void escribir(const Intervalo &i);

/**
* @brief Lee los valores del intervalo según el formato indicado en el guión
* @param i El intervalo
*/
void leer(Intervalo &i);

/**
 * @brief Ordena un array de intervalos por el método de selección.
 * @param a Array a ordenar
 * @param util Posiciones útiles del array
 * @pre Ningún intervalo se intersecciona con otro.
 */
void ordena_intervalos ( Intervalo a[], int util);



#endif
