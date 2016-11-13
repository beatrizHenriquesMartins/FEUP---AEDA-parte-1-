/*
 * Taxi.cpp
 *
 *  Created on: 30/10/2016
 *      Author: Beatriz de Henriques Martins
 */

#include "Taxi.h"

//Taxi
Taxi::Taxi(int nTaxi, Hora horI, Hora horO) {
	horaIn = horI;
	horaOff = horO;
	numeroTaxi = nTaxi;
	rentabilidade = 0;
}

int Taxi::getNumeroTaxi() const {
	return numeroTaxi;
}

bool Taxi::getDisponivel(Hora hi, Hora hf) {
	if (hf <= horaOff && horaIn <= hi)
		return true;
	else
		return false;
}

float Taxi::getRentabilidade() {
	return rentabilidade;
}

void Taxi::setRentabilidade(float n) {
	rentabilidade += n;
}

Hora Taxi::getHoraIn() {
	return horaIn;
}

Hora Taxi::getHoraOff() {
	return horaOff;
}

/*ostream & operator <<(ostream os, Taxi t)
 {

 os<<"Taxi numero "<<t.getNumeroTaxi()<<" Rentabilidade Atual: "<<t.getRentabilidade()<<" Disponivel entre:"<<t.getHoraIn() <<" e as "<<t.getHoraOff()<<endl;
 return os;
 }*/
