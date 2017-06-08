/**
 * @file	poupanca.cpp
 * @brief	Implementacao da classe Poupanca
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
#include "poupanca.h"

/** @brief Construtor Padrao */
Poupanca::Poupanca(){
	saldoConta = 0;
	jurosNegat=0;
	jurosPosit=0;
}

/** @brief Destrutor Padrao */
Poupanca::~Poupanca(){
	saldoConta = 0;
	jurosNegat=0;
	jurosPosit=0;
}

/** @brief Realiza um deposito*/
void Poupanca::deposito(){
	float valor;
	cout << "=================================" << endl;
	cout << "--- Deposito ---" << endl;
	cout << "Digite o valor do deposito: ";
	cin >> valor;

	if(valor>0) {
		saldoConta+=valor;
	} else cerr << "IMPOSSIVEL DEPOSITAR VALORES NAO POSITIVOS!" << endl;
}

/** @brief Realiza um saque*/
void Poupanca::saque(){
	cout << "=================================" << endl;
	cout << "--- Saque ---" << endl;
	float valor;
	cout << "Digite o valor do saque: ";
	cin >> valor;

	if(valor>0 and (saldoConta-valor)>=0) {
		saldoConta-=valor;
	} else cerr << "IMPOSSIVEL REALIZAR SAQUE!" << endl;
}

/** @return Retorna o saldo*/
float Poupanca::saldo(){
	return saldoConta;
}

/** @return Retorna a taxacao de juros  */
float Poupanca::juros(){
	if(saldo()>=0) return jurosPositivos();
	else return jurosNegativos();
}

/** @brief Atualiza os juros 
	*@param j O novo juros */
void Poupanca::setJuros(float j){
	jurosPosit = j;
}

/** @brief Atualiza o saldo 
	*@param novo O novo saldo*/
void Poupanca::setSaldo(float novo){
	saldoConta = novo;
}

/** @return Retorna o juros positivo  */
float Poupanca::jurosPositivos(){
	return jurosPosit;
}

/** @return Retorna o juros negativo */
float Poupanca::jurosNegativos(){
	return jurosNegat;
}

/** @brief Atualiza o saldo pela taxacao de juros
	*@param hoje A data de hoje */
void Poupanca::atualiza(Data *hoje){
	if(aniversario.getDia()==hoje->getDia() and aniversario.getMes()==hoje->getMes() and aniversario.getAno()==hoje->getAno()){
		aniversario.setAno(aniversario.getAno()+1);
		cout << "=================================" << endl;
		cout << "--- Aplicando Juros ---" << endl;
		setSaldo(saldo()+saldo()*juros());
		cout << "Juros aplicados: " << saldo() << endl;
	} 
}

/**@brief Atualiza a data de aniversario 
	*@param d A nova data de aniversario*/
void Poupanca::setAniversario(Data d){
	aniversario = d;
}

/**@return Retorna a data de aniversario*/
Data Poupanca::getAniversario(){
	return aniversario;
}

/** @brief Cria uma nova conta poupanca */
void Poupanca::criar(){	
		cout << "=================================" << endl;
		cout << "--- Criando Conta Poupanca ---" << endl;
		cout << "Digite o nome do titular: ";
		cin.ignore();
		getline(cin, titular);
		cout << "Digite a data de aniversario da poupanca (dd/mm/aaaa): ";
		cin >> aniversario;
		do{
			cout << "Digite a taxa dos seus juros [0, 1]: ";
			cin >> jurosPosit;
		if(jurosPosit<0 or jurosPosit>1) cerr << "IMPOSSIVEL TER TAXA DE JUROS FORA DO INTERVALO [0, 1]!" << endl;
	}while(jurosPosit<0 or jurosPosit>1);
}

/** @brief Menu para acoes do usuario */
int Poupanca::menu(int num){
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
string Poupanca::tipo(){
	return "Conta Poupanca";
}

/** @brief  Atualiza o titular 
	*@param t O novo titular*/
void Poupanca::setTitular(string t){ titular = t; }

/** @return Retorna o titular  */
string Poupanca::getTitular() { return titular; }

/** @return Retorna a data para atualizar  */
Data Poupanca::getData(){ return aniversario; }