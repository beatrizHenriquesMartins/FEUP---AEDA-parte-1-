/*
 * Cliente.cpp
 *
 *  Created on: 30/10/2016
 *      Author: Beatriz de Henriques Martins
 */

#include "Cliente.h"

//Utente
Utente::Utente(int nif, int tipo_pagamento) {
	custo = Pagamento(tipo_pagamento);
	NIF = nif;
}

int Utente::getNIF() const {
	return NIF;
}

void Utente::setNIF(int nif) {
	NIF = nif;
}

//Ocasionais
Ocasionais::Ocasionais(int nif, int tipo_pagamento) :
		Utente(nif, tipo_pagamento) {

}

//Cliente
Cliente::Cliente(string nC, string m, string mail, int nT, int nif,
		int tipo_pagamento) :
		Utente(nif, tipo_pagamento) {
	nomeC = nC;
	morada = m;
	email = m;
	numeroTelemovel = nT;
}

string Cliente::getNomeC() const {
	return nomeC;
}

string Cliente::getMorada() const {
	return morada;
}

string Cliente::getEmail() const {
	return email;
}

int Cliente::getNumeroTelemovel() const {
	return numeroTelemovel;
}

void Cliente::setNomeC(string nC) {
	nomeC = nC;
}

void Cliente::setMorada(string m) {
	morada = m;
}

void Cliente::setEmail(string mail) {
	email = mail;
}

void Cliente::setNumeroTelemovel(int nT) {
	numeroTelemovel = nT;
}

void givepromotion() {
}

//fun��o vazia, ser� implementada nas subclasses

//Particular
Particular::Particular(string nC, string m, string mail, int nT, int nif,
		int tipo_pagamento) :
		Cliente(nC, m, mail, nT, nif, tipo_pagamento) {

}

/*
 float Particular::givepromotion() {
 if (custo.getTipo() != "fim_do_mes")
 //if(historicoViagens.size()>=15)
 return 0.20;
 else {
 if(historicoViagens.size()>=25)
 return 0.20;
 else
 return 0;
 }
 }*/

//Empresa
Empresa::Empresa(string nC, string m, string mail, int nT, int nif,
		int tipo_pagamento, int num_funcionarios) :
		Cliente(nC, m, mail, nT, nif, tipo_pagamento) {
	this->num_funcionarios = num_funcionarios;
}

/*
 float Empresa::givepromotion() {
 if (custo.getTipo() != "fim_do_mes")
 //if(historicoViagens.size()/num_funcionarios>=20)
 return 0.20;
 else {
 if(historicoViagens.size()/num_funcionarios>=30)
 return 0.20;
 else
 return 0;
 }
 }*/
