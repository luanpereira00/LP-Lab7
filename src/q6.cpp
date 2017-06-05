#include "conta.h"
#include "data.h"
#include "poupanca.h"
#include "cc.h"

#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

#include <vector> 
using std::vector;

int main (){
	int result, total;
	bool endFlag=false;
	vector<ContaCorrente> v;
	vector<ContaCorrente>::iterator it;
	uint num;
	
	do{
		do{
			cout << "--- Conta ---" << endl;
			cout << "1 - Criar Conta"<< endl;
			cout << "2 - Remover Conta" << endl;
			cout << "3 - Acessar Conta" << endl;
			cout << "0 - Sair" << endl;
			cout << "Opcao: ";
			cin >> total;
		}while(total<0 or total>3);
		ContaCorrente cc;
		switch(total){
			case 1: // criar		
				cc.criar();
				v.push_back(cc);
				cout << "Conta criada com sucesso!" << endl;
			break;
			case 2: //remover
				cout << "Digite o numero da conta que queres remover: ";
				cin >> num;
				if(num>0 and num<=v.size()) {
					v.erase(v.begin()+num-1);
					cout << "Conta removida com sucesso!" << endl;
				}
				else cerr << "IMPOSSIVEL REMOVER! O ELEMENTO NAO EXISTE..." << endl;
			break;
			case 3: //acessar
				cout << "Digite o numero da conta que queres acessar: ";
				cin >> num;
				if(num>0 and num<=v.size()) {
					it = v.begin()+num-1;
					do{	
						do{
							cout << "--- Conta " << num << " ---" << endl;
							cout << "1 - Deposito"<< endl;
							cout << "2 - Saque" << endl;
							cout << "3 - Saldo" << endl;
							cout << "0 - Sair" << endl;
							cout << "Opcao: ";
							cin >> result;
						}while(result<0 or result>3);

						switch(result){
							case 1: //deposito
								it->deposito();
							break;
							case 2: //saque
								it->saque();
							break;
							case 3: //saldo
								cout << "Saldo: " << it->saldo() << endl;
							break;
							default:
							break;
						}

					}while(result!=0);
				}
				else cerr << "IMPOSSIVEL ACESSAR! O ELEMENTO NAO EXISTE..." << endl;
				
			break;
			default:
				endFlag=true;
			break;
		}
	}while(!endFlag);
	return 0;
}