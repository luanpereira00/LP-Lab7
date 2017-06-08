/**
 * @file	conta.h
 * @brief	Definicao da classe Conta para representar uma conta bancaria
 * @details Os atributos de uma Conta sao o nome do titular, a taxacao de juros e o saldo
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#ifndef BANCO_H
#define BANCO_H

#include <string>
using std::string;

#include "data.h"

/** 
 * @class 	Conta conta.h
 * @brief 	Classe que representa uma conta bancaria
 * @details Os atributos de uma Conta sao o nome do titular, a taxacao de juros e o saldo
 */
class Conta {
protected:
	string titular; /**< O nome do titular*/
	float jurosNegat; /**< A taxacao de juros para saldo negativo*/
	float jurosPosit; /**< A taxacao de juros para saldo positivo*/
	float saldoConta; /**< O saldo da conta*/

public:
	/**@brief Destrutor padrao*/
	virtual ~Conta(){
		//NADA
	};

	/**@return Retorna a data de atualizacao de juros associada a conta*/
	virtual Data getData()=0;

	/**@return Retorna o titular da conta */
	virtual string getTitular()=0;

	/**@brief Realiza um deposito na conta*/
	virtual void deposito()=0;

	/**@brief Realiza um saque na conta*/
	virtual void saque()=0;

	/**@return Retorna o saldo da conta*/
	virtual float saldo()=0;

	/**@return Retorna a taxacao de juros para saldo positivo*/
	virtual float jurosPositivos()=0;

	/**@return Retorna a taxacao de juros para saldo negativo*/
	virtual float jurosNegativos()=0;

	/**@brief Atualiza os juros de acordo com a data
	*@param hoje A data de hoje*/
	virtual void atualiza(Data *hoje)=0;

	/**@return Retorna os a taxacao de juros*/
	virtual float juros()=0;

	/**@brief Menu para escolhas de acao do usuario
	*@param num O numero da conta acessada
	*@return Retorna a escolha do usuario*/
	virtual int menu(int num)=0;

	/**@return Retorna o tipo da conta*/
	virtual string tipo()=0;

};


#endif