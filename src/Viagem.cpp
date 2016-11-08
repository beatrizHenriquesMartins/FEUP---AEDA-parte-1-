/*
 * Viagem.cpp
 *
 *  Created on: 01/11/2016
 *      Author: Diogo Pereira
 */

#include "Viagem.h"
#include "Data.h"
#include "Percurso.h"

Viagem::Viagem(Data dia, string horaIn, string horaOut, Percurso p1, int cliente)
{
	this->dia = dia;
	this->horaIn = horaIn;
	this->horaOut = horaOut;
	this->deslocacao=p1;
	this->idCliente = idCliente;
	this->pago = false;
	this->custo=0;
}

Data Viagem::getDia() const {
	return dia;
}


void Viagem::setDia(int d, int m, int a)
{
	Data d1 = Data(d, m, a);
	this->dia = d1;
}

string Viagem::getHoraIn()const
{
	return horaIn;
}


void Viagem::setHoraIn(string hora)
{
	this->horaIn = hora;
}


string Viagem::getHoraOut()const
{
	return horaOut;
}


void Viagem::setHoraOut(string hora)
{
	this->horaOut = hora;
}


string Viagem::getPartida() const
{
	return deslocacao.getLocalPartida();
}

void Viagem::setPartida(string localP, int dist1)
{
	deslocacao.setLocalPartida(localP, dist1);
}

string Viagem::getDestino() const
{
	return deslocacao.getLocalDestino();
}

void Viagem::setDestino(string localD, int dist2)
{
	deslocacao.setLocalDestino(localD, dist2);
}

void Viagem::pagarViagem()
{
	double tempo = 1.15 * deslocacao.getDistancia();
	string t1, t2, t3, t4;
	t1 = "7:15";
	t2 = "9:00";
	t3 = "18:00";
	t4 = "20:15";

	if ((horaIn < t2 && horaIn > t1) || (horaIn < t4 && horaIn > t3))
		tempo = tempo * 1.3;

	custo = tempo*0.6;

	//Pre?o fixo por tempo de viagem (1 minuto -- 0.6 euros)
	//atualiza-se o pre?o e se o boleano pago
}

double Viagem::getCustoViagem() const {
	return custo;
}
