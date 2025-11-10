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
    while (true){
        cin >> opcao;
        switch (opcao){

        case 'C':{
            paciente p;
            cin >> p.senha >> p.prioridade >> p.hh >> p.mm;
            break;
        }
        case 'A':{

        }
        case 'D':{
            
        }
        case 'Q':{
            
        }

        default:
            break;
        }
    }

    return 0;
}