/*
 * Data.cpp
 *
 *  Created on: 01/11/2016
 *      Author: Diogo Pereira
 */

#include "Data.h"

Data::Data() {

}

Data::Data(int d, int m, int a) {
	dia = d;
	mes = m;
	ano = a;
}

int Data::getDia() const {
	return dia;
}

int Data::getMes() const {
	return mes;
}

int Data::getAno() const {
	return ano;
}

void Data::setDia(int d) {
	dia = d;
}

void Data::setMes(int m) {
	mes = m;
}

void Data::setAno(int a) {
	ano = a;
}
