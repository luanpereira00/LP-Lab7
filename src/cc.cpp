#include "cc.h"

#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

ContaCorrente::ContaCorrente(){
	saldoConta = 0;
}

void ContaCorrente::deposito(){
	float valor;
	cout << "Digite o valor do deposito: ";
	cin >> valor;

	if(valor>0) {
		saldoConta+=valor;
	} else cerr << "IMPOSSIVEL DEPOSITAR VALORES NEGATIVOS!" << endl;
}
void ContaCorrente::saque(){
	float valor;
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
	do{
		cout << "Digite seu limite: " << endl;
		cin >> limite;
		if(limite>=0) cerr << "IMPOSSIVEL TER LIMITE NAO NEGATIVO!" << endl;
	}while(limite>=0);
}