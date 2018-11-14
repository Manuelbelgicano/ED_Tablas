/**
 * @file print.h
 * @author Manuel Gachs Ballegeer
 */

#include<string>
#include"table.h"

#ifndef _PRINT_H
#define _PRINT_H

/**
 * @brief Imprime la tabla en el formato seleccionado
 * @param t Tabla a imprimir
 * @param format Formato en el que se quiere imprimir
 * @param file Fichero en el que se quiere escribir la tabla
 * @return @retval true Si ha tenido exito
 * 	   @retval false Si ha habido un error
 */
bool print_table(const table &t,const std::string &mode,const std::string &file="none");

//------------------------------------------SIN FORMATO------------------------------------------
/**
 * @brief Imprime en formato de texto plano una tabla de una distribucion
 * @param t Tabla a imprimir
 */
void printplain_console(const table &t);
/**
 * @brief Imprime en formato de texto plano una tabla de una distribucion
 * @param t Tabla a imprimir
 * @param file Fichero en el que se quiere escribir la tabla
 * @return @retval true Si ha tenido exito
 * 	   @retval false Si ha habido un error
 */
bool printplain_file(const table &t,const std::string &file);

//---------------------------------------FORMATO MARKDOWN----------------------------------------
/**
 * @brief Imprime en formato markdown una tabla de una distribucion
 * @param t Tabla a imprimir
 * @param file Fichero en el que se quiere escribir la tabla
 * @return @retval true Si ha tenido exito
 * 	   @retval false Si ha habido un error
 */
bool printmd_file(const table &t,const std::string &file);

//-----------------------------------------FORMATO LATEX-----------------------------------------
/**
 * @brief Imprime en formato latex una tabla de una distribucion
 * @param t Tabla a imprimir
 * @param file Fichero en el que se quiere escribir la tabla
 * @return @retval true Si ha tenido exito
 * 	   @retval false Si ha habido un error
 */
bool printlatex_file(const table &t,const std::string &file);

#endif
