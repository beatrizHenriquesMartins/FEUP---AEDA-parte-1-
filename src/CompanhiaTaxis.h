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
	vector<Taxi> taxisTotais;
	vector<Percurso*> percursosDisponiveis;

public:
	CompanhiaTaxis();
	CompanhiaTaxis(string n, float c);
	string getNome();
	float getCapital();
	void somaCapital(float n);
	vector<Cliente *> getClientes() const;
	vector<Ocasionais> getOcasionais() const;
	vector<Taxi> getTaxisTotais() const;
	void adicionaTaxi(Hora horI, Hora horO);
	bool removeTaxi(int id);
	int procuraTaxi(int n) const;
	void setPercursos(vector<Percurso*> p);
	vector<Percurso*> getPercursos() const;
	void adicionaClienteParticular(string nome, string morada, string email,
			int nT, int nif, string tipoPagamento);
	void adicionaClienteEmpresa(string nome, string morada, string email,
			int nT, int nif, string tipoPagamento, int numFuncionarios);
	bool removeCliente(int id);
	int procuraCliente(int id) const;
	int ultimoIDcliente();
	void fazerViagemOcasional(Data dia, Hora horaIn, Percurso p1);
	void fazerViagemCliente(int id, Data dia, Hora horaIn, Percurso p1,
			bool disc, float per);
	void cobrarPagamentoMensal();
	void mostrarClientesPorCapital();
	void mostrarClientesPorID();
	void mostrarTaxis();
	void setClientes(vector<Cliente*> c);
	void concaClientes(vector<Cliente*> c);
};

#endif /* SRC_COMPANHIATAXIS_H_ */
