#include <iostream>
using std::cout;
using std::cin;
using std::getline;
using std::cerr;
using std::endl;

#include "conta.h"
#include "poupanca.h"

Poupanca::Poupanca(){
	saldoConta = 0;
	jurosNegat=0;
	jurosPosit=0;
}

Poupanca::~Poupanca(){
	saldoConta = 0;
	jurosNegat=0;
	jurosPosit=0;
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
	if(saldo()>=0) return jurosPositivos();
	else return jurosNegativos();
}
void Poupanca::setJuros(float j){
	jurosPosit = j;
}

void Poupanca::setSaldo(float novo){
	saldoConta = novo;
}

float Poupanca::jurosPositivos(){
	return jurosPosit;
}
float Poupanca::jurosNegativos(){
	return jurosNegat;
}
void Poupanca::atualiza(Data *hoje){
	if(aniversario.getDia()==hoje->getDia() and aniversario.getMes()==hoje->getMes() and aniversario.getAno()==hoje->getAno()){
		aniversario.setAno(aniversario.getAno()+1);
		cout << "=================================" << endl;
		cout << "--- Aplicando Juros ---" << endl;
		setSaldo(saldo()+saldo()*juros());
		cout << "Juros aplicados: " << saldo() << endl;
	} 
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


string Poupanca::tipo(){
	return "Conta Poupanca";
}

void Poupanca::setTitular(string t){ titular = t; }
string Poupanca::getTitular() { return titular; }
Data Poupanca::getData(){ return aniversario; }