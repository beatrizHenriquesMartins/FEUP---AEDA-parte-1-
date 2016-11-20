/*
 * CompanhiaTaxis.h
 *
 *  Created on: 17/10/2016
 *      Author: Pedro Silva
 */

#ifndef SRC_COMPANHIATAXIS_H_
#define SRC_COMPANHIATAXIS_H_

#include <string>
#include <vector>
#include <iostream>

#include "Cliente.h"
#include "Taxi.h"
#include "sequentialSearch.h"

using namespace std;

class CompanhiaTaxis {
private:
	string nome;
	float capital;
	vector<Cliente *> clientes;
	vector<Taxi> taxisTotais;
	vector<Percurso*> percursosDisponiveis;

public:
	/**
	 * @brief construtor companhia de taxis vazio
	 */
	CompanhiaTaxis();

	/**
	 * @brief construtor companhia de taxis
	 * @param n - nome companhia
	 * @param c - capital companhia
	 */
	CompanhiaTaxis(string n, float c);

	/**
	 * @brief função para obter nome
	 * @return nome
	 */
	string getNome();

	/**
	 * @brief função para obter capital companhia
	 * @return companhia
	 */
	float getCapital();

	/**
	 * @brief função que acumula custo de novas viagens ao capital já acumulado
	 * @param n - custo
	 */
	void somaCapital(float n);

	/**
	 * @brief função para obter lista de clientes
	 * @return vector de clientes
	 */
	vector<Cliente *> getClientes() const;

	/**
	 * @brief função para obter lista de todos os taxis
	 * @return vector de taxis
	 */
	vector<Taxi> getTaxisTotais() const;

	/**
	 * @brief função para adicionar taxi à lista de taxis
	 * @param horI - hora inicio
	 * @param horO - hora fim
	 */
	void adicionaTaxi(Hora horI, Hora horO);

	/**
	 * @brief função que actualiza a lista de taxis
	 * @param t - taxis
	 */
	void setTaxis(vector<Taxi> t);

	/**
	 * @brief função para eliminar taxi
	 * @param id - id taxi
	 */
	bool removeTaxi(int id);

	/**
	 * @brief função para procurar taxi
	 * @param id - id taxi
	 */
	int procuraTaxi(int n) const;

	/**
	 * @brief função que actualiza a lista de percursos
	 * @param p - percurso
	 */
	void setPercursos(vector<Percurso*> p);

	/**
	 * @brief função para obter lista de percursos
	 * @return vector de percursos
	 */
	vector<Percurso*> getPercursos() const;

	/**
	 * @brief função que adiciona um cliente particular à lista de clientes
	 * @param nome
	 * @param morada
	 * @param email
	 * @param nT - número de telemóvel
	 * @param nif - número fiscal
	 * @param tipoPagamento - modo pagamento
	 */
	void adicionaClienteParticular(string nome, string morada, string email,
			int nT, int nif, string tipoPagamento);

	/**
	 * @brief função que adiciona um cliente empresa à lista de clientes
	 * @param nome
	 * @param morada
	 * @param email
	 * @param nT - número de telemóvel
	 * @param nif - número fiscal
	 * @param tipoPagamento - modo pagamento
	 * @param numFuncionarios - número de funcionários
	 */
	void adicionaClienteEmpresa(string nome, string morada, string email,
			int nT, int nif, string tipoPagamento, int numFuncionarios);

	/**
	 * @brief função para eliminar cliente
	 * @param id - id cliente
	 */
	bool removeCliente(int id);

	/**
	 * @brief função para procurar cliente
	 * @param id - id cliente
	 */
	int procuraCliente(int id) const;

	/**
	 * @brief função para ultimo id da lista de clientes
	 * @return último id
	 */
	int ultimoIDcliente();

	/**
	 * @brief função cria uma viagem de ocasinal
	 * @param dia - data
	 * @param horaIn - hora de inicio
	 * @param p1 -percurso
	 */
	void fazerViagemOcasional(Data dia, Hora horaIn, Percurso p1);

	/**
	 * @brief função cria uma viagem de cliente
	 * @param id - id cliente
	 * @param dia - data
	 * @param horaIn - hora de inicio
	 * @param p1 -percurso
	 * @param disc - desconto
	 * @param per - percentagem de desconto
	 */
	void fazerViagemCliente(int id, Data dia, Hora horaIn, Percurso p1,
			bool disc, float per);

	/**
	 * @brief função que calcula o valor total de todos os cliente que querem pagar no final do mês
	 */
	void cobrarPagamentoMensal();

	/**
	 * @brief função que imprime todos os clientes por ordem descrescente de total gasto em viagens
	 */
	void mostrarClientesPorCapital();

	/**
	 * @brief função que imprime todos os clientes por ordem crescente de id
	 */
	void mostrarClientesPorID();

	/**
	 * @brief função que imprime todos os taxis da companhia
	 */
	void mostrarTaxis();

	/**
	 * @brief função que actualiza a lista de clientes
	 * @param c - cliente
	 */
	void setClientes(vector<Cliente*> c);

	/**
	 * @brief função usada para concatenar 2 vectores de clientes
	 * @param c - vector de cliente
	 */
	void concaClientes(vector<Cliente*> c);
};

#endif /* SRC_COMPANHIATAXIS_H_ */
