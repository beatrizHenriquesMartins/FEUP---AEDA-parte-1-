#include "Data.h"


Data::Data(string dataStr){ // data na forma DD/MM/AAA
/*
	for (int i = 0; i < dataStr.size(); i++) //tirar espaços a mais
	{
		if (dataStr[i] == ' ')
		{
			dataStr.erase(dataStr.begin() + i);
			i--;
		}
	}*/

	char ch;
	stringstream line(dataStr);
	line >> dia >> ch >> mes >> ch >> ano;
}

int Data::getDia() const{
  return dia;
}

int Data::getMes() const{
  return mes;
}

int Data::getAno() const{
  return ano;
}

void Data::setDia(int dia){
	this->dia = dia;
}

void Data::setMes(int mes){
	this->mes = mes;
}

void Data::setAno(int ano){
	this->ano = ano;
}
