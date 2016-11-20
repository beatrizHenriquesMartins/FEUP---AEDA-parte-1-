/*
 * Taxi.h
 *
 *  Created on: 30/10/2016
 *      Author: Beatriz de Henriques Martins
 */

#ifndef SRC_TAXI_H_
#define SRC_TAXI_H_

#include <string>
#include <iostream>
#include "Hora.h"

using namespace std;

class Taxi {
	static int ultinumeroTaxi;
	int numeroTaxi;
	float rentabilidade;
	Hora horaIn;
	Hora horaOff;
public:
	Taxi(Hora horI, Hora horO);
	~Taxi();
	int getNumeroTaxi() const;
	bool getDisponivel(Hora hi, Hora hf);
	float getRentabilidade();
	void setRentabilidade(float n);
	Hora getHoraIn();
	Hora getHoraOff();
	friend ostream & operator <<(ostream & os, Taxi t);
};

class TaxisIndisponiveis {
	string razao;
public:
	TaxisIndisponiveis(string r) {
		razao = r;
	}
	;
	string getRazao() {
		return razao;
	}
	;
};

#endif /* SRC_TAXI_H_ */
