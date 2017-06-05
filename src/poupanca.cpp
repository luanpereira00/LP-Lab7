#include "poupanca.h"

#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

Poupanca::Poupanca(){
	saldoConta = 0;
}

void Poupanca::deposito(){
	float valor;
	cout << "Digite o valor do deposito: ";
	cin >> valor;

	if(valor>0) {
		saldoConta+=valor;
	} else cerr << "IMPOSSIVEL DEPOSITAR VALORES NAO POSITIVOS!" << endl;
}
void Poupanca::saque(){
	float valor;
	cout << "Digite o valor do saque: ";
	cin >> valor;

	if(valor>0 and (saldoConta-valor)>=0) {
		saldoConta-=valor;
	} else cerr << "IMPOSSIVEL REALIZAR SAQUE!" << endl;
}
float Poupanca::saldo(){
	return saldoConta;
}

float Poupanca::juros(){
	return taxaJuros;
}
void Poupanca::setJuros(float j){
	taxaJuros = j;
}

void Poupanca::atualiza(){
	cout << "Juros aplicados: " << saldo()*juros() << endl;
}
void Poupanca::setAniversario(Data d){
	aniversario = d;
}
Data Poupanca::getAniversario(){
	return aniversario;
}