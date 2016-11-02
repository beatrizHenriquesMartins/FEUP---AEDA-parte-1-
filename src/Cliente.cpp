/*
 * Cliente.cpp
 *
 *  Created on: 30/10/2016
 *      Author: Beatriz de Henriques Martins
 */

#include "Cliente.h"

//Utente
Utente::Utente(int nif) { //int tipo_pagamento
	//custo = Pagamento(tipo_pagamento);
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
		Utente(nif) { //int tipo_pagamento

}
void Ocasionais::fazerViagem(Data dia, string horaIn, string horaOut,
		Percurso & p1) {
	v = Viagem(dia, horaIn, horaOut, p1, -1); //-1 para mudar
	custo.changeTotal(v.getCustoViagem());

}

float Ocasionais::pagarViagem() {
	float total = custo.getTotal();
	custo.changeTotal(0);
	return total;
}

//Cliente
Cliente::Cliente(int id, string nC, string m, string mail, int nT, int nif) :
		Utente(nif) { //int tipo_pagamento
	idC = id;
	nomeC = nC;
	morada = m;
	email = m;
	numeroTelemovel = nT;
}

int Cliente::getID() const {
	return idC;
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

/*void Cliente::givepromotion() {
 }*/  //funcao vazia, seria implementada nas subclasses
void Cliente::fazerViagem(Data dia, string horaIn, string horaOut,
		Percurso & p1) {
	Viagem v = Viagem(dia, horaIn, horaOut, p1, this->getID());
	historicoViagens.push_back(v);

	{
	viagens_nao_pagas.push_back(v);
	}
if(custo.getTipo()=="credito")
	{
	custo.changeTotal(v.getCustoViagem()*1.05);
	}
else
	custo.changeTotal(v.getCustoViagem();

//pontos++;
	}


void Cliente::fimdoMes()
{
	float n=0;
for (unsigned int i=0; i<viagens_nao_pagas.size(); i++)
	n+=viagens_nao_pagas[i].getCustoViagem();

custo.changeTotal(n);

}

float Cliente::pagarViagem() {
	if(custo.getTipo()=="fim_do_mes")
		this->fimdoMes();
		float total = custo.getTotal();
			custo.changeTotal(0);
			return total;
	}

//Particular
	Particular::Particular(int id, string nC, string m, string mail, int nT,
			int nif) :
			Cliente(id, nC, m, mail, nT, nif) { //, tipo_pagamento

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
	Empresa::Empresa(int id, string nC, string m, string mail, int nT, int nif,
			int num_funcionarios) :
			Cliente(id, nC, m, mail, nT, nif) { //, tipo_pagamento
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
