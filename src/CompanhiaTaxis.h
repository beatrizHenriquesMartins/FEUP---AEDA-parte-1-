/*
 * CompanhiaTaxis.h
 *
 *  Created on: 17/10/2016
 *      Author: Pedro Silva
 */

#ifndef SRC_COMPANHIATAXIS_H_
#define SRC_COMPANHIATAXIS_H_

#include <string>
#include <vector>
#include "Cliente.h"

using namespace std;

class CompanhiaTaxis {
private:
	string nome;
	float capital;
	vector<Cliente *> clientes;
	vector<Ocasionais> ocasionais;
	//vector<Taxi*> taxis_totais;    ?
	//vector<Taxi*> taxis_disponiveis;    ?

public:
	CompanhiaTaxis();
	CompanhiaTaxis(string n, float c);
	string getNome();
	float getCapital();
	//vector<Clientes *> getClientes();
	//vector<Ocasionais> getOcasionais();
	//vector<Taxi *> getTaxis_totais();
	//vector<Taxi *> getTaxis_disponiveis();

};



#endif /* SRC_COMPANHIATAXIS_H_ */
