#include "Empresa.h"

const string &Empresa::getNome() const {
    return nome;
}

const vector<Camiao*> &Empresa::getFrota() const {
    return frota;
}

Local *Empresa::getGaragem() const {
    return garagem;
}

Local *Empresa::getDeposito() const {
    return deposito;
}

void Empresa::addCamiao(Camiao *camiao) {
    frota.push_back(camiao);

}

Empresa::Empresa(string nome, Camiao *camiao, Local *garagem, Local *deposito) {
    this->nome = nome;
    frota.push_back(camiao);
    this->garagem = garagem;
    this->deposito = deposito;
}

void Empresa::addProduto(Produto *produto) {
    produtos.push_back(produto);
    produtos.sort();
}

Produto *Empresa::findProduto(string nome) {
    for(auto it = produtos.begin(); it != produtos.end(); it++)
        if((*it)->getNome() == nome) return *it;
    return nullptr;
}


void Empresa::setProdEntrega(int idCamiao){
	for(int i = 0; i < frota.size(); i++)
	{
		if(frota.at(i).getId() == idCamiao)
		{
			frota.at(i).setProd(produtos);
			return;
		}
	}
}
	
list<Produto*> Empresa::getProdEntrega(int idCamiao){
	for(int i = 0; i < frota.size(); i++)
	{
		if(frota.at(i).getId() == idCamiao)
			return frota.at(i).getProd();
	}
}

