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
#include <math.h>
#include <iostream>
#include <fstream>

#include "Hora.h"
#include "Data.h"
#include "Percurso.h"

using namespace std;

class Viagem {
private:
	Data data;
	Hora horaIn;
	Hora horaOut;
	Percurso deslocacao;
	float custo;
	bool pago;
public:

	/**
	 * @brief função construtor Viagem
	 * @param dia - data
	 * @param horaIn - hora inicio
	 * @param p1 - percurso
	 */
	Viagem(Data dia, Hora horaIn, Percurso p1);

	/**
	 * @brief função construtor Viagem
	 * @param dia - data
	 * @param horaIn - hora inicio
	 * @param horaOut - hora fim
	 * @param p1 - percurso
	 * @param c - custo
	 */
	Viagem(Data dia, Hora horaIn, Hora horaOut, Percurso p1, float c);

	/**
	 * @brief função destrutora de viagem
	 */
	~Viagem();

	/**
	 * @brief função para obter data
	 * @return data
	 */
	Data getData() const;

	/**
	 * @brief função que actualiza data
	 * @param data - data
	 */
	void setData(int d, int m, int a);

	/**
	 * @brief função para obter hora de inicio
	 * @return hora de inicio
	 */
	Hora getHoraIn() const;

	/**
	 * @brief função que actualiza hora de inicio
	 * @param hora - hora de inicio
	 */
	void setHoraIn(Hora hora);

	/**
	 * @brief função para obter hora de fim
	 * @return hora de fim
	 */
	Hora getHoraOut() const;

	/**
	 * @brief função que actualiza hora de fim
	 * @param hora - hora de fim
	 */
	void setHoraOut(Hora hora);

	/**
	 * @brief função para obter partida
	 * @return partida
	 */
	string getPartida() const;

	/**
	 * @brief função que actualiza partida
	 * @param localP - local partida
	 * @param dist1 - distancia
	 */
	void setPartida(string localP, int dist1);

	/**
	 * @brief função para obter destino
	 * @return destino
	 */
	string getDestino() const;

	/**
	 * @brief função que actualiza partida
	 * @param localD - local destino
	 * @param dist2 - distancia
	 */
	void setDestino(string localD, int dist2);

	/**
	 * @brief função que calcula a hora final da viagem
	 * @return hora final
	 */
	float horaFinal();

	/**
	 * @brief função que calcula o custo da viagem
	 * @return custo
	 */
	float pagarViagem();

	/**
	 * @brief função para obter custo viagem
	 * @return custo viagem
	 */
	float getCustoViagem() const;

	/**
	 * @brief função que calcula custo viagem com desconto
	 * @param per - percentagem
	 */
	void modificaCusto(float per);

	/**
	 * @brief função para obter percurso
	 * @return percurso
	 */
	Percurso getDeslocacao();

	/**
	 * @brief função para imprimir detalhes viagem com formatação especifica
	 * @return string viagem
	 */
	string toString();

	/**
	 * @brief função operador<< impressão para detalhes viagem com formatação especifica
	 * @param os - ostream
	 * @param v - viagem
	 * @return string viagem
	 */
	friend ostream & operator <<(ostream & os, Viagem &v);
};

#endif /* SRC_VIAGEM_H_ */
