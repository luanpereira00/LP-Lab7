/**
 * @file	q6.cpp
 * @brief	Funcao principal que cria contas correntes e poupanca
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	15/05/2017
 * @date	15/05/2017
 */
#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

#include <vector> 
using std::vector;

#include "conta.h"
#include "data.h"
#include "poupanca.h"
#include "cc.h"

/** @brief Funcao principal */
int main (){
	int result, total;
	bool endFlag=false;
	vector<Conta*> v;
	vector<Conta*>::iterator it;
	uint num;
	Data aux;
	Data hoje(7, 6, 2017);

	
	do{
		do{
			cout << "=================================" << endl;
			cout << "\t\tHoje: " << hoje << endl;
			cout << "--- Conta ---" << endl;
			cout << "1 - Criar Conta Corrente"<< endl;
			cout << "2 - Criar Conta Poupanca"<< endl;
			cout << "3 - Listar Contas" << endl;
			cout << "4 - Remover Conta" << endl;
			cout << "5 - Acessar Conta" << endl;
			cout << "6 - Avancar Data" << endl;
			cout << "0 - Sair" << endl;
			cout << "Opcao: ";
			cin >> total;
			if(total<0 or total>6) cerr << "ERRO! OPCAO INVALIDA..." << endl;
		}while(total<0 or total>6);
		ContaCorrente *cc = new ContaCorrente;
		Poupanca *pp = new Poupanca;

		switch(total){
			case 1: // criar	
				
				delete pp;
				cc->criar();
				v.push_back(cc);
				cout << "Conta corrente criada com sucesso!" << endl;
			break;
			case 2: // criar
				
				delete cc;		
				pp->criar();
				v.push_back(pp);
				cout << "Conta poupanca criada com sucesso!" << endl;
			break;
			case 3:
				it = v.begin();
				num=1;
				cout << "=================================" << endl;
				cout << "--- Lista de Contas ---" << endl;
				while(it!=v.end()){
					cout << num << ": " << (*it)->tipo() << ": " << (*it)->getTitular() << endl;
					it++;
					num++;
				}
				
			break;
			case 4: //remover
				cout << "=================================" << endl;
				cout << "--- Removendo Conta ---" << endl;
				cout << "Digite o numero da conta que queres remover: ";
				cin >> num;
				if(num>0 and num<=v.size()) {
					v.erase(v.begin()+num-1);
					cout << "Conta removida com sucesso!" << endl;
				}
				else cerr << "IMPOSSIVEL REMOVER! O ELEMENTO NAO EXISTE..." << endl;
			break;
			case 5: //acessar
				cout << "=================================" << endl;
				cout << "--- Acessar Conta ---" << endl;
				cout << "Digite o numero da conta que queres acessar: ";
				cin >> num;
				if(num>0 and num<=v.size()) {
					it = v.begin()+num-1;
					do{	
						result = (*it)->menu(num);
						switch(result){
							case 1: //deposito
								(*it)->deposito();
							break;
							case 2: //saque
								(*it)->saque();
							break;
							case 3: //saldo
								cout << "=================================" << endl;
								cout << "--- Verificando Saldo ---" << endl;
								cout << "Saldo: " << (*it)->saldo() << endl;
							break;
							case 4:
								cout << "=================================" << endl;
								cout << "--- Proxima data de atualizacao ---" << endl;
								aux = (*it)->getData();
								cout << "Data: " << aux << endl;
							break;
							default:
							break;
						}

					}while(result!=0);
				}
				else cerr << "IMPOSSIVEL ACESSAR! O ELEMENTO NAO EXISTE..." << endl;
				
			break;
			case 6:
				cout << "=================================" << endl;
				cout << "--- Atualizando Data ---" << endl;
				cout << "Digite a nova data (dd/mm/aaaa): ";
				cin >> hoje;
				it = v.begin();
				while(it!=v.end()){
					(*it)->atualiza(&hoje);
					it++;
				}
				
			break;
			case 0:
				endFlag=true;
			break;
		}
	}while(!endFlag);
	cout << "=================================" << endl;
	return 0;
}