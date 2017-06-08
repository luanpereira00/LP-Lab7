/**
 * @file	cc.cpp
 * @brief	Implementacao da classe ContaCorrente
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#include <iostream>
using std::cout;
using std::cin;
using std::getline;
using std::cerr;
using std::endl;

#include "conta.h"
#include "cc.h"

/** @brief Construtor Padrao */
ContaCorrente::ContaCorrente(){
	saldoConta = 0;
	Data d(8, 6, 2017);
	diaAtualizar = d;
	jurosNegat=0;
	jurosPosit=0;
}

/** @brief Destrutor Padrao */
ContaCorrente::~ContaCorrente(){
	saldoConta = 0;
	jurosNegat = 0;
	jurosPosit = 0;
}

/** @brief Realiza um deposito*/
void ContaCorrente::deposito(){
	float valor;
	cout << "=================================" << endl;
	cout << "--- Deposito ---" << endl;
	cout << "Digite o valor do deposito: ";
	cin >> valor;

	if(valor>0) {
		saldoConta+=valor;
	} else cerr << "IMPOSSIVEL DEPOSITAR VALORES NEGATIVOS!" << endl;
}

/** @brief Realiza um saque*/
void ContaCorrente::saque(){
	float valor;
	cout << "=================================" << endl;
	cout << "--- Saque ---" << endl;
	cout << "Digite o valor do saque: ";
	cin >> valor;

	if(valor>0 and (saldoConta-valor)>limite) {
		saldoConta-=valor;
	} else cerr << "IMPOSSIVEL REALIZAR SAQUE!" << endl;
}

/** @return Retorna o saldo*/
float ContaCorrente::saldo(){
	return saldoConta;
}

/** @return Retorna a taxacao de juros  */
float ContaCorrente::juros(){
	if(saldo()>=0) return jurosPositivos();
	else return jurosNegativos();
}

/** @return Retorna o juros positivo  */
float ContaCorrente::jurosPositivos(){
	return jurosPosit;
}

/** @return Retorna o juros negativo */
float ContaCorrente::jurosNegativos(){
	return jurosNegat;
}

/** @brief Atualiza o saldo 
	*@param novo O novo saldo*/
void ContaCorrente::setSaldo(float novo){
	saldoConta = novo;
}

/** @brief Atualiza o saldo pela taxacao de juros
	*@param hoje A data de hoje */
void ContaCorrente::atualiza(Data *hoje){
	if(diaAtualizar.getDia()!=hoje->getDia() or diaAtualizar.getMes()!=hoje->getMes() or diaAtualizar.getAno()!=hoje->getAno()){
		diaAtualizar = *hoje;
		
		setSaldo(saldo()+saldo()*juros());
		cout << "Saldo com Juros aplicados: " << saldo() << endl;
	}
}

/** @brief  Atualiza o limite
	*@param l O novo limite */
void ContaCorrente::setLimite(int l){
	limite = l;
}

/** @return Retorna o limite  */
int ContaCorrente::getLimite(){
	return limite;
}

/** @brief Cria uma nova conta corrente */
void ContaCorrente::criar(){
	cout << "=================================" << endl;
	cout << "--- Criando Conta Corrente ---" << endl;	
	cout << "Digite o nome do titular: ";
	cin.ignore();
	getline(cin, titular);
	do{
		cout << "Digite seu limite: ";
		cin >> limite;
		if(limite>=0) cerr << "IMPOSSIVEL TER LIMITE NAO NEGATIVO!" << endl;
	}while(limite>=0);
	do{
		cout << "Digite a taxa dos seus juros [0, 1]: ";
		cin >> jurosNegat;
		if(jurosNegat<0 or jurosNegat>1) cerr << "IMPOSSIVEL TER TAXA DE JUROS FORA DO INTERVALO [0, 1]!" << endl;
	}while(jurosNegat<0 or jurosNegat>1);
}

/** @brief Menu para acoes do usuario */
int ContaCorrente::menu(int num){
	int result=0;
	do{
		cout << "=================================" << endl;
		cout << "--- " << num << ": " << tipo() << " de " << getTitular() << " ---" << endl;
		cout << "1 - Deposito"<< endl;
		cout << "2 - Saque" << endl;
		cout << "3 - Saldo" << endl;
		cout << "4 - Proxima Data" << endl;
		cout << "0 - Sair" << endl;
		cout << "Opcao: ";
		cin >> result;
	}while(result<0 or result>4);
	return result;
}

/** @brief Retorna o tipo da conta */
string ContaCorrente::tipo(){
	return "Conta Corrente";
}

/** @brief  Atualiza o titular 
	*@param t O novo titular*/
void ContaCorrente::setTitular(string t){ titular = t; }

/** @return Retorna o titular  */
string ContaCorrente::getTitular() {return titular; }

/** @return Retorna a data para atualizar  */
Data ContaCorrente::getData(){ return diaAtualizar; }