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

vector<Taxi *> CompanhiaTaxis::getTaxisDisponiveis() const {
	return taxisDisponiveis;
}
