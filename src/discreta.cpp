#include "discreta.h"
#include "tabla.h"
#include "auxiliares.h"

using namespace std;


void Discreta::crearPorValores (unsigned int n){
  double Aaux[n];
  unsigned int k = 0;

  for (int i=0; i<n; i++) {
      double aux;
      cin >> aux;

      Aaux[i] = aux;
      bool n_modalidad = true;

      for (int j=0; j<k; j++)
          if (Aaux[i]==xi[j])
              n_modalidad = false;

      if (n_modalidad) {
          xi[k] = Aaux[i];
          k++;
      }
  }

  ordena(xi,k);

  unsigned int n_i[k];

  for (int l=0; l < k ; l++) {
      unsigned int aux = 0;

      for (int m=0; m<n; m++)
          if (xi[l]==Aaux[m])
              aux++;

      n_i[l] = aux;
  }

  string xiS[k];///Arrat

  for (int ii=0; ii<k; ii++) {
    string aux_string = to_string(xi[ii]);
    xiS[ii] = aux_string;
  }

  Tabla t (xiS,n_i,k);

  tabla = t;
}


void Discreta::crearPorDistribucion (unsigned int k){
  string x_i[k];
  unsigned int n_i[k];

  for (int i=0; i<k; i++) {
      double aux_mod = 0;
      unsigned int aux_n = 0;
      cin >> aux_mod >> aux_n;

      xi[i] = aux_mod; ///<Array de cálculo;
      string aux_string = to_string(aux_mod);        ///<Conversion de double a string

      x_i[i] = aux_string; ///< De representación
      n_i[i] = aux_n;
  }

  Tabla t (x_i,n_i,k);
  tabla = t;
}
