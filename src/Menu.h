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

using namespace std;

class Menu {
public:
	Menu();
	void menuInicio();
	void menuClientes(CompanhiaTaxis &comp);
	void menuNovoCliente();
	void menuCompanhia(CompanhiaTaxis &comp);
};

class OpcaoErrada{
public:
	int alertaErro(){cout<<"Opcao errada, tente outra vez"<<endl; return 1;};
};

class ErroInput{
public:
	int alertaErro(){cout<<"Erro de input, digite tudo outra vez"<<endl; return 1;};
};


#endif /* SRC_MENU_H_ */
