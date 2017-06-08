/**
 * @file	q5.cpp
 * @brief	Funcao principal que calcula e exibe os quadrados dos numeros entre 1 e 9 (incluidos)
 * @author	Desconhecido
 * @since	15/05/2017
 * @date	15/05/2017
 */
#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::back_inserter;

#include <vector>
using std::vector;

#include <algorithm>
using std::transform;

/** 
*@brief Calcula o quadrado de um valor
*@param val O valor que tera seu quadrado calculado
*@return Retorna o quadrado de val
*/
int square(int val) {
	return val * val;
}

/** @brief Funcao principal */
int main(int argc, char* argv[]) {
	vector<int> col;
	vector<int> col2;
	for (int i = 1; i <= 9; ++i) {
		col.push_back(i);
	}
	transform(col.begin(), col.end(), back_inserter(col2), square);
	for (vector<int>::iterator it = col2.begin(); it != col2.end(); ++it) {
		cout << (*it) << " ";
	}
	cout << endl;
	return 0;
}