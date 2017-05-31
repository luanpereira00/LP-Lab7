#include <iostream>
using std::cout;
using std::endl;

#include <stack> 
using std::stack; 
 
#include "templateSTL.h"

int main() {    
	stack<char> pilha;
	pilha.push('2');  
	pilha.push('3');
	pilha.push('+');
	pilha.push('5');
	pilha.push('*'); 
	
	cout << "Resultado: " << solveRPN(pilha) << endl;
	return 0; 
}