#include <iostream>
#include <queue>

using namespace std;
struct paciente
{
    int senha;
    string prioridade;
    int hh;
    int mm;
};


/*bool compara(const  &e1, const  &e2){
    return(c1.P > e2.P) || // primeiro critério
          (e1.P == e2.P && e1.saldo > e2.saldo) || //segundo critério
          (e1.P == e2.P && e1.saldo == e2.saldo && e1.SG > e2.SG) || //terceiro 
          (e1.P == e2.P && e1.saldo == e2.saldo && e1.SG == e2.SG && e1.nome < e2.nome); // quarto critérios
          bool da prova pra usar como base
}*/


int main(){
    queue<paciente> V, A, D, B;
    char opcao;
    bool controle = true;

    int totalAtendidos = 0;
    int atendidosV = 0, atendidosA = 0, atendidosD = 0, atendidosB = 0;
    int maxlotacao = 0;
    int esperaMaxima = 0;
    while (controle){
        cout << "\n[C] Chegada\n[A] Atendimento\n[D] Display\n[Q] Sair\n> ";
        cin >> opcao;
        paciente p;
        switch (opcao){

        case 'C':{
            cin >> p.senha >> p.prioridade >> p.hh >> p.mm;
            if(p.prioridade == "V"){
                V.push(p);
            }
            else if (p.prioridade == "A"){
               A.push(p);
            }
            else if (p.prioridade == "D"){
               D.push(p);
            }
            else if (p.prioridade == "B"){
               B.push(p);
            }
            int total = V.size() + A.size() + D.size() + B.size();
            maxlotacao = max(maxlotacao, total);
            break;
        }
        case 'A':{
            if (V.empty() && A.empty() && D.empty() && B.empty()) {
                cout << p.hh << p.mm << "Sem pacientes aguardando atendimento." << endl;
            }
            else{

            }
            break;
        }
        case 'D':{
            break;
        }
        case 'Q':{
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