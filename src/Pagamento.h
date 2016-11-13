/*
 * Pagamento.h
 *
 *  Created on: 30/10/2016
 *      Author: Pedro Silva
 */

#include <string>
#include <vector>

using namespace std;


class Pagamento{
private:
	float dinheiro;
	string tipo;
public:
	Pagamento();
	Pagamento(string t);
	float getTotal();
	string getTipo();
	void changeTotal(float n);
	void changeTipo (string t);
};

