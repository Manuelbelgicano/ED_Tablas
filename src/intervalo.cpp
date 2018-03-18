
#include <iostream>
#include "intervalo.h"
#include <string>
using namespace std;

bool Intervalo::validar (double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior){
  bool validez;

  if ( cotaInferior < cotaSuperior )
    validez = true;
  else if ( cotaInferior == cotaSuperior && cerradoInferior == cerradoSuperior )
    validez = true;
  else
    validez = false;

  return validez;
}

Intervalo::Intervalo(){
  cerradoInf = false;
  cerradoSup = false;
  cotaInf = 0;
  cotaSup = 0;
}

Intervalo::Intervalo(double cinf,double csup){
	assert (validar(cinf,csup, true, true));
	cotaInf = cinf;
	cotaSup = csup;
	cerradoInf = true;
	cerradoSup = true;
}

Intervalo::Intervalo (double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior){
  cotaInf = cotaInferior;
	cotaSup = cotaSuperior;
	cerradoInf = cerradoInferior;
	cerradoSup = cerradoSuperior;
}

double Intervalo::getCotaInf() const{
  return cotaInf;
}

double Intervalo::getCotaSup() const{
  return cotaSup;
}
double getValorIntermedio()const{
  return (cotaSup*cotaInf)/2;
}

bool Intervalo::esCerradoInf() const{
  return cerradoInf;
}

bool Intervalo::esCerradoSup() const{
  return cerradoSup;
}

bool Intervalo::esVacio () const{
  bool vacio;

  if ( cotaInf == cotaSup && cerradoInf == false && cerradoSup == false ){
    vacio = true;
  }
  else{
    vacio = false;
  }
  return vacio;
}

bool Intervalo::estaDentro ( double n ) const{
  bool dentro;

  if ( cerradoInf ){
    if ( cerradoSup ){
      if ( n >= cotaInf && n <= cotaSup ){
        dentro = true;
      }
      else{
        dentro = false;
      }
    }
    else{
      if ( n >= cotaInf && n < cotaSup){
        dentro = true;
      }
      else{
        dentro = false;
      }
    }
  }
  else {
    if ( cerradoSup ){
      if (n > cotaInf && n <= cotaSup){
        dentro = true;
      }
      else{
        dentro = false;
      }
    }
    else{
      if ( n > cotaInf && n < cotaSup){
        dentro = true;
      }
      else{
        dentro = false;
      }
    }
  }

  return dentro;
}

string Intervalo::aString() const{
  string inter_string;

  string izq;
  string der;

  if ( i.esCerradoInf() ){
    izq = "[";
  }
  else{
    izq = "(";
  }

  if ( i.esCerradoSup() ){
    der = "]";
  }
  else{
    der = ")";
  }

  inter_string = izq + to_string( i.getCotaInf() ) + "," + to_string( i.getCotaSup() ) + der;

  return inter_string;
}

//CODIGO PRESCINDIBLE ABAJO
void escribir(const Intervalo & i ){
  char izq;
  char der;

  if ( i.esCerradoInf() ){
    izq = '[';
  }
  else{
    izq = '(';
  }

  if ( i.esCerradoSup() ){
    der = ']';
  }
  else{
    der = ')';
  }

  cout << izq << i.getCotaInf() << "," << i.getCotaSup() << der;


}
//Fin de codigo PRESCINDIBLE.
//---



void leer( Intervalo & i ){
  char izq;
  char der;
  bool cerradoInf;
  bool cerradoSup;
  int cotaInf;
  int cotaSup;
  char aux;


  cin >> izq >> cotaInf >> aux >> cotaSup >> der;

  if ( izq == '('){
    cerradoInf = false;
  }
  else if (izq == '['  ){
    cerradoInf = true;
  }
  cout << der;
  if ( der == ')'){
    cerradoSup = false;
  }
  else if (der == ']'  ){
    cerradoSup = true;
  }
  Intervalo nuevo (cotaInf,cotaSup,cerradoInf,cerradoSup);
  i = nuevo;

}
Intervalo interseccion(const Intervalo & intervalo1, const Intervalo & intervalo2){
  int cotaInf = 0;
  int cotaSup = 0;
  bool cerradoInf = false;
  bool cerradoSup = false;

  if ( intervalo1.cotaInf > intervalo2.cotaInf ){
    cotaInf = intervalo1.cotaInf;
    if ( intervalo1.cerradoInf){
	     cerradoInf = true;
    }
  }
  else if (intervalo1.cotaInf == intervalo2.cotaInf){
    cotaInf = intervalo1.cotaInf;
    if ( intervalo1.cerradoInf == intervalo2.cerradoInf ){
      cerradoInf = intervalo1.cerradoInf;
    }
  }
  else{
    cotaInf = intervalo2.cotaInf;
    if ( intervalo2.cerradoInf ){
	      cerradoInf = true;
    }
  }

  if ( intervalo1.cotaSup < intervalo2.cotaSup ){
    cotaSup = intervalo1.cotaSup;
    if ( intervalo1.cerradoSup){
	     cerradoSup = true;
    }
  }
  else if (intervalo1.cotaSup == intervalo2.cotaSup){
    cotaSup = intervalo1.cotaSup;
    if ( intervalo1.cerradoSup == intervalo2.cerradoSup ){
      cerradoSup = intervalo1.cerradoSup;
    }
  }
  else{
    cotaSup = intervalo2.cotaSup;
    if ( intervalo2.cerradoSup){
	      cerradoSup = true;
    }
  }
//ERROR EN VALIDAR
  Intervalo intervalof ( cotaInf, cotaSup, cerradoInf, cerradoSup );
  if ( ! intervalof.validar(cotaInf, cotaSup, cerradoInf , cerradoSup) ){
    intervalof.cotaSup = 0;
    intervalof.cotaInf = 0;
    intervalof.cerradoInf = false;
    intervalof.cerradoSup = false;
  }

  return intervalof;
}


void ordena_intervalos ( Intervalo a[], int util){
  int min;
  Intervalo aux;

  for (int i=0; i<util; i++) {
    min = i;

    for (int j=i; j<util; i++)
      if (a[j].getValorIntermedio() < a[min].getValorIntermedio())
	     min = j;

    aux = a[i];
    a[i] = a[min];
    a[min] = aux;
  }
}
