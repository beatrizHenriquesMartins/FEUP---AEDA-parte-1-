/*
 * Empresa.h
 *
 *  Created on: 17/10/2016
 *      Author: Pedro Silva
 */

#ifndef SRC_EMPRESA_H_
#define SRC_EMPRESA_H_
#include <string>
#include <vector>

using namespace std;

class Empresa {
private:
	string nome;
	float capital;
	//vector<Clientes *> clientes;
	//vector<Ocasionais> ocasionais;   ?
	//vector<Taxi*> taxis_totais;    ?
	//vector<Taxi*> taxis_disponiveis;    ?

public:
	Empresa();
	Empresa(string n, float c);
	string getNome();
	float getCapital();
	//vector<Clientes *> getClientes();
	//vector<Ocasionais> getOcasionais();
	//vector<Taxi *> getTaxis_totais();
	//vector<Taxi *> getTaxis_disponiveis();

};

#endif /* SRC_EMPRESA_H_ */
