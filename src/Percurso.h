/*
 * Percurso.h
 *
 *  Created on: 01/11/2016
 *      Author: Diogo
 */

#ifndef SRC_PERCURSO_H_
#define SRC_PERCURSO_H_

#include <sstream>
#include <string>
#include <vector>


using namespace std;

class Percurso {
private:
	string localPartida;
	string localDestino;
	int distancia;
public:
	Percurso();
	Percurso(string localPart, string localDest, int distancia);
	string getLocalPartida() const;
	string getLocalDestino() const;
	int getDistancia() const;
	void setLocalPartida(string localPart, int dist);
	void setLocalDestino(string localDest, int dist);
	void setDistancia(int distancia);
	friend ostream & operator << (ostream os, Percurso p);
};



#endif /* SRC_PERCURSO_H_ */
