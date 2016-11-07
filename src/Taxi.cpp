/*
 * Taxi.cpp
 *
 *  Created on: 30/10/2016
 *      Author: Beatriz de Henriques Martins
 */

#include "Taxi.h"

//Taxi
Taxi::Taxi(int nTaxi) {
	numeroTaxi = nTaxi;
	disponivel = true;
	rentabilidade=0;
}

int Taxi::getNumeroTaxi() const {
	return numeroTaxi;
}

bool Taxi::getDisponivel() const {
	return disponivel;
}

void Taxi::setDisponivel(bool d) {
	disponivel = d;
}

float Taxi::getRentabilidade() {
	return rentabilidade;
}

void Taxi::setRentabilidade(float n) {
	rentabilidade+=n;
}
