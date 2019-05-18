#include "Local.h"
#include <list>
#include <vector>
#include <string>
class Produto
{
private:
    string nome;
    long fatura;
    double peso, preco;
    Local *destino;
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

    void getInfo();

    Produto(string nome, long fatura, double peso, double preco, Local *destino);

};



