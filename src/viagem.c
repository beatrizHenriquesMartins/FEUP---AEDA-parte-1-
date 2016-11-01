#include "viagem.h"

#include <vector>
#include <string>

using namespace std;

Viagem::Viagem (string data_in, string local_part, string local_dest, int cliente)
{
	this->inicio = data_in;
	this->local_partida = local_part;
	this->local_destino = local_dest;
	this->id_cliente = cliente;
	this->pago = false;
}


Data Viagem::getDatainicio() const
{
	return inicio;
}


Data Viagem::getDatafim() const
{
	return fim;
}


void Viagem::setDatainicio(string data)
{
	d1 = Data(data);

	this->inicio = d1;
}


void Viagem::setDatafim(string data)
{
	d1 = Data(data);

	this->fim = d1;
}


string Viagem::getPartida() const
{
	return local_partida;
}


string Viagem::getDestino() const
{
	return local_fim;
}


void Viagem::setPartida(string local)
{
	this->local_partida = local;
}


void Viagem::setDestino(string local)
{
	this->local_destino = local;
}


void Viagem::pagarViagem()
{
	//o tempo é calculado multiplicando o numero de km por 1 minuto e 15 segundos
	//em horas de ponta multiplica-se o tempo por 1.3
	//horas de ponta:
		//7:15 às 9:00
		//18:00 às 20:15
	//Preço fixo por tempo de viagem (1 minuto -- 0.8 euros)
	//atualiza-se o preço e se o boleano pago
}


double Viagem::getCustoViagem() const
{
	return custo;
}
