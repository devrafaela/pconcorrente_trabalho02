#include <iostream>
#include <unistd.h>
using namespace std;

/**
 *										VARIAVEIS 		GLOBAIS 
 *  pid_t xxx: definido pela biblioteca unistd.h, representa os identificadores dos processos
 *  int nascDoXxxXx : ira representar o ano de nascimento dos descendentes da Mae
 *  int ano: ira representar o ano, e sera inicializado com 0
 */
static pid_t mae, filhaUm, filhaDois, filhaTres, netaUm, netaDois, bisnetaUm;
int nascDaFilhaUm, nascDaFilhaDois, nascDaFilhaTres, nascDaNetaUm, nascDaNetaDois, nascDaBisnetaUm;
int ano = 0;

/* ***************************************************************
 * Autor............: Rafaela Pereira Santos
 * Matricula........: 202110838
 * Inicio...........: 14/03/2023
 * Ultima alteracao.: 14/03/2023
 * Nome.............: Principal
 * Funcao...........: Simula a Arvore Genealogica da Familia Code
 *************************************************************** */
int main (){

	mae = getpid();

	cout << "=====================\n INICIO da Simulacao \n=====================" << "\n";
	cout << "\nArvore Genealogica da Familia Code\n";

	while (true) {
		if (getpid() == mae) {
			cout << "Ano: " << 2000 + ano << endl;
		}

		switch (ano) {
			case -1: // -- Ocorreu um erro na execucao -- // 
			exit(1);

			case 0: // -- NASCE A MAE -- //
				if (getpid() == mae) {
				  cout << " - Em: " << 2000 + ano << ", nasce Ada Code, a matriarca (mae) da Familia Code -" << endl;
				}
			break;

			case 22: // -- A MAE TEM A PRIMEIRA FILHA AOS 22 ANOS -- //
				if (getpid() == mae) {
					cout << " [Ada Code (mae) teve a sua PRIMEIRA FILHA aos " << ano << " anos]\n";
				  cout << " - Em: " << 2000 + ano << ", nasce Sofia Code, A PRIMEIRA FILHA de Ada. - " << endl;
					filhaUm = fork(); // nasce a primeira filha
					nascDaFilhaUm = ano;
					if (filhaUm == 0) { // processo da primeira filha
						cout << " {ID Processo da Sofia eh: " << (filhaUm = getpid()) << "}" << endl;
					}
				}
			break;

			case 25: // -- A MAE TEM A SEGUNDA FILHA AOS 25 ANOS -- //
			 if (getpid() == mae) {
					cout << " [Ada Code (mae) teve a sua SEGUNDA FILHA aos " << ano << " anos]\n";
				  cout << " - Em: " << 2000 + ano << ", nasce Grace Code, A SEGUNDA FILHA de Ada. - " << endl;
				  filhaDois = fork(); // nasce a segunda filha
					nascDaFilhaDois = ano;
					if (filhaDois == 0) { // processo da segunda filha
						cout << " {ID Processo da Grace eh: " << (filhaDois = getpid()) << "}" << endl;
					}
				}
			break;

			case 32: // --A MAE TEM A TERCEIRA FILHA AOS 32 ANOS -- //
			  if (getpid() == mae) {
					cout << " [Ada Code (mae) teve a sua TERCEIRA FILHA aos " << ano << " anos]\n";
				  cout << " - Em: " << 2000 + ano << ", nasce Hedy Code, A TERCEIRA FILHA de Ada. - " << endl;
				  filhaTres = fork(); // nasce a terceira filha
					nascDaFilhaTres = ano;
					if (filhaTres == 0) { // processo da terceira filha
						cout << " {ID Processo da Hedy eh: " << (filhaTres = getpid()) << "}" << endl;
					}
				}
			break;

			case 39: // -- A MAE EH AVO (PRIMEIRA FILHA) AOS 38 ANOS -- //
			  if (getpid() == filhaUm) {
					cout << " [Ada Code (mae) teve a sua PRIMEIRA NETA (da primeira filha) aos " << ano - 1 << " anos]\n";
				  cout << " - Em: " << (2000 + ano) - 1 << ", nasce Barbara Code, a PRIMEIRA NETA de Ada. - " << endl;
				  netaUm = fork(); // nasce a primeira neta
					nascDaNetaUm = ano;
					if (netaUm == 0) { // processo da primeira neta
						cout << " {ID Processo da Barbara eh: " << (netaUm = getpid()) << "}" << endl;
					}
				}
			break;

			case 46: // -- A MAE EH AVO (SEGUNDA FILHA) AOS 45 ANOS -- //
			  if (getpid() == filhaDois) {
					cout << " [Ada Code (mae) teve a sua SEGUNDA NETA (da segunda filha) aos " << ano - 1 << " anos]\n";
				  cout << " - Em: " << (2000 + ano) - 1 << ", nasce Radia Code, a SEGUNDA NETA de Ada. - " << endl;
				  netaDois = fork(); // nasce a primeira neta
					nascDaNetaDois = ano;
					if (netaDois == 0) { // processo da primeira neta
						cout << " {ID Processo da Radia eh: " << (netaDois = getpid()) << "}" << endl;
					}
				}
			break;

    case 69: // -- A MAE EH BISAVO (PRIMEIRA FILHA) AOS 68 ANOS -- //
      if(getpid() == netaUm) {
        cout << " [Ada Code (mae) teve a sua PRIMEIRA BISNETA (da primeira filha) aos " << ano - 1 << " anos]\n";
        cout << " - Em: " << (2000 + ano) - 1 << ", nasce Susan Code, a PRIMEIRA BISNETA de Ada. - " << endl;
        bisnetaUm = fork(); // nasce a primeira neta
        nascDaBisnetaUm = ano;
        if (bisnetaUm == 0) { // processo da primeira neta
          cout << " {ID Processo da Radia eh: " << (bisnetaUm = getpid()) << "}" << endl;
        }
      }
    break;

    // -- MORTE DOS FAMILIARES A PARTIR DESSE TRECHO -- //
		// -- Os cases abaixo foram associados a quantos anos a mae possui no exato momento em que ocorre uma morte -- //

		case 73: // -- A PRIMEIRA NETA MORRE AOS 35 ANOS -- //
      if (getpid() == netaUm) {
        cout << "[Barbara Code, a PRIMEIRA NETA (da primeira filha) de Ada morre aos " << (ano - nascDaNetaUm) + 1 << " anos]\n";
				cout << " - Em " << (2000 + ano) - 1 << ", morre Barbara Code. -" << endl;
        _exit(0);
      }
      break;

		case 78: // -- A SEGUNDA NETA MORRE AOS 33 ANOS -- //
      if (getpid() == netaDois)
      {
        cout << "[Radia Code, a SEGUNDA NETA (da segunda filha) de Ada morre aos " << (ano - nascDaNetaDois) + 1 << " anos]" << endl;
				cout << " - Em " << (2000 + ano) - 1 << ", morre Radia Code. -" << endl;
        _exit(0);
      }
      break;

		case 80: // -- A SEGUNDA FILHA MORRE AOS 55 ANOS -- //
      if (getpid() == filhaDois) {
        cout << "[Grace Code, a SEGUNDA FILHA de Ada morre aos " << (ano - nascDaFilhaDois) << " anos" << endl;
        cout << " - Em " << (2000 + ano) - 1 << ", morre Grace Code. -" << endl;      
        _exit(0);
      }
      if (getpid() == bisnetaUm) {
        cout << "[Susan Code, a PRIMEIRA BISNETA (da primeira filha) de Ada morre aos " << (ano - nascDaBisnetaUm) + 1 << " anos]\n";
        cout << " - Em " << (2000 + ano) - 1 << ", morre Susan Code. - " << endl;
        _exit(0);
      }
    break;

		case 82: // -- A PRIMEIRA FILHA MORRE AOS 61 ANOS -- //
			if (getpid() == filhaUm) {
				cout << "[Sofia Code, a PRIMEIRA FILHA de Ada morre aos " << (ano - nascDaFilhaUm) << " anos" << endl;
        cout << " - Em " << (2000 + ano) - 1 << ", morre Sofia Code. -" << endl;      
        _exit(0);
			}
    break;

    case 87: // -- A TERCEIRA FILHA MORRE AOS 55 ANOS -- //
      if (getpid() == filhaTres) {
        cout << "[Hedy Code, a TERCEIRA FILHA de Ada morre aos " << (ano - nascDaFilhaTres) << " anos" << endl;
        cout << " - Em " << (2000 + ano) - 1 << ", morre Hedy Code. -" << endl;      
        _exit(0);
			}
    break; 

    case 90: // -- A MAE MORRE AOS 90 ANOS -- //
      if (getpid() == mae) {
        cout << "[Ada Code, a matriarca da Familia Code morre aos " << ano << " anos]" << endl;
        cout << " - Em " << 2000 + ano << ", morre Ada Code. -" << endl;      
        _exit(0);
      }
    break;

		} // fim do switch

		sleep(1); // -- A cada 1 Segundo ocorre algo -- //
		ano++; // -- O ano eh incrementado de 1 em 1 -- //
	} // fim do while

  cout << "=====================\n FIM da Simulacao \n=====================" << "\n";
  
return 0;
} // fim de main