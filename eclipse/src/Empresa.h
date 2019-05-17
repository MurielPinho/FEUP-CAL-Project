#include "Camiao.h"

using namespace std;

class Empresa
{
private:
    string nome;
    vector<Camiao*> frota;
    Local *garagem;
    Local *deposito;

    list<Produto*> produtos;
    list<Produto*> prodEntrega;
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

    list<Produto *> getProdEntrega(int idCamiao);
};

