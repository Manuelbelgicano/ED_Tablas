/**
* @file tablasdiscretas.cpp
* @author Manuel Gachs Ballegeer
*/

#include<iostream>
#include<assert.h>
#include"tablasdiscretas.h"

using namespace std;

TablaDiscreta::TablaDiscreta(double x_i[], unsigned int n_i[], unsigned int K) {
    assert (K<=100);
    
    unsigned int auxn = 0;
    k = K;
    
    for (int i=0; i<k; i++) {
        xi[i] = x_i[i];
        ni[i] = n_i[i];
        auxn += ni[i];
        Ni[i] = auxn;
    }
    
    n = auxn;
    double auxf = 0;
    
    for (int j=0; j<k; j++) {
        fi[j] = ni[j]/n;
        auxf += fi[j];
        Fi[j] = auxf;
    }    
}

TablaDiscreta::TablaDiscreta(double x_i[], double f_i[], unsigned int N, unsigned int K) {
    assert (K<=100);
    
    double auxf = 0;
    unsigned int auxn = 0;
    k = K;
    n = N;
    
    for (int i=0; i<k; i++) {
        xi[i] = x_i[i];
        fi[i] = f_i[i];
        auxf += fi[i];
        Fi[i] = auxf;
        ni[i] = fi[i]*n;
        auxn += ni[i];
        Ni[i] = auxn;
    }
}

unsigned int TablaDiscreta::get_k() const {
    return k;
}

unsigned int TablaDiscreta::get_n() const {
    return n;
}

void TablaDiscreta::escribe() const {
	cout << "   xi   |   ni   |   Ni   |   fi   |   Fi   \n";

	for (int i=0; i<k; i++) {
		cout << "  " << xi[i] << "  |";
		cout << "  " << ni[i] << "  |";
		cout << "  " << Ni[i] << "  |";
		cout << "  " << fi[i] << "  |";
		cout << "  " << Fi[i] << "  |\n";
	}
}

void TablaDiscreta::escribeMD() const {
	cout << "\n| *x_i* | *n_i* | *N_i* | *f_i* | *F_i* |\n";
	cout << "|:---:|:---:|:---:|:---:|:---:|\n";

	for (int i=0; i<k; i++) {
		cout << "| " << xi[i] << " |";
		cout << " " << ni[i] << " |";
		cout << " " << Ni[i] << " |";
		cout << " " << fi[i] << " |";
	}
}