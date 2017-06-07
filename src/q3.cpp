/**
 * @file	q3.cpp
 * @brief	Funcao principal que calcula equacoes matematicas usando notacao polonesa reversa
 * @since	15/05/2017
 * @date	15/05/2017
 */

#include <iostream>
using std::cout;
using std::endl;

#include <stack> 
using std::stack; 

#include <string>
using std::string;
 
#include "templateSTL.h"

/**@brief Funcao principal */
int main(int argc, char ** argv) {    
	stack<string> pilha;
	int i=1;
	while(i<argc){
		pilha.push(argv[i]);
		i++;  
	}
	
	cout << "Resultado: " << solveRPN(pilha) << endl;
	return 0; 
}