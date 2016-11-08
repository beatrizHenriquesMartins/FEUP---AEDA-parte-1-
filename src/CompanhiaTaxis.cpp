/*
 * CompanhiaTaxis.cpp
 *
 *  Created on: 17/10/2016
 *      Author: Pedro Silva
 */

#include "CompanhiaTaxis.h"

CompanhiaTaxis::CompanhiaTaxis() {
	capital = 0;
}
;

CompanhiaTaxis::CompanhiaTaxis(string n, float c) {
	nome = n;
	capital = c;
}

string CompanhiaTaxis::getNome() {
	return nome;
}

float CompanhiaTaxis::getCapital() {
	return capital;
}

void CompanhiaTaxis::somaCapital(float n) {
	capital+=n;
}

vector<Cliente *> CompanhiaTaxis::getClientes() const {
	return clientes;
}

/*vector<Ocasionais> CompanhiaTaxis::getOcasionais() const {
	return ocasionais;
}*/

vector<Taxi *> CompanhiaTaxis::getTaxisTotais() const {
	return taxisTotais;
}

/*
 vector<Taxi *> CompanhiaTaxis::getTaxisDisponiveis() const {
 return taxisDisponiveis;
 }
 */

void CompanhiaTaxis::adicionaClienteParticular(string nome, string morada,
		string email, int nT, int nif, int tipo_pagamento) {
	int id;
	id = ultimoIDcliente();
	Cliente *c = new Particular(id, nome, morada, email, nT, nif, tipo_pagamento);
	clientes.push_back(c);
}

bool CompanhiaTaxis::removeCliente(string nomeC) {
	int ind;
	ind = procuraCliente(nomeC);

	if (ind == -1) {
		return false;
	}

	vector<Cliente*>::iterator itBegin = clientes.begin();

	clientes.erase(itBegin + ind);

	return true;
}

int CompanhiaTaxis::procuraCliente(const string &nomeC) const {
	if (clientes.size() == 0) {
		return -1;
	}

	vector<string> aux;

	for (unsigned int i = 0; i < clientes.size(); i++) {
		aux.push_back(clientes[i]->getNomeC());
	}

	int ind;
	ind = sequentialSearch(aux, nomeC);

	if (ind == -1) {
		return -1;
	}

	return ind;
}

int CompanhiaTaxis::ultimoIDcliente() {
	int ind;
	ind = clientes.size() - 1;

	return clientes[ind]->getID() + 1;
}


void CompanhiaTaxis::fazerviagem_ocasional(Data dia, string horaIn, string horaOut, Percurso & p1)
{

for(unsigned int i=0; i<taxisTotais.size();i++)
{
if(taxisTotais[i]->getDisponivel())
{
	Viagem v(dia,horaIn,horaOut,p1,-1);
	v.pagarViagem();
	taxisTotais[i]->setRentabilidade(v.getCustoViagem());
	return;
}
}
throw TaxisIndisponiveis("Nao existem taxis de momento disponiveis");
}

void CompanhiaTaxis::fazerviagem_cliente(int id, Data dia, string horaIn, string horaOut, Percurso & p1)
{

	for(unsigned int j=0; j<clientes.size();j++)
	{
		if(clientes[j]->getID()==id)
		{

for(unsigned int i=0; i<taxisTotais.size();i++)
{

if(taxisTotais[i]->getDisponivel())
{
	Viagem v(dia,horaIn,horaOut,p1,-1);
	if(clientes[j]->getCusto().getTipo()=="fim_do_mes")
		{
		clientes[j]->addViagem_nao_paga(v);
		return;
		}
	if(clientes[j]->getCusto().getTipo()=="credito")
		{
		v.pagarViagem();
		clientes[j]->changeCusto_total(v.getCustoViagem()*1.05);
		taxisTotais[i]->setRentabilidade(v.getCustoViagem()*1.05);
		return;
		}
	else
		{
		v.pagarViagem();
		clientes[j]->changeCusto_total(v.getCustoViagem());
		taxisTotais[i]->setRentabilidade(v.getCustoViagem());
		return;
		}
}

}
throw TaxisIndisponiveis("Nao existem taxis de momento disponiveis");
		}
	}

throw ClienteInexistente(id);

}


void CompanhiaTaxis::cobrarPagamentoMensal()
{

for (unsigned int i=0; i<clientes.size(); i++)
{
	if(clientes[i]->getCusto().getTipo()=="fim_do_mes")
		capital+=clientes[i]->fimdoMes();

}

for (unsigned int j=0; j<taxisTotais.size(); j++)
	{
	capital+=taxisTotais[j]->getRentabilidade();
	taxisTotais[j]->setRentabilidade(0);
	}
}

