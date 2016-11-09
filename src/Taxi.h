/*
 * Taxi.h
 *
 *  Created on: 30/10/2016
 *      Author: Beatriz de Henriques Martins
 */

#ifndef SRC_TAXI_H_
#define SRC_TAXI_H_

#include <string>
#include "Hora.h"

class Taxi {
	int numeroTaxi;
	float rentabilidade;
	Hora horaIn;
	Hora horaOff;
public:
	Taxi(int nTaxi, Hora horI, Hora horO);
	int getNumeroTaxi() const;
	bool getDisponivel(Hora hi, Hora hf);
	float getRentabilidade();
	void setRentabilidade(float n);
};

class TaxisIndisponiveis{
	string razao;
public:
	TaxisIndisponiveis(string r){razao=r;};
	string getRazao(){return razao;};
};

#endif /* SRC_TAXI_H_ */
