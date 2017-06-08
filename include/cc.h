#ifndef CC_H
#define CC_H

#include "conta.h"

class ContaCorrente : public Conta {
private:
	int limite;
	Data diaAtualizar;

public:
	ContaCorrente();
	~ContaCorrente();
	void setLimite(int l);
	int getLimite();
	void setSaldo(float novo);

	void setTitular(string t);
	string getTitular();
	Data getData();

	void deposito();
	void saque();
	float saldo();
	float jurosPositivos();
	float jurosNegativos();
	void atualiza(Data *hoje);
	float juros();

	void criar();
	int menu(int num);
	string tipo();
};
#endif