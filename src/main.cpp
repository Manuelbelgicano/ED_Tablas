/**
* @file main.cpp
* @author Manuel Gachs Ballegeer
*/

#include<iostream>
#include"tablasdiscretas.h"
#include"auxiliares.h"

using namespace std;

int main() {
    char eleccion= 'a';
    
    while (eleccion=='a' || eleccion=='b') {
        cin >> eleccion;
        
        if (eleccion=='a') {///<Crea una tabla a partir de un conjunto de valores          
            int poblacion;
            cin >> poblacion;
            
            TablaDiscreta t1 = crearPorValores(poblacion);
            markdown(t1);
        }
        else if (eleccion=='b') {///<Crea una tabla a partir de la distribución de frecuencias
            int modalidades;
            cin >> modalidades;
            
            TablaDiscreta t2 = crearPorDistribucion(modalidades);
            markdown(t2);
        }
    }
    
    return 0;
}
