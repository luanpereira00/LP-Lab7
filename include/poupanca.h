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
	void setAniversario(Data d);
	Data getAniversario();

	void deposito();
	void saque();
	float saldo();
	void atualiza();

	float juros();
	void setJuros(float j);
};


#endif 