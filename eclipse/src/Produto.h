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
    /**
     * Funcao que retorna o nome do produto. 
     */
    const string &getNome() const;

    /**
     * Funcao que retorna o numero da fatura do produto.
     */
    long getFatura() const;

    /**
     * Funcao que retorna o peso do produto.
     */
    int getPeso() const;

    /**
     * Funcao que retorna o preco do produto.
     */
    int getPreco() const;

    /**
     * Funcao que retorna um apontador para o destino do produto.
     */
    Local *getDestino() const;

    /**
     * Funcao que mostra no ecra uma mensagem com detalhes sobre o produto.
     */
    void getInfo();

    bool operator<(const Produto &rhs) const;

    bool operator>(const Produto &rhs) const;

    bool operator<=(const Produto &rhs) const;

    bool operator>=(const Produto &rhs) const;

    bool operator==(const Produto &rhs) const;

    /**
    * Construtor de produto que recebe nome, numero de fatura, peso, preco e um apontador para o destino como parametros.
    */
    Produto(string nome, long fatura, int peso, int preco, Local *destino);

};



