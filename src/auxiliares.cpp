/**
 * @file auxiliares.cpp
 * @author Manuel Gachs Ballegeer 
 */

#include<iostream>
#include"tablasdiscretas.h"
#include"auxiliares.h"

using namespace std;

TablaDiscreta crearPorValores(unsigned int n) {
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
    
    unsigned int n_i[k];
    
    for (int l=0; l<k; l++) {
        unsigned int aux = 0; 
        
        for (int m=0; m<n; m++)
            if (x_i[l]==Aaux[m])
                aux++;
        
        n_i[l] = aux;
    }
    
    TablaDiscreta t (x_i,n_i,k);
    
    return t;
}

TablaDiscreta crearPorDistribucion(unsigned int k) {
    double x_i[k];
    unsigned int n_i[k];
    
    for (int i=0; i<k; i++) {
        double auxx = 0;
        unsigned int auxn = 0;
        cin >> auxx >> auxn;
        
        x_i[i] = auxx;
        n_i[i] = auxn;
    }
    
    TablaDiscreta t (x_i,n_i,k);
    
    return t;
}

void markdown(const TablaDiscreta & tabla) {
    cout << "\n##";
    char aux = 'm';
    
    while (aux!='.') {
        cin >> aux;
        cout << aux;
    }
    
    cout << endl;
    
    tabla.escribeMD();
    unsigned int auxk = tabla.get_k();
    unsigned int auxn = tabla.get_n();
    
    cout << "\n- " << auxk << "\n- " << auxn << endl; 
}