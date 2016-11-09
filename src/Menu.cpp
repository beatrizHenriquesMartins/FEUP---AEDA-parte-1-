/*
 * Menu.cpp
 *
 *  Created on: 01/11/2016
 *      Author: Beatriz de Henriques Martins
 */

#include "Menu.h"

Menu::Menu() {
	menuInicio();
}

void Menu::menuInicio() {
	cout << "||Menu||" << endl << setw(5) << " " << "1. Clientes" << endl
			<< setw(5) << " " << "2. Companhia" << endl << setw(5) << " "
			<< "3. Sair" << endl << setw(5) << " " << "op: ";

	int op;

	cin >> op;

	switch (op) {
	case 1:
		menuClientes();
		break;

	case 2:
		CompanhiaTaxis comp= CompanhiaTaxis("TaxUber",0);
		menuCompanhia(comp);
		break;

	case 3:
		break;

	}
}

void Menu::menuClientes() {
	cout << "||Clientes" << endl << setw(5) << " " << "1. Novo Cliente" << endl
			<< setw(5) << " " << "2. Remover Cliente" << endl << setw(5) << " "
			<< "3. Sair" << endl << setw(5) << " " << "op: ";

	int opC;

	cin >> opC;

	switch (opC) {
	case 1:
		menuNovoCliente();
		break;

	case 2:
		break;

	case 3:
		menuInicio();
		break;

	}
}

void Menu::menuNovoCliente() {
	cout << "NOVO CLIENTE" << endl;
	string nome;
	string morada;
	string email;
	int nT;
	int nif;

	cin.ignore();
	cout << setw(5) << " " << "Nome: ";
	getline(cin, nome);

	cout << setw(5) << " " << "Morada: ";
	getline(cin, morada);

	cout << setw(5) << " " << "Email: ";
	getline(cin, email);

	cout << endl << nome << endl << morada << endl << email << endl;

	menuClientes();
}

void Menu::menuCompanhia(CompanhiaTaxis comp) {
	cout << "||Companhia de taxis" << endl << setw(5) << " " << "1. Nome da Companhia" << endl
				<< setw(5) << " " << "2. Ver Clientes"<<" "<<"3. Adicionar Cliente"<<" "<<endl<<"4. Remover Cliente"<<" "<<"5. Ver capital" <<" "<<"6. Cobrar pagamentos mensais"<< endl << setw(5) << " "
				<< "3. Sair" << endl << setw(5) << " " << "op: ";

	int opC;

		cin >> opC;

		switch (opC) {
		case 1:
			cout<< comp.getNome()<<endl;
			break;

		case 2:
			comp.mostrarClientesPorID(cout)<<endl;
			break;

		case 3:
			int emp;
			cout<<"1:Empresa ou 2:Particular? "<<emp<<endl;
			int idC, NIF,numeroTelemovel, t;
			string nome, morada,email;

			cin.ignore();
			cout << setw(5) << " " << "Nome: ";
			getline(cin, nome);

			cout << setw(5) << " " << "Morada: ";
			getline(cin, morada);

			cout << setw(5) << " " << "Email: ";
			getline(cin, email);

			cin.ignore();
			cout << setw(5) << " " << "NIFF: ";
			cin>>NIF;

			cout << setw(5) << " " << "Nr.Telemovel: ";
			cin>>numeroTelemovel;

			cout << setw(5) << " " << "Tipo de pagamento: "<<endl;
			cout<<"Escolher entre:"<<endl;
			cout<<"1: Numerario  "<<"2: Multibanco  "<<"3: Credito  "<<"4: Mensal"<<endl;
			cin>>t;

			if(emp==1)
			{
				int num_func;
				cout << setw(5) << " " << "Nr.Funcionarios da Empresa: ";
				cin>>num_func;
				comp.adicionaClienteEmpresa(nome,morada,email,numeroTelemovel,NIF,t,num_func);
			}
			else
				comp.adicionaClienteParticular(nome,morada,email,numeroTelemovel,NIF,t);
			break;

		}
	}







