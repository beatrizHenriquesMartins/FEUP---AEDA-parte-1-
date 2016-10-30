/*
 * Taxi.h
 *
 *  Created on: 30/10/2016
 *      Author: Beatriz de Henriques Martins
 */

#ifndef SRC_TAXI_H_
#define SRC_TAXI_H_

#include <string>

class Taxi {
	int numeroTaxi;
	bool disponivel;
public:
	Taxi(int nTaxi);
	int getNumeroTaxi() const;
	bool getDisponivel() const;
	void setDisponivel(bool d);
};

#endif /* SRC_TAXI_H_ */
