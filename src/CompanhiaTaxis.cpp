/*
 * CompanhiaTaxis.cpp
 *
 *  Created on: 17/10/2016
 *      Author: Pedro Silva
 */

#include "CompanhiaTaxis.h"
#include <algorithm>

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

vector<Taxi> CompanhiaTaxis::getTaxisTotais() const {
	return taxisTotais;
}

/*
 vector<Taxi *> CompanhiaTaxis::getTaxisDisponiveis() const {
 return taxisDisponiveis;
 }
 */
void CompanhiaTaxis::setClientes(vector<Cliente*> c) {
	this->clientes = c;
}

void CompanhiaTaxis::adicionaClienteParticular(string nome, string morada,
		string email, int nT, int nif, string tipo_pagamento) {
	int id;
	id = ultimoIDcliente();
	Cliente *c = new Particular(id, nome, morada, email, nT, nif, tipo_pagamento);
	clientes.push_back(c);
}

void CompanhiaTaxis::adicionaClienteEmpresa(string nome, string morada,
		string email, int nT, int nif, string tipo_pagamento,int num_funcionarios) {
	int id;
	id = ultimoIDcliente();
	Cliente *c = new Empresa(id, nome, morada, email, nT, nif, tipo_pagamento,num_funcionarios);
	clientes.push_back(c);
}

bool CompanhiaTaxis::removeCliente(int id) {
	int ind;
	ind = procuraCliente(id);

	if (ind == -1) {
		return false;
	}

	vector<Cliente*>::iterator itBegin = clientes.begin();

	clientes.erase(itBegin + ind);

	return true;
}

int CompanhiaTaxis::procuraCliente(int id) const {
	if (clientes.size() == 0) {
		return -1;
	}

	vector<int> aux;

	for (unsigned int i = 0; i < clientes.size(); i++) {
		aux.push_back(clientes[i]->getID());
	}

	int ind;
	ind = sequentialSearch(aux, id);

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


void CompanhiaTaxis::fazerviagem_ocasional(Data dia, Hora horaIn, Hora horaOut, Percurso p1)
{

for(unsigned int i=0; i<taxisTotais.size();i++)
{
if(taxisTotais[i].getDisponivel(horaIn,horaOut));
{
	Viagem v(dia,horaIn,horaOut,p1);

	taxisTotais[i].setRentabilidade(v.pagarViagem());
	return;
}
}
//throw TaxisIndisponiveis("Nao existem taxis de momento disponiveis");
}

void CompanhiaTaxis::fazerviagem_cliente(int id, Data dia, Hora horaIn, Hora horaOut, Percurso p1)
{

	for(unsigned int j=0; j<clientes.size();j++)
	{
		if(clientes[j]->getID()==id)
		{

for(unsigned int i=0; i<taxisTotais.size();i++)
{

if(taxisTotais[i].getDisponivel(horaIn,horaOut))
{
	Viagem v(dia,horaIn,horaOut,p1);
	clientes[j]->addViagem_historico(v);
	clientes[j]->aumentaPontos();
	if(clientes[j]->getCusto().getTipo()=="fim_do_mes")
		{
		if(clientes[j]->getPontos()>50)
			return;
		clientes[j]->addViagem_mensal(v);
		return;
		}
	if(clientes[j]->getCusto().getTipo()=="credito")
		{

		if(clientes[j]->getPontos()>50)
			return;
		clientes[j]->changeCusto_total(v.pagarViagem()*1.05);
		taxisTotais[i].setRentabilidade(v.pagarViagem()*1.05);
		return;
		}
	else
		{
		v.pagarViagem();
		if(clientes[j]->getPontos()>50)
			return;
		clientes[j]->changeCusto_total(v.pagarViagem());
		taxisTotais[i].setRentabilidade(v.pagarViagem());
		return;
		}
}

}
//throw TaxisIndisponiveis("Nao existem taxis de momento disponiveis");
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
	capital+=taxisTotais[j].getRentabilidade();
	taxisTotais[j].setRentabilidade(0);
	}
}

void CompanhiaTaxis::mostrarClientesPorCapital()
{
	vector<Cliente *> v=clientes;
	vector<Cliente *>::iterator it=v.begin();
	vector<Cliente *>::iterator ite=v.end();

	sort(it,ite);
	reverse(it,ite);

	for (;it!=ite; it++)
	{
		cout<< *it<<endl;
	}

}

void CompanhiaTaxis::mostrarClientesPorID()
{

	vector<Cliente *>::iterator it=clientes.begin();
	vector<Cliente *>::iterator ite=clientes.end();

	for (;it!=ite; it++)
	{
		cout<<*it<<endl;
	}

}

void CompanhiaTaxis::mostrarTaxis()
{

	vector<Taxi>::iterator it=taxisTotais.begin();
	vector<Taxi>::iterator ite=taxisTotais.end();

	for (;it!=ite; it++)
	{
		cout<<(*it);
	}
}


