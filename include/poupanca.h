/**
 * @file	poupanca.h
 * @brief	Definicao da classe Poupanca para representar uma conta poupanca bancaria
 * @details O atributo de uma poupanca eh a data de aniversario
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#ifndef POUPANCA_H
#define POUPANCA_H

#include "conta.h"

/** 
 * @class 	Poupanca poupanca.h
 * @brief 	Classe que representa uma conta poupanca bancaria
 * @details O atributo de uma poupanca eh a data de aniversario
  */
class Poupanca : public Conta {
private:
	Data aniversario; /**< A data de aniversario*/

public: 
	/** @brief Construtor Padrao */
	Poupanca();

	/** @brief Destrutor Padrao */
	~Poupanca();

	/**@brief Atualiza a data de aniversario 
	*@param d A nova data de aniversario*/
	void setAniversario(Data d);

	/**@return Retorna a data de aniversario*/
	Data getAniversario();

	/** @brief Atualiza o saldo 
	*@param novo O novo saldo*/
	void setSaldo(float novo);

	/** @brief  Atualiza o titular 
	*@param t O novo titular*/
	void setTitular(string t);

	/** @return Retorna o titular  */
	string getTitular();

	/** @return Retorna a data para atualizar  */
	Data getData();

	/** @brief Realiza um deposito*/
	void deposito();

	/** @brief Realiza um saque*/
	void saque();

	/** @return Retorna o saldo*/
	float saldo();

	/** @brief Atualiza o saldo pela taxacao de juros
	*@param hoje A data de hoje */
	void atualiza(Data *hoje);

	/** @return Retorna a taxacao de juros  */
	float juros();

	/** @return Retorna o juros positivo  */
	float jurosPositivos();

	/** @return Retorna o juros negativo */
	float jurosNegativos();

	/** @brief Atualiza os juros 
	*@param j O novo juros */
	void setJuros(float j);

	/** @brief Cria uma nova conta poupanca */
	void criar(Data *hoje);

	/** @brief Menu para acoes do usuario */
	int menu(int num);

	/** @brief Retorna o tipo da conta */
	string tipo();
};


#endif 