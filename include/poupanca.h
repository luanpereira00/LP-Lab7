#ifndef POUPANCA_H
#define POUPANCA_H

#include "data.h"
#include "conta.h"

class Poupanca : public Conta {
private:
	Data aniversario;
	float taxaJuros;

public: 
	Poupanca();
	~Poupanca();
	void setAniversario(Data d);
	Data getAniversario();

	void deposito();
	void saque();
	float saldo();
	void atualiza();

	float juros();

	float jurosPositivos();
	float jurosNegativos();

	void setJuros(float j);
	void criar();
	int menu(int num);
	string tipo();
};


#endif 