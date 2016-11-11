/*
 * Menu.cpp
 *
 *  Created on: 01/11/2016
 *      Author: Beatriz de Henriques Martins
 */

#include "Menu.h"

Menu::Menu() {
	menuInicio();
}

void Menu::menuInicio() {
	cout << "||Menu||" << endl << setw(5) << " " << "Bem vindo" << endl
			<< setw(5) << " " << "1. Companhia" << endl << setw(5) << " "
			<< "2. Sair" << endl << setw(5) << " " << "op: ";

	int op;
while(1){
try{
	cin >> op;

	switch (op) {

	case 1:
		CompanhiaTaxis comp = CompanhiaTaxis("TaxUber", 0);
		menuCompanhia(comp);
		break;

	case 2:
		return;
	default:
		throw OpcaoErrada();

	}
}
catch (OpcaoErrada &x){
	x.alertaErro();
}
}
}
void Menu::menuClientes(CompanhiaTaxis &comp) {
	cout << "||Clientes" << endl << setw(5) << " " << "1. Novo Cliente" << endl
			<< setw(5) << " " << "2. Remover Cliente" << endl << setw(5) << " "
			<< "3. Fazer uma viagem" <<" " << "4. Ver Cliente especifico" <<" " << "5. Voltar ao Menu da Companhia"
			<< endl << setw(5) << " " << "op: ";

	int opC;
	while(1){
	try{
	cin >> opC;

	switch (opC) {
	case 1:
		int emp;
		do{
			try{

		cout << "1:Empresa ou 2:Particular? " << emp << endl;
		if(emp!=1 || emp!=2)
			throw OpcaoErrada();
		}
		catch(OpcaoErrada &x)
			{
				x.alertaErro();
			}
		}while(emp!=1 || emp!=2);

		int NIF, numeroTelemovel, t;
		string nome, morada, email;

		cin.ignore();
		cout << setw(5) << " " << "Nome: ";
		getline(cin, nome);

		cout << setw(5) << " " << "Morada: ";
		getline(cin, morada);

		cout << setw(5) << " " << "Email: ";
		getline(cin, email);

		cin.ignore();
		cout << setw(5) << " " << "NIFF: ";
		cin >> NIF;

		cout << setw(5) << " " << "Nr.Telemovel: ";
		cin >> numeroTelemovel;

		cout << setw(5) << " " << "Tipo de pagamento: " << endl;
		cout << "Escolher entre:" << endl;
		cout << "1: Numerario  " << "2: Multibanco  " << "3: Credito  "
				<< "4: Mensal" << endl;
		cin >> t;

		if (emp == 1) {
			int num_func;
			cout << setw(5) << " " << "Nr.Funcionarios da Empresa: ";
			cin >> num_func;
			comp.adicionaClienteEmpresa(nome, morada, email, numeroTelemovel,
					NIF, t, num_func);
		} else
			comp.adicionaClienteParticular(nome, morada, email, numeroTelemovel,
					NIF, t);
		break;

	case 2:
		int id;
		mostrarClientesPorID(cout, comp) << endl;
		cout << "ID do cliente que quer remover: ";
		cin >> id;
		bool rem=comp.removeCliente(id);
		if (rem)
			cout << "Cliente removido"<<endl;
		else
			cout << "Cliente nao encontrado para remover"<<endl;
		break;

	case 3:
		int erro, id, distancia, hi, mi, si, hf, mf, sf, dia, mes, ano;
		string localPartida, localDestino;
		while(erro==1)
		{
			try{
		cout << "Qual é o local de origem da viagem? ";
		cin >> localPartida;
		if(cin.fail())
			throw ErroInput();
		cout << "E de destino? ";
		cin >> localDestino;
		if(cin.fail())
					throw ErroInput();
		cout << "Distancia entre locais: ";
		cin >> distancia;
		if(cin.fail())
				throw ErroInput();

		cout << "Digite as horas a que a viagem começa: Horas ";
		cin >> hi;
		if(cin.fail())
					throw ErroInput();
		cout << " Minutos: ";
		cin >> mi;
		if(cin.fail())
					throw ErroInput();
		cout << " Segundos: ";
		cin >> si;
		if(cin.fail())
					throw ErroInput();

		cout << "Digite as horas a que a viagem acaba: Horas ";
		cin >> hf;
		if(cin.fail())
					throw ErroInput();
		cout << " Minutos: ";
		cin >> mf;
		if(cin.fail())
					throw ErroInput();
		cout << " Segundos: ";
		cin >> sf;
		if(cin.fail())
					throw ErroInput();

		cout << "Digite a dia em que a viagem ocorre: Dia ";
		cin >> dia;
		if(cin.fail())
					throw ErroInput();
		cout << " Mes: ";
		cin >> mes;
		if(cin.fail())
					throw ErroInput();
		cout << " Ano: ";
		cin >> ano;
		if(cin.fail())
					throw ErroInput();

		mostrarClientesPorID(cout,comp) << endl;
		cout << "ID do cliente que quer fazer uma viagem: ";
		cin >> id;
		if(cin.fail())
					throw ErroInput();
		erro=0;
		}

		catch (ErroInput &e){

			erro=e.alertaErro();
		}
		}
		try{

			comp.fazerviagem_cliente(id, Data(dia, mes, ano), Hora(hi, mi, si),
		Hora(hf, mf, sf),
				Percurso(localPartida, localDestino, distancia));
		break;
		}
		catch (ClienteInexistente &c){
		cout<<"Cliente numero "<<c.getID()<<" nao existe"<<endl;
		}
		/*catch (TaxisIndisponiveis &t)
		{
			cout<<t.getRazao()<<endl;

		}*/

	case 4:
		int id,i,erro;
		while(erro==1){
		try
		{cout << "ID do cliente que quer ver: ";
		cin >> id;
		erro=0;
		if(cin.fail())
			throw ErroInput();
		}
		catch (ErroInput &e){

					erro=e.alertaErro();
				}
		}
		i=comp.procuraCliente(id);
		if(i==-1)
			{cout<<"Cliente numero "<<id<<" nao existe"<<endl;
			break;}
		cout<<comp[i];
		break;

	case 5:
		return;

	default:
		throw OpcaoErrada();
	}
}
	catch(OpcaoErrada &x)
	{
		x.alertaErro();
	}
	}
}

void Menu::menuCompanhia(CompanhiaTaxis &comp) {
	cout << "||Companhia de taxis" << endl << setw(5) << " "
			<< "1. Nome da Companhia" << endl << setw(5) << " "
			<< "2. Ver Clientes por ID" << " " << "3. Gestao de Clientes" << " "
			<< "4. Ver capital" << " "
			<< "5. Prestar serviço a utente ocasional" << " "
			<< "6. Lista de clientes mais lucrativos" << " "
			<< "7. Mostrar todos os Taxis " << " "
			<< "8. Cobrar pagamentos mensais" << endl << setw(5) << " "
			<< "9. Sair" << endl << setw(5) << " " << "op: ";

	int opC;
	while(1){
	try{
	cin >> opC;

	switch (opC) {
	case 1:
		cout << comp.getNome() << endl;
		break;

	case 2:
		mostrarClientesPorID(cout,comp) << endl;
		break;

	case 3:
		menuClientes(comp);
		break;

	case 4:
		cout << "Capital: " << comp.getCapital() << endl;
		break;

	case 5:
		string nome;
		int t;
		cin.ignore();
		cout << setw(5) << " " << "Nome: ";
		getline(cin, nome);

		cout << setw(5) << " " << "Tipo de pagamento: " << endl;
		cout << "Escolher entre:" << endl;
		cout << "1: Numerario  " << "2: Multibanco" << endl;
		cin >> t;
		int id, distancia, hi, mi, si, hf, mf, sf, dia, mes, ano;
		string localPartida, localDestino;
		mostrarClientesPorID(cout,comp) << endl;
		cout << "ID do utente que quer fazer uma viagem: ";
		cin >> id;
		cout << "Qual é o local de origem da viagem? ";
		cin >> localPartida;
		cout << "E de destino? ";
		cin >> localDestino;
		cout << "Distancia entre locais: ";
		cin >> distancia;

		cout << "Digite as horas a que a viagem começa: Horas ";
		cin >> hi;
		cout << " Minutos: ";
		cin >> mi;
		cout << " Segundos: ";
		cin >> si;

		cout << "Digite as horas a que a viagem acaba: Horas ";
		cin >> hf;
		cout << " Minutos: ";
		cin >> mf;
		cout << " Segundos: ";
		cin >> sf;

		cout << "Digite a dia em que a viagem ocorre: Dia ";
		cin >> dia;
		cout << " Mes: ";
		cin >> mes;
		cout << " Ano: ";
		cin >> ano;

		//try{
		comp.fazerviagem_ocasional(Data(dia, mes, ano), Hora(hi, mi, si),
				Hora(hf, mf, sf),
				Percurso(localPartida, localDestino, distancia));
		break;
		//}
		/*catch (TaxisIndisponiveis &t)
				{
					cout<<t.getRazao()<<endl;

				}*/
	case 6:
		mostrarClientesPorCapital(cout,comp) << endl;
		break;

	case 7:
		mostrarTaxis(cout,comp);
		break;
	case 8:
		comp.cobrarPagamentoMensal();
		break;

	case 9:
		return;

	default:
		throw OpcaoErrada();
	}
	}
	catch (OpcaoErrada &x){
		x.alertaErro();
	}
	}
	}

