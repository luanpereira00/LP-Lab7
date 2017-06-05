#include <iostream>
using std::cout;
using std::endl;

#include <stack> 
using std::stack; 

#include <string>
using std::string;
 
#include "templateSTL.h"

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