#include <iostream>
#include <queue>
#include <string>
#include <cctype>
//funçao para deixar a entrada sempre maiusculo
std::string toUpperString(std::string s) {
    for(char &c : s) {
        c = std::toupper(static_cast<unsigned char>(c));
    }
    return s;
}
char toUpperChar(char c) {
    return std::toupper(static_cast<unsigned char>(c));
}
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
        opcao = toUpperChar(opcao);
        paciente p;
        switch (opcao){

        case 'C':{
            cin >> p.senha >> p.prioridade >> p.hh >> p.mm;
            p.prioridade = toUpperChar(p.prioridade);
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
                cout << ah << " " << am << " Sem pacientes aguardando atendimento " << endl;
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
                int chegada = atendido.hh * 60 + atendido.mm;
                int agora = ah * 60 + am;
                int espera = agora - chegada;
                esperaMaxima = max(esperaMaxima, espera);
                totalAtendidos++;
                cout << "Atendido: " << atendido.senha
                    << " (" << atendido.prioridade << ") às "
                    << ah << ":" 
                    << (am < 10 ? "0" : "") << am
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
            cout << "--- RELATÓRIO FINAL ---\n";
            cout << "Total atendidos: " << totalAtendidos << "\n";
            cout << "Por prioridade: "
                << "V=" << atendidosV << " "
                << "A=" << atendidosA << " "
                << "D=" << atendidosD << " "
                << "B=" << atendidosB << "\n";
            cout << "Pico de lotação: " << maxlotacao << "\n";
            cout << "Espera máxima: " << esperaMaxima << " min\n";
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