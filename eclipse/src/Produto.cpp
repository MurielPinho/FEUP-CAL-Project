#include <iostream>
#include "Produto.h"

Produto::Produto(string nome, long fatura, int peso, int preco, Local *destino) {
    this->nome = nome;
    this->fatura = fatura;
    this->peso = peso;
    this->preco = preco;
    this->destino = destino;
}

const string &Produto::getNome() const {
    return nome;
}

long Produto::getFatura() const {
    return fatura;
}

int Produto::getPeso() const {
    return peso;
}

int Produto::getPreco() const {
    return preco;
}

Local *Produto::getDestino() const {
    return destino;
}

bool Produto::operator<(const Produto &rhs) const {
    return peso < rhs.peso;
}

bool Produto::operator>(const Produto &rhs) const {
    return rhs < *this;
}

bool Produto::operator<=(const Produto &rhs) const {
    return !(rhs < *this);
}

bool Produto::operator>=(const Produto &rhs) const {
    return !(*this < rhs);
}

bool Produto::operator==(const Produto &rhs) const {
    if(nome == rhs.getNome() && fatura == rhs.getFatura() && peso == rhs.getPeso() && preco == rhs.getPreco() && destino == rhs.getDestino())
		return true;

    return false;
}

void Produto::getInfo() {
    cout << "Nome: " << nome << endl;
    cout << "Fatura: " << fatura << endl;
    cout << "Peso: " << peso  << endl;
    cout << "Preço: " << preco << endl;
    cout << "Destino: " << destino->getId() << endl;
}
