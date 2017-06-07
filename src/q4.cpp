/**
 * @file	q4.cpp
 * @brief	Funcao principal que imprime todo os primos entre 1 e o valor digitado pelo usuario
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	15/05/2017
 * @date	15/05/2017
 */

#include <iostream>
using std::cout;
using std::endl;

#include <vector> 
using std::vector; 

#include <algorithm>
using std::find_if;

#include <string>
using std::string;
using std::to_string;

#include <set> 
using std::set; 
 
#include "templateSTL.h"

/** @brief Funcao que verifica se um numero eh primo 
*	@param i O numero que sera vericado
*	@return Retorna bool para o numero ser primo
*/
bool isPrime(int i){
	int j=2;
	while(j<=i/2){
		if(i%j==0) return false;
		j++;
	}
	return true;
}

/** @brief Funcao principal */
int main(int argc, char** argv) {    
	vector<int> v;
	set<int> y;
	string aux;
	int n = 0, i=2;

	aux = argv[1];

	cout << aux << endl;

	n = atoi(aux.c_str());

	while(i<n) {
		v.push_back(i);
		i++;
	}   

	//print_elements(v);
	auto it = v.begin();
	while(it!=v.end()){
		y.insert(*(find_if(it, v.end(), isPrime)));
		it++;
	}  
	aux = "Numeros primos [1-"+to_string(n)+"]:";
	print_elements(y, aux.c_str());
	return 0; 
}
