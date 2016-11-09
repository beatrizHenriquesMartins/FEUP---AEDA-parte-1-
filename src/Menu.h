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
	void menuClientes();
	void menuNovoCliente();
	void menuCompanhia(CompanhiaTaxis comp);
};

#endif /* SRC_MENU_H_ */
