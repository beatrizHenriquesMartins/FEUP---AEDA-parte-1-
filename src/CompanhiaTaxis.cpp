/*
 * CompanhiaTaxis.cpp
 *
 *  Created on: 17/10/2016
 *      Author: Pedro Silva
 */

#include "CompanhiaTaxis.h"

CompanhiaTaxis::CompanhiaTaxis() {
	capital = 0;
}
;

CompanhiaTaxis::CompanhiaTaxis(string n, float c) {
	nome = n;
	capital = c;
}

string CompanhiaTaxis::getNome() {
	return nome;
}

float CompanhiaTaxis::getCapital() {
	return capital;
}

vector<Cliente *> CompanhiaTaxis::getClientes() const {
	return clientes;
}

vector<Ocasionais> CompanhiaTaxis::getOcasionais() const {
	return ocasionais;
}

vector<Taxi *> CompanhiaTaxis::getTaxisTotais() const {
	return taxisTotais;
}

/*
 vector<Taxi *> CompanhiaTaxis::getTaxisDisponiveis() const {
 return taxisDisponiveis;
 }
 */

void CompanhiaTaxis::adicionaClienteParticular(string nome, string morada,
		string email, int nT, int nif) {
	int id;
	id = ultimoIDcliente();
	Cliente *c = new Particular(id, nome, morada, email, nT, nif);
	clientes.push_back(c);
}

bool CompanhiaTaxis::removeCliente(string nomeC) {
	int ind;
	ind = procuraCliente(nomeC);

	if (ind == -1) {
		return false;
	}

	vector<Cliente*>::iterator itBegin = clientes.begin();

	clientes.erase(itBegin + ind);

	return true;
}

int CompanhiaTaxis::procuraCliente(const string &nomeC) const {
	if (clientes.size() == 0) {
		return -1;
	}

	vector<string> aux;

	for (int i = 0; i < clientes.size(); i++) {
		aux.push_back(clientes[i]->getNomeC());
	}

	int ind;
	ind = sequentialSearch(aux, nomeC);

	if (ind == -1) {
		return -1;
	}

	return ind;
}

int CompanhiaTaxis::ultimoIDcliente() {
	int ind;
	ind = clientes.size() - 1;

	return clientes[ind]->getID() + 1;
}
