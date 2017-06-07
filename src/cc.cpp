#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

#include "conta.h"
#include "cc.h"

ContaCorrente::ContaCorrente(){
	saldoConta = 0;
	taxaJurosNegativo=1;
	taxaJurosPositivo=1;
}

ContaCorrente::~ContaCorrente(){
	saldoConta = 0;
	taxaJurosNegativo=1;
	taxaJurosPositivo=1;
}

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
float ContaCorrente::saldo(){
	return saldoConta;
}

float ContaCorrente::juros(){
	if(saldoConta>=0) return 0;
	else return taxaJurosNegativo;
}

float ContaCorrente::jurosPositivos(){
	return taxaJurosPositivo;
}
float ContaCorrente::jurosNegativos(){
	return taxaJurosNegativo;
}
void ContaCorrente::atualiza(){
	cout << "Juros aplicados: " << saldo()*juros() << endl;
}
void ContaCorrente::setLimite(int l){
	limite = l;
}
int ContaCorrente::getLimite(){
	return limite;
}

void ContaCorrente::criar(){
	cout << "=================================" << endl;
	cout << "--- Criando Conta Corrente ---" << endl;	
	do{
		cout << "Digite seu limite: ";
		cin >> limite;
		if(limite>=0) cerr << "IMPOSSIVEL TER LIMITE NAO NEGATIVO!" << endl;
	}while(limite>=0);
}

int ContaCorrente::menu(int num){
	int result=0;
	do{
		cout << "=================================" << endl;
		cout << "--- Conta Corrente " << num << " ---" << endl;
		cout << "1 - Deposito"<< endl;
		cout << "2 - Saque" << endl;
		cout << "3 - Saldo" << endl;
		cout << "0 - Sair" << endl;
		cout << "Opcao: ";
		cin >> result;
	}while(result<0 or result>3);
	return result;
}

string ContaCorrente::tipo(){
	return "Conta Corrente";
}