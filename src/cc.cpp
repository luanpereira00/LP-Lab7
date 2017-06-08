#include <iostream>
using std::cout;
using std::cin;
using std::getline;
using std::cerr;
using std::endl;

#include "conta.h"
#include "cc.h"

ContaCorrente::ContaCorrente(){
	saldoConta = 0;
	Data d(8, 6, 2017);
	diaAtualizar = d;
	jurosNegat=0;
	jurosPosit=0;
}

ContaCorrente::~ContaCorrente(){
	saldoConta = 0;
	jurosNegat = 0;
	jurosPosit = 0;
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
	if(saldo()>=0) return jurosPositivos();
	else return jurosNegativos();
}

float ContaCorrente::jurosPositivos(){
	return jurosPosit;
}
float ContaCorrente::jurosNegativos(){
	return jurosNegat;
}

void ContaCorrente::setSaldo(float novo){
	saldoConta = novo;
}

void ContaCorrente::atualiza(Data *hoje){
	if(diaAtualizar.getDia()==hoje->getDia() and diaAtualizar.getMes()==hoje->getMes() and diaAtualizar.getAno()==hoje->getAno()){
		diaAtualizar.setDia(diaAtualizar.getDia()+1);
		if(diaAtualizar.getDia()>31){
			diaAtualizar.setDia(diaAtualizar.getDia()-31);
			diaAtualizar.setMes(diaAtualizar.getMes()+1);
			if(diaAtualizar.getMes()>12){
				diaAtualizar.setMes(diaAtualizar.getMes()-12);
				diaAtualizar.setAno(diaAtualizar.getAno()+1);
			}
		}
		setSaldo(saldo()+saldo()*juros());
		cout << "Saldo com Juros aplicados: " << saldo() << endl;
	}
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

string ContaCorrente::tipo(){
	return "Conta Corrente";
}

void ContaCorrente::setTitular(string t){ titular = t; }
string ContaCorrente::getTitular() {return titular; }
Data ContaCorrente::getData(){ return diaAtualizar; }