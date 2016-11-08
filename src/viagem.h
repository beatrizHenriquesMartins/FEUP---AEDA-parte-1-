/*
 * Viagem.h
 *
 *  Created on: 01/11/2016
 *      Author: Diogo Pereira
 */

#ifndef SRC_VIAGEM_H_
#define SRC_VIAGEM_H_

#include <sstream>
#include <string>
#include <vector>

#include "Data.h"
#include "Percurso.h"

using namespace std;

class Viagem {
private:
	Data dia;
	string horaIn;
	string horaOut;
	Percurso deslocacao;
	int idCliente;
	double custo;
	bool pago;
public:
	Viagem(Data dia, string horaIn, string horaOut, Percurso p1, int cliente);

	//void alteraViagem();

	Data getDia() const;
	void setDia(int d, int m, int a);
	string getHoraIn()const;
	void setHoraIn(string hora);
	string getHoraOut()const;
	void setHoraOut(string hora);
	string getPartida() const;
	void setPartida(string localP, int dist1);
	string getDestino() const;
	void setDestino(string localD, int dist2);
	void pagarViagem();
	double getCustoViagem() const;
};

#endif /* SRC_VIAGEM_H_ */
