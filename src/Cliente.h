/*
 * Cliente.h
 *
 *  Created on: 30/10/2016
 *      Author: Beatriz de Henriques Martins
 */

#ifndef SRC_CLIENTE_H_
#define SRC_CLIENTE_H_

#include <vector>
#include <string>
#include "Pagamento.h"
#include "Percurso.h"
#include "viagem.h"

using namespace std;

class Utente {
protected:
	string nomeC;
	Pagamento custo;
public:
	Utente(string nome, string tipo_pagamento);
	string getNomeC() const;
	void setNomeC(string nome);
	void changeCusto_total(float n);
	void changeCusto_tipo(string tipo);
	Pagamento getCusto();
};

class Ocasionais: public Utente {
public:
	Ocasionais(string nome, string tipo_pagamento);

};

class Cliente: public Utente {
protected:
	int idC;
	int NIF;
	string morada;
	string email;
	int numeroTelemovel;
	vector<Viagem> historicoViagens;
	vector<Viagem> viagens_mensais;
	int cartao_pontos;
public:
	Cliente(int id, string nC, string m, string mail, int nT, int nif,
			string tipo_pagamento);
	virtual ~Cliente() {
	}
	;
	int getID() const;
	int getNIF() const;
	void setNIF(int nif);
	string getMorada() const;
	string getEmail() const;
	vector<Viagem> getHistoricoViagens();
	int getNumeroTelemovel() const;
	int getPontos();
	void aumentaPontos();
	void resetPontos();
	void setMorada(string m);
	void setEmail(string mail);
	void setNumeroTelemovel(int nT);
	void addViagem_mensal(Viagem v);
	void addViagem_historico(Viagem v);
	void resetMes();
	virtual float give_monthly_promotion(float p);
	float fimdoMes();
	virtual string mostrarCliente();
	bool operator <(Cliente c2);
};

class Particular: public Cliente {
public:
	Particular(int id, string nC, string m, string mail, int nT, int nif,
			string tipo_pagamento);
	float give_monthly_promotion(float p);
	string mostrarCliente();

};

class Empresa: public Cliente {
	int num_funcionarios;
public:
	Empresa(int id, string nC, string m, string mail, int nT, int nif,
			string tipo_pagamento, int num_funcionarios);
	float give_monthly_promotion(float p);
	string mostrarCliente();
};

class ClienteInexistente {
	int id;
public:
	ClienteInexistente(int n) {
		id = n;
	}
	;
	int getID() {
		return id;
	}
	;

};
#endif /* SRC_CLIENTE_H_ */
