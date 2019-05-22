#include "Camiao.h"

using namespace std;

class Empresa
{
private:
    string nome;
    vector<Camiao*> frota;
    Local *garagem;
    Local *deposito;

    vector<Produto*> produtos;

public:
    Empresa(string nome, Camiao *camiao, Local *garagem, Local *deposito);

    const string &getNome() const;

    const vector<Camiao*> &getFrota() const;

    Local *getGaragem() const;

    Local *getDeposito() const;

    void addCamiao(Camiao *camiao);

    void addProduto(Produto *produto);

    Produto* findProduto(string nome);

	void setProdEntrega(int idCamiao);

    vector<Produto *> getProdEntrega(int idCamiao);

    void updateProd(vector<Produto*> oldProd);

    bool findTruck(int id);
};

