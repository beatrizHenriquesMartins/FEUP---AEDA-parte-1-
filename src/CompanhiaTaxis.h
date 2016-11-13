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
#include <iostream>

#include "Cliente.h"
#include "Taxi.h"
#include "sequentialSearch.h"

using namespace std;

class CompanhiaTaxis {
private:
	string nome;
	float capital;
	vector<Cliente *> clientes;
	//vector<Ocasionais> ocasionais;
	vector<Taxi> taxisTotais;
	//vector<Taxi*> taxisDisponiveis;

public:
	CompanhiaTaxis();
	CompanhiaTaxis(string n, float c);
	string getNome();
	float getCapital();
	void somaCapital(float n);
	vector<Cliente *> getClientes() const;
	vector<Ocasionais> getOcasionais() const;
	vector<Taxi> getTaxisTotais() const;
	//vector<Taxi *> getTaxisDisponiveis() const;
	void setClientes(vector<Cliente*> c);
	void adicionaClienteParticular(string nome, string morada, string email,
			int nT, int nif, string tipo_pagamento);
	void adicionaClienteEmpresa(string nome, string morada, string email,
			int nT, int nif, string tipo_pagamento, int num_funcionarios);
	bool removeCliente(int id);
	int procuraCliente(int id) const;
	int ultimoIDcliente();
	void fazerviagem_ocasional(Data dia, Hora horaIn, Hora horaOut,
			Percurso p1);
	void fazerviagem_cliente(int id, Data dia, Hora horaIn, Hora horaOut,
			Percurso p1);
	void cobrarPagamentoMensal();
	void mostrarClientesPorCapital();
	void mostrarClientesPorID();
	void mostrarTaxis();
};

#endif /* SRC_COMPANHIATAXIS_H_ */
