#include<iostream>
#include"tabla.h"
#include"auxiliares.h"

using namespace std;

int main() {
    char eleccion= 'a';

    //while (eleccion=='a' || eleccion=='b') {  //Entra en bucle infinito no se por que ocurre
        cin >> eleccion;

        if (eleccion=='a') {///<Crea una tabla a partir de un conjunto de valores
            int poblacion;
            cin >> poblacion;

            Tabla t1 = crearPorValores(poblacion);
            markdown(t1);
        }
        else if (eleccion=='b') {///<Crea una tabla a partir de la distribución de frecuencias
            int modalidades;
            cin >> modalidades;

            Tabla t2 = crearPorDistribucion(modalidades);
            markdown(t2);
        }
    //}

    return 0;
}
