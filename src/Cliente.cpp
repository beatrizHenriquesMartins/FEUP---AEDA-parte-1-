/*
 * Cliente.cpp
 *
 *  Created on: 30/10/2016
 *      Author: Beatriz de Henriques Martins
 */

#include "Cliente.h"

//Utente
Utente::Utente(string nome, string tipo_pagamento) {
	custo = Pagamento(tipo_pagamento);
	nomeC = nome;
}

string Utente::getNomeC() const {
	return nomeC;
}

void Utente::setNomeC(string nC) {
	nomeC = nC;
}

Pagamento Utente::getCusto() {
	return custo;
}

void Utente::changeCusto_total(float n) {
	custo.changeTotal(n);
}

void Utente::changeCusto_tipo(string tipo) {
	custo.changeTipo(tipo);
}

//Ocasionais
Ocasionais::Ocasionais(string nome, string tipo_pagamento) :
		Utente(nome, tipo_pagamento) {

}

//Cliente
Cliente::Cliente(int id, string nC, string m, string mail, int nT, int nif,
		string tipo_pagamento) :
		Utente(nC, tipo_pagamento) {
	idC = id;
	NIF = nif;
	morada = m;
	email = m;
	numeroTelemovel = nT;
	cartao_pontos = 0;
}

int Cliente::getID() const {
	return idC;
}

int Cliente::getNIF() const {
	return NIF;
}

void Cliente::setNIF(int nif) {
	NIF = nif;
}

string Cliente::getMorada() const {
	return morada;
}

string Cliente::getEmail() const {
	return email;
}

vector<Viagem> Cliente::getHistoricoViagens() {
	return historicoViagens;
}

int Cliente::getNumeroTelemovel() const {
	return numeroTelemovel;
}

int Cliente::getPontos() {
	return cartao_pontos;
}

void Cliente::aumentaPontos() {
	cartao_pontos++;
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

void Cliente::addViagem_nao_paga(Viagem v) {
	viagens_nao_pagas.push_back(v);

}

void Cliente::addViagem_historico(Viagem v) {
	historicoViagens.push_back(v);
}

float Cliente::give_monthly_promotion() {
	return 1;
}  //funcao vazia, seria implementada nas subclasses

float Cliente::fimdoMes() {
	float n = 0;
	for (unsigned int i = 0; i < viagens_nao_pagas.size(); i++) {
		viagens_nao_pagas[i].pagarViagem();
		n += viagens_nao_pagas[i].getCustoViagem();
	}
	vector<Viagem> vazio;
	viagens_nao_pagas = vazio;
	return n;

}

string Cliente::mostrarCliente() {
	stringstream ss;
	ss << idC << " Nome: " << this->getNomeC() << " Morada: " << morada
			<< " Email: " << email << " Nr Telemovel: " << numeroTelemovel
			<< " Total dispendido na Companhia: " << this->getCusto().getTotal()
			<< " Tipo de pagamento: " << this->getCusto().getTipo()
			<< " Nr total de pontos no cartao: " << cartao_pontos;
	return ss.str();
}

bool Cliente::operator <(Cliente c2) {
	if (this->custo.getTotal() < c2.getCusto().getTotal())
		return true;
	else if (this->custo.getTotal() == c2.getCusto().getTotal()
			&& this->historicoViagens.size() < c2.getHistoricoViagens().size())
		return true;
	else
		return false;

}

//Particular
Particular::Particular(int id, string nC, string m, string mail, int nT,
		int nif, string tipo_pagamento) :
		Cliente(id, nC, m, mail, nT, nif, tipo_pagamento) {

}

float Particular::give_monthly_promotion() {
	if (custo.getTipo() != "fim_do_mes") {
		if (historicoViagens.size() >= 15)
			return 1.20;
	} else {
		if (historicoViagens.size() >= 25)
			return 1.20;
		else
			return 1;
	}
}

string Particular::mostrarCliente() {
	stringstream ss;
	ss << idC << " Nome: " << this->getNomeC() << " Morada: " << morada
			<< " Email: " << email << " Nr Telemovel: " << numeroTelemovel
			<< " Total dispendido na Companhia: " << this->getCusto().getTotal()
			<< " Tipo de pagamento: " << this->getCusto().getTipo()
			<< " Nr total de pontos no cartao: " << cartao_pontos;
	return ss.str();
}

//Empresa
Empresa::Empresa(int id, string nC, string m, string mail, int nT, int nif,
		string tipo_pagamento, int num_funcionarios) :
		Cliente(id, nC, m, mail, nT, nif, tipo_pagamento) {
	this->num_funcionarios = num_funcionarios;
}

float Empresa::give_monthly_promotion() {
	if (custo.getTipo() != "fim_do_mes") {
		if (historicoViagens.size() / num_funcionarios >= 20)
			return 1.20;
	} else {
		if (historicoViagens.size() / num_funcionarios >= 30)
			return 1.20;
		else
			return 1;
	}
}

string Empresa::mostrarCliente() {
	stringstream ss;
	ss << idC << " Nome: " << this->getNomeC() << " Morada: " << morada
			<< " Email: " << email << " Nr Telemovel: " << numeroTelemovel
			<< " Total dispendido na Companhia: " << this->getCusto().getTotal()
			<< " Tipo de pagamento: " << this->getCusto().getTipo()
			<< " Nr total de pontos no cartao: " << cartao_pontos
			<< "Nr de funcionarios: " << num_funcionarios;
	return ss.str();
}
