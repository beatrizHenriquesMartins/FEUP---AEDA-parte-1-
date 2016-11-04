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
#include "CompanhiaTaxis.h"

using namespace std;

class Utente {
protected:
	int NIF;
	Pagamento custo;
public:
	Utente(int nif); //, int tipo_pagamento
	int getNIF() const;
	void setNIF(int nif);
	virtual void fazerViagem(Data dia, string horaIn, string horaOut, Percurso & p1);
	virtual void pagarViagem(CompanhiaTaxis c);
};

class Ocasionais: public Utente {
	Viagem v;
public:
	Ocasionais(int nif); //, int tipo_pagamento
	void fazerViagem(Data dia, string horaIn, string horaOut, Percurso & p1);
	void pagarViagem(CompanhiaTaxis c);

};

class Cliente: public Utente {
	int idC;
	string nomeC;
	string morada;
	string email;
	int numeroTelemovel;
	vector<Viagem> historicoViagens;
	vector<Viagem> viagens_nao_pagas;
	//int pontos=0;
public:
	Cliente(int id, string nC, string m, string mail, int nT, int nif); //int tipo_pagamento
	int getID() const;
	string getNomeC() const;
	string getMorada() const;
	string getEmail() const;
	int getNumeroTelemovel() const;
	void setNomeC(string nC);
	void setMorada(string m);
	void setEmail(string mail);
	void setNumeroTelemovel(int nT);
	//float givepromotion();
	void fazerViagem(Data dia, string horaIn, string horaOut, Percurso & p1);
	void pagarViagem(CompanhiaTaxis c);
	void fimdoMes();
	friend ostream operator <<(ostream os, Cliente cli);
};

class Particular: public Cliente {
public:
	Particular(int id, string nC, string m, string mail, int nT, int nif); //,int tipo_pagamento
	void givepromotion();
};

class Empresa: public Cliente {
	int num_funcionarios;
public:
	Empresa(int id, string nC, string m, string mail, int nT, int nif,
			int num_funcionarios); //,int tipo_pagamento,
	float givepromotion();
};

#endif /* SRC_CLIENTE_H_ */
