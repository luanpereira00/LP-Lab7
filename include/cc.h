/**
 * @file	cc.h
 * @brief	Definicao da classe ContaCorrente para representar uma conta corrente bancaria
 * @details Os atributos de uma conta corrente sao o limite e o dia para atualizar
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#ifndef CC_H
#define CC_H

#include "conta.h"

/** 
 * @class 	ContaCorrente cc.h
 * @brief 	Classe que representa uma conta corrente bancaria
 * @details Os atributos de uma conta corrente sao o limite e o dia para atualizar
  */
class ContaCorrente : public Conta {
private:
	int limite; /**< O limite */
	Data diaAtualizar; /**< O dia para atualizar */

public:
	/** @brief Construtor Padrao */
	ContaCorrente();

	/** @brief Destrutor Padrao */
	~ContaCorrente();

	/** @brief  Atualiza o limite
	*@param l O novo limite */
	void setLimite(int l);

	/** @return Retorna o limite  */
	int getLimite();

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

	/** @return Retorna o juros positivo  */
	float jurosPositivos();

	/** @return Retorna o juros negativo */
	float jurosNegativos();

	/** @brief Atualiza o saldo pela taxacao de juros
	*@param hoje A data de hoje */
	void atualiza(Data *hoje);

	/** @return Retorna a taxacao de juros  */
	float juros();

	/** @brief Cria uma nova conta corrente */
	void criar();

	/** @brief Menu para acoes do usuario */
	int menu(int num);

	/** @brief Retorna o tipo da conta */
	string tipo();
};
#endif