#include "Empresa.h"

Empresa::Empresa()
{
}

Empresa::~Empresa()
{
}

const string &Empresa::getNome() const {
    return nome;
}

const vector<Camiao> &Empresa::getFrota() const {
    return frota;
}

Garagem *Empresa::getGaragem() const {
    return garagem;
}

Deposito *Empresa::getDeposito() const {
    return deposito;
}

void Empresa::addCamiao(const Camiao &camiao) {
    frota.push_back(camiao);

}

Empresa::Empresa(string nome, Camiao camiao, Garagem *garagem, Deposito *deposito) {
    this->nome = nome;
    frota.push_back(camiao);
    this->garagem = garagem;
    this->deposito = deposito;
}

void Empresa::addProduto(const Produto &produto) {
    produtos.push_back(produto);
    produtos.sort();
}

