#include <iostream>
#include <queue>
#include <string>

using namespace std;
struct paciente
{
    string senha;
    char prioridade;
    int hh;
    int mm;
};

int main(){
    queue<paciente> V, A, D, B;
    char opcao;
    bool controle = true;

    int totalAtendidos = 0;
    int atendidosV = 0, atendidosA = 0, atendidosD = 0, atendidosB = 0;
    int maxlotacao = V.size() + A.size() + D.size() + B.size();
    int esperaMaxima = 0;
    while (controle){
        cout << "\n[C] Chegada\n[A] Atendimento\n[D] Display\n[Q] Sair\n> ";
        cin >> opcao;
        paciente p;
        switch (opcao){

        case 'C':{
            cin >> p.senha >> p.prioridade >> p.hh >> p.mm;
            switch (p.prioridade) { 
                case 'V': V.push(p); break;
                case 'A': A.push(p); break;
                case 'D': D.push(p); break;
                default:  B.push(p); break;
            }
            int total = V.size() + A.size() + D.size() + B.size();
            maxlotacao = max(maxlotacao, total);
            break;
        }
        case 'A': {
            int ah, am;
            cin >> ah >> am;

            if (V.empty() && A.empty() && D.empty() && B.empty()) {
                cout << ah << " " << am << "Sem pacientes aguardando atendimento " << endl;
            } 
            else {
                paciente atendido;
                if (!V.empty()) {
                    atendido = V.front();
                    V.pop();
                    atendidosV++;
                }
                else if (!A.empty()) {
                    atendido = A.front();
                    A.pop();
                    atendidosA++;
                }
                else if (!D.empty()) {
                    atendido = D.front();
                    D.pop();
                    atendidosD++;
                }
                else {
                    atendido = B.front();
                    B.pop();
                    atendidosB++;
                }
                totalAtendidos++;
                cout << "Atendido: " << atendido.senha
                    << " (" << atendido.prioridade << ") às "
                    << atendido.hh << ":" 
                    << (atendido.mm < 10 ? "0" : "") << atendido.mm
                    << endl;
            }
            break;
        }
        case 'D':{
            cout << "V:" << V.size() << " " << "A:" << A.size() << " " << "D:" << 
            D.size() << " " << "B:" <<
            B.size() << "|" << " Atendidos:" <<totalAtendidos << endl;

            break;
        }
        case 'Q':{
            cout << "Total Atendidos:" << totalAtendidos << "\n"
            << "V=" << V.size() << " " << "A=" << A.size() << " " << "D=" <<
            D.size() << " " << "B=" << B.size() << "\n"
            << "Pico de lotação" << maxlotacao << "\n";
            controle = false;
            break;
        }

        default:
            controle = false;
            break;
        }
    }
    
    return 0;
}



// while (opção != 4)