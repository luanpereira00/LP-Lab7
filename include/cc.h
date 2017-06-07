#ifndef CC_H
#define CC_H



#include "conta.h"

class ContaCorrente : public Conta {
private:
	float taxaJurosNegativo;
	float taxaJurosPositivo;
	int limite;

public:
	ContaCorrente();
	~ContaCorrente();
	void setLimite(int l);
	int getLimite();

	void deposito();
	void saque();
	float saldo();
	float jurosPositivos();
	float jurosNegativos();
	void atualiza();
	float juros();

	void criar();
	int menu(int num);
	string tipo();
};
#endif