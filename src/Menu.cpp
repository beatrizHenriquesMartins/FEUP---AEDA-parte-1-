/*
 * Menu.cpp
 *
 *  Created on: 01/11/2016
 *      Author: Beatriz de Henriques Martins
 */

#include "Menu.h"

Menu::Menu() {
	menuIncio();
}

void Menu::menuIncio() {
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
		menuCompanhia();
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
		menuIncio();
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

void Menu::menuCompanhia() {
	cout << "menu comapnhia" << endl;
}
