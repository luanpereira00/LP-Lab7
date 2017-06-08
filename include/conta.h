#ifndef BANCO_H
#define BANCO_H

#include <string>
using std::string;

#include "data.h"

class Conta {
protected:
	string titular;
	float jurosNegat;
	float jurosPosit;
	float saldoConta;

public:
	virtual ~Conta(){
		//NADA
	};
	virtual Data getData()=0;
	virtual string getTitular()=0;
	virtual void deposito()=0;
	virtual void saque()=0;
	virtual float saldo()=0;
	virtual float jurosPositivos()=0;
	virtual float jurosNegativos()=0;
	virtual void atualiza(Data *hoje)=0;
	virtual float juros()=0;
	virtual int menu(int num)=0;
	virtual string tipo()=0;

};


#endif