#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

#include "conta.h"
#include "poupanca.h"

Poupanca::Poupanca(){
	saldoConta = 0;
}

Poupanca::~Poupanca(){
	saldoConta = 0;
}

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
float Poupanca::saldo(){
	return saldoConta;
}

float Poupanca::juros(){
	return taxaJuros;
}
void Poupanca::setJuros(float j){
	taxaJuros = j;
}

float Poupanca::jurosPositivos(){
	return 1;
}
float Poupanca::jurosNegativos(){
	return 1;
}
void Poupanca::atualiza(){
	cout << "=================================" << endl;
	cout << "--- Aplicando Juros ---" << endl;
	cout << "Juros aplicados: " << saldo()*juros() << endl;
}
void Poupanca::setAniversario(Data d){
	aniversario = d;
}
Data Poupanca::getAniversario(){
	return aniversario;
}

void Poupanca::criar(){	
		cout << "=================================" << endl;
		cout << "--- Criando Conta Poupanca ---" << endl;
		cout << "Digite sua data de aniversario: ";
		cin >> aniversario;
}

int Poupanca::menu(int num){
	int result=0;
	do{
		cout << "=================================" << endl;
		cout << "--- Conta Poupanca " << num << " ---" << endl;
		cout << "1 - Deposito"<< endl;
		cout << "2 - Saque" << endl;
		cout << "3 - Saldo" << endl;
		cout << "0 - Sair" << endl;
		cout << "Opcao: ";
		cin >> result;
	}while(result<0 or result>3);
	return result;
}


string Poupanca::tipo(){
	return "Conta Poupanca";
}