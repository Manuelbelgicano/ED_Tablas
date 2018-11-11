/**
 * @file distribution.cpp
 * @author Manuel Gachs Ballegeer
 */

#include"distribution.h"
#include<vector>

void distribution::copy(const distribution &orig) {
	xi = orig.xi;
	ni = orig.ni;
	k = orig.k;
}

void distribution::set(const size_t &_k) {
	k = _k;
	xi.resize(_k);
	ni.resize(_k);
}

void distribution::sort() {
	float min;
	unsigned int auxfrec;
	size_t aux;
	
	for (size_t i=0;i<k-1;i++) {
		min = xi[i];
		aux = i;
		for (size_t j=i;j<k;j++)
			if (xi[j]<min) {
				min = xi[j];
				aux = j;
			}
		if (aux!=i) {
			auxfrec = ni[aux];
			ni[aux] = ni[i];
			ni[i] = auxfrec;
			xi[aux] = xi[i];
			xi[i] = min; 
		}
	}
}

distribution::distribution(size_t _k=0) {
	if (_k>0)
		set(_k);
	else
		set(0);
}

distribution::distribution(const distribution &orig) {
	copy(orig);
}

float distribution::*get_mod(const size_t &i) {
	float mod[2];
	mod[0] = xi[i];
	mod[1] = ni[i];
	return mod;
}

void distribution::set_nmod(const size_t &_k) {
	set(_k);
}

void distribution::add_mod(const float &x,const unsigned int &n) {
	xi.push_back(x);
	ni.push_back(n);
	k++;
}
