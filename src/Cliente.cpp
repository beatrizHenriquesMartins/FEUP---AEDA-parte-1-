/*
 * Cliente.cpp
 *
 *  Created on: 30/10/2016
 *      Author: Beatriz de Henriques Martins
 */

#include "Cliente.h"

//Utente
Utente::Utente(int nif) {
	NIF = nif;
}

int Utente::getNIF() const {
	return NIF;
}

void Utente::setNIF(int nif) {
	NIF = nif;
}

//Ocasionais
Ocasionais::Ocasionais(int nif) :
		Utente(nif) {

}

//Cliente
Cliente::Cliente(string nC, string m, string mail, int nT, int nif) :
		Utente(nif) {
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

//Particular
Particular::Particular(string nC, string m, string mail, int nT, int nif) :
		Cliente(nC, m, mail, nT, nif) {

}

//Empresa
Empresa::Empresa(string nC, string m, string mail, int nT, int nif) :
		Cliente(nC, m, mail, nT, nif) {

}
