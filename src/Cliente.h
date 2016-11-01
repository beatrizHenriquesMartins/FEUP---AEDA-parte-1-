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

using namespace std;

class Utente {
	int NIF;
	Pagamento custo;
public:
	Utente(int nif); //, int tipo_pagamento
	int getNIF() const;
	void setNIF(int nif);
};

class Ocasionais: public Utente {
public:
	Ocasionais(int nif); //, int tipo_pagamento
};

class Cliente: public Utente {
	int idC;
	string nomeC;
	string morada;
	string email;
	int numeroTelemovel;
	//vector<Viagens> historicoViagens;
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
	float givepromotion();
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
