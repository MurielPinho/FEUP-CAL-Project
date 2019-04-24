#include <iostream>

using namespace std;

void menuInicial();
void carregarMapa();
void estoque();
void navegar();


int main() {
    int opt;

    do{
        cout << endl;
        system("clear");
        menuInicial();
        cin >> opt;
        system("clear");

        cout << endl;

        if(opt == 1) carregarMapa();
        else if(opt == 2) estoque();
        else if(opt == 3) navegar();


    } while (opt != 0);
    return 0;
}

void menuInicial(){
    cout << "--------- Smart Delivery ---------" << endl;
    cout << "           Menu Inicial" << endl << endl;
    cout << "Selecione uma opção:" << endl;
    cout << "1. Carregar um mapa" << endl;
    cout << "2. Estoque" << endl;
    cout << "3. Navegar" << endl;
    cout << "0. Sair" << endl;
    cout << "----------------------------------" << endl;
    cout << "Opção: ";
}

void carregarMapa(){
    int opt;
    cout << "--------- Smart Delivery ---------" << endl;
    cout << "          Carregar Mapa" << endl << endl;
    cout << "Selecione uma opção:" << endl;
    cout << "1. Mapa Paranhos (Pequeno)" << endl;
    cout << "2. Mapa Porto (Grande)" << endl;
    cout << "0. Voltar" << endl;
    cout << "----------------------------------" << endl;
    cout << "Opção: ";
    cin >> opt;
    cout << endl;


}

void estoque() {
    int opt;
    cout << "--------- Smart Delivery ---------" << endl;
    cout << "             Estoque" << endl << endl;
    cout << "Selecione uma opção:" << endl;
    cout << "1. Adicionar produto" << endl;
    cout << "2. Pesquisar item" << endl;
    cout << "3. Carregar camiao" << endl;
    cout << "0. Voltar" << endl;
    cout << "----------------------------------" << endl;

    cout << "Opção: ";
    cin >> opt;
    cout << endl;
}

void navegar(){
    int opt;
    cout << "------------------- Smart Delivery ------------------" << endl;
    cout << "                       Navegar" << endl << endl;
    cout << "Selecione uma opção:" << endl;
    cout << "1. Visualizar mapa" << endl;
    cout << "2. Caminho mais curto entre dois pontos" << endl;
    cout << "3. Caminho mais curto para entrega de mercadorias" << endl;
    cout << "   (Passando em um conjunto de pontos de interesse)" << endl;
    cout << "0. Voltar" << endl;
    cout << "-----------------------------------------------------" << endl;

    cout << "Opção: ";
    cin >> opt;
    cout << endl;
}

