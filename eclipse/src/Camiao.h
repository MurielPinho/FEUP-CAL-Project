#include "Produto.h"
class Camiao
{
private:
    double capacidade;
    int id;
    vector<Produto*> entrega;
public:
    /**
    * Id static que incrementa-se toda vez que se cria um novo Camiaos
    */
    static int num;

    /**
    * Construtor de Camiao que recebe a capacidade como parametro.
    */
    Camiao(double capacidade);

    /**
    * Funcao que retorna o id do camiao.
    */
    int getId();

    /**
    * Funcao que recebe um vector de produtos e calcula a forma mais eficaz de carregar os produtos no camiao.
    */
    void setProd(vector<Produto*> prod);

    /**
    * Funcao que retorna o vector de produtos do camiao.
    */
    vector<Produto*> getProd();

    /**
    * Funcao que recebe um apontador para um produto e adiciona ao vector entrega.
    */
    void addProduto(Produto *produto);

    /**
    * Funcao que retorna a capacidade do camiao.
    */
    double getCapacidade();

};
