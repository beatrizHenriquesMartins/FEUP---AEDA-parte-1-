/*
 * Cliente.cpp
 *
 *  Created on: 30/10/2016
 *      Author: Beatriz de Henriques Martins
 */

#include "Cliente.h"

//Utente
Utente::Utente(string nome, string tipoPagamento) {
	custo = Pagamento(tipoPagamento);
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

void Utente::changeCustoTotal(float n) {
	custo.changeTotal(n);
}

void Utente::changeCustoTipo(string tipo) {
	custo.changeTipo(tipo);
}

//Ocasionais
Ocasionais::Ocasionais(string nome, string tipoPagamento) :
		Utente(nome, tipoPagamento) {

}

//Cliente
Cliente::Cliente(int id, string nC, string m, string mail, int nT, int nif,
		string tipoPagamento) :
		Utente(nC, tipoPagamento) {
	idC = id;
	NIF = nif;
	morada = m;
	email = m;
	numeroTelemovel = nT;
	cartaoPontos = 0;
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
	return cartaoPontos;
}

void Cliente::aumentaPontos() {
	cartaoPontos++;
}

void Cliente::resetPontos() {
	cartaoPontos = 0;
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

void Cliente::addViagemMensal(Viagem v) {
	viagensMensais.push_back(v);

}

void Cliente::addViagemHistorico(Viagem v) {
	historicoViagens.push_back(v);
}

void Cliente::resetMes() {
	vector<Viagem> v;
	viagensMensais = v;
}

float Cliente::giveMonthlyPromotion(float p) {
	return 1;
}  //funcao vazia, seria implementada nas subclasses

float Cliente::fimdoMes() {
	float n = 0;
	for (unsigned int i = 0; i < viagensMensais.size(); i++) {
		viagensMensais[i].pagarViagem();
		n += viagensMensais[i].getCustoViagem();
	}
	custo.changeTotal(n);
	return n;

}

string Cliente::mostrarCliente() {
	stringstream ss;
	ss << idC << " Nome: " << this->getNomeC() << " Morada: " << morada
			<< " Email: " << email << " Nr Telemovel: " << numeroTelemovel
			<< " Total dispendido na Companhia: " << this->getCusto().getTotal()
			<< " Tipo de pagamento: " << this->getCusto().getTipo()
			<< " Nr total de pontos no cartao: " << cartaoPontos;
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
		int nif, string tipoPagamento) :
		Cliente(id, nC, m, mail, nT, nif, tipoPagamento) {

}

float Particular::giveMonthlyPromotion(float p) {
	if (custo.getTipo() != "fim_do_mes") {
		if (viagensMensais.size() >= 15) {
			return (1 - p);
		}
	} else {
		if (viagensMensais.size() >= 25) {
			return (1 - p);
		} else {
			return 1;
		}
	}
	return 1;
}

string Particular::mostrarCliente() {
	stringstream ss;
	ss << idC << " Nome: " << this->getNomeC() << " Morada: " << morada
			<< " Email: " << email << " Nr Telemovel: " << numeroTelemovel
			<< " Total dispendido na Companhia: " << this->getCusto().getTotal()
			<< " Tipo de pagamento: " << this->getCusto().getTipo()
			<< " Nr total de pontos no cartao: " << cartaoPontos;
	return ss.str();
}
//Empresa
Empresa::Empresa(int id, string nC, string m, string mail, int nT, int nif,
		string tipoPagamento, int numFuncionarios) :
		Cliente(id, nC, m, mail, nT, nif, tipoPagamento) {
	this->numFuncionarios = numFuncionarios;
}

float Empresa::giveMonthlyPromotion(float p) {
	if (custo.getTipo() != "fim_do_mes") {
		if (viagensMensais.size() / numFuncionarios >= 20) {
			return (1 - p);
		}
	} else {
		if (viagensMensais.size() / numFuncionarios >= 30) {
			return (1 - p);
		} else {
			return 1;
		}
	}
	return 1;
}

string Empresa::mostrarCliente() {
	stringstream ss;
	ss << idC << " Nome: " << this->getNomeC() << " Morada: " << morada
			<< " Email: " << email << " Nr Telemovel: " << numeroTelemovel
			<< " Total dispendido na Companhia: " << this->getCusto().getTotal()
			<< " Tipo de pagamento: " << this->getCusto().getTipo()
			<< " Nr total de pontos no cartao: " << cartaoPontos
			<< "Nr de funcionarios: " << numFuncionarios;
	return ss.str();
}
