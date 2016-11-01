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

using namespace std;

class Viagem {
private:
	Data inicio;
	Data fim;
	string local_partida;
	string local_destino;
	int id_cliente;
	double custo;
	bool pago;
public:
	Viagem(Data data_in, string local_part, string local_dest, int cliente);
	//Fun??o que adiciona e retira viagens dever?o ser implementadas na empresa de t?xis
	//void alteraViagem();
	Data getDatainicio() const;
	Data getDatafim() const;
	void setDatainicio(string data);
	void setDatafim(string data);
	string getPartida() const;
	string getDestino() const;
	void setPartida(string local);
	void setDestino(string local);
	void pagarViagem();
	double getCustoViagem() const;
};

#endif /* SRC_VIAGEM_H_ */
