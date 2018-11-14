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

distribution::distribution(size_t _k=0) {
	if (_k>0)
		set(_k);
	else
		set(0);
}

distribution::distribution(const distribution &orig) {
	copy(orig);
}

size_t distribution::get_pop() const {
	int aux = 0;
	for (size_t i=0;i<k;i++)
		aux += ni[i];
	return aux;
}

float* distribution::get_mod(const size_t &i) const{
	float mod[2];
	mod[0] = xi[i];
	mod[1] = ni[i];
	return mod;
}

std::vector<float> distribution::get_fi() const {
	std::vector<float> fi;
	unsigned int n = get_pop();
	for (size_t i=0;i<k;i++)
		fi.push_back((float)ni[i]/n);
	
	return fi;
}

std::vector<float> distribution::get_Fi() const {
	std::vector<float> fi = get_fi();
	std::vector<float> Fi;
	float aux = 0;
	for (size_t i=0;i<k;i++) {
		aux += fi[i];
		Fi.push_back(aux);
	}
	
	return Fi;
}

std::vector<unsigned int> distribution::get_Ni() const {
	std::vector<unsigned int> Ni;
	float aux = 0;
	for (size_t i=0;i<k;i++) {
		aux += ni[i];
		Ni.push_back(aux);
	}
	
	return Ni;
}

void distribution::set_nmod(const size_t &_k) {
	set(_k);
}

void distribution::add_mod(const size_t &i,const float &x,const unsigned int &n) {
	if (i!=-1) {
		xi[i] = x;
		ni[i] = n;
	} else {
		xi.push_back(x);
		ni.push_back(n);
		k++;
	}
}

void subst_mod(const size_t &i) {
	xi.erase(xi.begin()+i);
	ni.erase(ni.begin()+i);
	k--;	
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

distribution& distribution::operator=(const distribution &dist) {
	copy(dist);
	return aux;
}
