/*
 * Menu.cpp
 *
 *  Created on: 01/11/2016
 *      Author: Beatriz de Henriques Martins
 */

#include "Menu.h"

static bool desconto = false;
static float percentagem = 1;

Menu::Menu() {
	ifstream file("Companhia.txt");

	if (!file.is_open()) {
		return;
	}
	string nome;
	float capital;

	file >> nome;
	file >> capital;

	CompanhiaTaxis comp = CompanhiaTaxis(nome, capital);
	menuInicio(comp);
}

void Menu::menuInicio(CompanhiaTaxis &comp) {
	while (1) {
		cout << "||Menu||" << endl << setw(5) << " " << "Bem vindo" << endl
				<< setw(5) << " " << "1. Entrar" << endl << setw(5) << " "
				<< "2. Sair" << endl;

		int op;
		try {
			cout << setw(5) << " " << "op: ";
			cin >> op;

			if (cin.fail()) {
				throw ErroInput();
			}
			if (op < 1 || op > 2)
				throw OpcaoErrada();

			if (op == 1) {
				menuEntrar(comp);
			} else if (op == 2) {
				return;
			}

		} catch (OpcaoErrada &x) {
			x.alertaErro();

		} catch (ErroInput &e) {

			e.alertaErro();

		}
	}
}

/*
 int Menu::lerFicheiroClienteParticular(CompanhiaTaxis &comp) {
 ifstream partic("clientesParticulares.txt");
 cout << endl << "chegueifich!" << endl;

 if (!partic.is_open()) {
 return -1;
 }
 cout << endl << "chegueifich!" << endl;
 unsigned int total;

 partic >> total;

 string lixo;

 vector<Cliente*> aux;

 while (!partic.eof()) {
 int id;
 partic >> id;
 getline(partic, lixo, ';');
 string nome;
 getline(partic, nome, ';');
 string morada;
 getline(partic, morada, ';');
 string email;
 getline(partic, email, ';');
 int nTelemovel;
 partic >> nTelemovel;
 getline(partic, lixo, ';');
 int nif;
 partic >> nif;
 getline(partic, lixo, ';');
 string tipoPagamento;
 getline(partic, tipoPagamento, '\n');
 Cliente *p = new Particular(id, nome, morada, email, nTelemovel, nif,
 tipoPagamento);
 aux.push_back(p);
 }

 //partic.close();

 if (aux.size() != total) {
 return -1;
 }

 comp.setClientes(aux);
 cout << endl << "chegueifich!" << endl;
 return 0;
 }

 int Menu::lerFicheiroClienteEmpresas(CompanhiaTaxis &comp) {
 ifstream file("clientesParticulares.txt");

 if (!file.is_open()) {
 return -1;
 }

 unsigned int total;

 file >> total;

 string lixo;

 vector<Cliente*> aux;

 while (!file.eof()) {
 int id;
 file >> id;
 getline(file, lixo, ';');
 string nome;
 getline(file, nome, ';');
 string morada;
 getline(file, morada, ';');
 string email;
 getline(file, email, ';');
 int nTelemovel;
 file >> nTelemovel;
 getline(file, lixo, ';');
 int nif;
 file >> nif;
 getline(file, lixo, ';');
 string tipoPagamento;
 getline(file, tipoPagamento, ';');
 int nFunc;
 file >> nFunc;
 getline(file, lixo, '\n');
 Cliente *p = new Empresa(id, nome, morada, email, nTelemovel, nif,
 tipoPagamento, nFunc);
 aux.push_back(p);
 }

 file.close();

 if (aux.size() != total) {
 return -1;
 }

 comp.setClientes(aux);
 cout << endl << "chegueiem!" << endl;
 return 0;
 }*/

void Menu::menuEntrar(CompanhiaTaxis &comp) {

	//lerFicheiroClienteParticular(comp);
	//lerFicheiroClienteEmpresas(comp);

	menuCompanhia(comp);
}

void Menu::menuTaxis(CompanhiaTaxis &comp) {
	while (1) {

		cout << endl << "||Taxis" << endl << setw(5) << " "
				<< "1. Compra de Taxi" << endl

				<< setw(5) << " " << "2. Remover Taxi" << endl << setw(5) << " "
				<< "3. Ver Taxi especifico" << " "
				<< "4. Voltar ao Menu da Companhia" << endl;

		int opC;

		try {
			cout << setw(5) << " " << "op: ";
			cin >> opC;

			switch (opC) {
			case 1: {
				int hi, mi, si, hf, mf, sf;
				cout << "Digite a hora inicial na qual o Taxi esta disponivel:"
						<< endl << "Horas ";
				cin >> hi;
				if (cin.fail())
					throw ErroInput();
				cout << " Minutos: ";
				cin >> mi;
				if (cin.fail())
					throw ErroInput();
				cout << " Segundos: ";
				cin >> si;
				if (cin.fail())
					throw ErroInput();

				cout << "E a final:" << endl << "Horas ";
				cin >> hf;
				if (cin.fail())
					throw ErroInput();
				cout << " Minutos: ";
				cin >> mf;
				if (cin.fail())
					throw ErroInput();
				cout << " Segundos: ";
				cin >> sf;
				if (cin.fail())
					throw ErroInput();

				comp.adicionaTaxi(Hora(hi, mi, si), Hora(hf, mf, sf));
				break;
			}

			case 2: {
				int n;
				comp.mostrarTaxis();
				cout << "Nr do taxi que quer remover: ";
				cin >> n;
				bool rem = comp.removeTaxi(n);
				if (rem)
					cout << "Taxi removido" << endl;
				else
					cout << "Taxi nao encontrado para remover" << endl;
				break;
			}

			case 3: {
				int id, i;

				try {
					cout << "Nr do taxi que quer ver: ";
					cin >> id;
					if (cin.fail())
						throw ErroInput();
				} catch (ErroInput &e) {

					e.alertaErro();
				}

				i = comp.procuraTaxi(id);
				if (i == -1) {
					cout << "Taxi numero " << id << " nao existe" << endl;
					break;
				}
				vector<Taxi> vC = comp.getTaxisTotais();

				cout << vC[i] << endl;
				break;
			}

			case 4: {
				return;
			}
			default:
				throw OpcaoErrada();
			}
		} catch (OpcaoErrada &x) {
			x.alertaErro();
		}
	}
}

void Menu::menuClientes(CompanhiaTaxis &comp) {
	while (1) {

		cout << endl << "||Clientes" << endl << setw(5) << " "
				<< "1. Novo Cliente" << endl

				<< setw(5) << " " << "2. Remover Cliente" << endl << setw(5)
				<< " " << "3. Fazer uma viagem" << endl << setw(5) << " "
				<< "4. Ver Cliente especifico" << endl << setw(5) << " "
				<< "5. Voltar ao Menu da Companhia" << endl;

		int opC;
		try {
			cout << setw(5) << " " << "op: ";
			cin >> opC;

			switch (opC) {
			case 1: {
				int emp;
				while (1) {
					try {

						cout << "1:Empresa ou 2:Particular? ";
						cin >> emp;
						if (emp == 1 || emp == 2)
							break;
						throw OpcaoErrada();
					} catch (OpcaoErrada &x) {
						x.alertaErro();
					}
				}

				int NIF, numeroTelemovel, op;
				string nome, morada, email, t;

				cin.ignore();
				cout << setw(5) << " " << "Nome: ";
				getline(cin, nome);

				cout << setw(5) << " " << "Morada: ";
				getline(cin, morada);

				cout << setw(5) << " " << "Email: ";
				getline(cin, email);

				//cin.ignore();
				cout << setw(5) << " " << "NIFF: ";
				cin >> NIF;

				cout << setw(5) << " " << "Nr.Telemovel: ";
				cin >> numeroTelemovel;

				int erro = 1;
				while (erro) {
					cout << setw(5) << " " << "Tipo de pagamento: " << endl;
					cout << "Escolher entre:" << endl;
					cout << "1: Numerario  " << "2: Multibanco  "
							<< "3: Credito  " << "4: Mensal" << endl;
					cin >> op;

					if (cin.fail())
						throw OpcaoErrada();

					switch (op) {
					case 1: {
						t = "numerario";
						erro = 0;
						break;
					}
					case 2: {
						t = "multibanco";
						erro = 0;
						break;
					}
					case 3: {
						t = "credito";
						erro = 0;
						break;
					}
					case 4: {
						t = "fim_do_mes";
						erro = 0;
						break;
					}
					default:
						throw OpcaoErrada();
					}
				}

				if (emp == 1) {
					int num_func;
					cout << setw(5) << " " << "Nr.Funcionarios da Empresa: ";
					cin >> num_func;
					comp.adicionaClienteEmpresa(nome, morada, email,
							numeroTelemovel, NIF, t, num_func);
				} else
					comp.adicionaClienteParticular(nome, morada, email,
							numeroTelemovel, NIF, t);
				break;
			}

			case 2: {
				int id;
				comp.mostrarClientesPorID();
				cout << "ID do cliente que quer remover: ";
				cin >> id;
				bool rem = comp.removeCliente(id);
				if (rem)
					cout << "Cliente removido" << endl;
				else
					cout << "Cliente nao encontrado para remover" << endl;
				break;
			}

			case 3: {

				int id, distancia, hi, mi, si, dia, mes, ano;
				string localPartida, localDestino;
				try {
					cout << "Qual e o local de origem da viagem? ";
					cin >> localPartida;
					if (cin.fail())
						throw ErroInput();
					cout << "E de destino? ";
					cin >> localDestino;
					if (cin.fail())
						throw ErroInput();
					cout << "Distancia entre locais: ";
					cin >> distancia;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000);
						break;
						//throw ErroInput();
					}
					cout << "Digite as horas a que a viagem comeca:" << endl
							<< "Horas ";
					cin >> hi;
					if (cin.fail())
						throw ErroInput();
					cout << " Minutos: ";
					cin >> mi;
					if (cin.fail())
						throw ErroInput();
					cout << " Segundos: ";
					cin >> si;
					if (cin.fail())
						throw ErroInput();

					cout << "Digite o dia em que a viagem ocorre: Dia ";
					cin >> dia;
					if (cin.fail())
						throw ErroInput();
					cout << " Mes: ";
					cin >> mes;
					if (cin.fail())
						throw ErroInput();
					cout << " Ano: ";
					cin >> ano;
					if (cin.fail())
						throw ErroInput();

					comp.mostrarClientesPorID();
					cout << "ID do cliente que quer fazer uma viagem: ";
					cin >> id;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000);
						throw ErroInput();
					}
					if (comp.procuraCliente(id) == -1)
						throw ClienteInexistente(id);
				}

				catch (ErroInput &e) {

					e.alertaErro();
					break;
				}

				try {

					comp.fazerViagemCliente(id, Data(dia, mes, ano),
							Hora(hi, mi, si),
							Percurso(localPartida, localDestino, distancia),
							desconto, percentagem);
					break;
				} catch (ClienteInexistente &c) {
					cout << "Cliente numero " << c.getID() << " nao existe"
							<< endl;
				} catch (TaxisIndisponiveis &t) {
					cout << t.getRazao() << endl;

				}
			}

			case 4: {
				int id, i;

				try {
					cout << "ID do cliente que quer ver: ";
					cin >> id;
					if (cin.fail())
						throw ErroInput();
				} catch (ErroInput &e) {

					e.alertaErro();
					break;
				}

				i = comp.procuraCliente(id);
				if (i == -1) {
					cout << "Cliente numero " << id << " nao existe" << endl;
					break;
				}
				vector<Cliente*> vC = comp.getClientes();

				cout << vC[i]->mostrarCliente() << endl;
				break;
			}

			case 5: {
				return;
			}
			default:
				throw OpcaoErrada();
			}
		} catch (OpcaoErrada &x) {
			x.alertaErro();
		}
	}
}

void Menu::menuCompanhia(CompanhiaTaxis &comp) {
	while (1) {

		cout << endl << "||Companhia de taxis" << endl << setw(5) << " "

		<< "1. Nome da Companhia" << endl << setw(5) << " "
				<< "2. Ver Clientes por ID" << endl << setw(5) << " "
				<< "3. Gestao de Clientes" << endl << setw(5) << " "
				<< "4. Ver capital" << endl << setw(5) << " "
				<< "5. Prestar servico a utente ocasional" << endl << setw(5)
				<< " " << "6. Lista de clientes mais lucrativos" << endl
				<< setw(5) << " " << "7. Mostrar todos os Taxis " << endl
				<< setw(5) << " " << "8. Aplicar desconto mensal " << endl
				<< setw(5) << " " << "9. Gestao de Taxis " << endl << setw(5)
				<< " " << "10. Cobrar pagamentos mensais" << endl << setw(5)
				<< " " << "11. Sair" << endl;
		int opC;

		try {
			cout << setw(5) << " " << "op: ";
			cin >> opC;

			switch (opC) {
			case 1: {
				cout << comp.getNome() << endl;
				break;
			}
			case 2: {
				comp.mostrarClientesPorID();
				break;
			}
			case 3: {
				menuClientes(comp);
				break;
			}

			case 4: {
				cout << "Capital: " << comp.getCapital() << endl;
				break;
			}
			case 5: {
				string nome;
				int t;
				cin.ignore();
				cout << setw(5) << " " << "Nome: ";
				getline(cin, nome);

				int distancia, hi, mi, si, dia, mes, ano;
				string localPartida, localDestino;

				try {
					cout << "Qual e o local de origem da viagem? ";
					cin >> localPartida;
					if (cin.fail())
						throw ErroInput();
					cout << "E de destino? ";
					cin >> localDestino;
					if (cin.fail())
						throw ErroInput();
					cout << "Distancia entre locais: ";
					cin >> distancia;
					if (cin.fail())
						throw ErroInput();

					cout << "Digite as horas a que a viagem comeca:" << endl
							<< "Horas ";
					cin >> hi;
					if (cin.fail())
						throw ErroInput();
					cout << " Minutos: ";
					cin >> mi;
					if (cin.fail())
						throw ErroInput();
					cout << " Segundos: ";
					cin >> si;
					if (cin.fail())
						throw ErroInput();

					cout << "Digite o dia em que a viagem ocorre: Dia ";
					cin >> dia;
					if (cin.fail())
						throw ErroInput();
					cout << " Mes: ";
					cin >> mes;
					if (cin.fail())
						throw ErroInput();
					cout << " Ano: ";
					cin >> ano;
					if (cin.fail())
						throw ErroInput();

				}

				catch (ErroInput &e) {

					e.alertaErro();
					break;
				}

				int erro = 1;
				while (erro) {
					try {
						cout << setw(5) << " " << "Tipo de pagamento: " << endl;
						cout << "Escolher entre:" << endl;
						cout << "1: Numerario  " << "2: Multibanco :";
						cin >> t;
						if (cin.fail())
							throw ErroInput();
						if ((t != 2) && (t != 1))
							throw OpcaoErrada();
						else
							erro = 0;

					} catch (OpcaoErrada &x) {
						x.alertaErro();
					}
				}
				try {
					comp.fazerViagemOcasional(Data(dia, mes, ano),
							Hora(hi, mi, si),
							Percurso(localPartida, localDestino, distancia));
					break;
				} catch (TaxisIndisponiveis &t) {
					cout << t.getRazao() << endl;

				}
			}
			case 6: {
				comp.mostrarClientesPorCapital();
				break;
			}
			case 7: {
				comp.mostrarTaxis();
				break;
			}
			case 8: {
				desconto = true;
				cout << "Percentagem de desconto:(entre 0 e 1): ";
				cin >> percentagem;
				break;
			}

			case 9: {
				menuTaxis(comp);
				break;
			}

			case 10: {
				comp.cobrarPagamentoMensal();
				desconto = false;
				break;
			}
			case 11: {
				return;
			}
			default:
				throw OpcaoErrada();
			}
		} catch (OpcaoErrada &x) {
			x.alertaErro();
		}
	}
}

