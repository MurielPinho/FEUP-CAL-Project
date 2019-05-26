#include "Local.h"
#include <list>
#include <vector>
#include <string>

class Produto
{
private:
    string nome;
    long fatura;
    int peso, preco;
    Local *destino;
public:
    const string &getNome() const;

    long getFatura() const;

    int getPeso() const;

    int getPreco() const;

    Local *getDestino() const;

    bool operator<(const Produto &rhs) const;

    bool operator>(const Produto &rhs) const;

    bool operator<=(const Produto &rhs) const;

    bool operator>=(const Produto &rhs) const;

    bool operator==(const Produto &rhs) const;

    void getInfo();

    Produto(string nome, long fatura, int peso, int preco, Local *destino);

};



