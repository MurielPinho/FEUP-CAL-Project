#include "Produto.h"

Produto::Produto(string nome, long fatura, double peso, double preco, Local *destino) {
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

double Produto::getPeso() const {
    return peso;
}

double Produto::getPreco() const {
    return preco;
}

Local *Produto::getDestino() const {
    return destino;
}

bool Produto::operator<(const Produto &rhs) const {
    if (nome < rhs.nome)
        return true;
    if (rhs.nome < nome)
        return false;
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
