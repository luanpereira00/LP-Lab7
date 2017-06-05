/**
 * @file	data.h
 * @brief	Definicao da classe Data para representar uma data no estilo DD/MM/AAAA
 * @details Os atributos de uma Data sao o dia, o mes e o ano
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */
#ifndef DATA_H
#define DATA_H

#include <string>
using std::string;

#include <ostream> 
using std::ostream; 

#include <istream> 
using std::istream;

/** 
 * @class 	Data data.h
 * @brief 	Classe que representa uma Data
 * @details Os atributos de uma Data sao o dia, o mes e o ano.
 */
class Data{
private:	
	int dia; /**< O dia*/
	int mes; /**< O mes*/
	int ano; /**< O ano*/
public:
	/**@brief Construtor padrao*/
	Data();

	/**@brief Destrutor padrao*/
	~Data();

	/**@brief Construtor parametrizado*/
	Data(int dd, int mm, int aa);

	/**@return Retorna o dia*/
	int getDia();

	/**@return Retorna o mes*/
	int getMes();

	/**@return Retorna o ano*/
	int getAno();


	/**@brief Atualiza o dia
	*@param dd O novo dia*/
	void setDia(int dd);

	/**@brief Atualiza o mes 
	*@param mm O novo mes*/
	void setMes(int mm);
	
	/**@brief Atualiza o ano 
	*@param aa O novo ano*/
	void setAno(int aa);

	/*@brief Converte uma string no formato dd/mm/aaaa nos atributos da Data
	*@param a A string que devera ser convertida */
	void string2Data(string a);

	/** @brief Sobrecarga do operador de atribuicao (para Data)
	* @param	d Data que sera passada por atribuicao  
	* @return	Retorna a Data atribuida
	*/
	Data& operator=(const Data d);

	/** @brief Sobrecarga do operador de insercao em stream 
	* @details O operador eh sobrecarregado para representar uma Data na formatacao "dd/mm/aaaa"  
	* @param	os Referencia para stream de saida  
	* @param	a Referencia para o objeto Data a ser impresso  
	* @return	Referencia para stream de saida  
	*/
	friend ostream& operator<<(ostream& os, Data &a);

	/** @brief Sobrecarga do operador de extracao de stream 
	* @param	is Referencia para stream de entrada  
	* @param	a Referencia para o objeto Data a ser criado com base nos  
	*			valores fornecidos  
	* @return	Referencia para stream de entrada  
	*/
	friend istream& operator>>(istream& is, Data &a);
};

#endif