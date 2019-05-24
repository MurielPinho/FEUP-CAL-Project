#include <iostream>
#include "Utilities.h"

using namespace std;

Empresa *empresa;
GraphViewer *graph;
bool porto = false;

//ADD CAMIOES e ADD PRODUTOS
//Graphs
Graph<Local> city;

//Functions
void createNetwork(Graph<Local> & cidade, string name);
void menuInicial();
void carregarMapa();
void estoque();
void navegar();
void verificaOpcao(int &opt, int min, int max);
void definirGaragemPorto();
void definirDepoPorto();

int main() {
    int opt;
    double capacidade;

    carregarMapa();

/*
	//DEBUG MODE
    cout << "Imprimir" << endl;
    displayGraph(city);
    return 0;
*/
    cout << endl << "Insira a capacidade do cami�o inicial: ";
    cin >> capacidade;
    cin.clear();
    cin.ignore(1000, '\n');
    Camiao *camiao = new Camiao(capacidade);

    if(porto)
    {
    	definirDepoPorto();
    	definirGaragemPorto();
    }
    else
    {
    	//maia load
    }

    empresa = new Empresa("SmartDelivery", camiao);

    do{
        cout << endl;
        menuInicial();
        cin >> opt;
        verificaOpcao(opt, 0, 3);

        cout << endl;

        if(opt == 1) estoque();
        else if(opt == 2) navegar();

    } while (opt != 0);
    return 0;
}

void menuInicial(){
    cout << "--------- Smart Delivery ---------" << endl;
    cout << "           Menu Inicial" << endl << endl;
    cout << "Selecione uma op��o:" << endl;
    cout << "1. Estoque" << endl;
    cout << "2. Navegar" << endl;
    cout << "0. Sair" << endl;
    cout << "----------------------------------" << endl;
    cout << "Op��o: ";
}

void carregarMapa(){
	int bg;
	cout << "---------Bem Vindo ao Smart Delivery ---------" << endl;
    cout << "Selecione em qual cidade deseja operar:" << endl;
    cout << "1. Porto" << endl;
    cout << "2. Maia" << endl;
    cout << "0. Sair" << endl;
    cout << "----------------------------------" << endl;
    cout << "Op��o: ";
    cin >> bg;
    verificaOpcao(bg, 0, 2);

    if(bg == 1)
    {
    	createNetwork(city, "porto");
    	porto = true;
    }
    else if(bg == 2)
    {
    	createNetwork(city, "maia");
    	porto = false;
    }
    else
    	exit (0);
}

void estoque() {
    int opt;
    cout << "--------- Smart Delivery ---------" << endl;
    cout << "             Estoque" << endl << endl;
    cout << "Selecione uma op��o:" << endl;
    cout << "1. Adicionar produto" << endl;
    cout << "2. Pesquisar item" << endl;
    cout << "3. Carregar camiao" << endl;
    cout << "0. Voltar" << endl;
    cout << "----------------------------------" << endl;
    cout << "Op��o: ";

    cin >> opt;
    verificaOpcao(opt, 0, 3);


    if(opt == 1){
        string nome;
        int id;
        long fatura;
        double peso, preco;

        cin.clear();
        cout << "Insira o nome do produto: ";
        getline(cin, nome);

        cout << endl << "Insira o numero da fatura: ";
        cin >> fatura;

        cout << endl << "Insira o peso do produto: ";
        cin >> peso;

        cout << endl << "Insira o pre�o do produto: ";
        cin >> preco;

        cout << endl << "Insira o Id do local de destino do produto: ";
        cin >> id;

        Local *local = new Local(city.findVertex(Local(id, 0, 0))->getInfo());
        Produto *p = new Produto(nome, fatura, peso, preco, local);
        empresa->addProduto(p);
    } else if(opt == 2){

    	Produto *produto;
        string nome;
        cout << "Insira o nome do produto: ";
        getline(cin, nome);

        if((produto = empresa->findProduto(nome)) == nullptr)
            cout << "Produto n�o encontrado." << endl, estoque();
        else
            produto->getInfo();

    } else {
    	int id;
    	bool ret = false;
    	cout << "Insira o ID do cami�o: ";
        cin >> id;
        for(unsigned i = 0; i < empresa->getFrota().size(); i++)
        {
        	ret = true;
        	if(empresa->getFrota().at(i)->getId() == id)
        		empresa->setProdEntrega(id);
        }
        if(ret)
        	cout << "Cami�o carregado com sucesso!" << endl;
        else
        	cout << "ID n�o encontrado" << endl;
    }


    cout << endl;
}

void navegar(){
    int opt;
    cout << "------------------- Smart Delivery ------------------" << endl;
    cout << "                       Navegar" << endl << endl;
    cout << "Selecione uma op��o:" << endl;
    cout << "1. Visualizar mapa" << endl;
    cout << "2. Caminho mais curto entre dois pontos" << endl;
    cout << "3. Caminho mais curto para entrega de mercadorias" << endl;
    cout << "   (Passando em um conjunto de pontos de interesse)" << endl;
    cout << "0. Voltar" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Op��o: ";


    cin >> opt;
    verificaOpcao(opt, 0, 3);
    if(opt == 1)
    {
        displayGraph(city);
    }
    else if(opt == 2)
    {
    	int c, id;
    	vector<Local> aux;
    	cout << endl << "Escolha o sentido" << endl;
        cout << "1. Garagem -> Dep�sito" << endl;
        cout << "2. �ltima entrega -> Garagem" << endl;
        cout << "Op��o: ";
        cin >> c;
        verificaOpcao(c, 1, 2);
        if(c == 1)
        {
        	city.dijkstraShortestPath(city.getGarage());
        	aux = city.getPath(city.getGarage(), city.getDepo());
        	cout << aux.size() << endl;
/*
        	for(unsigned i = 0; i < aux.size(); i++)
        		cout << aux.at(i).getId() << endl;
*/
        	displayGraph(aux);
        	aux.clear();
        }
        else
        {
            cout << "Qual ID do cami�o" << endl;
            cout << "ID: ";
            cin >> id;
            if(!empresa->findTruck(id)){
            	cout << "Cami�o n�o existe" << endl;
            	exit (0);
            }
        	Local *extra = empresa->getProdEntrega(id).at(empresa->getProdEntrega(id).size()-1)->getDestino();
        	if(empresa->getProdEntrega(id).empty()){
        		cout << "Cami�o n�o esta na rua" << endl;
        		exit (0);
        	}
        	Local e = *extra;
        	city.dijkstraShortestPath(e);
        	aux = city.getPath(e, city.getGarage());
        	displayGraph(aux);
        	aux.clear();
        }
    }
    else if(opt == 3)
    {
    	Graph<Local> aux;
    	int id;
        cout << "Qual ID do cami�o" << endl;
        cout << "ID: ";
        cin >> id;
        if(!empresa->findTruck(id)){
        	cout << "Cami�o n�o existe" << endl;
        	exit (0);
        }
        Camiao *c = empresa->getTruck(id);
        aux.addVertex(city.getDepo());
        for(unsigned i = 0; i < c->getProd().size(); i++)
        {
        	Local e = *c->getProd().at(i)->getDestino();
        	aux.addVertex(city.findVertex(e)->getInfo());
        }

    	displayGraph(aux.dfs());
    }
    else
    	exit (0);
}

void verificaOpcao(int &opt, int min, int max) {
    while(opt < min || opt > max){
        cout << endl << "Digito inv�lido. Insira novamente:" << endl;
        cin >> opt;
    }
    cin.clear();
    cin.ignore(1000, '\n');
}


void createNetwork(Graph<Local> & cidade, string name){
	if(name == "maia")
		loadGraph("Mapas\\Maia\\T04_nodes_X_Y_Maia.txt", "Mapas\\Maia\\T04_edges_Maia.txt", "Mapas\\Maia\\T04_tags_Maia.txt", cidade);
	else
		loadGraph("Mapas\\Porto\\T04_nodes_X_Y_Porto.txt", "Mapas\\Porto\\T04_edges_Porto.txt", "Mapas\\Porto\\T04_tags_Porto.txt", cidade);
}

void definirGaragemPorto(){
	int bg;
	cout << "Definir garagem" << endl;
    cout << "Selecione uma op��o:" << endl;
    cout << "1. Boa Vista" << endl;
    cout << "2. S�o Jo�o" << endl;
    cout << "3. Est�dio do Drag�o" << endl;
    cout << "4. Matosinhos" << endl;
    cin >> bg;
    verificaOpcao(bg, 1, 4);

    if(bg == 1)
    {
    	if(city.setGarage(137817855))
    		cout << "Garagem registada com sucesso" << endl;
    }
    else if(bg == 2)
    {
    	if(city.setGarage(429833953))
    		cout << "Garagem registada com sucesso" << endl;
    }
    else if(bg == 3)
    {
    	if(city.setGarage(424013918))
    		cout << "Garagem registada com sucesso" << endl;
    }
    else
    {
    	if(city.setGarage(111506000))
    		cout << "Garagem registada com sucesso" << endl;
    }
}

void definirDepoPorto(){
	int bg;
	cout << "Definir garagem" << endl;
    cout << "Selecione uma op��o:" << endl;
    cout << "1. Boa Vista" << endl;
    cout << "2. S�o Jo�o" << endl;
    cout << "3. Est�dio do Drag�o" << endl;
    cout << "4. Matosinhos" << endl;
    cin >> bg;
    verificaOpcao(bg, 1, 4);

    if(bg == 1)
    {
    	if(city.setDepo(137817855))
    		cout << "Garagem registada com sucesso" << endl;
    }
    else if(bg == 2)
    {
    	if(city.setDepo(429833953))
    		cout << "Garagem registada com sucesso" << endl;
    }
    else if(bg == 3)
    {
    	if(city.setDepo(424013918))
    		cout << "Garagem registada com sucesso" << endl;
    }
    else
    {
    	if(city.setDepo(111506000))
    		cout << "Garagem registada com sucesso" << endl;
    }
}
