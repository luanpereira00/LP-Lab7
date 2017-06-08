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
*	@param num O numero que sera vericado
*	@return Retorna bool para o numero ser primo
*/
bool isPrime(int num){
	if(num<=1) return false;
	else if(num == 2) return true;
	else if(num%2==0) return false;
	else{
		int divisor = 3;
		while(divisor<num){
			if(num%divisor==0) return false;

			divisor+=2;
		}
	}
	return true;

}

/** @brief Funcao principal */
int main(int argc, char** argv) {    
	vector<int> v;
	string aux;
	int n = 0, i=2, num;
	set<int> primos;
	aux = argv[1];

	//cout << aux << endl;

	n = atoi(aux.c_str());

	while(i<=n) {
		v.push_back(i);
		i++;
	}   
	//print_elements(v);

	for(auto it = v.begin(); it < v.end(); it++){
		num = *find_if(it, v.end(), isPrime);
		if(num>=2) primos.insert(num);
	}  
	aux = "Numeros primos [1-"+to_string(n)+"]:";
	print_elements(primos, aux.c_str());
	return 0; 
}
