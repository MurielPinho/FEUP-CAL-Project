#include "Camiao.h"

int Camiao::num = 0;

Camiao::Camiao(double capacidade)
{
    this->capacidade = capacidade;
    num++;
    this->id = num;
}

Camiao::~Camiao()
{
}

int Camiao::getId(){
	return id;
}

void Camiao::setProd(list<Produto*> prod){

	//size = peso
	//val = preco
	vector<double> cost;
	vector<Produto*> best;
	
	for(int i = 0; i <= capacidade; i++)
	{
		cost.push_back(0.0);
		best.push_back(NULL);
	}
	
	for(int i = 1; i <= prod.size(); i++){
		for(k = prod.at(i).getPeso(); k <= capacidade; k++){
			if(prod.at(i).getPreco() + cost.at(k-prod.at(i).getPeso()) > cost.at(k))
			{
				cost.at(k) = prod.at(i).getPreco() + cost.at(k-prod.at(i).getPeso()
				best.at(k) = prod.at(i);
			}
		}
	}
	
	for(int i = 0; i < best.size(); i++)
	{
		entrega.push_back(best.at(i));
	}
}

list<Produto*> Camiao::getProd(){
	return entrega;
}

void Camiao::addProduto(Produto *produto) {
    entrega.push_back(produto);
}
