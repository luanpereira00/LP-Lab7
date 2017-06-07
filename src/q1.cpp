/**
 * @file	q1.cpp
 * @brief	Funcao principal que calcula o elemento de um container mais proximo da media
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	15/05/2017
 * @date	15/05/2017
 */

#include <iostream>
using std::cout;
using std::endl;

#include <vector> 
using std::vector; 
 
#include "templateSTL.h"

/** @brief Funcao principal */
int main() {    
	vector<int> v { 1, 2, 3, 30, 40, 50 };    
	auto result = closest2mean(v.begin(), v.end());    
	cout <<"O elemento mais proximo da media eh o "<< (*result) << endl;    
	return 0; 
}
