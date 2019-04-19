#include "Local.h"

class Produto
{
private:
    string nome;
    long fatura;
public:
    const string &getNome() const;

    long getFatura() const;

    double getPeso() const;

    double getPreco() const;

    Local *getDestino() const;

    bool operator<(const Produto &rhs) const;

    bool operator>(const Produto &rhs) const;

    bool operator<=(const Produto &rhs) const;

    bool operator>=(const Produto &rhs) const;

private:
    double peso, preco;
    Local *destino;
public:
    Produto(string nome, long fatura, double peso, double preco, Local *destino);

};



