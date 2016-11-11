/*
 * Pagamento.c
 *
 *  Created on: 30/10/2016
 *      Author: Pedro Silva
 */
#include "Pagamento.h"


Pagamento::Pagamento()
{
	tipo="indefinido";
	dinheiro=0;
}

Pagamento::Pagamento(int t)
{
	switch (t)
	{
	case(1):
			tipo="numerario";
	case(2):
			tipo="multibanco";
	case(3):
			tipo="credito";
	case(4):
			tipo="fim_do_mes";
	default:
		tipo="indefinido";
	}
	dinheiro=0;
}

float Pagamento::getTotal()
{
	return dinheiro;
}

string Pagamento::getTipo()
{
	return tipo;
}

void Pagamento::changeTotal(float n)
{
	dinheiro=n;
}

void Pagamento::changeTipo (int t)
{
	switch (t)
		{
		case(1):
				tipo="numerario";
		case(2):
				tipo="multibanco";
		case(3):
				tipo="credito";
		case(4):
				tipo="fim_do_mes";
}
}
