#include "Empresa.h"

const string &Empresa::getNome() const {
    return nome;
}

const vector<Camiao*> &Empresa::getFrota() const {
    return frota;
}

void Empresa::addCamiao(Camiao *camiao) {
    frota.push_back(camiao);

}

Empresa::Empresa(string nome, Camiao *camiao) {
    this->nome = nome;
    frota.push_back(camiao);
}

void Empresa::addProduto(Produto *produto) {
    produtos.push_back(produto);
    sort(produtos.begin(), produtos.end());
}

Produto *Empresa::findProduto(string nome) {
    for(auto it = produtos.begin(); it != produtos.end(); it++)
        if((*it)->getNome() == nome) return *it;
    return nullptr;
}


void Empresa::setProdEntrega(int idCamiao){
	for(unsigned i = 0; i < frota.size(); i++)
	{
		if(frota.at(i)->getId() == idCamiao)
		{
			frota.at(i)->setProd(produtos);
			updateProd(frota.at(i)->getProd());
			return;
		}
	}
}
	
vector<Produto*> Empresa::getProdEntrega(int idCamiao){
	for(unsigned i = 0; i < frota.size(); i++)
	{
		if(frota.at(i)->getId() == idCamiao)
			return frota.at(i)->getProd();
	}
    vector<Produto*> v;
    return v;
}

void Empresa::updateProd(vector<Produto*> oldProd){
	vector<Produto*> res;

	for(unsigned i = 0; i < produtos.size(); i++)
	{
		bool add = true;
		for(unsigned j = 0; j < oldProd.size(); j++)
		{
			if(oldProd.at(j)==produtos.at(i))
			{
				add = false;
				break;
			}
		}
		if(add)
			res.push_back(produtos.at(i));
	}
	produtos.clear();
	produtos = res;
}

bool Empresa::findTruck(int id){
	for(unsigned i = 0; i < frota.size(); i++)
		if(frota.at(i)->getId() == id)
			return true;

	return false;
}

Camiao* Empresa::getTruck(int id){
	for(unsigned i = 0; i < frota.size(); i++)
		if(frota.at(i)->getId() == id)
			return frota.at(i);

	return NULL;
}
