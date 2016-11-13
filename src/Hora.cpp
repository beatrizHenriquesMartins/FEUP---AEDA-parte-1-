/*
 * Hora.cpp
 *
 *  Created on: 08/11/2016
 *      Author: Pedro Silva
 */

#include "Hora.h"


Hora::Hora() {

}

Hora::Hora(int h, int m, int s) {

	if(h<0 || h>23)
		//throw HoraInvalida("Hora nao permitida");
	if(m<0 || m>59)
			//throw HoraInvalida("Minutos nao permitidos");
	if(s<0 || s>59)
			//throw HoraInvalida("Segundos nao permitidos");

	hora = h;
	minutos = m;
	segundos = s;

}

int Hora::get_hora() const {
	return hora;
}

int Hora::get_minutos() const {
	return minutos;
}

int Hora::get_segundos() const {
	return segundos;
}

Hora Hora::somaHoras(int min)
{
	int minfinal;

	minfinal = this->minutos + min;

	if (minfinal / 60 > 0)
	{
		if (hora + 1 == 24 )
		{
			Hora h = Hora(0,0,0);
			return h;
		}
	}

	int hor = this->hora + 1;
	int minu = this->minutos + minfinal % 60;
	int sec = this->segundos;

	Hora h = Hora(hor,minu,sec);
	return h;
}

bool Hora::operator <(Hora h2)
{

if(hora<h2.get_hora())
	return true;
else
	if(hora==h2.get_hora() && minutos<h2.get_minutos())
		return true;
	else
		if(hora==h2.get_hora() && minutos==h2.get_minutos() && segundos<h2.get_segundos())
			return true;
		else
			return false;

}

bool Hora::operator <=(Hora h2)
{

if(hora<=h2.get_hora())
	return true;
else
	if(hora==h2.get_hora() && minutos<=h2.get_minutos())
		return true;
	else
		if(hora==h2.get_hora() && minutos==h2.get_minutos() && segundos<=h2.get_segundos())
			return true;
		else
			return false;

}

ostream & operator <<(ostream os, Hora h)
{

	os<<h.get_hora()<<":"<<h.get_minutos()<<":"<<h.get_segundos()<<endl;
	return os;

}




