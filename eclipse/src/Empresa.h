#include "Camiao.h"

using namespace std;

class Empresa
{
private:
    string nome;
    vector<Camiao*> frota;
    vector<Produto*> produtos;

public:
    /**
    * Construtor de Empresa que recebe um nome e um apontador para um camiao como parametros.
    */
    Empresa(string nome, Camiao *camiao);

    /**
    * Funcao que retorna o nome da Empresa.
    */
    const string &getNome() const;

    /**
    * Funcao que retorna um vector dos camioes da empresa.
    */
    const vector<Camiao*> &getFrota() const;

    /**
    * Funcao que recebe um apontador para um camiao e adiciona no vector frota.
    */
    void addCamiao(Camiao *camiao);
    
    /**
    * Funcao que recebe um apontador para um produto e adiciona no vector produtos.
    */
    void addProduto(Produto *produto);

    /**
    * Funcao que recebe um nome como parametro e retorna um apontador para o produto com este nome.
    */
    Produto* findProduto(string nome);

    /**
    * Funcao que recebe um id e coloca produtos a serem entregues no camiao com este id.
    */
    void setProdEntrega(int idCamiao);

    /**
    * Funcao que recebe um id como parametro e retorna um vector dos produtos a serem entregues pelo camiao com este id.
    */
    vector<Produto *> getProdEntrega(int idCamiao);

    /**
    * Funcao que recebe um vector de produtos e atualiza o vector produtos.
    */
    void updateProd(vector<Produto*> oldProd);

    /**
    * Funcao que recebe um id como parametro e retorna se existe um camiao com este id.
    */
    bool findTruck(int id);

    /**
    * Funcao que recebe um id como parametro e retorna um apontador para o camiao com este id.
    */
    Camiao* getTruck(int id);

    /**
    * Funcao que retorna um vector com os produtos.
    */
    vector<Produto*> getProd();
};

