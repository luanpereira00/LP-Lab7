/**
 * @file	q2.cpp
 * @brief	Funcao principal que imprime elementos de um container
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	15/05/2017
 * @date	15/05/2017
 */
#include <set> 
using std::set; 

#include "templateSTL.h"

/** @brief Funcao principal */
int main() {    
	set<int> numeros;    
	numeros.insert(3);    
	numeros.insert(1);    
	numeros.insert(4);    
	numeros.insert(1);    
	numeros.insert(2);   
	numeros.insert(5); 
	print_elements(numeros, "Set: ");    
	print_elements(numeros, "CSV Set: ", ';');    
	return 0; 
}