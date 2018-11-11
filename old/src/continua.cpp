#include "intervalo.h"
#include "tabla.h"
#include "continua.h"
#include <string>

using namespace std;

void Continua::crearPorValores (unsigned int n, ){ //FUCK
  Intervalo Aaux[n];
  unsigned int k = 0;
}

void Continua::crearPorDistribucion(unsigned int k){
  string x_i[k];
  unsigned int n_i[k];


  for (int i = 0; i < k ; i++){
    Intervalo aux_mod;
    unsigned int aux_n;
    leer(aux_mod);
    cin >> aux_n;

    xi[i] = aux_mod; ///<Array cálculo;
    n_i = aux_n;
    x_i[i] = aux_mod.aString(); ///Array representación
  }
  
  for ( int i = 0; i < k; i++ ){
    marcas_clase[i] = xi[i].getValorIntermedio(); ///<Array de marcas de clase para el cálculo.
  }
  
    Tabla t (x_i,n_i,k)
    tabla = t;
}
