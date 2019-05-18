#include <iostream>
#include "Empresa.h"
#include "Utilities.h"

using namespace std;

Empresa *empresa;
vector<GraphViewer> graphs;


void menuInicial();
void carregarMapa();
void estoque();
void navegar();
void verificaOpcao(int &opt, int min, int max);


int main() {
    int opt;
    double capacidade;
    string loc1, loc2;

    cout << endl << "Insira a capacidade do camião inicial: ";
    cin >> capacidade;
    cin.clear();
    cin.ignore(1000, '\n');
    Camiao *camiao = new Camiao(capacidade);

    cout << endl << "Insira a localidade da Garagem: ";
    getline(cin, loc1);
    Local *garagem = new Local(loc1);

    cout << endl << "Insira a localidade do Deposito: ";
    getline(cin, loc1);
    Local *deposito = new Local(loc2);


    empresa = new Empresa("SmartDelivery", camiao, garagem, deposito);

    do{
        cout << endl;
        menuInicial();
        cin >> opt;
        verificaOpcao(opt, 0, 3);

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
    verificaOpcao(opt, 0, 2);

    if(opt == 2)
    {

    }
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
    verificaOpcao(opt, 0, 3);


    if(opt == 1){
        string nome, loc;
        long fatura;
        double peso, preco;

        cin.clear();
        cout << "Insira o nome do produto: ";
        getline(cin, nome);

        cout << endl << "Insira o numero da fatura: ";
        cin >> fatura;

        cout << endl << "Insira o peso do produto: ";
        cin >> peso;

        cout << endl << "Insira o preço do produto: ";
        cin >> preco;

        cout << endl << "Insira o local do destino do produto: ";
        cin.clear();
        cin.ignore(1000, '\n');
        getline(cin, loc);
        Local *local = new Local(loc);

        Produto *p = new Produto(nome, fatura, peso, preco, local);
        empresa->addProduto(p);
    } else if(opt == 2){
        Produto *produto;
        string nome;
        cout << "Insira o nome do produto: ";
        getline(cin, nome);

        if((produto = empresa->findProduto(nome)) == nullptr)
            cout << "Produto não encontrado." << endl, estoque();
        else
            produto->getInfo();

    }


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
    verificaOpcao(opt, 0, 3);

    switch (opt){
        case 1:

            break;
        case 2:
            break;
        case 3:
            break;
    }

    cout << endl;
}

void verificaOpcao(int &opt, int min, int max) {
    while(opt < min || opt > max){
        cout << endl << "Digito inválido. Insira novamente:" << endl;
        cin >> opt;
    }
    cin.clear();
    cin.ignore(1000, '\n');
}

