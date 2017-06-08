#ifndef POUPANCA_H
#define POUPANCA_H

#include "conta.h"

class Poupanca : public Conta {
private:
	Data aniversario;

public: 
	Poupanca();
	~Poupanca();
	void setAniversario(Data d);
	Data getAniversario();
	void setSaldo(float novo);

	void setTitular(string t);
	string getTitular();
	Data getData();

	void deposito();
	void saque();
	float saldo();
	void atualiza(Data *hoje);

	float juros();

	float jurosPositivos();
	float jurosNegativos();

	void setJuros(float j);
	void criar();
	int menu(int num);
	string tipo();
};


#endif 