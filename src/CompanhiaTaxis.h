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
#include "Taxi.h"
#include "sequentialSearch.h"

using namespace std;

class CompanhiaTaxis {
private:
	string nome;
	float capital;
	vector<Cliente *> clientes;
	vector<Ocasionais> ocasionais;
	vector<Taxi*> taxisTotais;
	//vector<Taxi*> taxisDisponiveis;

public:
	CompanhiaTaxis();
	CompanhiaTaxis(string n, float c);
	string getNome();
	float getCapital();
	vector<Cliente *> getClientes() const;
	vector<Ocasionais> getOcasionais() const;
	vector<Taxi *> getTaxisTotais() const;
	//vector<Taxi *> getTaxisDisponiveis() const;
	void adicionaClienteParticular(string nome, string morada, string email,
			int nT, int nif);
	bool removeCliente(string nomeC);
	int procuraCliente(const string &nomeC) const;
	int ultimoIDcliente();
};

#endif /* SRC_COMPANHIATAXIS_H_ */
