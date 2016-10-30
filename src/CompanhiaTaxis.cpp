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

/*vector<Clientes *> CompanhiaTaxis::getClientes()
 {return clientes;}*/

/*vector<Ocasionais> CompanhiaTaxis::getOcasionais()
 {return ocasionais;}*/

/*vector<Taxi *> CompanhiaTaxis::getTaxis_totais()
 {return taxis_totais;}

 vector<Taxi *> CompanhiaTaxis::getTaxis_disponiveis()
 {return taxis_disponiveis;}*/
