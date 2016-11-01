#ifndef DATA_H_
#define DATA_H_

#include <sstream>
#include <string>
using namespace std;


class Data {
 private:
  int dia;
  int mes;
  int ano;

 public:
  Data(){};
  Data(string data); // data na forma DD/MM/AAA
  int getDia() const;
  int getMes() const;
  int getAno() const;
  void setDia(int dia);
  void setMes(int mes);
  void setAno(int ano);
};


#endif /* SRC_DATA_H_ */
