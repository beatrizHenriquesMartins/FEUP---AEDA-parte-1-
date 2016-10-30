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

//Particular
Particular::Particular(string nC, string m, string mail, int nT, int nif) :
		Cliente(nC, m, mail, nT, nif) {

}

//Empresa
Empresa::Empresa(string nC, string m, string mail, int nT, int nif) :
		Cliente(nC, m, mail, nT, nif) {

}
