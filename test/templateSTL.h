#ifndef TEMPLATE_STL_H
#define TEMPLATE_STL_H

#include <numeric>
using std::accumulate;

#include <iterator>
using std::iterator;

#include <vector>
using std::vector;

template <typename InputIterator> 
InputIterator closest2mean(InputIterator first, InputIterator last){
	int soma = accumulate(first, last, 0);

	int cont=0;
	for (auto it = first; it != last; ++it) {
	    cont++;
	}

	float media = soma/(float)cont;
	float *modulo = new float[cont];
	int i=0;
	float menor;
	int menorI = 0;

	for (auto it = first; it != last; ++it) {
	    modulo[i] = (*it)-media;
	    
	    if(modulo[i]<0) modulo[i]*=-1;

	    if(i==0) {
	    	menor=modulo[i];
	    	menorI=i;
	    }
	    if(modulo[i]<menor) {
			menor=modulo[i];
			menorI=i;
		}
	    i++;
	}

	i=0;
	auto it = first;
	while(it != last and i<menorI){
		i++;
		it++;
	}

	//cout << soma << " - " << cont << " - " << media << endl;
	return it;
}

#endif