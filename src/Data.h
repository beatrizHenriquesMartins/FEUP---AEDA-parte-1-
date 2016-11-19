/*
 * Data.h
 *
 *  Created on: 01/11/2016
 *      Author: Diogo Pereira
 */

#ifndef SRC_DATA_H_
#define SRC_DATA_H_

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Data {
	int dia;
	int mes;
	int ano;

public:
	Data();
	Data(int d, int m, int a);
	int getDia() const;
	int getMes() const;
	int getAno() const;
	void setDia(int d);
	void setMes(int m);
	void setAno(int a);
	string toString();
	friend ostream & operator <<(ostream os, Data d);
};

#endif /* SRC_DATA_H_ */
