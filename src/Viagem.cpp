/*
 * Viagem.cpp
 *
 *  Created on: 01/11/2016
 *      Author: Diogo Pereira
 */

#include "viagem.h"

Viagem::Viagem(Data data_in, string local_part, string local_dest,int cliente)
{
	this->inicio = data_in;
	this->local_partida = local_part;
	this->local_destino = local_dest;
	this->id_cliente = cliente;
	this->pago = false;
}

Data Viagem::getDatainicio() const {
	return inicio;
}


string Viagem::getPartida() const {
	return local_partida;
}

string Viagem::getDestino() const {
	return local_destino;
}

void Viagem::setPartida(string local) {
	this->local_partida = local;
}

void Viagem::setDestino(string local) {
	this->local_destino = local;
}

void Viagem::pagarViagem() {
	//o tempo ? calculado multiplicando o numero de km por 1 minuto e 15 segundos
	//em horas de ponta multiplica-se o tempo por 1.3
	//horas de ponta:
	//7:15 ?s 9:00
	//18:00 ?s 20:15
	//Pre?o fixo por tempo de viagem (1 minuto -- 0.8 euros)
	//atualiza-se o pre?o e se o boleano pago
}

double Viagem::getCustoViagem() const {
	return custo;
}
