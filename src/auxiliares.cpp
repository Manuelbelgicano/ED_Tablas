#include<iostream>
#include"tabla.h"
#include"auxiliares.h"

//VER ANOTACION PUESTA EN AUXILIARES.H

using namespace std;

Tabla crearPorValores(unsigned int n) {
    double Aaux[n];
    double x_i[100];
    unsigned int k = 0;

    for (int i=0; i<n; i++) {
        double aux;
        cin >> aux;
                                                       
        Aaux[i] = aux;
        bool n_modalidad = true;
	
        for (int j=0; j<k; j++)
            if (Aaux[i]==x_i[j])
                n_modalidad = false;

        if (n_modalidad) {
            x_i[k] = Aaux[i];
            k++;
        }
    }
   
    ordena(x_i,k);    
      
    unsigned int n_i[k];

    for (int l=0; l<k; l++) {
        unsigned int aux = 0;

        for (int m=0; m<n; m++)
            if (x_i[l]==Aaux[m])
                aux++;

        n_i[l] = aux;
    }

    string xi[k];

    for (int ii=0; ii<k; ii++) {
      string aux_string = to_string(x_i[ii]);
      xi[ii] = aux_string;
    }
    
    Tabla t (xi,n_i,k);

    return t;
}

Tabla crearPorDistribucion(unsigned int k) {
    string x_i[k];
    unsigned int n_i[k];

    for (int i=0; i<k; i++) {
        double aux_mod = 0;
        unsigned int aux_n = 0;
        cin >> aux_mod >> aux_n;

        string aux_string = to_string(aux_mod);        ///<Conversion de double a string

        x_i[i] = aux_string;
        n_i[i] = aux_n;
    }

    Tabla t (x_i,n_i,k);

    return t;
}

void markdown(const Tabla & tabla) {
    cout << "\n##";
    char aux = 'm';

    //while (aux!='.') {
    //    cin >> aux;
    //    cout << aux;
    //}

    cout << endl;

    tabla.escribeMD();
    unsigned int auxk = tabla.get_k();
    unsigned int auxn = tabla.get_n();

    cout << "\n- " << auxk << "\n- " << auxn << endl;
}

void ordena (double a[], int util) {
  int min;
  double aux;

  for (int i=0; i<util; i++) {
    min = i;

    for (int j=i; j<util; i++)
      if (a[j]<a[min])
	min = j;

    aux = a[i];
    a[i] = a[min];
    a[min] = aux;
  }
}
