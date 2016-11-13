 /* * Hora.h
 *
 *  Created on: 08/11/2016
 *      Author: Pedro Silva
 */

#ifndef SRC_HORA_H_
#define SRC_HORA_H_

#include <string>

using namespace std;

class Hora {
	int hora;
	int minutos;
	int segundos;


public:
	Hora();
	Hora(int h, int m, int s);
	int get_hora() const;
	int get_minutos() const;
	int get_segundos() const;
	Hora somaHoras(int min);
	bool operator < (Hora h2);
	bool operator <= (Hora h2);
	friend ostream & operator <<(ostream os, Hora h);
};

/*
class HoraInvalida{
	string razao;
public:
	HoraInvalida(string r){razao=r;};
	string getRazao(){return razao;};
};*/





#endif /* SRC_HORA_H_ */
