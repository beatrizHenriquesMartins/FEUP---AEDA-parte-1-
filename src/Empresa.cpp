/*
 * Empresa.cpp
 *
 *  Created on: 17/10/2016
 *      Author: Pedro Silva
 */
#include "Empresa.h"


Empresa::Empresa(){capital=0;};

Empresa::Empresa(string n, float c)
{
nome=n;
capital=c;
}

string Empresa::getNome()
{return nome;}

float Empresa::getCapital()
{return capital;}

/*vector<Clientes *> Empresa::getClientes()
{return clientes;}*/

/*vector<Ocasionais> Empresa::getOcasionais()
{return ocasionais;}*/

/*vector<Taxi *> Empresa::getTaxis_totais()
{return taxis_totais;}

vector<Taxi *> Empresa::getTaxis_disponiveis()
{return taxis_disponiveis;}*/
