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
	bool particOuEmpre;
public:
	Utente(string nome, string tipo_pagamento, bool pOuE);
	string getNomeC() const;
	bool getParticOuEmpre() const;
	void setNomeC(string nome);
	void changeCustoTotal(float n);
	void changeCustoTipo(string tipo);
	Pagamento getCusto();
};

class Ocasionais: public Utente {
public:
	Ocasionais(string nome, string tipo_pagamento, bool pOuE);

};

class Cliente: public Utente {
protected:
	static int ultidC;
	int id;
	int NIF;
	string morada;
	string email;
	int numeroTelemovel;
	vector<Viagem> historicoViagens;
	vector<Viagem> viagensMensais;
	int cartaoPontos;
public:
	Cliente(int id, string nome, int nif, string morada, string email,
			int numeroTelemovel, string tipoPagamento, bool pOuE);
	Cliente(string nC, string m, string mail, int nT, int nif,
			string tipoPagamento, bool pOuE);
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
	void addViagemMensal(Viagem v);
	void addViagemHistorico(Viagem v);
	void resetMes();
	virtual float giveMonthlyPromotion(float p);
	float fimdoMes();
	virtual string mostrarCliente();
	bool operator <(Cliente c2);
};

class Particular: public Cliente {
public:
	Particular(int id, string nome, int nif, string morada, string email,
			int numeroTelemovel, string tipoPagamento, bool pOuE);
	Particular(string nC, string m, string mail, int nT, int nif,
			string tipo_pagamento, bool pOuE);
	float giveMonthlyPromotion(float p);
	string mostrarCliente();

};

class Empresa: public Cliente {
	int numFuncionarios;
public:
	Empresa(int id, string nome, int nif, string morada, string email,
			int numeroTelemovel, string tipoPagamento,int nFuncionarios, bool pOuE);
	Empresa(string nC, string m, string mail, int nT, int nif,
			string tipoPagamento, int numFuncionarios, bool pOuE);
	float giveMonthlyPromotion(float p);
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
