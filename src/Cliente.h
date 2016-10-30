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

using namespace std;

class Utente {
	int NIF;
public:
	Utente(int nif);
	int getNIF() const;
	void setNIF(int nif);
};

class Ocasionais: Utente {
public:
	Ocasionais(int nif);
};

class Cliente: Utente {
	string nomeC;
	string morada;
	string email;
	int numeroTelemovel;
	//vector<Viagens> historicoViagens;
public:
	Cliente(string nC, string m, string mail, int nT, int nif);
	string getNomeC() const;
	string getMorada() const;
	string getEmail() const;
	int getNumeroTelemovel() const;
	void setNomeC(string nC);
	void setMorada(string m);
	void setEmail(string mail);
	void setNumeroTelemovel(int nT);
};

class Particular: Cliente {
public:
	Particular(string nC, string m, string mail, int nT, int nif);
};

class Empresa: Cliente {
public:
	Empresa(string nC, string m, string mail, int nT, int nif);
};

#endif /* SRC_CLIENTE_H_ */
