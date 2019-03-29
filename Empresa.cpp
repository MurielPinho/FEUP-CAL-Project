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

Local *Empresa::getLocal() const {
    return local;
}
