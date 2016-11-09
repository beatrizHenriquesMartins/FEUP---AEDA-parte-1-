/*
 * Taxi.cpp
 *
 *  Created on: 30/10/2016
 *      Author: Beatriz de Henriques Martins
 */

#include "Taxi.h"

//Taxi
Taxi::Taxi(int nTaxi, Hora horI, Hora horO){
	horaIn=horI;
	horaOff=horO;
	numeroTaxi = nTaxi;
	rentabilidade=0;
}

int Taxi::getNumeroTaxi() const {
	return numeroTaxi;
}

bool Taxi::getDisponivel(Hora hi, Hora hf)  {
	if(hf<=horaOff && horaIn<=hi)
		return true;
	else
		return false;
}


float Taxi::getRentabilidade() {
	return rentabilidade;
}

void Taxi::setRentabilidade(float n) {
	rentabilidade+=n;
}
