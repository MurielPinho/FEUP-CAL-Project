#include "Camiao.h"

int Camiao::num = 0;

Camiao::Camiao(double capacidade)
{
    this->capacidade = capacidade;
    this->id = num++;
}

Camiao::~Camiao()
{
}

int Camiao::getId(){
	return id;
}

void Camiao::setProd(vector<Produto*> prod){

	//size = peso
	//val = preco
	vector<double> cost;
	vector<Produto*> best;

	
	for(int i = 0; i <= capacidade; i++)
	{
		cost.push_back(0.0);
		best.push_back(NULL);
	}
	
	for(auto it = prod.begin(); it != prod.end(); it++){
		for(int k = (*it)->getPeso(); k <= capacidade; k++){
			if((*it)->getPreco() + cost.at(k-(*it)->getPeso()) > cost.at(k))
			{
				cost.at(k) = (*it)->getPreco() + cost.at(k-(*it)->getPeso());
				best.at(k) = *it;
			}
		}
	}
	
	for(unsigned i = 0; i < best.size(); i++)
	{
		entrega.push_back(best.at(i));
	}
}

vector<Produto*> Camiao::getProd(){
	return entrega;
}

void Camiao::addProduto(Produto *produto) {
    entrega.push_back(produto);
}
