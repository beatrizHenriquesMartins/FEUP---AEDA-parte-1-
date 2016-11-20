/*
 * Menu.h
 *
 *  Created on: 01/11/2016
 *      Author: Beatriz de Henriques Martins
 */

#ifndef SRC_MENU_H_
#define SRC_MENU_H_

#include <string>
#include <iomanip>
#include <iostream>

#include "CompanhiaTaxis.h"
#include <fstream>

using namespace std;

class Menu {
public:
	Menu();
	void menuInicio(CompanhiaTaxis &comp);
	void trim(string &str);
	void lerFicheiroClienteParticular(CompanhiaTaxis &comp);
	void lerFicheiroClienteEmpresas(CompanhiaTaxis &comp);
	void lerFicheiroPercurso(CompanhiaTaxis &comp);
	void lerFicheiroViagens(CompanhiaTaxis &comp);
	Data* stringToData(string &s);
	Hora* stringToHora(string &s);
	//int escreverFicheiroClienteParticular(CompanhiaTaxis comp);
	//int escreverFicheiroClienteEmpresas(CompanhiaTaxis comp);
	void menuEntrar(CompanhiaTaxis &comp);
	void menuClientes(CompanhiaTaxis &comp);
	void menuTaxis(CompanhiaTaxis &comp);
	void menuCompanhia(CompanhiaTaxis &comp);
};

class OpcaoErrada {
public:
	int alertaErro() {
		cout << "Opcao errada, tente outra vez" << endl;
		return 1;
	}
	;
};

class ErroInput {
public:
	void alertaErro() {
		cout << "Erro de input, digite tudo outra vez" << endl;

	}
	;
};

#endif /* SRC_MENU_H_ */
