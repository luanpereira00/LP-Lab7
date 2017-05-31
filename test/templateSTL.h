#ifndef TEMPLATE_STL_H
#define TEMPLATE_STL_H

#include <iostream>
using std::cout;
using std::endl;

#include <numeric>
using std::accumulate;

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

	cout << "Media: " << media << endl;
	return it;
}

template<typename TContainer> 
void print_elements(const TContainer& collection, const char* label="",  const char separator=' '){
	cout << label << " ";
	for(auto it = collection.begin(); it!=collection.end(); ++it){
		cout << *it << separator;
	}
	cout << endl;
}

template<typename TContainer> 
int solveRPN(const TContainer collection){
	auto *ted = const_cast<TContainer*>(&collection);
	TContainer pilha;
	int op1, op2; 
	char opr;
	while(!ted->empty()){
		pilha.push(ted->top());

		ted->pop();
	}

	cout << pilha.top() << endl;
	
	op1=pilha.top()-48; //GAMBIARRA?
	
	pilha.pop();
	cout << "OP1=" <<op1 << " " <<pilha.top() << endl;
	bool flag=true;
	int result=0;
	while(!pilha.empty()){
		if(!flag) op1=result;
		flag=false;
		
		
		op2=pilha.top()-48;
		cout << "OP2=" <<op2 << " " <<pilha.top() << endl;
		pilha.pop();
		
		opr=pilha.top();
		pilha.pop();

		cout << "-> " << op1 << opr << op2 << endl;

		if(opr=='+') result = op1+op2;
		if(opr=='-') result = op1-op2;
		if(opr=='*') result = op1*op2;
		if(opr=='/') result = op1/op2;

		cout << endl << "Result = " << result << endl;
	}
	return result;
	
}

#endif