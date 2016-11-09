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
	Utente(string nome, int tipo_pagamento);
	string getNomeC() const;
	void setNomeC(string nome);
	void changeCusto_total(float n);
	void changeCusto_tipo(int tipo);
	Pagamento getCusto();
};

class Ocasionais: public Utente {
public:
	Ocasionais(string nome,int tipo_pagamento);


};

class Cliente: public Utente {
protected:
	int idC;
	int NIF;
	string morada;
	string email;
	int numeroTelemovel;
	vector<Viagem> historicoViagens;
	vector<Viagem> viagens_nao_pagas;
	int cartao_pontos;
public:
	Cliente(int id, string nC, string m, string mail, int nT, int nif,int tipo_pagamento); //int tipo_pagamento
	int getID() const;
	int getNIF() const;
	void setNIF(int nif);
	string getNomeC() const;
	string getMorada() const;
	string getEmail() const;
	vector<Viagem> getHistoricoViagens();
	int getNumeroTelemovel() const;
	int getPontos();
	void aumentaPontos();
	void setNomeC(string nC);
	void setMorada(string m);
	void setEmail(string mail);
	void setNumeroTelemovel(int nT);
	void addViagem_nao_paga(Viagem v);
	void addViagem_historico(Viagem v);
	virtual float give_monthly_promotion();
	float fimdoMes();
	friend ostream & operator <<(ostream os, Cliente cli);
	bool operator <(Cliente c2);
};

class Particular: public Cliente {
public:
	Particular(int id, string nC, string m, string mail, int nT, int nif, int tipo_pagamento);
	float give_monthly_promotion();
};

class Empresa: public Cliente {
	int num_funcionarios;
public:
	Empresa(int id, string nC, string m, string mail, int nT, int nif, int tipo_pagamento, int num_funcionarios);
	float give_monthly_promotion();
};


class ClienteInexistente{
	int id;
public:
	ClienteInexistente(int n){id=n;};
	int getID(){return id;};

};
#endif /* SRC_CLIENTE_H_ */
