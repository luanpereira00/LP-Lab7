/**
 * @file	data.cpp
 * @brief	Implementacao dos metodos da classe Data
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#include <iostream>
using std::getline;

#include <sstream> 
using std::istringstream;

#include "data.h"

/**@brief Construtor padrao*/
Data::Data(){
	setDia(1);
	setMes(1);
	setAno(1900);
}

/**@brief Destrutor padrao*/
Data::~Data(){
	//FAZ NADA
}
/**@brief Construtor parametrizado*/
Data::Data(int dd, int mm, int aa){
	setDia(dd);
	setMes(mm);
	setAno(aa);
}
/**@return Retorna o dia*/
int Data::getDia(){ return dia; }

/**@return Retorna o mes*/
int Data::getMes(){ return mes; }

/**@return Retorna o ano*/
int Data::getAno(){ return ano; }

/**@brief Atualiza o dia
*@param dd O novo dia*/
void Data::setDia(int dd){ dia = dd; }

/**@brief Atualiza o mes 
*@param mm O novo mes*/
void Data::setMes(int mm){ mes = mm; }

/**@brief Atualiza o ano 
*@param aa O novo ano*/
void Data::setAno(int aa){ ano = aa; }

/*@brief Converte uma string no formato dd/mm/aaaa nos atributos da Data
*@param a A string que devera ser convertida */
void Data::string2Data(string a){	
	string aux;
	istringstream iss(a);

	getline(iss, aux, '/');
	setDia(atoi(aux.c_str())); 	
	getline(iss, aux, '/');
	setMes(atoi(aux.c_str())); 
	getline(iss, aux);
	setAno(atoi(aux.c_str())); 

}

/** @brief Sobrecarga do operador de atribuicao (para Data)
* @param	d Data que sera passada por atribuicao  
* @return	Retorna a Data atribuida
*/
Data& Data::operator=(const Data d) {
	dia = d.dia;
	mes = d.mes;
	ano = d.ano;
	
    return *this;
}


/** @brief Sobrecarga do operador de insercao em stream 
* @details O operador eh sobrecarregado para representar uma Data na formatacao "dd/mm/aaaa"  
* @param	os Referencia para stream de saida  
* @param	a Referencia para o objeto Data a ser impresso  
* @return	Referencia para stream de saida  
*/
ostream& operator<<(ostream& os, Data &a){
	os << a.getDia() << "/"; 	
	os << a.getMes() << "/"; 	
	os << a.getAno();
	return os; 
}

/** @brief Sobrecarga do operador de extracao de stream 
* @param	is Referencia para stream de entrada  
* @param	a Referencia para o objeto Data a ser criado com base nos  
*			valores fornecidos  
* @return	Referencia para stream de entrada  
*/
istream& operator>>(istream& is, Data &a){
	string aux; 

	getline(is, aux, '/'); 	
	a.setDia(atoi(aux.c_str())); 	
	getline(is, aux, '/'); 	
	a.setMes(atoi(aux.c_str())); 
	getline(is, aux); 	
	a.setAno(atoi(aux.c_str())); 	

	return is; 
}