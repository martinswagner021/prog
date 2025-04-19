#include "tratarcsv.h"

void printOpcoes(){
    cout << "1- Realizar consulta" << endl;
    cout << "2- Filtrar resultados" << endl;
    cout << "3- Sair" << endl;
}

int main(){

    int selection;
    printOpcoes();
    cin >> selection;
    int mes, ano, x, y, tipoE;

    while(1){
        switch (selection)
        {
        case 1:
            cout << "Digite um mês: ";
            cin >> mes;
            cout << "Digite um ano: ";
            cin >> ano;
            consultarMovimentação(mes, ano);

            printOpcoes();
            cin >> selection;
            break;

        case 2:
            cout << "Digite um mês: ";
            cin >> mes;
            cout << "Digite um ano: ";
            cin >> ano;
            cout << "As movimentações em espécie devem ser pelo menos: ";
            cin >> x;
            cout << "As movimentações em eletrônicas devem ser pelo menos: ";
            cin >> y;
            cout << "As movimentações em espécie devem ser pelo menos" << x << " E/Ou " << "pelo menos " << y << endl;
            cout << "1- Ou" << endl;
            cout << "2- E" << endl;
            cin >> tipoE;
            switch (tipoE)
            {
            case 1:
                tipoE = 0;
                break;
            case 2:
                tipoE = 1;
                break;
            default:
                cout << "Digite um valor válido." << endl;
                break;
            }
            filtrarMovimentacao(mes, ano, x, y, tipoE);

            printOpcoes();
            cin >> selection;
            break;

        case 3:
            
            return 0;
            break;

        default:
            cout << selection << " não é uma opção válida." << endl;

            printOpcoes();
            cin >> selection;
            break;
        }
    }
}