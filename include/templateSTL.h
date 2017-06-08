/**
 * @file	templateSTL.h
 * @brief	Declaracoes de funcoes que atuam sobre containers
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	15/05/2017
 * @date	15/05/2017
 */

#ifndef TEMPLATE_STL_H
#define TEMPLATE_STL_H

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::to_string;

#include <numeric>
using std::accumulate;

#include <cstdlib>

/**@brief Template tipo InputIterator */
template <typename InputIterator> 
/**
*	@brief Funcao que aponta o elemento mais proximo a media
*  	@param first O iterador para o inicio do container 
*	@param last O iterador para o final do container
*	@return Retorna um iterador apontando para o elemento mais proximo da media 
*/
InputIterator closest2mean(InputIterator first, InputIterator last){
	int soma = accumulate(first, last, 0);

	int cont=0;
	for (InputIterator it = first; it != last; ++it) {
	    cont++;
	}

	float media = soma/(float)cont;
	float *modulo = new float[cont];
	int i=0;
	float menor;
	int menorI = 0;

	for (InputIterator it = first; it != last; ++it) {
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
	InputIterator it = first;
	while(it != last and i<menorI){
		i++;
		it++;
	}

	cout << "Media: " << media << endl;
	return it;
}

/**@brief Template tipo TContainer */
template<typename TContainer> 
/**
*	@brief Funcao que imprime os elementos de um container
*  	@param collection O container 
*	@param label Uma informacao para a impressao, vazia por default
*	@param separator Um simbolo para separar os elementos do container, espaço eh definido por default
*	@return Sem tipo de retorno 
*/
void print_elements(const TContainer& collection, const char* label="",  const char separator=' '){
	cout << label << " ";
	for(auto it = collection.begin(); it!=collection.end(); ++it){
		cout << *it << separator;
	}
	cout << endl;
}

/**@brief Template tipo TContainer */
template<typename TContainer> 
/**
*	@brief Funcao que resolve equacoes matematicas atraves de notacao polonesa reversa
*  	@param collection O container com as equacoes
*	@return Retorna o resultado da equacao 
*/
int solveRPN(const TContainer collection){
	TContainer *ted = const_cast<TContainer*>(&collection);
	TContainer pilha;
	int op1, op2; 
	string aux="", operandos;
	string opr;
	//cout << "ted->empty" << endl;
	while(!ted->empty()){
		pilha.push(ted->top());
		ted->pop();
	}
	
	while(!pilha.empty()){
		aux = pilha.top();
		pilha.pop();
		
		if(aux=="+") {
			operandos = ted->top();
			ted->pop();
			op2=atoi(operandos.c_str());
			
			operandos = ted->top();
			ted->pop();
			op1=atoi(operandos.c_str());
			cout << op1 << " + " << op2 << endl;
			ted->push(to_string(op1+op2));
		}else if(aux=="-") {
			operandos = ted->top();
			ted->pop();
			op2=atoi(operandos.c_str());
			operandos = ted->top();
			ted->pop();
			op1=atoi(operandos.c_str());
			cout << op1 << " - " << op2 << endl;
			ted->push(to_string(op1-op2));
		}else if(aux=="*"){
			operandos = ted->top();
			ted->pop();
			op2=atoi(operandos.c_str());
			operandos = ted->top();
			ted->pop();
			op1=atoi(operandos.c_str());
			cout << op1 << " * " << op2 << endl;
			ted->push(to_string(op1*op2));
		} else if(aux=="/"){
			operandos = ted->top();
			ted->pop();
			op2=atoi(operandos.c_str());
			operandos = ted->top();
			ted->pop();
			op1=atoi(operandos.c_str());
		cout << op1 << " / " << op2 << endl;
			ted->push(to_string(op1/op2));
		} else {
			ted->push(aux);	
		}

	}	
	aux = ted->top();
	ted->pop();
	return atoi(aux.c_str());
}
#endif