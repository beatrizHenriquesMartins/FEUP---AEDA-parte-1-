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
	Utente(int nif, int tipo_pagamento);
	int getNIF() const;
	void setNIF(int nif);
};

class Ocasionais: Utente {
public:
	Ocasionais(int nif, int tipo_pagamento);
};

class Cliente: public Utente {
	string nomeC;
	string morada;
	string email;
	int numeroTelemovel;
	//vector<Viagens> historicoViagens;
public:
	Cliente(string nC, string m, string mail, int nT, int nif,
			int tipo_pagamento);
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

class Particular: Cliente {
public:
	Particular(string nC, string m, string mail, int nT, int nif,
			int tipo_pagamento);
	void givepromotion();
};

class Empresa: Cliente {
	int num_funcionarios;
public:
	Empresa(string nC, string m, string mail, int nT, int nif,
			int tipo_pagamento, int num_funcionarios);
	float givepromotion();
};

#endif /* SRC_CLIENTE_H_ */
