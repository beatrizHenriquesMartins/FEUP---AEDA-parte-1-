/*
 * Viagem.cpp
 *
 *  Created on: 01/11/2016
 *      Author: Diogo Pereira
 */

#include "Viagem.h"
#include "Data.h"
#include "Percurso.h"

Viagem::Viagem(Data dia, Hora horaIn, Hora horaOut, Percurso p1, int cliente)
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

Hora Viagem::getHoraIn()const
{
	return horaIn;
}


void Viagem::setHoraIn(Hora hora)
{
	horaIn = hora;
}


Hora Viagem::getHoraOut()const
{
	return horaOut;
}


void Viagem::setHoraOut(Hora hora)
{
	horaOut = hora;
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

float Viagem::pagarViagem()
{
	float tempo = 1.15 * deslocacao.getDistancia();
	Hora t1(7,15,0), t2(9,0,0), t3(18,0,0), t4(20,15,0);

	if ((horaIn < t2 && t1 < horaIn) || (horaIn < t4 && t3<horaIn))
		tempo = tempo * 1.3;

	int temp = floor(tempo);

	horaOut = horaIn.somaHoras(temp);

	custo = tempo*0.6;
	this->pago = true;

	return custo;
}

float Viagem::getCustoViagem() const {
	return custo;
}
